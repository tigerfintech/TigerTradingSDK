//
//  TBModuleBaseProtocol.h
//  TBBaseKit
//
//  Created by linbingjie on 2021/3/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBModuleBaseDelegate <NSObject>

@optional
/// YES 是单例 NO 初始化一个对象
+ (BOOL)moduleSingleton;

+ (id)sharedInstance;

@end

NS_ASSUME_NONNULL_END
