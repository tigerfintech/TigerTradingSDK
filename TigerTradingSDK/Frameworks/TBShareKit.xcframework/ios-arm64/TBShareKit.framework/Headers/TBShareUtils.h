//
//  TBShareUtils.h
//  TBShareKit
//
//  Created by chenxin on 2021/7/28.
//

#import <Foundation/Foundation.h>
#import <TBShareKit/TBShareDefines.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBShareUtils : NSObject

// 是否安装微信客户端
+ (BOOL)judgeForWeixin;

// 是否安装微博客户端
+ (BOOL)judgeForWeiBo;

// 是否安装QQ客户端
+ (BOOL)judgeForTencent;

// 分享渠道名，用于埋点
+ (NSString *)channelNameFromSharePlatformType:(TBSharePlatformType)type;

// 生成唯一的 shareID，用于埋点和分享链接，每次重新点击分享的时候，都需要重新生成
+ (NSString *)createShareID;
// 埋点事件获取 shareID（上面在分享入口生成的 shareID）
+ (NSString *)getShareID;

//生成邀请链接
+ (NSString *)getInvitationLinkWithCampaign:(nullable NSString *)campaign
                                     source:(nullable NSString *)source
                                     medium:(nullable NSString *)medium
                                    shareID:(nullable NSString *)shareID;

+ (NSString *)getShareLinkWithUrl:(nullable NSString *)urls
                         campaign:(nullable NSString *)campaign
                           source:(nullable NSString *)source
                           medium:(nullable NSString *)medium
                          shareID:(nullable NSString *)shareID;

// 生成短链, 官网接口
// https://tigertech.feishu.cn/wiki/wikcnIjggZxy0PJKQCfRnrNj4sh
//+ (void)shortlink:(void (^)(NSString *shorturl))completion;
+ (void)fetchShortlinkWithLink:(NSString *)link completion:(void (^)(NSString *shortlink))completion;

// 分享生成链接使用的host
+ (NSString *)shareLinkHost;

// 下载APP链接
+ (NSString *)downloadAppUrl;

/// 将原链接中的域名替换为可用的站内或站外域名，然后转为短链接
/// - Parameters:
///   - link: 原链接
///   - isInside: 是否转为站内域名
///   - completion: 完成block
+ (void)fetchShortlinkWithLink:(NSString *)link isInside:(BOOL)isInside completion:(void (^)(NSString *shortlink))completion;

@end

NS_ASSUME_NONNULL_END
