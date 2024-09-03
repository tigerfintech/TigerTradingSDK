//
//  TBShareDefines.h
//  Pods
//
//  Created by chenxin on 2021/7/28.
//

#ifndef TBShareDefines_h
#define TBShareDefines_h

// 分享内容类型
typedef NS_ENUM(NSUInteger, TBShareContentType) {
    TBShareContentTypeNone,     
    TBShareContentTypeURL,     // 分享链接
    TBShareContentTypeImage,    // 分享图片
    TBShareContentTypeFile    // 分享文件
};

// 分享平台
typedef NS_ENUM(NSUInteger, TBSharePlatformType) {
    TBSharePlatformTypeNone,
    TBSharePlatformTypeTigerPost,               // 老虎社区
    TBSharePlatformTypeWechatSession,           // 微信好友
    TBSharePlatformTypeWechatTimeline,          // 微信朋友圈
    TBSharePlatformTypeQQ,                      // QQ
    TBSharePlatformTypeWeibo,                   // 微博
    TBSharePlatformTypeInstagram,               // Instagram
    TBSharePlatformTypeTwitter,                 // Twitter
    TBSharePlatformTypeFacebook,                // Facebook
    TBSharePlatformTypeWhatsApp,                // WhatsApp
    TBSharePlatformTypeTelegram,                // Telegram
    TBSharePlatformTypeMessenger,               // Messenger
    TBSharePlatformTypeLine,                    // Line
    TBSharePlatformTypeMore = 100,
    TBSharePlatformTypeSaveImage,               // 保存图片
    TBSharePlatformTypeCopyLink,                // 复制链接
    TBSharePlatformTypeCopyContent,             // 复制文字
    TBSharePlatformTypeOpenSafari,              // 浏览器打开
    TBSharePlatformTypeGeneratePicture,         // 帖子生成图片
    TBSharePlatformTypeGenerateCard,            // 个人主页生成名片
    TBSharePlatformTypeComplain,                // 举报
    TBSharePlatformTypeReEdit,                  // 重新编辑 供企业号问答使用
    TBSharePlatformTypeAnonymous,               // 匿名 供企业号问答使用
    TBSharePlatformTypeDeleteAsk,               // 删除 供企业号问答使用
    
};

// 分享结果
typedef NS_ENUM(NSUInteger, TBShareResult) {
    TBShareResultDone,          // 完成
    TBShareResultCancelled,     // 取消
    TBShareResultError,         // 出错
};

// 分享完成回调
typedef void (^TBShareCompletion)(TBShareResult result, NSString *message);

/*
 分享返回通知
 userInfo内容：
    @"type" : @"wechat", // 分享类型字符串，
    @"platformType" : @(TBSharePlatformTypeWechatSession), // 分享平台，TBSharePlatformType类型
    @"result" : @(TBShareResultDone) // 分享结果，TBShareResult类型
 */
static NSString * const NOTIFICATION_KEY_SEND_MESSAGE_BACK_FROM_SHARE                                  = @"sendMessageBackFromShare";

static NSString * const kTB_NOTIFICATION_SHARE_BOARD_WILL_DISMISS                                  = @"kTB_NOTIFICATION_SHARE_BOARD_WILL_DISMISS";

// 微博回调地址
#define SINA_REDIRECT_URL   @"http://www.tigerbrokers.com"

#endif /* TBShareDefines_h */
