//
//  TBServiceManager+TBHostService.h
//  TBBaseKit
//
//  Created by 秦晓强 on 2023/1/3.
//

#import "TBServiceManager.h"
#import <TBServiceProtocolKit/TBHostService.h>

NS_ASSUME_NONNULL_BEGIN

// 执行无参数的TBHostService方法, 用于获取域名, 用这种方法获取的域名带"/"后缀
#define TBHost(delegate) \
({ \
    NSString *str = @""; \
    id<TBHostService> object = TBService(TBHostService); \
    if (object && [object conformsToProtocol:@protocol(TBHostService)]) { \
        if ([object respondsToSelector:@selector(delegate)]) { \
            str = [object delegate]; \
            if (!TextValid(str)) { \
                NSAssert(NO, @"没有获取到host内容"); \
            } \
        } \
        else { \
            NSAssert(NO, @"没有这个方法"); \
        } \
    } \
    else { \
        NSAssert(NO, @"没有实现代理"); \
    } \
    (str); \
}) \

// 执行带一个参数的TBHostService方法, 需要符合performSelector:withObject:的规则
#define TBHostWithParam(_selector, _object) \
({ \
    NSString *host = @""; \
    id<TBHostService> service = TBService(TBHostService); \
    if (service && [service conformsToProtocol:@protocol(TBHostService)]) { \
        if ([service respondsToSelector:@selector(_selector:)]) { \
            host = [service performSelector:@selector(_selector:) withObject:_object]; \
            if (!TextValid(host)) { \
                NSAssert(NO, @"没有获取到host内容"); \
            } \
        } \
        else { \
            NSAssert(NO, @"没有这个方法"); \
        } \
    } \
    else { \
        NSAssert(NO, @"没有实现代理"); \
    } \
    (host); \
}) \

// 用hostId获取域名, 无"/"后缀
#define TBHostWithId(hostId) TBHostWithParam(hostWithIdentifier, hostId)


@interface TBServiceManager (TBHostService)

+ (NSString *)TBHostWithId:(NSString *)hostId;

@end

NS_ASSUME_NONNULL_END
