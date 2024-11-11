//
//  TBServiceManagerProtocol.h
//  TBBaseKit
//
//  Created by linbingjie on 2021/3/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBServiceBaseProtocol <NSObject>

@optional

/// 返回YES表示当前类是一个单例
+ (BOOL)serviceSingleton;

+ (id)sharedInstance;

@end

NS_ASSUME_NONNULL_END

