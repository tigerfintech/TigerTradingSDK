//
//  TBHostManager.h
//  Pods
//
//  Created by chenxin on 2021/2/8.
//

#import <Foundation/Foundation.h>
#import "TBHostFactory.h"
#import "TBBaseHost.h"

NS_ASSUME_NONNULL_BEGIN

#define TBHostKit [TBHostManager fetchHost]

@interface TBHostManager : NSObject

// 域名工厂
+ (TBBaseHost *)fetchHost;

// 根据不同App设置host
+ (void)configHostType:(TBHostType)type;

@end

NS_ASSUME_NONNULL_END
