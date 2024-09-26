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

#import "UIWindow+TBShake.h"
#import "TBSDKAppDelegate+TBApplePay.h"
#import "TBSDKAppDelegate+TBBootingProtection.h"
#import "TBSDKAppDelegate+TBDebugTool.h"
#import "TBSDKAppDelegate+TBNetworking.h"
#import "TBSDKAppDelegate+URLMap.h"
#import "TBSDKAppDelegate.h"
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

