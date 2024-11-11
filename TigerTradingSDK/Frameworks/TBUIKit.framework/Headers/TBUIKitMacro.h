//
//  TBUIKitMacro.h
//  Pods
//
//  Created by chenxin on 2021/4/8.
//

#ifndef TBUIKitMacro_h
#define TBUIKitMacro_h

#import <TBUIKit/TBUITool.h>
#import <TBTigerTradeResources/TBResourcesManager.h>

#define TB_UIKIT_BUNDLE_IMAGE(imageName) [TBResourcesManager resources_xcassetImageNamed:imageName]

#define TB_UIKIT_THEME_BUNDLE_IMAGE(imageName, hasBlack) TB_UIKIT_BUNDLE_IMAGE([TBUITool bundleThemeImageName:imageName hasBlackTheme:hasBlack])

#endif /* TBUIKitMacro_h */
