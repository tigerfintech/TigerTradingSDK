//
//  TBShareViewController.h
//  Stock
//
//  Created by ChenXin on 2017/5/26.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBBaseViewController.h>
#import "TBShareInfoModel.h"
#import "TBShareSDK.h"

static NSString *const kTBShareImageIsPreparingKey                                           = @"kTBShareImageIsPreparingKey";
static NSString *const kTBNotificationShareImageDidReady                                     = @"kTBNotificationShareImageDidReady";

@class TBShareToolbar;
@class TBShareViewController;
@protocol TBShareToolbarDelegate;

// 当可以分享图片时，通过这个代理获取图片
@protocol TBShareCreateImageDelegate <NSObject>

- (void)createShareImageWithShareViewController:(TBShareViewController *)shareViewController;

@end

typedef enum : NSUInteger {
    TBShareCustomTypeLink,
    TBShareCustomTypeImage,
} TBShareCustomType;

@protocol TBShareTypeDelegate <NSObject>

- (void)shareTypeDidChange:(TBShareCustomType)type;

@end

#define kImageViewTag 100

// 当用户点击了某个平台时向外部发通知，参数type为TBSharePlatformType类型（不方便实现TBShareToolbarDelegate方法的可以监听这个通知）
extern NSString * const TBShareDidSelectPlatformTypeNotification;

@interface TBShareViewController : TBBaseViewController

// images可能存UIImage对象或者网络图片链接
@property (nonatomic, copy) NSArray *images;

@property (nonatomic, assign) BOOL alwaysShareToTigerPost; // 总是分享到老虎社区
@property (nonatomic, assign) BOOL isInSegmentedPageVC;

@property (nonatomic, copy) void (^indexChangedBlock)(NSUInteger index);

// views
@property (nonatomic, strong, readonly) UIView *backgroundView;
@property (nonatomic, strong) UIScrollView *imageScrollView; // 内容区域
@property (nonatomic, strong) UIView *shareTypeView; // 切换链接/图片
@property (nonatomic, strong) UIButton *shareLinkButton;
@property (nonatomic, strong) UIButton *shareImageButton;
@property (nonatomic, strong) UIView *bottomView; // 底部菜单
@property (nonatomic, strong) TBShareToolbar *shareToolbar;

@property (nonatomic, strong) UIButton *cancelButton;

- (instancetype)initWithInfo:(TBShareInfoModel *)infoModel inViewController:(UIViewController *)viewController;

- (instancetype)initWithInfo:(TBShareInfoModel *)infoModel
            inViewController:(UIViewController *)viewController
        imageToolbarDelegate:(id<TBShareToolbarDelegate>)imageToolbarDelegate;

- (void)shareWithType:(TBSharePlatformType)type;

- (void)updateImageScrollViewContentSize; // 需要更新图片的尺寸（写到.h中是为了，子类调用有更改图片布局，之后要调用这个方法）

- (UIColor *)contentBgColor;

- (void)showWithAnimated:(BOOL)animated;

+ (void)hide;

- (void)hideAction;

#pragma mark - 旧分享方法暂保留，新分享功能不再使用
//
//// 分享图片
+ (void)showWithImage:(UIImage *)image inViewController:(UIViewController *)viewController;
+ (void)shareImage:(UIImage *)image inViewController:(UIViewController *)viewController withoutShowingIt:(BOOL)notShow enableCommunity:(BOOL)enableCommunity;
//
// 分享图片,允许自选设置是否分享到社区
+ (void)showWithImage:(UIImage *)image inViewController:(UIViewController *)viewController enableCommunity:(BOOL)enableCommunity;
//
///// 用于communityAction埋点
+ (void)showWithImage:(UIImage *)image inViewController:(UIViewController *)viewController enableCommunity:(BOOL)enableCommunity communityActionDic:(NSDictionary *)dic shareDic:(NSDictionary *)shareDic  delegate:(id<TBShareToolbarDelegate>)delegate;
//
//// 传入多张图片，选一个分享
+ (void)showWithImages:(NSArray <UIImage *> *)images inViewController:(UIViewController *)viewController;
+ (void)showWithImages:(NSArray <UIImage *> *)images inViewController:(UIViewController *)viewController delegate:(id<TBShareToolbarDelegate>)delegate enablePostTiger:(BOOL)enablePostTiger infoModel:(TBShareInfoModel *)infoModel shareDic:(NSDictionary *)shareDic;


#pragma mark - 分享提供给外部调用的接口（新分享都用下边的方法）
/// 分享
/// - Parameters:
///   - infoModel: 分享数据model
///   - platforms: 附件的分享平台，如果传递了该参数，则分享的平台为：默认的分享平台+参数所传递的
///   - viewController: 分享所在VC
///   - linkToolbarDelegate: 分享链接时ToolbarDelegate
///   - imageToolbarDelegate: 分享图片时ToolbarDelegate
///   - shareTypeDelegate: 分享方式代理
+ (void)shareWithInfo:(TBShareInfoModel *)infoModel
  additionalPlatforms:(NSArray *)platforms
     inViewController:(UIViewController *)viewController
  linkToolbarDelegate:(id<TBShareToolbarDelegate>)linkToolbarDelegate
 imageToolbarDelegate:(id<TBShareToolbarDelegate>)imageToolbarDelegate
 shareTypeDelegate:(id<TBShareTypeDelegate>)shareTypeDelegate;

+ (void)shareWithInfo:(TBShareInfoModel *)infoModel
  additionalPlatforms:(NSArray *)platforms
     inViewController:(UIViewController *)viewController
  linkToolbarDelegate:(id<TBShareToolbarDelegate>)linkToolbarDelegate
 imageToolbarDelegate:(id<TBShareToolbarDelegate>)imageToolbarDelegate;

/// 分享 （说明：此方法目前只有在分享文件时调用了。infomodel.fileData赋值，specificItemTypes传TBSharePlatformTypeMore）
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
 imageToolbarDelegate:(id<TBShareToolbarDelegate>)imageToolbarDelegate;




@end
