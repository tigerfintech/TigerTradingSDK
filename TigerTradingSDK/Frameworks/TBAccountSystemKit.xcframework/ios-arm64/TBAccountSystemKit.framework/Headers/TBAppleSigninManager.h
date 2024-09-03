//
//  TBAppleSigninManager.h
//  Stock
//
//  Created by chenxin on 2021/4/30.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBAppleSigninManager : NSObject

/// 声明单例（苹果调用类继承NSObject时，要持有对象，否则回调不执行；若继承自UIViewController则不用持有对象，便可回调成功）
DECLARE_SHARED_INSTANCE(TBAppleSigninManager);

/// 苹果登录
- (void)signinWithApple;

@end

NS_ASSUME_NONNULL_END
