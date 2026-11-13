//
//  TBSDKShareViewController.m
//  Stock
//
//  Created by ChenXin on 2017/5/26.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import "TBSDKShareViewController.h"
#import <TBUIKIt/TBPopupWindowManager.h>
#import <TBShareKit/TBShareToolbar.h>
#import <TBShareKit/TBShareItemView.h>
#import <TBShareKit/TBShareUtils.h>
#import <TBShareKit/TBShareHandler.h>
#import <TBUIKit/MBProgressHUD+Wrapper.h>
#import <TBToolsKit/TBNotificationManager.h>
#import <TBUIKit/TBPageControl.h>
#import <TBBaseKit/TBBaseKit.h>
#import <TBUIKit/TBUIKit.h>
#import <SDWebImage/UIImageView+WebCache.h>
#import <TBToolsKit/TBSupportUtility.h>
#import <TBToolsKit/TBUserBehaviorMarcro.h>
#import <TBBaseKit/TBThirdPartyAccountManager.h>
#import <TBBusinessSupportKit/TBStockGlobalConfigManager.h>
#import <TBToolsKit/TBImageManager.h>
#import <TBToolsKit/TBUserBehaviorManager.h>
#import <TBToolsKit/TBSensorsDataUtil.h>
#import <TBBaseKit/NSObject+MJKeyValue.h>
#import <TBShareKit/TBCardShareUtil.h>
#import <TBShareKit/TBShareEmojiManager.h>
#import <TBUIKit/TBCustomIconManager.h>

#define kAnimationDuration 0.2

NSString * const TBShareDidSelectPlatformTypeNotification = @"TBShareDidSelectPlatformTypeNotification";

@interface TBSDKShareViewController () <UIScrollViewDelegate, TBShareToolbarDelegate>

// data
@property (nonatomic, strong) TBShareInfoModel *shareInfoModel;

@property (nonatomic, weak) id<TBShareTypeDelegate> shareTypeDelegate;
@property (nonatomic, weak) id<TBShareToolbarDelegate> toolbarDelegate;
@property (nonatomic, weak) id<TBShareToolbarDelegate> linkToolbarDelegate;
@property (nonatomic, weak) id<TBShareToolbarDelegate> imageToolbarDelegate;

// communityAction埋点相关
@property (nonatomic, strong) NSMutableDictionary *communityActionDic;
// 分享场景埋点相关
@property (nonatomic, copy) NSDictionary *sharePositionDic;
//后面统一使用的埋点字典，参数对应埋点的 uuid, type
@property (nonatomic, copy) NSDictionary *shareDic;

// settings
@property (nonatomic, copy) NSArray *specificItemTypes; // 指定某些平台, ???似乎用于加社区操作
@property (nonatomic, copy) NSArray *additionalPlatforms;

@property (nonatomic, assign) BOOL channelWechatSession;
@property (nonatomic, assign) BOOL channelWechatTimeline;
@property (nonatomic, assign) BOOL channelQQ;
@property (nonatomic, assign) BOOL channelWeibo;
@property (nonatomic, assign) BOOL channelInstagram;
@property (nonatomic, assign) BOOL channelTwitter;
@property (nonatomic, assign) BOOL channelFacebook;
@property (nonatomic, assign) BOOL channelWhatsApp;
@property (nonatomic, assign) BOOL channelTigerPost; // 老虎社区
@property (nonatomic, assign) BOOL channelMore; // 系统更多分享

@property (nonatomic, assign) BOOL channelSaveImage; // 保存图片到相册
@property (nonatomic, assign) BOOL channelCopy; // 分享集成复制链接
@property (nonatomic, assign) BOOL channelSafari; // 分享到safari打开
@property (nonatomic, assign) BOOL channelGeneratePicure; // 生成图片
@property (nonatomic, assign) BOOL channelCard; // 生成主页二维码

/// 在分享界面是否显示要分享的图片, 默认YES, NO用于截图分享, 最低程度修改界面以便通过审核
@property (nonatomic, assign) BOOL showImage;

//todo：确定要保留的
@property (nonatomic, assign) BOOL channelCopyContent; //是否分享文字内容
@property (nonatomic, assign) BOOL channelComplain; // 投诉
@property (nonatomic, assign) BOOL channelDeleteAsk;   // 企业问答 删除
@property (nonatomic, assign) BOOL channelReEdit;   // 企业问答 重新编辑
@property (nonatomic, assign) BOOL channelAnonymous;   // 企业问答 匿名

// views
@property (nonatomic, strong) UIView *backgroundView;

// 特殊场景下的views
@property (nonatomic, strong) TBPageControl *imagePageControl;

// viewcontroller
@property (nonatomic, weak) UIViewController *fromViewController;
@property (nonatomic, assign) TBShareContentType currentShareContentType;// 当前分享内容类型（链接、图片）

@end

@implementation TBSDKShareViewController

- (instancetype)initWithInfo:(TBShareInfoModel *)infoModel inViewController:(UIViewController *)viewController {
    self = [self initWithInfo:infoModel inViewController:viewController imageToolbarDelegate:nil];
    if (self) {
    }
    return self;
}

- (instancetype)initWithInfo:(TBShareInfoModel *)infoModel
            inViewController:(UIViewController *)viewController
        imageToolbarDelegate:(id<TBShareToolbarDelegate>)imageToolbarDelegate {
    self = [super init];
    if (self) {
        self.shareInfoModel = infoModel;
        self.fromViewController = viewController;
        self.alwaysShareToTigerPost = YES;
        self.imageToolbarDelegate = imageToolbarDelegate;
        self.showImage = YES; // default
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor clearColor];
    
    if (self.shareInfoModel.imageData && !self.images) {
        UIImage *image = [UIImage imageWithData:self.shareInfoModel.imageData];
        if (image && [image isKindOfClass:[UIImage class]]) {
            self.images = @[image];
        }
    }
    [self addSubviews];
    
    [self updateShareItems];
    
    if (self.isInSegmentedPageVC) {
        [self showAnimation:NO];
    }
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    [self updateImageScrollViewContentSize];//在创建image时候也会调用，这里调用是对imageView做最终的修正
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    [TBNotificationManager postNotificationName:kTB_NOTIFICATION_SHARE_BOARD_WILL_DISMISS object:nil userinfo:nil];
}

