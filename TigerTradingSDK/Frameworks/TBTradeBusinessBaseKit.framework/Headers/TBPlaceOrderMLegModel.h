//
//  TBPlaceOrderMLegModel.h
//  TBTradeBusiness
//
//  Created by zlc on 2023/4/13.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/JSONModel.h>
NS_ASSUME_NONNULL_BEGIN

@class TBPlaceOrderMLegItemModel;
@class TBTradeAPIOrderItemModel;
@class TBTradeAPIPositionItemModel;
@class TBOmnibusOrderMarginItemModel;

@interface TBPlaceOrderMLegModel : JSONModel

@property (nonatomic, copy) NSString *strategyKey; // 策略类型，必传

@property (nonatomic, copy, nullable) NSString *market; // 不传默认美股
@property (nonatomic, copy, nullable) NSString *secType; // sec类型mleg，必传
@property (nonatomic, copy) NSArray <TBPlaceOrderMLegItemModel *> *legs;

@property (nonatomic, copy) NSString *strategyName; // 策略名称, 如果自身无，则使用strategyKey从本地缓存中取
/// 组合symbol
@property (nonatomic, copy, readonly) NSString *complexSymbol;


@property (nonatomic, copy, readonly, nullable) NSString *symbol; // 底层标的symbol，eg: AAPL

@property (nonatomic, strong, nullable) NSNumber *quantity; ///< 持仓数量

+ (instancetype)mlegModelWithContractModel:(TBOmnibusOrderMarginItemModel *)contractModel
                             positionModel:(TBTradeAPIPositionItemModel *)positionModel;

/// 从orderModel创建MLegModel
+ (instancetype)mlegModelWithOrderModel:(TBTradeAPIOrderItemModel *)orderModel;

@end


NS_ASSUME_NONNULL_END
