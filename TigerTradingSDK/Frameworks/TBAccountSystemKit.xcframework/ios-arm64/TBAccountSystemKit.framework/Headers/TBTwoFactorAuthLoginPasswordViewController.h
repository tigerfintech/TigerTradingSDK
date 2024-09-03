//
//  TBTwoFactorAuthLoginPasswordViewController.h
//  Stock
//
//  Created by chenxin on 2021/12/3.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBBaseViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBTwoFactorAuthLoginPasswordViewController : TBBaseViewController

@property (nonatomic, assign) BOOL verifyForOpen; // 区分为了开启还是关闭验证
@property (nonatomic, copy) NSString *linkCode; // 关闭两步验证时需要该字段（来源：h5签署协议页，会通过bridge回传linkCode，用于关闭接口）

@end

NS_ASSUME_NONNULL_END