// 横竖屏切换
- (void)viewWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator {
    [super viewWillTransitionToSize:size withTransitionCoordinator:coordinator];

    if (IS_IPAD) {
        [TBSDKShareViewController hide];
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (BOOL)shouldAutorotate {
    return NO;
}

- (UIStatusBarStyle)preferredStatusBarStyle {
    if (self.shareInfoModel.backgroundViewColor) {
        return [TBAppColor preferredStatusBarStyle];
    } else {
        return UIStatusBarStyleLightContent;
    }
}

+ (void)showWithInfo:(TBShareInfoModel *)infoModel inViewController:(UIViewController *)viewController {
    [self showWithInfo:infoModel inViewController:viewController delegate:nil];
}

+ (void)showWithInfo:(TBShareInfoModel *)infoModel inViewController:(UIViewController *)viewController delegate:(id<TBShareToolbarDelegate>)delegate {
    [self showWithInfo:infoModel inViewController:viewController enableCommunity:NO delegate:delegate];
}

+ (void)showWithInfo:(TBShareInfoModel *)infoModel inViewController:(UIViewController *)viewController enableCommunity:(BOOL)enableCommunity delegate:(id<TBShareToolbarDelegate>)delegate
{
    [self showWithInfo:infoModel inViewController:viewController enableCommunity:enableCommunity delegate:delegate shareDic:nil];
}

+ (void)showWithInfo:(TBShareInfoModel *)infoModel inViewController:(UIViewController *)viewController enableCommunity:(BOOL)enableCommunity delegate:(id<TBShareToolbarDelegate>)delegate shareDic:(NSDictionary *)shareDic {
    if (!infoModel) {
        infoModel = [[TBShareInfoModel alloc] init];
    }
    
    infoModel.enableCommunity = enableCommunity;
    infoModel.shareDic = shareDic;
    [self shareWithInfo:infoModel additionalPlatforms:nil inViewController:viewController linkToolbarDelegate:delegate imageToolbarDelegate:nil];
}

+ (void)showWithImage:(UIImage *)image inViewController:(UIViewController *)viewController {
    if (!image) {
        return;
    }
    [self showWithImages:@[image] inViewController:viewController delegate:nil enablePostTiger:NO infoModel:nil shareDic:nil];
}

// TODO: 因为要求特殊, 暂时添加一个方法定制分享vc; 分享vc重构, 对外提供统一接口
+ (void)shareImage:(UIImage *)image inViewController:(UIViewController *)viewController withoutShowingIt:(BOOL)notShow enableCommunity:(BOOL)enableCommunity {
    if (!image) {
        return;
    }
    
    TBShareInfoModel *infoModel = [[TBShareInfoModel alloc] init];
    infoModel.images = @[image];
    infoModel.enableCommunity = enableCommunity;
    if ([TBService(TBAccountSystemComponentService) tbAccount_needUserAuthorization]) {
        return;
    }
    
    TBSDKShareViewController *shareVC = [[TBSDKShareViewController alloc] init];
    shareVC.shareInfoModel = infoModel;
    shareVC.fromViewController = viewController;
    if (infoModel.images) {
        shareVC.images = infoModel.images;
    }
    shareVC.showImage = NO;
    [shareVC show];
}

+ (void)showWithImage:(UIImage *)image inViewController:(UIViewController *)viewController delegate:(id<TBShareToolbarDelegate>)delegate {
    if (!image) {
        return;
    }
    [self showWithImages:@[image] inViewController:viewController delegate:delegate enablePostTiger:NO infoModel:nil shareDic:nil];
}

+ (void)showWithImage:(UIImage *)image inViewController:(UIViewController *)viewController enableCommunity:(BOOL)enableCommunity communityActionDic:(NSDictionary *)dic shareDic:(NSDictionary *)shareDic  delegate:(id<TBShareToolbarDelegate>)delegate{
    if(!image) {
        return;
    }

    TBShareInfoModel *shareInfoModel = [[TBShareInfoModel alloc] init];
    shareInfoModel.shareDic = shareDic;
    shareInfoModel.communityActionDic = dic;
    shareInfoModel.enableCommunity = enableCommunity;
    if (image && [image isKindOfClass:[UIImage class]]) {
        shareInfoModel.images = @[image];
    }
    [self shareWithInfo:shareInfoModel additionalPlatforms:nil inViewController:viewController linkToolbarDelegate:nil imageToolbarDelegate:delegate];
}

+ (void)showWithImage:(UIImage *)image inViewController:(UIViewController *)viewController enableCommunity:(BOOL)enableCommunity communityBadgeDic:(NSDictionary *)dic {
    if(!image) {
        return;
    }

    TBShareInfoModel *shareInfoModel = [[TBShareInfoModel alloc] init];
    shareInfoModel.shareDic = dic;
    shareInfoModel.enableCommunity = enableCommunity;
    if (image && [image isKindOfClass:[UIImage class]]) {
        shareInfoModel.images = @[image];
    }
    [self shareWithInfo:shareInfoModel additionalPlatforms:nil inViewController:viewController linkToolbarDelegate:nil imageToolbarDelegate:nil];
}

+ (void)showWithImage:(UIImage *)image inViewController:(UIViewController *)viewController enableCommunity:(BOOL)enableCommunity {
    [self showWithImage:image inViewController:viewController enableCommunity:enableCommunity delegate:nil];
}

+ (void)showWithImage:(UIImage *)image inViewController:(UIViewController *)viewController enableCommunity:(BOOL)enableCommunity delegate:(id<TBShareToolbarDelegate>)delegate {
    if(!image) {
        return;
    }
    
    [self showWithImages:@[image] inViewController:viewController delegate:delegate enablePostTiger:enableCommunity infoModel:nil shareDic:nil];
}

//分享图片外，还增加了复制文字选项
+ (void)showWithImage:(UIImage *)image content:(NSString *)contentString enableCommunity:(BOOL)enableCommunity inViewController:(UIViewController *)viewController shareDic:(NSDictionary *)shareDic {
    if(!image) {
        return;
    }

    TBShareInfoModel *shareInfoModel = [[TBShareInfoModel alloc] init];
    if (TextValid(contentString)) {
        shareInfoModel.desc = contentString;
    }
    shareInfoModel.shareDic = shareDic;
    shareInfoModel.enableCommunity = enableCommunity;
    if (image && [image isKindOfClass:[UIImage class]]) {
        shareInfoModel.images = @[image];
    }
    [self shareWithInfo:shareInfoModel additionalPlatforms:@[@(TBSharePlatformTypeCopyContent)] inViewController:viewController linkToolbarDelegate:nil imageToolbarDelegate:nil];
}

+ (void)showWithImages:(NSArray <UIImage *> *)images inViewController:(UIViewController *)viewController {
    [self showWithImages:images inViewController:viewController delegate:nil enablePostTiger:NO infoModel:nil shareDic:nil];
}

+ (void)showWithImages:(NSArray <UIImage *> *)images
      inViewController:(UIViewController *)viewController
              delegate:(id<TBShareToolbarDelegate>)delegate
       enablePostTiger:(BOOL)enablePostTiger
             infoModel:(TBShareInfoModel *)infoModel
              shareDic:(NSDictionary *)shareDic
{
    if (!infoModel) {
        infoModel = [[TBShareInfoModel alloc] init];
    }
    
    infoModel.enableCommunity = enablePostTiger;
    infoModel.shareDic = shareDic;
    if (images && [images isKindOfClass:[NSArray class]]) {
        infoModel.images = images;
    }
    [self shareWithInfo:infoModel additionalPlatforms:nil inViewController:viewController linkToolbarDelegate:nil imageToolbarDelegate:delegate];
}


+ (void)showWithSpaceImages:(NSArray <UIImage *> *)images inViewController:(UIViewController *)viewController delegate:(id<TBShareToolbarDelegate>)delegate enablePostTiger:(BOOL)enablePostTiger {
    if ([TBService(TBAccountSystemComponentService) tbAccount_needUserAuthorization]) {
        return;
    }
    [self showWithImages:images inViewController:viewController delegate:delegate enablePostTiger:enablePostTiger infoModel:nil shareDic:nil];
}

+ (void)showWithWebImages:(NSArray <NSString *> *)webImages inViewController:(UIViewController *)viewController delegate:(id<TBShareToolbarDelegate>)delegate {
    if ([TBService(TBAccountSystemComponentService) tbAccount_needUserAuthorization]) {
        return;
    }
    
    TBShareInfoModel *shareInfoModel = [[TBShareInfoModel alloc] init];
    TBSDKShareViewController *shareVC = [[TBSDKShareViewController alloc] initWithInfo:shareInfoModel inViewController:viewController imageToolbarDelegate:delegate];
    shareVC.images = webImages;

    [shareVC show];
    
    [self showWithImages:webImages inViewController:viewController delegate:delegate enablePostTiger:NO infoModel:nil shareDic:nil];
}

- (void)showWithAnimated:(BOOL)animated {
    [[TBPopupWindowManager sharedInstance] showViewController:self];

    [self showAnimation:animated];
}

- (void)show {
    [[TBPopupWindowManager sharedInstance] showViewController:self];
    
    [self showAnimation:YES];
}

+ (void)hide {
    [[TBPopupWindowManager sharedInstance] dismiss];
}

+ (void)shareWithInfo:(TBShareInfoModel *)infoModel platforms:(NSArray *)platforms inViewController:(UIViewController *)viewController {
    [self shareWithInfo:infoModel platforms:platforms inViewController:viewController delegate:nil];
}

+ (void)shareWithInfo:(TBShareInfoModel *)infoModel platforms:(NSArray *)platforms inViewController:(UIViewController *)viewController delegate:(id<TBShareToolbarDelegate>)delegate
{
    [TBSDKShareViewController shareWithInfo:infoModel additionalPlatforms:platforms inViewController:viewController linkToolbarDelegate:delegate imageToolbarDelegate:nil];
}

+ (void)shareWithInfo:(TBShareInfoModel *)infoModel platforms:(NSArray *)platforms inViewController:(UIViewController *)viewController delegate:(id<TBShareToolbarDelegate>)delegate imageToolbarDelegate:(id<TBShareToolbarDelegate>)imageToolbarDelegate
{
    if ([TBService(TBAccountSystemComponentService) tbAccount_needUserAuthorization]) {
        return;
    }
    
    if (platforms.count == 0) {
        return;
    }

    if (platforms.count == 1) {
        // 如果只有一个平台，直接分享
        [TBShareSDK shareWithInfo:infoModel platformType:(TBSharePlatformType)[platforms[0] integerValue] inViewController:viewController completion:^(TBShareResult result, NSString *message) {
            if (result == TBShareResultError) {
                [viewController showHint:message hide:3];
            }
        }];
    }
    else
    {
        TBSDKShareViewController *shareVC = [[TBSDKShareViewController alloc] init];
        shareVC.shareInfoModel = infoModel;
        shareVC.fromViewController = viewController;
        shareVC.additionalPlatforms = platforms;
        shareVC.toolbarDelegate = delegate;
        shareVC.imageToolbarDelegate = imageToolbarDelegate;
        [shareVC show];
    }
}

#pragma mark - Action

- (void)shareWithType:(TBSharePlatformType)type {
    if (!self.shareInfoModel) {
        return;
    }
    
    if(type == TBSharePlatformTypeCopyLink){
        if(self.shareInfoModel.shareLinkUrl.length > 0){
//            NSString *shareTo = [TBShareUtils channelNameFromSharePlatformType:type];
//            self.shareInfoModel.linkUrl = [self.shareInfoModel.linkUrl tb_stringByAddingParameterKey:@"utm_medium" value:shareTo];
            [UIPasteboard generalPasteboard].string = self.shareInfoModel.shareLinkUrl;
            [MBProgressHUD showHint:TBResourcesLocalizedString(@"mobile_ios_common_copied_to_clipboard", nil) hide:1.5f];
        }
        return;
    }
    
    if(type == TBSharePlatformTypeCopyContent){
        if(self.shareInfoModel.desc.length > 0){
            [UIPasteboard generalPasteboard].string = self.shareInfoModel.desc;
            [MBProgressHUD showHint:TBResourcesLocalizedString(@"mobile_ios_common_copied_to_clipboard", nil) hide:1.5f];
        }
        return;
    }
    
    if(type == TBSharePlatformTypeOpenSafari){
        NSString *originUrl = self.shareInfoModel.originUrl;
        if (!TextValid(originUrl)) {
            originUrl = self.shareInfoModel.shareLinkUrl;
        }
        if (TextValid(originUrl)) {
            [[UIApplication sharedApplication] openURL:[NSURL URLWithString:originUrl] options:@{} completionHandler:nil];
        }
        return;
    }
    
    NSDictionary *shareDic = self.shareDic ?: self.shareInfoModel.shareDic;
    
    if (self.images.count > 0) {
        UIImage *image = nil;
        
        if (self.showImage && self.currentShareContentType == TBShareContentTypeImage) {
            NSInteger index = self.imagePageControl.currentPage;
            UIImageView *imageView = [self.imageScrollView viewWithTag:kImageViewTag + index];
            if ([imageView isKindOfClass:[UIImageView class]]) {
                image = imageView.image;
            }
        } else {
            // 不显示要分享的图片, 是截屏分享, 取第一张图
            image = self.images.firstObject;
        }
        
        if (!image) {
            return;
        }
        
//        if (self.shareInfoModel.hasQRCode && shareDic && self.shareInfoModel.selectedShareContentType == TBShareContentTypeImage) {
//            // 替换二维码
//            NSString *shareType = shareDic[@"type"];
//            NSString *campaign = shareDic[@"uuid"];
//            NSString *shareTo = [TBShareUtils channelNameFromSharePlatformType:type];
//            image = [self imageWithNewQRCodeForImage:image type:shareType shareTo:shareTo campaign:campaign shareID:[TBShareUtils getShareID]];
//        }
        
        if (type == TBSharePlatformTypeSaveImage) {
            [TBSupportUtility requestAuthorizationStatus:^(BOOL enable) {
                if(enable){
                    UIImageWriteToSavedPhotosAlbum(image, self, @selector(image:didFinishSavingWithError:contextInfo:), nil);
                    [[TBShareHandler sharedInstance] shareBackFromType:@"saveimage" result:TBShareResultDone];
                }
                else {
                    [MBProgressHUD showHint:TBResourcesLocalizedString(@"mobile_ios_common_please_ensure_to_open_permission", nil) hide:2];
                }
            }];
            return;
        }
        
        self.shareInfoModel.imageData = UIImagePNGRepresentation(image);
    }
    
    if (self.communityActionDic) {
        if (type != TBSharePlatformTypeTigerPost) {
            TB_SA_TRACK_COMMUNITY_ACTION_DIC(self.communityActionDic);
        } else {
            self.communityActionDic[@"type"] = @"转发";
            self.shareInfoModel.communityActionDic = self.communityActionDic;
        }
    }
    
    if (self.sharePositionDic) {
        if (type == TBSharePlatformTypeTigerPost || type == TBSharePlatformTypeSaveImage) {
            self.shareInfoModel.imageData = self.shareInfoModel.imageDataWithNoQR;
        }
    }

    @weakify(self);
    [TBShareSDK shareWithInfo:self.shareInfoModel platformType:type inViewController:self.fromViewController completion:^(TBShareResult result, NSString *message) {
        @strongify(self);
        if (result == TBShareResultError) {
            [self.fromViewController showHint:message hide:3];
        }
    }];
    
    // 分享成功后是否需要解锁新的表情包
    if (self.shareInfoModel.shouldUnlockOneNewEmojiAfterShare &&
        type != TBSharePlatformTypeCopyContent &&
        type != TBSharePlatformTypeCopyLink &&
        type != TBSharePlatformTypeSaveImage &&
        type != TBSharePlatformTypeOpenSafari) {
        [[TBShareEmojiManager sharedInstance] unlockFirstlockedEmoji];
    }
}

- (void)hideAction {
    if (self.isInSegmentedPageVC) {
        [self.fromViewController dismiss];
        return;
    }
    [self hideAnimationWithCompletion:^(BOOL finished) {
        if (finished) {
            [TBSDKShareViewController hide];
        }
    }];
    
    [[TBShareHandler sharedInstance] shareBackFromType:nil result:TBShareResultCancelled];
}

- (void)actionShareLinkButton:(id)sender {
    // 分享链接
    self.shareLinkButton.selected = YES;
    self.shareImageButton.selected = NO;
    if (self.currentShareContentType != TBShareContentTypeURL) {
        self.currentShareContentType = TBShareContentTypeURL;
        [self updateShareItems];
        [self updateShareImageShowOrHide];
    }
    self.shareInfoModel.selectedShareContentType = TBShareContentTypeURL;
    self.toolbarDelegate = self.linkToolbarDelegate;
    
    if ([self isShareImagePreparing]) {
        [self hideLoading:YES];
    }
    
    if (self.shareTypeDelegate && [self.shareTypeDelegate respondsToSelector:@selector(shareTypeDidChange:)]) {
        [self.shareTypeDelegate shareTypeDidChange:TBShareCustomTypeLink];
    }
}

- (void)actionShareImageButton:(id)sender {
    // 分享图片
    self.shareImageButton.selected = YES;
    self.shareLinkButton.selected = NO;
    if (self.currentShareContentType != TBShareContentTypeImage) {
        self.currentShareContentType = TBShareContentTypeImage;
        [self updateShareItems];
        
        if ([self isShareImagePreparing]) {
            [self showLoading:YES enableUserAction:YES];
        } else {
            if (self.images && self.images.count>0) {
                [self updateShareImageShowOrHide];
            }
        }
    }
    self.shareInfoModel.selectedShareContentType = TBShareContentTypeImage;
    self.toolbarDelegate = self.imageToolbarDelegate;
    
    if (self.shareTypeDelegate && [self.shareTypeDelegate respondsToSelector:@selector(shareTypeDidChange:)]) {
        [self.shareTypeDelegate shareTypeDidChange:TBShareCustomTypeImage];
    }
}

#pragma mark - Private Method

//- (UIImage *)imageWithNewQRCodeForImage:(UIImage *)image type:(NSString *)type shareTo:(NSString *)shareTo campaign:(NSString *)campaign shareID:(NSString *)shareID {
//    CGFloat bottomImageHeight = 80 * image.size.width / SCREEN_WIDTH;
//    CGRect rect = CGRectZero;
//    rect.size = image.size;
//    UIImage *newContentImage = [image subImageWithRect:CGRectMake(0, 0, image.size.width, image.size.height - bottomImageHeight)];
//    UIImage *newBottomImage = [TBImageManager generateShareBottomImageWithSize:CGSizeMake(image.size.width, bottomImageHeight)
//                                                                          type:type
//                                                                       shareTo:shareTo
//                                                                      campaign:campaign
//                                                                       shareID:shareID
//                                                                     shareText:nil
//                                                                      complete:^(UIImage * _Nonnull image) {
//        
//    }];
//    image = [TBImageManager combinShareImagefromArr:@[newContentImage, newBottomImage] withSize:rect.size];
//    return image;
//}

- (void)addSubviews {
    [self.view addSubview:self.backgroundView]; // 暗色遮罩, 点击解除
    [self.backgroundView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.edges.equalTo(self.view);
    }];
    self.backgroundView.backgroundColor = RGBACOLOR_HEX(0x000000, 0.35);
    if (self.shareInfoModel && self.shareInfoModel.backgroundViewColor && [self.shareInfoModel.backgroundViewColor isKindOfClass:[UIColor class]]) {
        self.backgroundView.backgroundColor = self.shareInfoModel.backgroundViewColor;
    }
    
    [self.view addSubview:self.bottomView];
    [self.bottomView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.right.equalTo(self.view);
        make.height.mas_greaterThanOrEqualTo(0);
        make.top.equalTo(self.view.mas_bottom);
    }];
    [self.view layoutIfNeeded];
    
    self.shareLinkButton.selected = YES; // 默认分享链接
    
    BOOL couldShareLink = TextValid(self.shareInfoModel.linkUrl) && ![TBService(TBSwiftComponentService) swiftService_isHiddenModuleWithKey:@"ShareHide"];
    BOOL couldShareImage = NO;
    BOOL couldShareFile = NO;
    if (self.shareInfoModel.images &&
        [self.shareInfoModel.images isKindOfClass:[NSArray class]] &&
        self.shareInfoModel.images.count>0) {
        couldShareImage = YES;
    }else if (self.shareInfoModel.imageData && [self.shareInfoModel.imageData isKindOfClass:[NSData class]]) {
        couldShareImage = YES;
    } else if (self.shareInfoModel.fileData) {
        couldShareFile = YES;
    }
    
    self.currentShareContentType = TBShareContentTypeNone;
    if (couldShareImage && couldShareLink) { // 既能分享链接，又能分享图片，才创建切换UI
        [self.shareTypeView addSubview:self.shareLinkButton];
        [self.shareTypeView addSubview:self.shareImageButton];
        [self.view addSubview:self.shareTypeView];
        self.currentShareContentType = TBShareContentTypeURL;
        [self.shareLinkButton mas_makeConstraints:^(MASConstraintMaker *make) {
            make.leading.equalTo(self.shareTypeView).offset(13);
            make.centerY.equalTo(self.shareTypeView);
            make.top.equalTo(self.shareTypeView).offset(6);
            make.bottom.equalTo(self.shareTypeView).offset(-6);
        }];
        [self.shareImageButton mas_makeConstraints:^(MASConstraintMaker *make) {
            make.leading.equalTo(self.shareLinkButton.mas_trailing).offset(18);
            make.trailing.equalTo(self.shareTypeView).offset(-10);
            make.centerY.top.bottom.equalTo(self.shareLinkButton);
        }];
        [self.shareTypeView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.leading.equalTo(self.view).offset(12);
            make.bottom.equalTo(self.bottomView.mas_top).offset(-12);
        }];
    } else if (couldShareLink) {
        self.currentShareContentType = TBShareContentTypeURL;
    } else if (couldShareImage) {
        self.currentShareContentType = TBShareContentTypeImage;
    } else if (couldShareFile) {
        self.currentShareContentType = TBShareContentTypeFile;
    }
    self.shareInfoModel.selectedShareContentType = self.currentShareContentType;
    self.toolbarDelegate = (self.currentShareContentType==TBShareContentTypeURL) ? self.linkToolbarDelegate : self.imageToolbarDelegate;
    
    // 图片
    [self.view addSubview:self.imageScrollView];
    [self.imageScrollView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.view);
        make.right.equalTo(self.view);
        make.top.equalTo(self.view.mas_top).offset(40);
        if (_shareTypeView) {
            make.bottom.equalTo(self.shareTypeView.mas_top).offset(-20);
        } else {
            make.bottom.equalTo(self.bottomView.mas_top).offset(-20);
        }
    }];
    if (self.images.count > 0) {
        [self showImages:self.images];
        [self updateImageScrollViewContentSize];
    }
    if (self.currentShareContentType==TBShareContentTypeImage) {
        self.imageScrollView.hidden = NO;
    } else {
        self.imageScrollView.hidden = YES;
    }
    if ([self isShareImagePreparing]) {
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(shareImageDidReady:) name:kTBNotificationShareImageDidReady object:nil];
    }
    
    // 如果默认勾选分享类型为图片
    if (couldShareImage && couldShareLink && self.shareInfoModel.defaultSelectedContentType == TBShareContentTypeImage) {
        [self actionShareImageButton:nil];
    }
}

