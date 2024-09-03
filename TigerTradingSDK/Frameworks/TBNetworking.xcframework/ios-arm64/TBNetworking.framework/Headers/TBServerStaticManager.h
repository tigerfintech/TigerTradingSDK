//
//  TBServerStaticManager.h
//  TBNetworking
//
//  Created by zhengzhiwen on 2023/9/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBServerStaticManager : NSObject

+ (instancetype)shared;

@property (nonatomic, assign) BOOL isTargetUser;

- (void)recordTask:(NSURLSessionTask *)task metrics:(NSURLSessionTaskMetrics *)metrics;

// 记录mqtt请求信息
- (void)recordMqttRequestString:(NSString *)string;

@end

NS_ASSUME_NONNULL_END
