//
//  TBOptionStrategyBuilderFundamentalModel.h
//  TBStockBusiness
//
//  Created by zlc on 2022/8/10.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionStrategyBuilderFundamentalModel : JSONModel

/**
 最大盈利
*/
@property (nonatomic, assign) double maxProfit;
/**
 最大亏损
*/
@property (nonatomic, assign) double maxLoss;
/**
 盈亏平衡点列表
*/
@property (nonatomic, copy) NSArray <NSNumber *> *breakEvens;

/**
盈亏平衡点集合（x:index, y:breakEven)
*/
@property (nonatomic, copy) NSDictionary <NSString *, NSString *> *breakEvensPoints;

/**
 结算日股价列表（x轴)
*/
@property (nonatomic, copy) NSArray <NSNumber *> *underlyingList;
/**
 指标列表 (y轴）
*/
@property (nonatomic, copy) NSArray <NSNumber *> *pnls;
/**
 曲线坐标点(x,y)集合数组
*/
@property (nonatomic, copy, readonly) NSArray <NSDictionary <NSString *, NSNumber *> *> *points;
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
 步进
 */
@property (nonatomic, assign) double step;

- (void)calculatePoints;

/// 追加点到points中
- (void)appendPointsWithModel:(TBOptionStrategyBuilderFundamentalModel *)model insertFirstOrLast:(BOOL)isLast;

// MARK: 用于调试的信息，可为nil
@property (nonatomic, assign) double stockPrice;
@property (nonatomic, copy, nullable) NSString *contractInfoString;
@property (nonatomic, copy, nullable) NSString *otherLegContractInfoString;
@property (nonatomic, copy, nullable) NSString *stockInfoString;
@property (nonatomic, copy, nullable) NSString *calculateToolInfoString;


@end

NS_ASSUME_NONNULL_END