- (void)shareImageDidReady:(NSNotification *)noti {
    NSDictionary *imageDic = noti.userInfo;
    if (imageDic && [imageDic isKindOfClass:[NSDictionary class]]) {
        id image = [imageDic objectForKey:@"image"];
        if ([image isKindOfClass:[UIImage class]]) {
            self.images = @[image];
        } else if ([image isKindOfClass:[NSArray class]]) {
            self.images = image;
        }
        
        if (self.images.count > 0) {
            [self showImages:self.images];
            [self updateImageScrollViewContentSize];
        }
        if (self.currentShareContentType==TBShareContentTypeImage) {
            self.imageScrollView.hidden = NO;
            [self hideLoading:YES];
        } else {
            self.imageScrollView.hidden = YES;
        }
        
        [[NSNotificationCenter defaultCenter] removeObserver:self name:kTBNotificationShareImageDidReady object:nil];
    }
}

- (void)showImages:(NSArray *)images {
    if ([self isShareImagePreparing]) {
        return;
    }
    
    [self.imageScrollView removeAllSubviews];
    NSInteger count = images.count;
    UIImageView *lastImageView = nil;
    for (NSInteger i = 0; i < count; i++) {
        UIImageView *imageView = [[UIImageView alloc] init];
        if (self.shareInfoModel.shouldHideImageInShareViewController) {
            imageView.hidden = YES;
        }
        imageView.layer.cornerRadius = 10;
        imageView.layer.masksToBounds = YES;
        imageView.contentMode = UIViewContentModeScaleAspectFill;
        imageView.tag = kImageViewTag + i;
        [self.imageScrollView addSubview:imageView];
        [imageView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.top.mas_equalTo(0);
            if (lastImageView) {
                make.left.equalTo(lastImageView.mas_right).offset(40);
            }
            else {
                make.left.mas_equalTo(20);
            }
            make.width.equalTo(self.imageScrollView).offset(-40);
            make.height.equalTo(self.imageScrollView);
        }];
        
        id image = images[i];
        if ([image isKindOfClass:[UIImage class]]) {
            imageView.image = image;
        }
        else if ([image isKindOfClass:[NSString class]]) {
            NSURL *imageURL = [NSURL URLWithString:image];
            weakSelf();
            [imageView sd_setImageWithURL:imageURL placeholderImage:nil options:SDWebImageRetryFailed | SDWebImageProgressiveLoad | SDWebImageScaleDownLargeImages completed:^(UIImage * _Nullable image, NSError * _Nullable error, SDImageCacheType cacheType, NSURL * _Nullable imageURL) {
                if (image) {
                    imageView.image = image;
                }
                else {
                    [weakSelf showHint:TBResourcesLocalizedString(@"mobile_comm_common_failed_to_load", nil) hide:2];
                }
            }];
        }
        lastImageView = imageView;
    }
    
    if (count > 1) {
        if (!_imagePageControl) {
            [self.view addSubview:self.imagePageControl];
            [self.imagePageControl mas_makeConstraints:^(MASConstraintMaker *make) {
                make.left.right.equalTo(self.view);
                make.top.equalTo(self.imageScrollView.mas_bottom).offset(5);
                make.height.mas_equalTo(10);
            }];
        }
        self.imagePageControl.numberOfPages = count;
    }
    [self.view layoutIfNeeded];
}

