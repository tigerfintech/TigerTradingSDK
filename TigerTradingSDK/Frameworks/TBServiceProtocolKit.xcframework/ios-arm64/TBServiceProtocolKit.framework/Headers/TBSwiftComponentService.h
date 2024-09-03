//
//  TBSwiftComponentService.h
//  Pods
//
//  Created by linbingjie on 2023/1/5.
//

#ifndef TBSwiftComponentService_h
#define TBSwiftComponentService_h

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBSwiftComponentService <NSObject>

/// 判断是否是red up
- (BOOL)swiftService_isMobileRedUP;

- (void)swiftService_setSymbolFont:(BOOL)symbolFront;

- (BOOL)swiftService_isSymbolFront;

- (id)swiftService_showFloatingPanelWithParentVC:(UIViewController *)parentVC
                                         contentVC:(UIViewController *)contentVC
                                         trackView:(UIScrollView *)trackView
                                     contentHeight:(CGFloat)contentHeight;
- (id)swiftService_showFloatingPanelWithParentVC:(UIViewController *)parentVC
                                         contentVC:(UIViewController *)contentVC
                                         trackView:(UIScrollView *)trackView
                                     contentHeight:(CGFloat)contentHeight
                                         backClear:(BOOL)backClear; // 背景透明，FloatingPanel默认为black

- (void)swiftService_showWithTitle:(NSString *)title
                           message:(NSString *)message
                      confirmTitle:(NSString *)confirmTitle
                       cancelTitle:(NSString *)cancelTitle
                  selectedCallback:(void(^)(NSInteger index))selectedCallback;

- (NSUInteger)swiftService_languageSelectedIndex;

- (void)swiftService_setLanguageSelectedIndex:(NSUInteger)selectedIndex;

- (NSArray *)swiftService_allLanguages;

- (NSString *)swiftService_currentLocalizableFolderName;

- (NSUInteger)swiftService_languageCurrentType;

- (NSString *)swiftService_languageLocalizedString:(NSString *)key bundle:(NSBundle *)bundle table:(NSString *)table withComment:(NSString *)comment;

- (NSString *)swiftService_languageLocalizedString:(NSString *)key withComment:(NSString *)comment;

- (BOOL)swiftService_languageIsTraditionalChinese;

- (BOOL)swiftService_languageIsSimpleChinese;

- (BOOL)swiftService_languageIsSysSimpleChinese;

- (NSString *)swiftService_currentLangParameter;

- (void)swiftService_fetchBFFConfigs:(BOOL)updateIndex;

- (void)swiftService_fetchBFFPortfolioFunctionModuleProConfigsWithBlock:(void(^)(BOOL success, NSError *error))block;

- (void)swiftService_resetBFFPortfolioFunctionModuleProConfigs;

- (void)swiftService_showPermissionAlert;

// 是否隐藏key对应功能模块（通过bff配置）
- (BOOL)swiftService_isHiddenModuleWithKey:(NSString *)key;
// 社区功能隐藏
- (BOOL)swiftService_isCommunityHide;
// 解释入口隐藏
- (BOOL)swiftService_isExplanationEntryHide;
// 指定行情市场隐藏
- (BOOL)swiftService_isHiddenMarket:(NSString *)market;

// 是否已展示过引导（bff控制）
- (BOOL)swiftService_hasShownGuideForKey:(NSString *)key;
// 设置引导隐藏（bff控制）
- (void)swiftService_hideGuideForKey:(NSString *)key;

// 控制默认的font类型（bff控制）
- (NSString *)swiftService_fetchBFFFont;

@end

NS_ASSUME_NONNULL_END

#endif /* TBSwiftComponentService_h */
