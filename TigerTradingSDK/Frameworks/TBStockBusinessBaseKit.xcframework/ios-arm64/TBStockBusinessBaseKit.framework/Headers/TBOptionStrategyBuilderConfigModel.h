//
//  TBOptionStrategyBuilderConfigModel.h
//  TBStockBusinessBaseKit
//
//  Created by zlc on 2024/4/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TBOptionInfoDetailItem;

typedef NS_ENUM(NSInteger, TBOptionStrategyBuilderConfigPriceOptions) {
    TBOptionStrategyBuilderConfigPriceOptionsMidPrice, ///< 中间价
    TBOptionStrategyBuilderConfigPriceOptionsCounterPrice, ///< 对手价
    TBOptionStrategyBuilderConfigPriceOptionsOtherPrice, ///< 其他价格
};


// MARK: - 股票
@interface TBOptionStrategyBuilderConfigStockModel: NSObject
/// 买卖方向：BUY or SELL, 默认BUY
@property (nonatomic, copy) NSString *orderAction;

- (instancetype)initWithOrderAction:(NSString *)orderAction;

@end


// MARK: - 期权
@interface TBOptionStrategyBuilderConfigOptionModel: NSObject

/// 市场，默认为US
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *right;
@property (nonatomic, strong) NSNumber *expiry;
@property (nonatomic, copy) NSString *strike;
@property (nonatomic, strong, nullable) NSNumber *bidPrice;
@property (nonatomic, strong, nullable) NSNumber *askPrice;
@property (nonatomic, strong, nullable) NSNumber *latestPrice;
/// 交易时间区间
@property (nonatomic, copy) NSArray <NSArray <NSNumber *> *> *openAndCloseTimeList;
/// 无风险利率
@property (nonatomic, strong, nullable) NSNumber *ratesBonds;
/// 股息利率
@property (nonatomic, strong, nullable) NSNumber *dividendYieldRatio;
/// 是否是指数期权
@property (nonatomic, assign) BOOL isIndexOption;

/// 买卖方向：BUY or SELL, 默认BUY
@property (nonatomic, copy) NSString *orderAction;
/// 数量/比例，默认 1
@property (nonatomic, strong, nullable) NSNumber *ratio;

/// 其他价格：外界带入(盈亏分析页使用,带入平均价)
@property (nonatomic, strong, nullable) NSNumber *extraPrice;

@property (nonatomic, strong, nullable) NSNumber *shares; // 每手股数

- (instancetype)initWithOptionItem:(TBOptionInfoDetailItem *)optionItem orderAction:(nullable NSString *)orderAction ratio:(nullable NSNumber *)ratio;

@end


// MARK: - config
/**
 * SDK文档 https://tigertech.feishu.cn/wiki/wikcnPpDZumbaiVZHIefIvsUdv0
 */
@interface TBOptionStrategyBuilderConfigModel : NSObject

/**
 * 股票价格
 */
@property (nonatomic, assign) double stockPrice;

/**
 * 价格选项（eg: 中间价、对手价、最新价）
 */
@property (nonatomic, assign) TBOptionStrategyBuilderConfigPriceOptions priceOptions;

/**
 * 选择的日期(到期日之前的日期）
 */
@property (nonatomic, strong, nullable) NSNumber *settlementDate;

/**
 * 采样点数
 */
@property (nonatomic, strong, nullable) NSNumber *underlyingListCount;

/**
 * 采样点集
 */
@property (nonatomic, copy, nullable) NSArray <NSNumber *> *underlyingListPoints;

/**
 * 步进
 */
@property (nonatomic, assign) double step;

/**
 * 设置组合与用户限价的价差(来自下单页)
 */
@property (nonatomic, strong, nullable) NSNumber *strategySpread;

/**
 * 设置组合数量(来自下单页)
 */
@property (nonatomic, strong, nullable) NSNumber *strategyQuantity;

/**
 * 期权数组（多腿）
 */
@property (nonatomic, copy) NSArray <TBOptionStrategyBuilderConfigOptionModel *> *optionModels;

/**
 * 股票: nil 时组合内没有股票；否则组合内带有股票信息
 */
@property (nonatomic, strong, nullable) TBOptionStrategyBuilderConfigStockModel *stockModel;

/**
 * 计算盈亏平衡点
 */
+ (TBOptionStrategyBuilderConfigModel *)configWithSettlementDate:(NSNumber *)settlementDate
                                                      stockPrice:(double)stockPrice
                                                      stockModel:(nullable TBOptionStrategyBuilderConfigStockModel *)stockModel
                                                    optionModels:(NSArray <TBOptionStrategyBuilderConfigOptionModel *> *)optionModels
                                                    priceOptions:(TBOptionStrategyBuilderConfigPriceOptions)priceOptions
                                             underlyingListCount:(nullable NSNumber *)underlyingListCount
                                            underlyingListPoints:(nullable NSArray <NSNumber *> *)underlyingListPoints
                                                  strategySpread:(nullable NSNumber *)strategySpread
                                                strategyQuantity:(nullable NSNumber *)strategyQuantity;

/**
 * 计算曲线1
 */

/**
 * 计算曲线2
 */

/**
 * 计算末日线
 */


@end

@interface TBOptionStrategyBuilderConfigModel (TBUtils)

- (double)getStrategyBuilderOptionPriceWithOptionModel:(TBOptionStrategyBuilderConfigOptionModel *)optionModel;

@end

NS_ASSUME_NONNULL_END