- (void)showAnimation:(BOOL)animated {
    [self.bottomView mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.left.right.equalTo(self.view);
        make.height.mas_greaterThanOrEqualTo(0);
        make.bottom.equalTo(self.view.mas_bottom);
    }];
    if (animated) {
        if (TBIsTradeUP) {
            [self.shareToolbar showAnimation];
        }

        self.backgroundView.alpha = 0;
        [UIView animateWithDuration:kAnimationDuration animations:^{
            [self.view layoutIfNeeded];
            self.backgroundView.alpha = 1;
        } completion:^(BOOL finished) {
//            [self updateImageScrollViewContentSize];
        }];
    }
    else {
        [self.view layoutIfNeeded];
//        [self updateImageScrollViewContentSize];
    }
}

- (void)updateImageScrollViewContentSize {
    NSInteger count = self.images.count;
    if (count > 0 /*&& self.currentShareContentType == TBShareContentTypeImage*/) {
        CGRect isvRect = self.imageScrollView.frame;
        CGFloat contentHeight = isvRect.size.height;
        // 单张长图支持上下滑动
        if (count == 1) {
            self.imageScrollView.pagingEnabled = NO;
            UIImageView *imageView = [self.imageScrollView viewWithTag:kImageViewTag + 0];
            if (imageView.image) {
                CGSize size = imageView.image.size;
                CGFloat ratio = size.height / size.width;
                CGFloat imageWidth = isvRect.size.width - 40;
                CGFloat imageHeight = imageWidth * ratio;
                [imageView mas_remakeConstraints:^(MASConstraintMaker *make) {
                    if (imageHeight > contentHeight) {
                        make.top.equalTo(self.imageScrollView);
                    }
                    else {
                        make.centerY.equalTo(self.imageScrollView);
                    }
                    make.left.mas_equalTo(20);
                    make.width.mas_equalTo(imageWidth);
                    make.height.mas_equalTo(imageHeight);
                }];
                if (imageHeight > contentHeight) {
                    contentHeight = imageHeight;
                }
                // 根据UI要求， 调整持仓分享和个股行情分享截图imageview 大小， 因为新的持仓分享老虎形象的替换，需要适当的缩小一下显示比例，协商结果为乘以0.8的系数
                CGAffineTransform transform =  CGAffineTransformIdentity;
                transform = CGAffineTransformScale(transform, 0.8, 0.8);
                transform = CGAffineTransformTranslate(transform, 0, -imageHeight*0.1);
                imageView.transform = transform;
            }
        } else {
            self.imageScrollView.pagingEnabled = YES;
            UIImageView *lastImageView = nil;
            for (NSInteger i = 0; i < self.images.count; i++) {
                UIImageView *imageView = [self.imageScrollView viewWithTag:kImageViewTag + i];
                if (imageView.image) {
                    CGSize size = imageView.image.size;
                    CGFloat ratio = size.height / size.width;
                    CGFloat imageWidth = isvRect.size.width - 40;
                    CGFloat imageHeight = imageWidth * ratio;
                    [imageView mas_remakeConstraints:^(MASConstraintMaker *make) {
                        if (lastImageView) {
                            make.left.equalTo(lastImageView.mas_right).offset(40);
                        }
                        else {
                            make.left.mas_equalTo(20);
                        }
                        
                        make.centerY.equalTo(self.imageScrollView);
                        make.width.mas_equalTo(imageWidth);
                        make.height.mas_equalTo(imageHeight);
                    }];
                    
                    self.view.backgroundColor = [self contentBgColor] ? [self contentBgColor] : RGBACOLOR_HEX(0x000000, 0.7);
                    
                    CGAffineTransform transform =  CGAffineTransformIdentity;
                    transform = CGAffineTransformScale(transform, 0.8, 0.8);
                    transform = CGAffineTransformTranslate(transform, 0, -imageHeight*0.1);
                    imageView.transform = transform;
                }
                
                lastImageView = imageView;
            }
        }
        CGSize contentSize = self.imageScrollView.contentSize;
        contentSize.width = count * isvRect.size.width;
        contentSize.height = contentHeight * 0.8 + 50; // 未考虑缩放后图片top变化，另外多图分享看起来逻辑不全
        if (count == 1) { // 补丁修复单图超长计算逻辑，
            UIImageView *imageView = [self.imageScrollView viewWithTag:kImageViewTag + 0];
            [imageView layoutIfNeeded];
            if (imageView.tb_bottom >  contentSize.height) {
                contentSize.height = imageView.tb_bottom + 50;
            }
        }
        self.imageScrollView.contentSize = contentSize;
        [self.imageScrollView flashScrollIndicators];
    }
}

