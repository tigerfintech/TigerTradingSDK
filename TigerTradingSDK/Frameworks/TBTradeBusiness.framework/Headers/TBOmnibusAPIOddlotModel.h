//
//  TBOmnibusAPIOddlotModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>
#import <TBTradeBusinessBaseKit/TBPlaceOrderContractInfoConstants.h>
#import "TBOddlotItemCell.h"

NS_ASSUME_NONNULL_BEGIN

//碎股
@interface TBOmnibusAPIOddlotItemModel : JSONModel <TBOddlotItemCell>

@property (nonatomic, copy) NSString *symbol;                                        // 股票代码
@property (nonatomic, copy) NSString *nameCN;                                         // 股票名称
@property (nonatomic, copy) NSString *currency;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, strong) NSNumber *quantity;                                   // 仅返回碎股部分持仓
@property (nonatomic, strong) NSNumber *isApplied;                                  // 当日是否已申请碎股处理

@property (nonatomic, copy) TBOmnibusFractionShareTradeMode oddTradeMode;///< 碎股回收模式

@end

@protocol TBOmnibusAPIOddlotItemModel;

//碎股
@interface TBOmnibusAPIOddlotModel : TBOmnibusAPIModel

@property (nonatomic, copy) NSArray <TBOmnibusAPIOddlotItemModel> *data;

@end

NS_ASSUME_NONNULL_END
