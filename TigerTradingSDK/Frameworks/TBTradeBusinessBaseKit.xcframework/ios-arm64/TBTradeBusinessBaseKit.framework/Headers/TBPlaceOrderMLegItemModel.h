//
//  TBPlaceOrderMLegItemModel.h
//  TBTradeBusiness
//
//  Created by zlc on 2023/4/13.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/JSONModel.h>
#import <TBBusinessSupportKit/TBMlegWatchListProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBPlaceOrderMLegItemModel : JSONModel<TBMlegWatchListProtocol>

// MARK: - 必要信息
@property (nonatomic, copy) NSString *market; // 市场：默认US
@property (nonatomic, copy) NSString *action; // 买卖方向，默认BUY
@property (nonatomic, copy) NSString *secType; // secType 默认OPT
@property (nonatomic, strong) NSNumber *ratio; // 默认为1

// 期权四要素
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *right;
@property (nonatomic, strong) NSNumber *expiry;
@property (nonatomic, copy) NSString *strike;

@property (nonatomic, copy, readonly) NSString *quoteTopicOptionSymbol; // 订阅行情时使用的symbol
@property (nonatomic, copy, readonly) NSString *optionCombinedSymbol; // 期权四要素组合的symbol

@property (nonatomic, copy, readonly) NSString *legCombinedSymbol;

// MARK: - 可选参数(从订单入口进入会传这个信息)
@property (nonatomic, strong, nullable) NSNumber <Optional> *multiplier;
@property (nonatomic, strong, nullable) NSNumber <Optional> *filledQuantity; // 执行数目
@property (nonatomic, copy, nullable) NSString <Optional> *currency;
@property (nonatomic, strong, nullable) NSNumber <Optional>  *avgFilledPrice;



@end


@interface TBPlaceOrderMLegItemModel (TBUtils)

/** array(model) 组装成 array(dictionary) - contracts接口使用
 *  eg: [{ "symbol": "AAPL", "expiry": "20241119", "strike": 160, "right": "CALL", "action": "BUY", "secType":"OPT" },]
 */
+ (NSArray <NSDictionary *> *)generateContractsParamsWithModels:(NSArray <TBPlaceOrderMLegItemModel *> *)models;


/** 行情AskBid接口参数
 *  eg: [{ "symbol": "AAPL", "expiry": 1678424400000, "strike": 160, "right": "CALL", "direction": "buy", "size":2 },]
 */
+ (NSArray <NSDictionary *> *)generateAskBidContractsWithModels:(NSArray <TBPlaceOrderMLegItemModel *> *)models;

/** 组装下单参数
 * 字段：contracts
 * 类型：list<ContractLeg>
 * 必须：false
 * 说明：多腿订单的合约组成，与上面的 symbol/expiry/strike/right 互斥
 */
+ (NSArray <NSDictionary *> *)generateOrderParamsWithModels:(NSArray <TBPlaceOrderMLegItemModel *> *)models;

/// 生成order预览使用的两行symbol
+ (NSArray <NSAttributedString *> *)generateOrderDisplaySymbolWithModels:(NSArray <TBPlaceOrderMLegItemModel *> *)models;

@end

NS_ASSUME_NONNULL_END