- (void)hideAnimationWithCompletion:(void (^ __nullable)(BOOL finished))completion {
    [self.bottomView mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.left.right.equalTo(self.view);
        make.height.mas_greaterThanOrEqualTo(0);
        make.top.equalTo(self.view.mas_bottom);
    }];
    [UIView animateWithDuration:kAnimationDuration animations:^{
        [self.view layoutIfNeeded];
        self.backgroundView.alpha = 0;
        self.view.alpha = 0;
    } completion:completion];
}

- (void)image:(UIImage *)image didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo
{
    UIViewController *topVC = [TBSupportUtility getTopVC];
    NSString *message = nil;
    if (!error) {
        message = TBResourcesLocalizedString(@"mobile_comm_common_save_successfully", nil);
    }
    else {
        message = error.localizedDescription;
    }
    [topVC showHint:message hide:2];
}

#pragma mark tool
- (BOOL)isShareImagePreparing {
    BOOL isPreparing = NO;
    if (self.shareInfoModel.images &&
        [self.shareInfoModel.images isKindOfClass:[NSArray class]] &&
        self.shareInfoModel.images.count>0) {
        NSString *image = self.shareInfoModel.images[0];
        if (image && [image isKindOfClass:[NSString class]] && [image isEqualToString:kTBShareImageIsPreparingKey]) {
            isPreparing = YES;
        }
    }
    return isPreparing;
}

// 分享链接加参数(1.UTM + Platform + shareID + invite + lang)
- (void)createParameterToShareLinkWithPlatformType:(TBSharePlatformType)platformType {
    if (self.shareInfoModel && TextValid(self.shareInfoModel.linkUrl)) {
        // 1.UTM
        if (TextValid(self.shareInfoModel.utmInfo.utm_source)) {
            self.shareInfoModel.linkUrl = [self.shareInfoModel.linkUrl tb_stringByAddingParameterKey:@"utm_source" value:self.shareInfoModel.utmInfo.utm_source];
        }
        if (TextValid(self.shareInfoModel.utmInfo.utm_campaign)) {
            self.shareInfoModel.linkUrl = [self.shareInfoModel.linkUrl tb_stringByAddingParameterKey:@"utm_campaign" value:self.shareInfoModel.utmInfo.utm_campaign];
        }
        NSString *shareTo = [TBShareUtils channelNameFromSharePlatformType:platformType];
        self.shareInfoModel.linkUrl = [self.shareInfoModel.linkUrl tb_stringByAddingParameterKey:@"utm_medium" value:shareTo];
        // 2.Platform
        self.shareInfoModel.linkUrl = [self.shareInfoModel.linkUrl tb_stringByAddingParameterKey:@"platform" value:@"iOS"];
        // 3.shareID
        self.shareInfoModel.linkUrl = [self.shareInfoModel.linkUrl tb_stringByAddingParameterKey:@"shareID" value:[TBShareUtils getShareID]];
        // 4.invite
        self.shareInfoModel.linkUrl = [self.shareInfoModel.linkUrl tb_stringByAddingParameterKey:@"invite" value:[TBService(TBCommunityComponentService) tbCommunity_personalInviteCode]];
        // 5.lang
        self.shareInfoModel.linkUrl = [self.shareInfoModel.linkUrl tb_stringByAddingParameterKey:@"lang" value:[TBLanguageManager currentLangParameter]];
    }
    if (self.shareInfoModel && TextValid(self.shareInfoModel.imageShareLink)) {
        // 1.UTM
        if (TextValid(self.shareInfoModel.utmInfo.utm_source)) {
            self.shareInfoModel.imageShareLink = [self.shareInfoModel.imageShareLink tb_stringByAddingParameterKey:@"utm_source" value:self.shareInfoModel.utmInfo.utm_source];
        }
        if (TextValid(self.shareInfoModel.utmInfo.utm_campaign)) {
            self.shareInfoModel.imageShareLink = [self.shareInfoModel.imageShareLink tb_stringByAddingParameterKey:@"utm_campaign" value:self.shareInfoModel.utmInfo.utm_campaign];
        }
        NSString *shareTo = [TBShareUtils channelNameFromSharePlatformType:platformType];
        self.shareInfoModel.imageShareLink = [self.shareInfoModel.imageShareLink tb_stringByAddingParameterKey:@"utm_medium" value:shareTo];
        // 2.Platform
        self.shareInfoModel.imageShareLink = [self.shareInfoModel.imageShareLink tb_stringByAddingParameterKey:@"platform" value:@"iOS"];
        // 3.shareID
        self.shareInfoModel.imageShareLink = [self.shareInfoModel.imageShareLink tb_stringByAddingParameterKey:@"shareID" value:[TBShareUtils getShareID]];
        // 4.invite
        self.shareInfoModel.imageShareLink = [self.shareInfoModel.imageShareLink tb_stringByAddingParameterKey:@"invite" value:[TBService(TBCommunityComponentService) tbCommunity_personalInviteCode]];
        // 5.lang
        self.shareInfoModel.imageShareLink = [self.shareInfoModel.imageShareLink tb_stringByAddingParameterKey:@"lang" value:[TBLanguageManager currentLangParameter]];
    }
}

