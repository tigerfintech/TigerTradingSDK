//
//  TBOptionItem.h
//  Stock
//
//  Created by liwt on 9/14/15.
//  Copyright (c) 2015 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBObject.h>
@class TBOptionHourTradingModel;
@class TBOptionExpiryItemModel;
@class TBStockDetailCorporationModel;
@class TBOptionChainExpireModel;
@class TBOptionIndiceQuoteModel;
@class TBOptionStrategyBuilderStrategyModel;
@class TBOptionChainDetailItemViewModel;

#import <TBBusinessSupportKit/TBStockDetailBaseModel.h>

static NSString *TBOptionTypeCall = @"call";
static NSString *TBOptionTypePut = @"put";
static NSString *TBOptionTypeAll = @"all";

@protocol TBOptionStrategyBuilderStrategyModel <NSObject>
@end


@interface TBOptionHourTradingModel : JSONModel
@property (nonatomic, assign) double preClose;
@property (nonatomic, copy) NSString *tag;
@property (nonatomic, assign) double latestPrice;
@end

@protocol TBOptionIndiceQuoteModel <NSObject>
@end
@interface TBOptionIndiceQuoteModel : TBStockDetailBaseModel
@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong)TBOptionHourTradingModel *hourTrading;
@end

@protocol TBOptionExpiryItemModel <NSObject>
@end
@interface TBOptionExpiryItemModel : JSONModel

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, strong) NSNumber *isMonth;
@property (nonatomic, strong) NSNumber *expiry;
@property (nonatomic, copy) NSString *periodTag;

// 附加属性
@property (nonatomic, copy) NSString *text;

@end


@protocol TBOptionChainItemModel;
@interface TBOptionChainItemModel : JSONModel

@property (nonatomic, strong) NSNumber *askPrice;
@property (nonatomic, strong) NSNumber *askSize;
@property (nonatomic, strong) NSNumber *bidPrice;
@property (nonatomic, strong) NSNumber *bidSize;
@property (nonatomic, strong) NSNumber *multiplier;
@property (nonatomic, strong) NSNumber *change;
@property (nonatomic, copy) NSString *strike;
@property (nonatomic, copy) NSString *right;
@property (nonatomic, strong) NSNumber *volatility;  //!< 历史波动率
@property (nonatomic, strong) NSNumber *ratesBonds;
@property (nonatomic, strong) NSNumber *volume;
@property (nonatomic, strong) NSNumber *openInt;
@property (nonatomic, strong) NSNumber *dividePrice;
@property (nonatomic, strong) NSNumber *lastTimestamp;
@property (nonatomic, strong) NSNumber *preOpenInt;  //!< 昨日未平仓数
@property (nonatomic, strong) NSNumber *latestPrice;
@property (nonatomic, strong) NSNumber *preClose;

#pragma mark -
@property (nonatomic, assign) BOOL isSupportMultiThread;//支持SDK多线程计算
@property (nonatomic, copy, readonly) NSArray *dataSourceArray; //!< 0 名称，1颜色
@property (nonatomic, copy, readonly) NSArray *landscapeDataSourceArray; //!< 0 名称，1颜色

@property (nonatomic, assign) BOOL isIndexOption;

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *oldOptionSymbol;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *optionSymbol;
@property (nonatomic, strong) TBOptionExpiryItemModel *expiry;
//
//@property (nonatomic, strong) NSNumber *rate;

@property (nonatomic, assign) BOOL isOld;//是否旧期权

@property (nonatomic, strong) NSNumber *stockStrikePrice;  //!< 股票价格
@property (nonatomic, strong) NSNumber *stockPrice;        //!< 期权行权价格

@property (nonatomic, assign) double volatilityRateValue;//隐含波动率

@property (nonatomic, strong) NSNumber *dividendYieldRatio;//股息率

@property (nonatomic, strong) TBStockDetailCorporationModel *actionModel;  //!< 公司行动
@property (nonatomic, copy) NSArray *openAndCloseTimeList;
@property (nonatomic, strong) NSNumber *latestTimestamp;

/// 期权组合key，将期权四要素以下划线进行拼接
@property (nonatomic, copy, readonly) NSString *optionCombineKey;

- (TBOptionChainItemModel *)applySymbol:(NSString *)symbol expiry:(TBOptionExpiryItemModel *)expiry;
- (TBOptionChainItemModel *)updateValueByOtherItem:(TBOptionChainItemModel *)other;

@end

