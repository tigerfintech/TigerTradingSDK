//
//  TBIBAPIOrderModifyParamsInfoModel.h
//  Stock
//
//  Created by 王昌阳 on 2020/8/27.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBIBAPIOrderModifyParamsInfoModel : JSONModel

@property (nonatomic, strong) NSNumber *totalQuantity; ///< 下单数量 double
@property (nonatomic, copy) NSString *orderType;///< 订单类型
@property (nonatomic, copy) NSString *timeInForce;///< 有效期 DAY/GTC
@property (nonatomic, strong) NSNumber *limitPrice;///< 限价 double
@property (nonatomic, strong) NSNumber *auxPrice;///< 止损价 double
@property (nonatomic, strong) NSNumber *trailingPercent;///< 跟踪止损单 百分比 double
@property (nonatomic, strong) NSNumber *trailStopPrice;///< 订单价格要素，目前用不到
@property (nonatomic, strong) NSNumber *percentOffset;///< 以货币数量下单，目前还不支持

@end

NS_ASSUME_NONNULL_END