// 上报埋点（点击分享渠道埋点）
- (void)saTrackWhenUserDidSelectWithPlatform:(TBSharePlatformType)platformType{
    NSMutableDictionary *properties = [[NSMutableDictionary alloc] init];
    // --------- 兼容之前各种奇形怪状的写法（通过shareDic传递、通过sharePositionDic传递），防止漏掉已有的老逻辑
    NSMutableDictionary *shareDic = [[NSMutableDictionary alloc] init];
    if (self.shareDic) {
        [shareDic addEntriesFromDictionary:self.shareDic];
    }
    if (self.shareInfoModel.shareDic) {
        [shareDic addEntriesFromDictionary:self.shareInfoModel.shareDic];
    }
    NSString *uuidString = nil;
    NSString *typeString = nil;
    if (shareDic.count > 0) {
        uuidString = [shareDic objectForKey:@"uuid"] ? : @"";
        typeString = [shareDic objectForKey:@"type"] ? : @"";
        [properties addEntriesFromDictionary:shareDic];
    }
    if (self.sharePositionDic) {
        uuidString = [self.sharePositionDic objectForKey:@"symbol"] ? : uuidString;
        typeString = [self.sharePositionDic objectForKey:@"type"] ? : typeString;
    }
    if (TextValid(uuidString) && !TextValid(self.shareInfoModel.utmInfo.utm_campaign)) {
        self.shareInfoModel.utmInfo.utm_campaign = uuidString;
    }
    if (TextValid(typeString) && !TextValid(self.shareInfoModel.utmInfo.utm_source)) {
        self.shareInfoModel.utmInfo.utm_source = typeString;
    }
    // ----------
    
    
    uuidString = TextValid(self.shareInfoModel.utmInfo.utm_campaign) ? self.shareInfoModel.utmInfo.utm_campaign : uuidString;
    typeString = TextValid(self.shareInfoModel.utmInfo.utm_source) ? self.shareInfoModel.utmInfo.utm_source : typeString;
    NSString *shareTo = [TBShareUtils channelNameFromSharePlatformType:platformType];
    NSString *shareID = [TBShareUtils getShareID];
    if (uuidString) {
        [properties setValue:uuidString forKey:@"uuid"];
    }
    if (typeString) {
        [properties setValue:typeString forKey:@"type"];
    }
    if (shareTo) {
        [properties setValue:shareTo forKey:@"shareTo"];
    }
    if (shareID) {
        [properties setValue:shareID forKey:@"shareID"];
    }
    if (self.shareInfoModel.selectedShareContentType == TBShareContentTypeURL) {
        [properties setValue:@"link" forKey:@"shareMaterial"];
    } else if (self.shareInfoModel.selectedShareContentType == TBShareContentTypeImage) {
        [properties setValue:@"image" forKey:@"shareMaterial"];
    }
    
    if (TextValid(self.shareInfoModel.actionID)) {
        [properties setValue:self.shareInfoModel.actionID forKey:@"actionID"];
    }
    
    [TBUserBehaviorManager track:@"appShare" withProperties:properties extraMessage:nil];
}

// 分享之前把链接转为短链接
+ (void)shortenShareLinkIfNeededWith:(TBShareInfoModel *)shareInfo
                selectedPlatformType:(TBSharePlatformType)platformType
                          completion:(void (^)(void))completion {
    if (!shareInfo) {
        if (completion) {
            completion();
        }
        return;
    }
    
    NSString *originalLink = nil;
    
    // 判断需要转换的链接类型
    if ((shareInfo.selectedShareContentType == TBShareContentTypeURL || shareInfo.selectedShareContentType == TBShareContentTypeNone) && TextValid(shareInfo.linkUrl)) {
        originalLink = shareInfo.linkUrl;
    } else if (platformType == TBSharePlatformTypeTwitter && TextValid(shareInfo.imageShareLink)) {
        originalLink = shareInfo.imageShareLink;
    }
    
    // 进行短链转换
    if (originalLink) {
        [TBShareUtils fetchShortlinkWithLink:originalLink
                                   isInside:(platformType == TBSharePlatformTypeTigerPost)
                                 completion:^(NSString * _Nonnull shortlink) {
            if (TextValid(shortlink)) {
                shareInfo.shortlinkUrl = shortlink;
            }
            if (completion) {
                completion();
            }
        }];
    } else {
        if (completion) {
            completion();
        }
    }
}


#pragma mark - shareToolbar delegate

- (void)shareToolbar:(TBShareToolbar *)shareToolbar didSelectWithPlatformType:(TBSharePlatformType)platformType {
    
    [self hideAnimationWithCompletion:^(BOOL finished) {
        if (finished) {
            [TBSDKShareViewController hide];
            [MBProgressHUD showHint:@"客户自定义点击分享逻辑" hide:2];
        }
    }];

    return;
    
    // 执行需要防止重复执行的代码
    if (self.currentShareContentType == TBShareContentTypeImage) {
        if ([self isShareImagePreparing]) {
            return;
        }
    }
    
    static BOOL isRunning = NO;
    if (isRunning) {
        return;
    }
    isRunning = YES;
    
    // 每次点击分享面板渠道时生成唯一的分享ID，后续的上报埋点，以及分享链接中拼的shareid 都用的这次生成的（特殊的：生成的分享图需要带二维码，生成二维码图的时候已经产出了shareid，这里就不用重新生成）
    if (!TextValid(self.shareInfoModel.qrImageShareId)) {
        [TBShareUtils createShareID];
    }
    
    // 上报埋点（点击分享渠道埋点）
    [self saTrackWhenUserDidSelectWithPlatform:platformType];
    
    // 分享链接加参数(1.UTM + Platform + shareID)
    [self createParameterToShareLinkWithPlatformType:platformType];
    
    // 处理短链接
    [TBSDKShareViewController shortenShareLinkIfNeededWith:self.shareInfoModel selectedPlatformType:platformType completion:^{
        [self continueShareToolbar:shareToolbar didSelectWithPlatformType:platformType];
    }];
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        isRunning = NO;
    });
}

- (void)continueShareToolbar:(TBShareToolbar *)shareToolbar didSelectWithPlatformType:(TBSharePlatformType)platformType {
    if (self.images.count > 0) {
        NSInteger index = self.imagePageControl.currentPage;
        UIImageView *imageView = [self.imageScrollView viewWithTag:kImageViewTag + index];
        if ([imageView isKindOfClass:[UIImageView class]]) {
            UIImage *image = imageView.image;
            if (!image) {
                [self showHint:@"当前图片尚未加载完，请稍后再试" hide:2];
                return;
            }
        }
    }
    
    if (self.isInSegmentedPageVC) {
        if (self.toolbarDelegate && [self.toolbarDelegate respondsToSelector:@selector(shareToolbar:willSelectWithPlatformType:)]) {
            [self.toolbarDelegate shareToolbar:shareToolbar willSelectWithPlatformType:platformType];
        }
        
        [self shareWithType:platformType];
        
        return;
    }
    
    [self hideAnimationWithCompletion:^(BOOL finished) {
        if (finished) {
            [TBSDKShareViewController hide]; //必须先隐藏
            [TBNotificationManager postNotificationName:TBShareDidSelectPlatformTypeNotification object:nil userinfo:@{@"type":@(platformType)}];
            if(self.toolbarDelegate && [self.toolbarDelegate respondsToSelector:@selector(shareToolbar:didSelectWithPlatformType:)]){
                [self.toolbarDelegate shareToolbar:shareToolbar didSelectWithPlatformType:platformType];
            } else {
                if (self.toolbarDelegate && [self.toolbarDelegate respondsToSelector:@selector(shareToolbar:willSelectWithPlatformType:)]) {
                    [self.toolbarDelegate shareToolbar:shareToolbar willSelectWithPlatformType:platformType];
                }
                
                [self shareWithType:platformType];
            }
        }
    }];
}

#pragma mark - scrollView delegate
- (void)scrollViewDidScroll:(UIScrollView *)scrollView {
    NSInteger page = round(scrollView.contentOffset.x / scrollView.frame.size.width);
    if (scrollView == self.imageScrollView) {
        self.imagePageControl.currentPage = page;        
        if (self.indexChangedBlock) {
            self.indexChangedBlock(page);
        }
    }
}

#pragma mark - View

- (UIView *)backgroundView {
    if (!_backgroundView) {
        _backgroundView = [[UIView alloc] init];
        _backgroundView.backgroundColor = RGBACOLOR_HEX(0x000000, 0.35);
        [_backgroundView addGestureRecognizer:[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(hideAction)]];
    }
    return _backgroundView;
}

