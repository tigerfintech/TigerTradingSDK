//
//  TBTwoFactorAuthLinkViewController.h
//  Stock
//
//  Created by chenxin on 2021/12/7.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBBaseViewController.h>
#import "TBTwoFactorAuthKey.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBTwoFactorAuthLinkViewController : TBBaseViewController

@property (nonatomic, strong) TBTwoFactorAuthKey * key;

@end

NS_ASSUME_NONNULL_END
