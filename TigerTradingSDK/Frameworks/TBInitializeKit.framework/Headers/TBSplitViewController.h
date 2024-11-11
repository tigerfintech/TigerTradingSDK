//
//  TBSplitViewController.h
//  TBUIKit
//
//  Created by linbingjie on 2023/12/14.
//

#import <UIKit/UIKit.h>
#import <TBUIKit/TBBaseSplitViewController.h>
#import "TBTabBarViewController.h"
#import <TBUIKit/TBNavigationController.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBSplitViewController : TBBaseSplitViewController 
<
 UISplitViewControllerDelegate,
 UITraitEnvironment
>

@property (nonatomic, strong) TBNavigationController *masterViewController;
@property (nonatomic, strong) TBNavigationController *detailViewController;
@property (nonatomic, strong) Class placeholderViewControllerClass;



/// 重置detailvc 页面成默认状态
/// ipad + 横屏的时候会触发这个逻辑 让splitvc 的右边detailvc 重置成基础的placeholder 页面
- (void)resetDetailVC;

@end
NS_ASSUME_NONNULL_END