- (UIView *)bottomView {
    if (!_bottomView) {
        UIView *bottomView = [[UIView alloc] init];
        bottomView.backgroundColor = COLOR_BACKGROUND_DARK;
        bottomView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleTopMargin;
        
        CGRect rect = CGRectMake(0, 0, SCREEN_WIDTH, kTBShareToolbarHeight + SAFEAREA_BOTTOM_HEIGHT);
        UIBezierPath *bezierPath = [UIBezierPath bezierPathWithRoundedRect:rect byRoundingCorners:UIRectCornerTopLeft | UIRectCornerTopRight cornerRadii:CGSizeMake(16, 16)];
        CAShapeLayer *maskLayer = [[CAShapeLayer alloc] init];
        maskLayer.path = bezierPath.CGPath;
        bottomView.layer.mask = maskLayer;
        
        static const BOOL showCancelButton = NO; // 不显示取消按钮
        if (showCancelButton) {
            CGFloat cancelButtonHeight = 45;
            
            UIView *lineView = [[UIView alloc] init];
            lineView.backgroundColor = COLOR_SINGLE_LINE;
            [bottomView addSubview:lineView];
            [lineView mas_makeConstraints:^(MASConstraintMaker *make) {
                make.left.right.mas_equalTo(0);
                make.height.mas_equalTo(K_1PX);
                make.bottom.equalTo(bottomView.tb_mas_bottom).offset(-cancelButtonHeight);
            }];
            
            [bottomView addSubview:self.cancelButton];
            [_cancelButton mas_makeConstraints:^(MASConstraintMaker *make) {
                make.left.right.bottom.mas_equalTo(0);
                make.bottom.equalTo(bottomView.tb_mas_bottom);
                make.height.mas_equalTo(cancelButtonHeight);
            }];
        }
        
        [bottomView addSubview:self.shareToolbar];
        [_shareToolbar mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.right.top.equalTo(bottomView);
            if (showCancelButton) {
                make.bottom.equalTo(self.cancelButton.mas_top);
            }
            else {
                make.bottom.equalTo(bottomView.tb_mas_bottom);
            }
            make.height.mas_equalTo(kTBShareToolbarHeight);
        }];
        
        _bottomView = bottomView;
    }
    return _bottomView;
}

- (UIView *)shareTypeView {
    if (!_shareTypeView) {
        UIView *view = [[UIView alloc] init];
        view.backgroundColor = COLOR_BACKGROUND_DARK;
        view.layer.cornerRadius = 8;
        [view setContentCompressionResistancePriority:UILayoutPriorityRequired forAxis:UILayoutConstraintAxisVertical];
        
        _shareTypeView = view;
    }
    return _shareTypeView;
}

- (UIButton *)shareLinkButton {
    if (!_shareLinkButton) {
        UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
        button.titleLabel.font = FONTO(12);
        [button setTitle:TBResourcesLocalizedString(@"mobile_comm_common_share_link", nil) forState:UIControlStateNormal];
        [button setTitleColor:COLOR_TITLE forState:UIControlStateNormal];
        [button setImage:[UIImage tb_themeImageNamed:@"icon_single_round_unselect"] forState:UIControlStateNormal];
        [button setImage:[TBCustomIconManager fetch_icon_single_round_selectedImage] forState:UIControlStateSelected];
        [button addTarget:self action:@selector(actionShareLinkButton:) forControlEvents:UIControlEventTouchUpInside];
        [button relayoutWithType:TBButtonTypeHorizontalImageTitle margin:12];
        _shareLinkButton = button;
    }
    return _shareLinkButton;
}

- (UIButton *)shareImageButton {
    if (!_shareImageButton) {
        UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
        button.titleLabel.font = FONTO(12);
        [button setTitle:TBResourcesLocalizedString(@"mobile_comm_common_share_image", nil) forState:UIControlStateNormal];
        [button setTitleColor:COLOR_TITLE forState:UIControlStateNormal];
        [button setImage:[UIImage tb_themeImageNamed:@"icon_single_round_unselect"] forState:UIControlStateNormal];
        [button setImage:[TBCustomIconManager fetch_icon_single_round_selectedImage] forState:UIControlStateSelected];
        [button addTarget:self action:@selector(actionShareImageButton:) forControlEvents:UIControlEventTouchUpInside];
        [button relayoutWithType:TBButtonTypeHorizontalImageTitle margin:12];
        _shareImageButton = button;
    }
    return _shareImageButton;
}

- (UIButton *)cancelButton {
    if (!_cancelButton) {
        UIButton *cancelButton = [UIButton buttonWithType:UIButtonTypeCustom];
        cancelButton.titleLabel.font = FONTO(15);
        [cancelButton setTitle:TBResourcesLocalizedString(@"mobile_comm_common_cancel", nil) forState:UIControlStateNormal];
        [cancelButton setTitleColor:COLOR_TITLE forState:UIControlStateNormal];
        [cancelButton addTarget:self action:@selector(hideAction) forControlEvents:UIControlEventTouchUpInside];
        _cancelButton = cancelButton;
    }
    return _cancelButton;
}

- (TBShareToolbar *)shareToolbar {
    if (!_shareToolbar) {
        _shareToolbar = [[TBShareToolbar alloc] init];
        _shareToolbar.delegate = self;
    }
    return _shareToolbar;
}

- (UIScrollView *)imageScrollView {
    if (!_imageScrollView) {
        _imageScrollView = [[UIScrollView alloc] init];
        _imageScrollView.pagingEnabled = YES;
        _imageScrollView.showsHorizontalScrollIndicator = NO;
        _imageScrollView.delegate = self;
        [_imageScrollView addGestureRecognizer:[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(hideAction)]];
    }
    return _imageScrollView;
}

- (TBPageControl *)imagePageControl {
    if (!_imagePageControl) {
        _imagePageControl = [[TBPageControl alloc] init];
        _imagePageControl.otherIndexColor = [TBCommonAppColor colorFromDark:0x7E829C white:0xFFFFFF];
    }
    return _imagePageControl;
}

- (UIColor *)contentBgColor {
    return nil;
}

#pragma mark -
- (NSArray *)currentSharePlatformTypes {
    NSMutableArray *itemTypes = [[self defaultSharePlatformTypes] mutableCopy];
    
    if (self.specificItemTypes && [self.specificItemTypes isKindOfClass:[NSArray class]]) { // 如果已经指定了特殊平台，则只用指定的
        [itemTypes removeAllObjects];
        for (NSNumber *platform in self.specificItemTypes) {
            if ([platform isKindOfClass:[NSNumber class]] && ![itemTypes containsObject:platform]) {
                [itemTypes addObject:platform];
            }
        }
        return itemTypes;
    }
    
    if (self.currentShareContentType == TBShareContentTypeURL) {
        // 删掉ins。因为ins仅支持分享图片
        if ([itemTypes containsObject:@(TBSharePlatformTypeInstagram)]) {
            [itemTypes removeObject:@(TBSharePlatformTypeInstagram)];
        }
        // 删除微博。因为我们的分享链接过长，导致微博分享失败
        if ([itemTypes containsObject:@(TBSharePlatformTypeWeibo)]) {
            [itemTypes removeObject:@(TBSharePlatformTypeWeibo)];
        }
        // 删除小红书。因为只支持分享图片（SDK支持图片、视频）
        if ([itemTypes containsObject:@(TBSharePlatformTypeXiaoHongShu)]) {
            [itemTypes removeObject:@(TBSharePlatformTypeXiaoHongShu)];
        }
        [itemTypes addObject:@(TBSharePlatformTypeCopyLink)];
        [itemTypes addObject:@(TBSharePlatformTypeMore)];
    } else if (self.currentShareContentType == TBShareContentTypeImage) {
        [itemTypes addObject:@(TBSharePlatformTypeSaveImage)];
        [itemTypes addObject:@(TBSharePlatformTypeMore)];
//        if (TBIsTradeUP) {
//            // TradeUP不显示Instagram，“印象是调用sdk分享多张图片不成功”-by周华剑
//            if ([itemTypes containsObject:@(TBSharePlatformTypeInstagram)]) {
//                [itemTypes removeObject:@(TBSharePlatformTypeInstagram)];
//            }
//        }
    } else if (self.currentShareContentType == TBShareContentTypeFile) {
        [itemTypes removeAllObjects];
        [itemTypes addObject:@(TBSharePlatformTypeMore)];
    }
    
    // 特殊操作，可以通过参数传递进来
    if (self.additionalPlatforms && [self.additionalPlatforms isKindOfClass:[NSArray class]]) {
        for (NSNumber *platform in self.additionalPlatforms) {
            if ([platform isKindOfClass:[NSNumber class]] && ![itemTypes containsObject:platform]) {
                [itemTypes addObject:platform];
            }
        }
    }
    
    
    // 处理 老虎社区是否要隐藏
    if ([TBStockGlobalConfigManager sharedInstance].isHiddenSharesToTiger || (!self.shareInfoModel.enableCommunity && !self.alwaysShareToTigerPost)) {
        // 删老虎社区
        if ([itemTypes containsObject:@(TBSharePlatformTypeTigerPost)]) {
            [itemTypes removeObject:@(TBSharePlatformTypeTigerPost)];
        }
    }
    
    return itemTypes;
}


