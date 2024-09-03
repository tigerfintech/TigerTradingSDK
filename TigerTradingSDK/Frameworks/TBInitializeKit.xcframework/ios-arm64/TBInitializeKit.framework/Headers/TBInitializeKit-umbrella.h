#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "AppDelegate+TBApplePay.h"
#import "AppDelegate+TBBootingProtection.h"
#import "AppDelegate+TBDebugTool.h"
#import "AppDelegate+TBNetworking.h"
#import "AppDelegate+URLMap.h"
#import "AppDelegate.h"
#import "UIWindow+TBShake.h"
#import "TBApplePayActionManager.h"
#import "TBApplePayOrderIdManager.h"
#import "TBCommonToolsHelper+MQTTHelper.h"
#import "TBCommonToolsHelper.h"
#import "TBInitializeComponentServiceImplementation.h"
#import "TBLaunchConfigTestSwitchViewController.h"
#import "TBLaunchLoadConfigManager.h"
#import "TBShellLifeCycleModule.h"
#import "TBSplitPlacrHolderViewController.h"
#import "TBSplitViewController.h"
#import "TBTabBarViewController+Animation.h"
#import "TBTabBarViewController.h"
#import "TBTabItemCreator.h"
#import "TBTabItems.h"
#import "TBThirdPartyHandler.h"
#import "TBUploadComponentServiceImplementation.h"

FOUNDATION_EXPORT double TBInitializeKitVersionNumber;
FOUNDATION_EXPORT const unsigned char TBInitializeKitVersionString[];

