//
//  TBExchangeRateManager.h
//  Stock
//
//  Created by ChenXin on 2017/8/28.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBStockKit/TBStock.h>
#import <TBBaseKit/TBBaseUtility.h>
#import <TBTradeBusiness/TBExchangeRateManager.h>
#import <TBTradeBusiness/TBOmnibusAPIModelHeader.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSString *const kCurrencyExchangeRateCacheKey;

@class TBOmnibusAPIModel;
@class TBTradeAPIOrderModel;
@class TBOmnibusExchangeRateModel;

@interface TBExchangeRateManager : NSObject

DECLARE_SHARED_INSTANCE(TBExchangeRateManager)

/**
 *  汇率, key为currency, value为美元对该币种的汇率, 即该币种1元对应多少美元
 */
@property (nonatomic, copy) NSDictionary *exchangeRateDictionary;

- (void)requestExchangeRateWithCompletion:(nullable void (^)(BOOL success))completion;

/**
 货币兑换
 
 请求方法: /portfolio/exchange_cash
 是否需要登录: 是
 HTTP请求方式: GET
 
 @param mainCurrency 主货币种类(USD/HKD)
 @param srcCurrency 源货币种类(USD/HKD)
 @param exchCurrency 兑换的货币种类(HKD/USD)
 @param exchValue 兑换金额
 @param isSource 兑换金额为源货币/目标货币, YES 兑换金额为源货币金额, NO 兑换金额为目标货币金额, 默认为NO
 @param settlementPeriods 结算周期
 */
+ (void)exchangeCash:(nullable NSNumber *)exchValue
          targetCash:(nullable NSNumber *)targetCash
        fromCurrency:(NSString *)srcCurrency
          toCurrency:(NSString *)exchCurrency
        mainCurrency:(NSString *)mainCurrency
            isSource:(nullable NSNumber *)isSource
             segType:(nullable NSString *)segType
   settlementPeriods:(nullable NSNumber *)period
             success:(nullable void (^)(NSString *successMessage))success
             failure:(nullable void (^)(NSString *failMessage, BOOL refetchTradeToken))failure;

/**
 查询所有换汇汇率
 
 请求方法: /forex/quotes
 是否需要登录: 是
 HTTP请求方式: GET
 */
+ (void)checkExchangeRateSucccess:(nullable void (^)(TBOmnibusExchangeRateModel *model))success
                          failure:(nullable void (^)(TBOmnibusAPIModel * _Nullable model, NSError * _Nullable error))failure;
 

/**
 获取换汇历史
 
 请求方法: /orders/filled
 是否需要登录: 是
 HTTP请求方式: GET
 @param successType 兑换类型
 */
+ (void)getExchangeCashOrdersListSuccessType:(TBSuccessType)successType
                                     segType:(nullable NSString *)segType
                                     success:(void (^)(TBTradeAPIOrderModel *model))success
                                     failure:(void (^)(NSString * _Nullable message, NSError * _Nullable error))failure;

/**
 把金额从一个币种换成另一个币种

 @param amount 订单金额
 @param fromCurrency 源币种
 @param toCurrency 目标币种
 @return toCurrency币种下的金额
 */
+ (NSNumber *)exchange:(NSNumber *)amount fromCurrency:(NSString *)fromCurrency toCurrency:(NSString *)toCurrency;

/**
 要换一定量的toCurrency币种, 需要多少fromCurrency币种的金额

 @param amount 交换后要得到多少金额的toCurrency币种
 @param toCurrency 目标币种
 @param fromCurrency 源币种
 @return 币种转换后的值
 */
+ (NSNumber *)exchange:(NSNumber *)amount currency:(NSString *)toCurrency fromCurrency:(NSString *)fromCurrency;

@end
NS_ASSUME_NONNULL_END
