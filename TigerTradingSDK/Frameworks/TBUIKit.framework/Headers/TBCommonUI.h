//
//  TBCommonUI.h
//  CommonUtilsDemo
//
//  Created by yangfan on 2019/7/30.
//  Copyright © 2019 yangfan. All rights reserved.
//

#import <TBBaseKit/TBBaseUtility.h>
#import <TBBaseKit/TBConstantUI.h>
#import <TBBaseKit/TBPhoneUtility.h>
#import <TBUIKit/TBUITool.h>
#import <TBTigerTradeResources/TBResourcesManager.h>

#ifndef TBCommonUI_h
#define TBCommonUI_h

#define TBBundleImage(imageName, bundleName)                [TBResourcesManager resources_xcassetImageNamed:imageName]
#define TBBundleThemeImage(imageName, bundleName, hasBlack) TBBundleImage([TBUITool bundleThemeImageName:imageName hasBlackTheme:hasBlack], bundleName)

#endif /* TBCommonUI_h */
