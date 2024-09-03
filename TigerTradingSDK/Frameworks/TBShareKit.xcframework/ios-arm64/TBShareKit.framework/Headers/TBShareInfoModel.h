//
//  TBShareInfoModel.h
//  Stock
//
//  Created by ChenXin on 2017/5/26.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBShareDefines.h"

typedef void (^TBShareImageToCommunityBlock)(UIImage *image, NSDictionary *userInfo);

@interface TBShareSaUtmInfoModel : NSObject

@property (nonatomic, copy) NSString      *utm_campaign; // 当分享邀请活动时为adcode、分享帖子为帖子id等等
@property (nonatomic, copy) NSString      *utm_source; // 表示用户在什么页面分享的

@end

@interface TBShareInfoModel : NSObject

@property (nonatomic, copy) NSString      *title; //标题
@property (nonatomic, copy) NSString      *desc;  //文本内容
@property (nonatomic, copy) NSString      *linkUrl; //链接
@property (nonatomic, copy) NSData        *thumbData; // 缩略图
@property (nonatomic, copy) NSData        *imageDataWithNoQR; ///< 分享图片不带二维码
@property (nonatomic, copy) NSData        *fileData; // 分享文件，文件数据
@property (nonatomic, copy) NSString        *miniPath; // 小程序路径
@property (nonatomic, copy) NSData        *miniImageData; // 小程序图片数据
@property (nonatomic, copy) NSString      *shortlinkUrl; //短链接（通过tiger接口，从linkUrl转换过来）

@property (nonatomic, copy) NSString      *originUrl; // 源url，用于浏览器打开
@property (nonatomic, copy) NSString      *shareLinkUrl; // 真正分享的url
@property (nonatomic, copy) NSString      *imageShareTitle;  // 分享图片时文本内容（可选，且目前只有twitter使用）
@property (nonatomic, copy) NSString      *imageShareLink;  //分享图片时链接（可选，且目前只有twitter使用）

@property (nonatomic, copy) NSString      *qrImageShareId;  //分享图片时已经生成过的shareid

// 可以通过这两个参数携带待分享的图片
@property (nonatomic, copy) NSData        *imageData; // 分享图片
@property (nonatomic, copy) NSArray *images; // 分享图片(类型可以是：uiimage，nsstring)

@property (nonatomic, assign) BOOL enableCommunity; // 是否允许分享到社区
@property (nonatomic, copy) NSString      *webShareCommunityImg;// h5分享链接到社区时使用的特殊图片

// 在社区发帖或回复时分享持仓或订单，直接回传分享图片
@property (nonatomic, strong) TBShareImageToCommunityBlock shareImageToCommunityBlock;

@property (nonatomic, copy) NSString *type; // 用于统计分享类型
@property (nonatomic, assign) BOOL hasQRCode; // 是否是底部带logo、文案、二维码，会在最后分享的时候添加一些参数比如uuid重新生成二维码，进行替换

@property (nonatomic, assign) BOOL communityRec; // 社区按钮是否显示推荐标识
@property (nonatomic, copy) NSDictionary *communityQuery; ///< 跳转社区发帖个股信息参数

@property (nonatomic, strong) NSNumber *score; // 积分商城分享任务积分（比如分享个股、持仓）
@property (nonatomic, copy) NSString      *actionID;

@property (nonatomic, assign) TBShareContentType selectedShareContentType;// 分享内容类型（链接、图片）
@property (nonatomic, assign) TBShareContentType defaultSelectedContentType;// 默认选中的分享内容类型（链接、图片）

// UI个性化
@property (nonatomic, assign) BOOL shouldHideImageInShareViewController; // 调起分享面板时是否要隐藏图片（场景：账户收益、持仓分享图片时有编辑页，由它调起的分享需要隐藏图片）
@property (nonatomic, strong) UIColor *backgroundViewColor; // 北京蒙层颜色

#pragma mark - 埋点（可选）
@property (nonatomic, copy) NSDictionary *shareDic; //分享埋点信息， 需要包含 uuid 和 type
@property (nonatomic, copy) NSDictionary *communityActionDic; ///< communityAction埋点需要
@property (nonatomic, copy) NSDictionary *sharePositionDic;// 分享场景埋点相关
@property (nonatomic, strong) TBShareSaUtmInfoModel *utmInfo;// utm追踪参数，用于拼接在分享链接中

@property (nonatomic, assign) BOOL shouldUnlockOneNewEmojiAfterShare; // 分享成功后是否需要解锁一个新的表情（目前需要的：订单分享/持仓分享/账户分享/定投分享）

@end
