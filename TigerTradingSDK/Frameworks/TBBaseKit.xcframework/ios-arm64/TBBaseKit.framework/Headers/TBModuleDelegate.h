//
//  TBModuleProtocol.h
//  TBBaseKit
//
//  Created by linbingjie on 2021/3/1.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TBCustomModuleDelegate.h"
#import "TBModuleBaseDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TBModuleDelegate <NSObject, UIApplicationDelegate, TBCustomModuleDelegate, TBModuleBaseDelegate>

@optional
/**
 模块加载方法
 @params params {
    "key1":"value1",
    "key2":"value2"
 }
 @return 模块是否加载成功
 */
- (BOOL)loadModuleWithParams:(NSDictionary *)params;


@end

NS_ASSUME_NONNULL_END
