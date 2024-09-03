//
//  TBOrderBaseUtils.h
//  TBTradeBusinessBaseKit
//
//  Created by wind on 2023/8/22.
//

#import <Foundation/Foundation.h>

@class TBTradeAPIOrderItemModel;

NS_ASSUME_NONNULL_BEGIN

@interface TBOrderBaseUtils : NSObject

/// 两个订单是否是关联订单
+ (BOOL)isAttachOrder:(TBTradeAPIOrderItemModel *)orderModel otherOrderModel:(TBTradeAPIOrderItemModel *)otherOrderModel;

/**
 * 根据tradingSessionType 和 outsideRth 返回成交时间段文案
 */
+ (NSString *)tradingSessionTypeString:(NSString *)market
                     tradingSessionType:(NSString *)tradingSessionType
                             outsideRth:(BOOL)outsideRth;


+ (NSString *)tradingSessionTypeTitle:(NSString *)market;

@end

NS_ASSUME_NONNULL_END
