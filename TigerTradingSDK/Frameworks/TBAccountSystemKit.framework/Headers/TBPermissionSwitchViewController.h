//
//  TBPermissionSwitchViewController.h
//  TBAccountSystemKit
//
//  Created by chenxin on 2023/10/19.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBPermissionSwitchViewController : UIViewController

+ (void)showWithSwitchAction:(void (^ _Nullable)(void))switchAction;

@end

NS_ASSUME_NONNULL_END
