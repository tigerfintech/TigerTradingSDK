//
//  TBOptionPickModel.h
//  DoraemonKit-DoraemonKit
//
//  Created by 王灵博 on 2021/11/23.
//
#import <TBBaseKit/TBBaseModel.h>
@class TBTradeAccountModel;
#import <TBAccountSystemKit/TBTradeAccountManager.h>
#import <TBBaseKit/TBBaseUtility.h>
NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, TBOptionPickListType) {
    TBOptionPickListTypeTime, ///< 时间
    TBOptionPickListTypePrice, ///< 价格
    TBOptionPickListTypeTrend, ///< 走势
    TBOptionPickListTypeStrategy, ///< 策略
    TBOptionPickListTypeStrategyBuilder, ///< 期权详情页-期权组合分析工具-策略
};
@interface TBOptionPickOptionsModel : TBBaseModel
@property(nonatomic, copy)NSString *type;
@property(nonatomic, copy)NSString *name;
@property(nonatomic, copy)NSString *bullish;
@property(nonatomic, copy)NSString *maxProfit;
@property(nonatomic, copy)NSString *maxLoss;
@property(nonatomic, copy)NSString *detail;

@property(nonatomic, copy)NSString *market;
@property(nonatomic, copy)NSString *symbol;
@property(nonatomic, strong)NSNumber *askPrice;
@property(nonatomic, strong)NSNumber *expiry;
@property(nonatomic, strong)NSNumber *latestPrice;
@property(nonatomic, strong)NSNumber *bidSize;
@property(nonatomic, strong)NSNumber *multiplier;
@property(nonatomic, strong)NSNumber *change;
@property(nonatomic, copy)NSString *strike;
@property(nonatomic, copy)NSString *right;
@property(nonatomic, strong)NSNumber *volatility;
@property(nonatomic, strong)NSNumber *bidPrice;
@property(nonatomic, strong)NSNumber *ratesBonds;
@property(nonatomic, strong)NSNumber *volume;
@property(nonatomic, strong)NSNumber *openInt;
@property(nonatomic, strong)NSNumber *dividePrice;
@property(nonatomic, strong)NSNumber *preClose;
@property(nonatomic, strong)NSNumber *lastTimestamp;
@property(nonatomic, strong)NSNumber *preOpenInt;
@property(nonatomic, strong)NSNumber *askSize;
@property(nonatomic, strong)NSNumber *CallDelta;
@property(nonatomic, strong)NSNumber *PutDelta;
@property(nonatomic, strong)NSNumber *rate;
@property(nonatomic, copy)NSString *optionDescribe;
@end
@protocol TBOptionPickOptionsModel;
@interface TBOptionPickStrategiesModel : TBBaseModel
@property(nonatomic, copy)NSString *type;
@property(nonatomic, copy)NSString *name;
@property(nonatomic, copy)NSString *bullish;
@property(nonatomic, copy)NSString *maxProfit;
@property(nonatomic, copy)NSString *maxLoss;
@property(nonatomic, copy)NSString *detail;
@property(nonatomic, strong)NSArray<TBOptionPickOptionsModel> *options;
@end
@protocol TBOptionPickStrategiesModel;
@interface TBOptionPickDataModel : TBBaseModel
@property(nonatomic, strong)NSNumber *preClose;
@property(nonatomic, strong)NSNumber *close;
@property(nonatomic, strong)NSNumber *change;
@property(nonatomic, strong)NSArray<TBOptionPickStrategiesModel> *strategies;
@end
@interface TBOptionPickModel : TBBaseModel
@property(nonatomic, strong)TBOptionPickDataModel *data;
@property(nonatomic, copy)NSString *err_msg;
@property(nonatomic, assign)BOOL is_success;
@end

@interface TBOptionPickAccountManager : NSObject
DECLARE_SHARED_INSTANCE(TBOptionPickAccountManager);
@property(nonatomic, strong)TBTradeAccountModel *currentAccount;
@property(nonatomic, strong)TBTradeAccountModel *virtualAccount;
- (void)fetchAccountList;
- (void)switchToVirtualWithBlock:(void(^)(BOOL))block;
//进入期权策略页面，会切换到模拟账户，下完单，或者退出、异常退出，恢复到原账户。此方法是返回原账户
- (void)switchToCurrentAccountWithBlock:(void(^)(BOOL))block;
@end

NS_ASSUME_NONNULL_END
