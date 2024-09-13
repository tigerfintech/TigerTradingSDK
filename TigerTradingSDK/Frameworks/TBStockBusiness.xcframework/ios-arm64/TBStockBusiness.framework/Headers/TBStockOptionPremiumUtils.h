//
//  TBStockOptionPremiumUtils.h
//  AFNetworking
//
//  Created by zlc on 2024/4/1.
//

#import <Foundation/Foundation.h>
#import "TBStockDetailOptionPremiumTypeEnum.h"

NS_ASSUME_NONNULL_BEGIN

@class TBStockDetailOptionPremiumOptionItemModel, TBStockDetailOptionPremiumHubModel, TBStockDetailOptionScenarioAnalysisModel, TBStockDetailOptionPremiumItemModel;

@interface TBStockOptionPremiumUtils : NSObject

+ (NSString *)displaySymbolWithModel:(TBStockDetailOptionPremiumOptionItemModel *)model;
+ (NSString *)displayEarnWithModel:(TBStockDetailOptionPremiumOptionItemModel *)model;
+ (NSString *)displayApyWithModel:(TBStockDetailOptionPremiumOptionItemModel *)model;
+ (NSString *)displayApyHint;

// eg: AAPL 04/06/2024 170.0 PUT
+ (NSString *)displayContractWithModel:(TBStockDetailOptionPremiumOptionItemModel *)model;

/// time 时间戳
+ (NSString *)formateDateByBffWithTimeStamp:(NSNumber *)time;

+ (NSAttributedString *)displayWinRate:(NSNumber *)winRate;

/// 详情页-chart 提示文案（右侧和下方）.key: rightTopHint, rightBottomHint, bottomHint
+ (NSDictionary *)premiumDetailChartHintsWithOptionItemModel:(TBStockDetailOptionPremiumOptionItemModel *)model latestPrice:(NSNumber *)latestPrice aboveStrike:(BOOL)isAbove;

// 详情页-分析标的下面文案
+ (NSAttributedString *)premiumDetailSymbolHintWithPremium:(NSString *)premium market:(NSString *)market;

/// BargainHunting positions参数
+ (NSString *)getBargainHuntingPositions;

/**
 * option/seller/premiums id 参数
 */
+ (nullable NSNumber *)sellerPremiumsIdWithModel:(nullable TBStockDetailOptionPremiumItemModel *)dataModel type:(TBStockDetailOptionPremiumHubType)type;

/**
 * option/seller/bargain_hunting id 参数
 */
+ (nullable NSNumber *)sellerBargainHuntingIdWithModel:(nullable TBStockDetailOptionPremiumItemModel *)dataModel type:(TBStockDetailOptionPremiumBargainHuntingType)type;

/**
 * type 对应的翻译文案
 * type取值范围：（TBStockDetailOptionPremiumHubType，TBStockDetailOptionPremiumBargainHuntingType）
 */
+ (NSString *)displayTypeNameWithType:(NSString *)type;

+ (NSArray <NSString *> *)displayTypeNamesWithTypes:(NSArray<NSString *> *)types;


/**
 * 价内价外概率
 */
+ (NSString *)probabilityRateWithType:(TBStockOptionPremiumDetailChartViewType)type withinProbability:(NSNumber *)withinProbability;

/**
 * 展示用的有效期
 * eg: 26/04/2022 （使用bff下发的formatter）
 */
+ (NSString *)displayExpiryWithExpiry:(NSString *)expiry;

@end

NS_ASSUME_NONNULL_END
