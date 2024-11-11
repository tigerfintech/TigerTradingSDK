//
//  TBHostTool.h
//  TBHostManager
//
//  Created by zhengzhiwen on 2021/9/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBHostTool : NSObject

+ (NSDictionary *)hostDict;

/*
 如果链接域名是{{businessName}}形式，返回处理后的url
 dynamicUrl 以{{businessName}}开头的动态链接
 defaultUrl 动态链接处理失败时的默认链接
 */
+ (NSString *)replacedUrlWithDynamicUrl:(NSString *)dynamicUrl defaultUrl:(NSString *)defaultUrl;

// 从服务器获取最新的服务器地址.
+ (void)updateServerConfigure;
+ (void)updateServerConfigureWithCompletion:(nullable void(^)(void))completion;

// 服务器测速
+ (void)testSpeedWithOneCompletion:(void (^)(NSInteger serverIndex, NSInteger speed))oneCompletion allCompletion:(void (^)(NSInteger recommendedIndex))allCompletion;

+ (void)setServerIndex:(NSInteger)index;

@end

NS_ASSUME_NONNULL_END
