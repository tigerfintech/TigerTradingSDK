//
//  UIWindow+TBShake.m
//  TBInitializeKit
//
//  Created by linbingjie on 2022/7/26.
//

#import "UIWindow+TBShake.h"
#import <TBBaseKit/TBBaseKit.h>
#import <TBToolsKit/TBSupportUtility.h>
#import <TigerTradingSDK/TigerTradingSDKManager.h>

#if !TB_PUBLIC_EXAMPLE
#import "TBViewController+TBInternalTestActions.h"
#endif

@implementation UIWindow (TBShake)

#pragma mark - 摇动
/**
 *  摇动开始
 */
- (void)motionBegan:(UIEventSubtype)motion withEvent:(UIEvent *)event {
    [super motionBegan:motion withEvent:event];

    if (motion == UIEventSubtypeMotionShake) {
        NSLog(@"shake");
        // 写一个uialertvc
        UIAlertController *activityVC = [UIAlertController alertControllerWithTitle:@"调试工具" message:@"" preferredStyle:UIAlertControllerStyleAlert];
        
#if !TB_PUBLIC_EXAMPLE
        UIAlertAction *flexAction = [self internalFLEXDebugAction];
        if (flexAction) {
            [activityVC addAction:flexAction];
        }
#endif

        [activityVC addAction:[UIAlertAction actionWithTitle:@"一次性退出SDK页面" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            
            UIAlertController *confirmAlert = [UIAlertController alertControllerWithTitle:@"是否要进行logout操作"
                                                                                   message:@"关闭所有SDK页面并logout"
                                                                            preferredStyle:UIAlertControllerStyleAlert];
            [confirmAlert addAction:[UIAlertAction actionWithTitle:@"登出" style:UIAlertActionStyleDestructive handler:^(UIAlertAction * _Nonnull action) {
                [TigerTradingSDKManager removeAllViewController:YES];
            }]];
            [confirmAlert addAction:[UIAlertAction actionWithTitle:@"不登出" style:UIAlertActionStyleDestructive handler:^(UIAlertAction * _Nonnull action) {
                [TigerTradingSDKManager removeAllViewController:NO];
            }]];
            
            [confirmAlert addAction:[UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:nil]];

            UIViewController *topVC = [TBSupportUtility getTopVC];
            [topVC presentViewController:confirmAlert animated:YES completion:nil];
        }]];

#if !TB_PUBLIC_EXAMPLE
        [activityVC addAction:[self internalPermissionRefreshDebugAction]];
#endif

        [activityVC addAction:[UIAlertAction actionWithTitle:@"分享日志" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            [TigerTradingSDKManager shareDebugLogFileSuccess:nil failure:nil];
        }]];

        [activityVC addAction:[UIAlertAction actionWithTitle:@"关闭" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            // 复制
        }]];
        UIViewController *topVC = [TBSupportUtility getTopVC];
        [topVC presentViewController:activityVC animated:YES completion:nil];

    }
}

@end
