//
//  TBMultiOptionStrategyBuilderFundamentalModel.h
//  TBStockBusiness
//
//  Created by wind on 2023/4/27.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBMultiOptionStrategyBuilderFundamentalModel : JSONModel

/**
 盈亏平衡点列表
*/
@property (nonatomic, copy) NSArray <NSNumber *> *breakEvens;

/**
 盈利概率
 */
@property (nonatomic, assign) double profitProbability;

/**
 衡量标的资产价格变动时，期权价格的变化幅度
 */
@property (nonatomic, assign) double delta;

/**
 衡量标的资产价格变动时，期权Delta值的变化幅度
 */
@property (nonatomic, assign) double gamma;

/**
 衡量标的资产价格波动率变动时，期权价格的变化幅度
 */
@property (nonatomic, assign) double vega;

/**
 量随着时间的消逝，期权价格的变化幅度
 */
@property (nonatomic, assign) double theta;

/**
 衡量利率变动时，期权价格的变化幅度
 */
@property (nonatomic, assign) double rho;

/**
 时间价值
 */
@property (nonatomic, assign) double timeValue;

/**
 内在价值： 期权价格-时间价值
 */
@property (nonatomic, assign) double intrinsicValue;

#pragma mark - 格式化

@property (nonatomic, copy, readonly) NSString *formateDelta;

@property (nonatomic, copy, readonly) NSString *formateGamma;

@property (nonatomic, copy, readonly) NSString *formateVega;

@property (nonatomic, copy, readonly) NSString *formateTheta;

@property (nonatomic, copy, readonly) NSString *formateRho;

@end

NS_ASSUME_NONNULL_END
