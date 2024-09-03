//
//  TBDeviceKickedOutAlert.h
//  TBAuthBusiness
//
//  Created by dulijun on 2022/7/5.
//

#import <TBUIKit/TBBaseViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBDeviceKickedOutAlert : TBBaseViewController

+ (void)showWithMessage:(NSString *)message doneBlock:(void(^)(void))doneBlock;

// 是否已经弹框提示被踢出登录
+ (BOOL)isShowingDeviceKickedOutAlert;
@end

NS_ASSUME_NONNULL_END
