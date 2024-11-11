//
//  TBTradeUtils.h
//  Pods
//
//  Created by swordzhou on 2021/8/4.
//

#import <Foundation/Foundation.h>
#import <TBStockKit/TBStock.h>
#import <TBAccountSystemKit/TBUserInfoManager+AccountStatus.h>
#import <TBTradeBusiness/TBTradeUtils.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *TBPositionIndicatorSettingBtnShowAreaType NS_STRING_ENUM;

/// 我的持仓/今日订单处
FOUNDATION_EXTERN TBPositionIndicatorSettingBtnShowAreaType const kTBPositionIndicatorSettingBtnShowAreaTypeCategoryView;
/// SEC sectionHeader处
FOUNDATION_EXTERN TBPositionIndicatorSettingBtnShowAreaType const kTBPositionIndicatorSettingBtnShowAreaTypeSecuritySectionHeader;
/// NOTE sectionHeader处
FOUNDATION_EXTERN TBPositionIndicatorSettingBtnShowAreaType const kTBPositionIndicatorSettingBtnShowAreaTypeNoteSectionHeader;
/// BOND sectionHeader处
FOUNDATION_EXTERN TBPositionIndicatorSettingBtnShowAreaType const kTBPositionIndicatorSettingBtnShowAreaTypeBondSectionHeader;

@interface TBTradeUtils : NSObject
+ (BOOL)isAllowAudioNotification;
+ (void)playAudio;
/// 订单震动
+ (void)impactVibrate;
+ (void)setVirtualGameDotStatus:(BOOL)virtualGameDotStatus;

// 先检查再进入下单页, 如果是期货, 先检查是否需要资金划转
+ (void)omnibusTradeWithAccountType:(TBOmnibusCurrentAccountType)accountType;

/// 是否显示期货资金划转弹窗
+ (BOOL)showTransferFundsAlert;

/// 是否显示数字货币资金划转弹窗
+ (BOOL)showTransferDigitalAlert;

// 发送交易动作通知
+ (void)postUserTradeNotificationWithSecType:(NSString *)secType market:(NSString *)market;

+ (NSString *)triangleIconName:(double)pnl;

+ (NSString *)getHKNameCN:(NSString *)nameCN right:(NSString *)right;

+ (NSString *)orderActionWithQuantity:(double)positionQuantity;

/**
 * 股票持仓页面-是否展示设置按钮
 * - 我的持仓/今日订单处
 * - SEC分组/BOND分组
 *
 * https://tigertech.feishu.cn/wiki/TZhdwhynCiGJOGkeY7DcvzKEnit?chunked=false#part-NSCCdsEunogPk3xW6W8crnionqK
 */
+ (BOOL)isPositionIndicatorSettingBtnHiddenWithType:(TBPositionIndicatorSettingBtnShowAreaType)type;


/// 组合期权最大腿数量（在stockBaseKit中定义的数量）
+ (int)optionStrategyMaxOptionLegsCount;

@end

NS_ASSUME_NONNULL_END

