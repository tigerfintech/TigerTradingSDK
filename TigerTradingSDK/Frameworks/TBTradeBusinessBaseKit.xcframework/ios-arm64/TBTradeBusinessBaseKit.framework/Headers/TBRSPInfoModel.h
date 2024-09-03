//
//  TBRSPModel.h
//  TBTradeBusiness
//
//  Created by swordzhou on 2022/11/2.
//

#import <TBBaseKit/JSONModel.h>
#import <TBTradeBusinessBaseKit/TBRSPConstants.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBRSPContractInfoModel : JSONModel

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *secType;

@end

/**
 * 定投列表&推荐热门定投使用的数据模型
 */

@interface TBRSPInfoModel : JSONModel

@property (nonatomic, strong) TBRSPContractInfoModel *contractInfo;

@property (nonatomic, strong) NSNumber *riReturn1Yr;      ///< 1年定投回报率
@property (nonatomic, strong) NSNumber *riReturn2Yr;      ///< 2年定投回报率
@property (nonatomic, strong) NSNumber *riReturn3Yr;      ///< 3年定投回报率
@property (nonatomic, strong) NSNumber *riReturn5Yr;      ///< 5年定投回报率
@property (nonatomic, strong) NSNumber *divideRate;       ///< 股息率

@property (nonatomic, strong) NSNumber *priceChg3M;       ///< 近3月股价涨跌幅
@property (nonatomic, strong) NSNumber *priceChg6M;       ///< 近6月股价涨跌幅
@property (nonatomic, strong) NSNumber *priceChg52W;      ///< 近52周股价涨跌幅

@property (nonatomic, copy) TBRiReturnYr displayField;  ///< 周期
@property (nonatomic, copy) NSArray <NSString *>*tags;  ///< 标签

- (NSNumber *)riReturnRate:(TBRiReturnYr)riReturnYrKey;
- (BOOL)caculatorEnable;

+ (NSString *)riReturnRateTitleKey:(TBRiReturnYr)riReturnYrKey;

@end

NS_ASSUME_NONNULL_END
