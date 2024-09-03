//
//  TigerQuoteSDKSettingManager.h
//  TigerQuoteSDK
//
//  Created by linbingjie on 2024/8/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TigerTradingSDKAppearType) {
    TigerTradingSDKAppearTypeDark,   // 黑金皮肤
    TigerTradingSDKAppearTypeLight,   // 浅色皮肤
};

/// TigerQuoteSDK 支持语言类型
typedef NS_ENUM(NSUInteger, TigerTradingLanguageType) {
    TigerTradingLanguageTypeAuto = 0,         // 自动，随系统设置
    TigerTradingLanguageTypeEnglish,          // 英文
    TigerTradingLanguageTypeZhHans,           // 中文简体
    TigerTradingLanguageTypeZhHant,           // 中文繁体
};

/// TigerQuoteSDK 涨跌颜色类型
typedef NS_ENUM(NSUInteger, TigerTradingSDKIncreaseColorType) {
    TigerTradingSDKIncreaseColorTypeGreen,   // 绿涨红跌，默认
    TigerTradingSDKIncreaseColorTypeRed,   // 红涨绿跌
};


@interface TigerTradingSDKSettingManager : NSObject

/// 获取当前设置的背景色
+ (TigerTradingSDKAppearType)currentAppColorStyle;

/// 设置SDK的背景色
+ (void)setAppColorStyle:(TigerTradingSDKAppearType)type;

/// 设置SDK语言类型
/// - Parameter language: SDK语言类型（TigerTradingLanguageType）
+ (void)setTigerQuoteLanguage:(TigerTradingLanguageType)language;


/// 设置SDK涨跌颜色类型：红涨绿跌 or 绿涨红跌；默认绿涨红跌
/// - Parameter language: SDK涨跌颜色类型（TigerTradingSDKIncreaseColorType）
+ (void)setTigerQuoteIncreaseColorType:(TigerTradingSDKIncreaseColorType)type;


@end

NS_ASSUME_NONNULL_END
