//
//  TBStockDetailShortMarginModel.h
//  Stock
//
//  Created by luopengfei on 2018/4/18.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

/// 合约PI标签
static NSString * _Nullable kHKPIRestrictedContract = @"PI_RESTRICTED_CONTRACT";


NS_ASSUME_NONNULL_BEGIN

@class TBMinTickModel;
@class TBOmnibusContractBondInfo;

@interface TBStockDetailShortMarginModel : JSONModel

@property (nonatomic, strong) NSNumber *ret;

@property (nonatomic, copy) NSString  <Optional>* secType; 

@property (nonatomic, copy) NSString *majorDescription;         // 合约名称（如：美国短期国债）
@property (nonatomic, copy) NSString *extraDescription;         // 合约扩展名称（如：债券票面利率+到期日）

@property (nonatomic, strong) NSNumber *longInitialMargin; // 初始保证金
@property (nonatomic, strong) NSNumber *longMaintenanceMargin; // 做多维持保证金
@property (nonatomic, strong) NSNumber *shortMargin; // 做空保证金
@property (nonatomic, strong) NSNumber *feeRate; // 做空费率2  Fed funds rate minus the interest rate charged on borrowed shares.表示 0.25%
@property (nonatomic, strong) NSNumber *rebateRate; // 做空费率1  Interest rate charted on borrowed shares.表示 0.66%

@property (nonatomic, strong) NSNumber *shortable; // //可做空数目，1.0E7表示>= 1.0E7
@property (nonatomic, strong) NSNumber *quantityUnit; // 最小数量单位
@property (nonatomic, strong) NSNumber *minTick; // 最小报价单位
@property (nonatomic, strong) NSNumber *multiplier;             // 乘数

@property (nonatomic, copy) NSString *msg;

@property (nonatomic, strong) NSNumber *serverTime;

#pragma mark-  ----OMNIBUS
@property (nonatomic, assign) BOOL tradeable; // 是否可交易
@property (nonatomic, assign) BOOL marginable; // 是否可融资
@property (nonatomic, assign) BOOL closeOnly; // 是否无法开仓
@property (nonatomic, assign) BOOL supportFractionalShare; // 是否支持碎股交易
@property (nonatomic, assign) BOOL monetaryOrderSupported; // 是否支持按金额下单交易
@property (nonatomic, assign) BOOL supportRegularSavings; // 是否支持定投交易

@property (nonatomic, assign) BOOL canUsOvernightTrading;
@property (nonatomic, assign) BOOL canContraTrading;
@property (nonatomic, assign) BOOL contraTradeable;

@property (nonatomic, assign) BOOL hiddenShortable; //隐藏卖空池余额

@property (nonatomic, strong, nullable) NSNumber *lotSize;    // 一手股数
@property (nonatomic, strong, nullable) NSNumber <Optional>*lotSizeScale; // 补全字段，用于数字货币

@property (nonatomic, strong) NSNumber *halt;
@property (nonatomic, readonly) NSString *promptString;
@property (nonatomic, readonly) NSString *promptTitle;

@property (nonatomic, strong, nullable) NSNumber <Optional> *canShort;             // 能否做空boolean
@property (nonatomic, strong, nullable) NSNumber <Optional> *shortableCount;       // 做空池大小
@property (nonatomic, strong, nullable) NSNumber <Optional> *shortFeeRate;         // 做空利率, 单位%. 假如此值为2.3, 意味年化做空利率为2.3%
@property (nonatomic, strong, nullable) NSNumber <Optional> *shortInitialMargin;   // 做空初始保证金比例
@property (nonatomic, strong, nullable) NSNumber <Optional> *shortMaintenanceMargin; // 做空维持保证金比例
@property (nonatomic, copy, nullable) NSArray <Optional> *availableOrderTypes;    // 定单类型,可能的值有 MKT(市价单), LMT(限价单), STP(止损单), STP_LMT(止损限价单)

// 期货

/**
 日内优惠开始时间
 */
@property (nonatomic, copy) NSString <Optional>*discountedStartAt;

/**
 日内优惠结束时间
 */
@property (nonatomic, copy) NSString <Optional>*discountedEndAt;

/**
 日内优惠初始保证金比例
 */
@property (nonatomic, strong) NSNumber <Optional>*discountedDayInitialMargin;

/**
 日内优惠维持保证金比例
 */
@property (nonatomic, strong) NSNumber <Optional>*discountedDayMaintenanceMargin;

/**
 时区
 */
@property (nonatomic, copy) NSString <Optional>*discountedTimeZoneCode;

/**
 时区名称
 */
@property (nonatomic, copy) NSString <Optional>*discountedTimeZoneName;

@property (nonatomic, assign) BOOL greyMarketSupported;///< 是否支持暗盘交易

@property (nonatomic, copy, nullable) NSArray  <TBMinTickModel *> *tickSizes;           // minTicks字段表示不同价格区间的最小报价单位
@property (nonatomic, copy, nullable) NSArray  <TBMinTickModel *> *minTicks;           // minTicks字段表示不同价格区间的最小报价单位

/**交易币种, 如USD\HKD
 * 说明：数字货币行情detail接口不会返回交易相关数据，所以需要通过contracts接口中的数据，这里引入currency字段
 */
@property (nonatomic, copy) NSString <Optional>*currency;

@property (nonatomic, strong) TBOmnibusContractBondInfo *bondResp;                      /// 910新增，存放债券合约的独有字段

/// 915 合约属性枚举（当前数字货币使用）
@property (nonatomic, copy) NSArray <NSString *> *attrs;
@end

NS_ASSUME_NONNULL_END
