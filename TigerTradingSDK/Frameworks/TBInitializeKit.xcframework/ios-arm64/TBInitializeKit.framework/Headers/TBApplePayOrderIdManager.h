//
//  TBApplePayOrderIdManager.h
//  Stock
//
//  Created by 王昌阳 on 2021/2/8.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBApplePayOrderIdManager : NSObject

@property (nonatomic, copy, readonly) NSArray *cachedIdsArray;///<  缓存中的 老虎商城订单 ID
@property (nonatomic, copy, readonly) NSDictionary *cachedIdPairsDict;///<  缓存中的 老虎商城订单 ID 和 苹果订单 ID

+ (instancetype)manager;

/// 用户点击购买时缓存老虎商城 订单 ID
/// @param orderId  订单 ID
/// @param productId  商品 ID
- (void)savePurchaseOrderId:(NSString *)orderId productId:(NSString *)productId;

/// 购买成功后，删除缓存的订单 ID 信息
/// @param orderId 订单 ID
- (void)removeCachedOrderId:(NSString *)orderId;

/// 用户苹果付款成功后，保存对应好的 老虎商城订单 ID 和 苹果服务订单 ID，建立起对应关系，用于在内购成功后，校验之前 app 被杀死后，又重新启动的时候使用
/// @param orderId 老虎商城 订单 ID
/// @param paymentNo 苹果服务订单 ID，在 苹果内购 updateTransactions 中有回调，会返回 paymentNo 和 orderId (payment.applicationUserName)
- (void)saveOrderId:(NSString *)orderId paymentNo:(NSString *)paymentNo;

/// 删除缓存中对应的 paymentNo 和 orderId 对应关系
/// @param paymentNo 苹果订单 ID
- (void)removeCacheWithPaymentNo:(NSString *)paymentNo;

/// 查询缓存中的数据，根据 paymentNo 查询 orderId
/// @param paymentNo 苹果服务订单 ID
- (NSString *)loadCacheOrderIdWithPaymentNo:(NSString *)paymentNo;

@end

NS_ASSUME_NONNULL_END