@interface TBOptionModel : JSONModel

@property (nonatomic, assign) NSInteger ret;
@property (nonatomic, assign) NSInteger serverTime;

@end

@interface TBOptionChainExpireModel : TBOptionModel

@property (nonatomic, copy) NSArray<NSArray<TBOptionChainItemModel> *> *data;

@property (nonatomic, strong) TBOptionExpiryItemModel *expiry;

#pragma mark -
// 获取指定过期日的期权链时返回
@property (nonatomic, strong) NSNumber *chainIV;//期权链波动率

#pragma mark - 分析数据(includeAnalysisData为true返回)

@property (nonatomic, strong) NSNumber *percentile; // 30日IV分位值
@property (nonatomic, strong) NSNumber *callPutRatio; // Call/Put Ratio
@property (nonatomic, strong) NSNumber *ivHisVRatio; // 30日IV / 历史波动率
@property (nonatomic, strong) NSNumber *impliedVol30Days; // 30日IV

#pragma mark - 策略信息(includeStrategy为true返回)

@property (nonatomic, strong) NSNumber *defaultStrikeWidth;
@property (nonatomic, copy) NSArray<NSNumber *> *strikeWidth;

#pragma mark -

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *optionSymbol;

@property (nonatomic, strong) TBStockDetailCorporationModel *actionModel;  //!< 公司行动

@property (nonatomic, strong) NSNumber *stockStrikePrice;  //!< 期权行权价格
@property (nonatomic, strong) NSNumber *stockPrice;        //!< 股票价格

@property (nonatomic, copy) NSArray *openAndCloseTimeList;
@property (nonatomic, strong) NSNumber *latestTimestamp;

//计算T型的列表指标
//setter方法
//tableCellIndexPath:doubleView.tableView的cell的NSIndexPath.row
//isLeft：T型的左边还是右边
//isSupportMultiThread：是否支持多线程
- (NSMutableArray *)calculateDoubleDataAtTableCellRow:(NSInteger)tableCellRow
                                   isLeft:(BOOL)isLeft
                     isSupportMultiThread:(BOOL)isSupportMultiThread;

- (void)setDataWithNSArray:(NSArray *)array;
- (NSString *)optionViewCellForStrikeItemAtIndexRow:(NSIndexPath *)indexRow;

- (BOOL)optionViewCellForDisplayOptionAtIndexRow:(NSIndexPath *)indexRow;

- (NSString *)optionViewCellForOldSymbolItemAtIndexRow:(NSIndexPath *)indexRow;
- (NSIndexPath *)findIndexPathWithDic:(NSDictionary *)dict;

@end

@interface TBOptionChainModel : TBOptionModel

@property (nonatomic, assign) BOOL isIndexOption;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, strong) NSNumber *latestTimestamp;

@property (nonatomic, copy) NSArray<TBOptionExpiryItemModel> *expires;

/// data+expiry
@property (nonatomic, strong) TBOptionChainExpireModel *defaultModel;

@property (nonatomic, copy) NSArray<NSArray<NSNumber *> *> *openAndCloseTimeList;

#pragma mark - 分析数据(includeAnalysisData为true返回)

@property (nonatomic, strong) NSNumber *percentile;// 30日IV分位值
@property (nonatomic, strong) NSNumber *callPutRatio;// Call/Put Ratio
@property (nonatomic, strong) NSNumber *ivHisVRatio;// 30日IV / 历史波动率
@property (nonatomic, strong) NSNumber *impliedVol30Days;// 30日IV
@property (nonatomic, strong) NSNumber *chainIV;//期权链波动率
@property (nonatomic, copy) NSDictionary *chainIVs;

#pragma mark - 策略信息(includeStrategy为true返回)

@property (nonatomic, strong) NSNumber *defaultStrikeWidth;
@property (nonatomic, copy) NSArray<NSNumber *> *strikeWidth;
// 字典内 width + periodTag
@property (nonatomic, copy) NSArray<NSDictionary *> *expiryWidth;
@property (nonatomic, copy) NSArray<TBOptionStrategyBuilderStrategyModel> *strategies;

#pragma mark -

/// self.expires到item.expiry的map
@property (nonatomic, copy) NSArray<NSNumber *> *expireNums;

@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) TBOptionIndiceQuoteModel *indiceQuote;

@end


@interface TBOptionIVModel : JSONModel

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *numberStr;
@property (nonatomic, strong) NSAttributedString *textAttribute;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) BOOL isShowExplain;

@end