- (void)updateShareImageShowOrHide {
    BOOL showShareImage = (self.currentShareContentType == TBShareContentTypeImage);
    if (showShareImage) {
        self.imageScrollView.hidden = NO;
        if (_imagePageControl) {
            self.imagePageControl.hidden = NO;
        }
    } else {
        self.imageScrollView.hidden = YES;
        if (_imagePageControl) {
            self.imagePageControl.hidden = YES;
        }
    }
}

- (void)addImagesToScrollView {
    
}

#pragma mark - 二期 新增
+ (void)shareWithInfo:(TBShareInfoModel *)infoModel
  additionalPlatforms:(NSArray *)platforms
     inViewController:(UIViewController *)viewController
  linkToolbarDelegate:(id<TBShareToolbarDelegate>)linkToolbarDelegate
 imageToolbarDelegate:(id<TBShareToolbarDelegate>)imageToolbarDelegate {
    [self shareWithInfo:infoModel additionalPlatforms:platforms inViewController:viewController linkToolbarDelegate:linkToolbarDelegate imageToolbarDelegate:imageToolbarDelegate shareTypeDelegate:nil];
}

+ (void)shareWithInfo:(TBShareInfoModel *)infoModel
  additionalPlatforms:(NSArray *)platforms
     inViewController:(UIViewController *)viewController
  linkToolbarDelegate:(id<TBShareToolbarDelegate>)linkToolbarDelegate
 imageToolbarDelegate:(id<TBShareToolbarDelegate>)imageToolbarDelegate
    shareTypeDelegate:(id<TBShareTypeDelegate>)shareTypeDelegate {
    
    if (!infoModel || ![infoModel isKindOfClass:[TBShareInfoModel class]]) {
        return;
    }
    if ([TBService(TBAccountSystemComponentService) tbAccount_needUserAuthorization]) {
        return;
    }
    
    // 判断是否有可以分享的数据
    BOOL couldShareLink = TextValid(infoModel.linkUrl);
    BOOL couldShareImage = NO;
    BOOL couldShareFile = NO;
    if (infoModel.images &&
        [infoModel.images isKindOfClass:[NSArray class]] &&
        infoModel.images.count>0) {
        couldShareImage = YES;
    } else if (infoModel.imageData && [infoModel.imageData isKindOfClass:[NSData class]]) {
        couldShareImage = YES;
    } else if (infoModel.fileData) {
        couldShareFile = YES;
    }
    // 无可分享内容，视为无效分享
    if (!couldShareLink && !couldShareImage && !couldShareFile) {
        return;
    }
    
    TBSDKShareViewController *shareVC = [[TBSDKShareViewController alloc] init];
    shareVC.shareInfoModel = infoModel;
    shareVC.fromViewController = viewController;
    shareVC.additionalPlatforms = platforms;
    if (infoModel.sharePositionDic) {
        shareVC.sharePositionDic = infoModel.sharePositionDic;
    }
    if (infoModel.communityActionDic) {
        shareVC.communityActionDic = [infoModel.communityActionDic mutableCopy];
    }
    if (infoModel.shareDic) {
        shareVC.shareDic = infoModel.shareDic;
    }
    if (infoModel.images) {
        shareVC.images = infoModel.images;
    }
    shareVC.linkToolbarDelegate = linkToolbarDelegate;
    shareVC.imageToolbarDelegate = imageToolbarDelegate;
    shareVC.shareTypeDelegate = shareTypeDelegate;
    shareVC.showImage = YES;
    [shareVC show];
}


/// 分享
/// - Parameters:
///   - infoModel: 分享数据model
///   - platforms: 指定平台，注意如果传递了该参数，则分享的平台只包含该参数所传递的
///   - viewController: 分享所在VC
///   - linkToolbarDelegate: 分享链接时ToolbarDelegate
///   - imageToolbarDelegate: 分享图片时ToolbarDelegate
+ (void)shareWithInfo:(TBShareInfoModel *)infoModel
    specificItemTypes:(NSArray *)platforms
     inViewController:(UIViewController *)viewController
  linkToolbarDelegate:(id<TBShareToolbarDelegate>)linkToolbarDelegate
 imageToolbarDelegate:(id<TBShareToolbarDelegate>)imageToolbarDelegate {
    
    if (!infoModel || ![infoModel isKindOfClass:[TBShareInfoModel class]]) {
        return;
    }
    if ([TBService(TBAccountSystemComponentService) tbAccount_needUserAuthorization]) {
        return;
    }
    
    // 如果只有一个平台，直接分享
    if (platforms.count == 1) {
        // 处理短链接
        TBSharePlatformType platformType = [platforms[0] integerValue];
        [self shortenShareLinkIfNeededWith:infoModel selectedPlatformType:platformType completion:^{
            [TBShareSDK shareWithInfo:infoModel platformType:platformType inViewController:viewController completion:^(TBShareResult result, NSString *message) {
                if (result == TBShareResultError) {
                    [viewController showHint:message hide:3];
                }
            }];
        }];
        return;
    }
    
    // 判断是否有可以分享的数据
    BOOL couldShareLink = TextValid(infoModel.linkUrl);
    BOOL couldShareImage = NO;
    BOOL couldShareFile = NO;
    if (infoModel.images &&
        [infoModel.images isKindOfClass:[NSArray class]] &&
        infoModel.images.count>0) {
        couldShareImage = YES;
    } else if (infoModel.imageData && [infoModel.imageData isKindOfClass:[NSData class]]) {
        couldShareImage = YES;
    } else if (infoModel.fileData) {
        couldShareFile = YES;
    }
    // 无可分享内容，视为无效分享
    if (!couldShareLink && !couldShareImage && !couldShareFile) {
        return;
    }
    
    TBSDKShareViewController *shareVC = [[TBSDKShareViewController alloc] init];
    shareVC.shareInfoModel = infoModel;
    shareVC.fromViewController = viewController;
    shareVC.specificItemTypes = platforms;
    if (infoModel.sharePositionDic) {
        shareVC.sharePositionDic = infoModel.sharePositionDic;
    }
    if (infoModel.communityActionDic) {
        shareVC.communityActionDic = [infoModel.communityActionDic mutableCopy];
    }
    if (infoModel.shareDic) {
        shareVC.shareDic = infoModel.shareDic;
    }
    if (infoModel.images) {
        shareVC.images = infoModel.images;
    }
    shareVC.linkToolbarDelegate = linkToolbarDelegate;
    shareVC.imageToolbarDelegate = imageToolbarDelegate;
    shareVC.showImage = YES;
    [shareVC show];
}

#pragma mark - 更新分享面板
- (void)updateShareItems {
    NSArray *itemTypes = [self currentSharePlatformTypes];
    
    if (self.shareInfoModel.score) {
        self.shareToolbar.score = [NSString stringWithFormat:@"%@", self.shareInfoModel.score];
    }
    self.shareToolbar.communityRec = self.shareInfoModel.communityRec;
    if (itemTypes.count <= 4) {
        [self.shareToolbar mas_updateConstraints:^(MASConstraintMaker *make) {
            make.height.mas_equalTo(kTBShareToolbarHeight - 65 - 24);
        }];
    }
    [self.shareToolbar setupItemViewsWithTypes:itemTypes];
    
    [self.view layoutIfNeeded];
}


#pragma mark - 23 自定义配置

- (NSMutableArray *)defaultSharePlatformTypes {
    NSMutableArray *itemTypes = [[NSMutableArray alloc] init];
    
    // 预设这几个分享渠道
    [itemTypes addObject:@(TBSharePlatformTypeWechatSession)];
    [itemTypes addObject:@(TBSharePlatformTypeWechatTimeline)];
    [itemTypes addObject:@(TBSharePlatformTypeWeibo)];
    
    return itemTypes;

}
@end
