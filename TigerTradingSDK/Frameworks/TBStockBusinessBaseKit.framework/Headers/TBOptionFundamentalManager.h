//
//  TBOptionFundamentalManager.h
//  Stock
//
//  Created by 骆朋飞 on 2017/8/7.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBServerTimeDataManager.h>
#import "TBOptionItem.h"
@class TBOptionInfoDetailItem;
@class TBStockDetailCorporationModel;

@interface TBOptionFundamentalModel : JSONModel


@property (nonatomic, copy, readonly) NSString *formateDelta;

@property (nonatomic, copy, readonly) NSString *formateTheta;


@property (nonatomic, copy, readonly) NSString *formateGamma;

@property (nonatomic, copy, readonly) NSString *formateVega;

@property (nonatomic, copy, readonly) NSString *formateRho;

/**
 衡量标的资产价格波动率变动时，期权价格的变化幅度
 */
@property (nonatomic, assign) double vega;

/**
 衡量标的资产价格变动时，期权价格的变化幅度 
 */
@property (nonatomic, assign) double delta;

/**
 量随着时间的消逝，期权价格的变化幅度
 */
@property (nonatomic, assign) double theta;

/**
 衡量标的资产价格变动时，期权Delta值的变化幅度
 */
@property (nonatomic, assign) double gamma;

/**
 衡量利率变动时，期权价格的变化幅度
 */
@property (nonatomic, assign) double rho;

/**
 隐含波动率
 */
@property (nonatomic, copy) NSString *volatilityRate;
@property (nonatomic, assign) double volatilityRateValue;
/**
 溢价率
 */
@property (nonatomic, copy) NSString *premimuRate;

/**
 买入盈利概率
 */
@property (nonatomic, copy) NSString *profitRate;

/**
 时间价值
 */
@property (nonatomic, assign) double timeValue;

/**
 杠杆率： delta*股票价格/期权价格
 */
@property (nonatomic, assign) double leverage;

/**
 内在价值： 期权价格-时间价值
 */
@property (nonatomic, assign) double intrinsicValue;

/**
 期权价格
 */
@property (nonatomic, assign) double optionPrice;

/**
 每份交割股数
 */
@property (nonatomic, assign) double deliverableShares;


/**
 卖出年化收益
 */
@property (nonatomic, assign) double estimatedARR;

/**
 杠杆卖出年化收益 = 时间价值*每份合约数/卖出期权的保证金*365/距离到期日
 */
@property (nonatomic, assign) double sellMarginValue;

@end

@interface TBOptionFundamentalManager : NSObject

/**
 期权溢价率计算

 @param right call or put
 @param optionPrice 期权价格
 @param strike 行权价格
 @param price 正股价格
 @param time 距到期时间差/365.f
 @return 期权溢价率
 */
+ (TBOptionFundamentalModel *)optionFundamentalWithRight:(NSString *)right
                                                  strike:(NSNumber *)strike
                                                  expiry:(NSNumber *)expiry
                                                  market:(NSString *)market
                                             stockPrice:(NSNumber *)stockPrice
                                         optionItemModel:(TBOptionInfoDetailItem *)optionItem
                                           dividendModel:(TBStockDetailCorporationModel *)actionModel;

+ (TBOptionFundamentalModel *)optionFundamentalWithRight:(NSString *)right
                                                  strike:(NSNumber *)strike
                                                  expiry:(NSNumber *)expiry
                                                  market:(NSString *)market
                                             stockPrice:(NSNumber *)stockPrice
                                         optionItemModel:(TBOptionInfoDetailItem *)optionItem
                                           dividendModel:(TBStockDetailCorporationModel *)actionModel
                                    isSupportMultiThread:(BOOL)isSupportMultiThread;



/// 期权预测价格计算
/// @param right 期权方向
/// @param strike 行权价
/// @param price 股票价格
/// @param time 间隔天数
/// @param bondsRate 费率
/// @param sigma 隐含波动率
+ (double)optionEsitimatePriceWithRight:(NSString *)right
                                 strike:(double)strike
                                  price:(double)price
                                   time:(NSTimeInterval)time
                              bondsRate:(double)bondsRate
                                  sigma:(double)sigma;

+ (NSTimeInterval)realExpiryTimeStampWithOptionInfoDetailItem:(TBOptionInfoDetailItem *)optionItem expiry:(NSNumber *)expiry market:(NSString *)market;

/// 1.如果在交易中取当前服务器时间
/// 2.不在交易中取上一个收盘的时间
+ (NSTimeInterval)realCalculateTimeStampWithOptionInfoDetailItem:(TBOptionInfoDetailItem *)optionItem;
@end
