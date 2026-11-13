//
//  TBSDKOrderShareCardView.h
//  TBTradeBusiness
//
//  Created by dulijun on 2023/4/17.
//
#if __has_include(<TBShareKit/TBCardShareView.h>)

#import <TBShareKit/TBCardShareView.h>

@class TBTradeAPIOrderItemModel;
@class TBTradeAPIPositionItemModel;

NS_ASSUME_NONNULL_BEGIN

/*
 调用业务：订单列表分享、交易明细分享
 分享图内容：盈亏金额
*/
 
 
@interface TBSDKOrderShareCardView : TBCardShareView

@property (nonatomic, strong) TBTradeAPIOrderItemModel *orderModel;// 订单列表分享时赋值
@property (nonatomic, strong) TBTradeAPIPositionItemModel *tradePositionItem; // 交易明细分享时赋值

@end

NS_ASSUME_NONNULL_END
#endif
