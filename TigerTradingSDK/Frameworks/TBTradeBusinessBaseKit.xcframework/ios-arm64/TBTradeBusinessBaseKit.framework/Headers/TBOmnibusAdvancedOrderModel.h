//
//  TBOmnibusAdvancedOrderModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

/// 高级订单（组合订单）详情
@interface TBOmnibusAdvancedOrderInfoModel : JSONModel

@property (nonatomic, assign) BOOL supported;///< 是否支持
@property (nonatomic, strong) NSArray *availableOrderTypes;///< 子订单支持的订单类型

@end

/// 支持的高级订单
@interface TBOmnibusAdvancedOrderModel : JSONModel

@property (nonatomic, strong) TBOmnibusAdvancedOrderInfoModel *oca;///< 括号订单
@property (nonatomic, strong) TBOmnibusAdvancedOrderInfoModel *attached;///< 附加订单
@property (nonatomic, strong) TBOmnibusAdvancedOrderInfoModel *conditional;///< 条件订单
@property (nonatomic, strong) TBOmnibusAdvancedOrderInfoModel *attachedOca;///< 附加OCA订单
@end

NS_ASSUME_NONNULL_END
