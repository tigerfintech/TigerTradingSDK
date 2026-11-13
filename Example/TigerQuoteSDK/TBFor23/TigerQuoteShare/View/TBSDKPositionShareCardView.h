//
//  TBSDKPositionShareCardView.h
//  TBTradeBusiness
//
//  Created by dulijun on 2023/4/12.
//
#if __has_include(<TBShareKit/TBCardShareView.h>)

#import <TBShareKit/TBCardShareView.h>

@class TBTradeAPIPositionItemModel;
@class TBTradeAssetTodayPnLShareInfoModel;

NS_ASSUME_NONNULL_BEGIN

/*
 调用业务：持仓分享、持仓订单分享、钱袋子持仓分享，
 分享图内容：盈亏比例、盈亏金额
*/
 
 
@interface TBSDKPositionShareCardView : TBCardShareView

@property (nonatomic, assign) BOOL usePositionPnl; // yes：使用持仓盈亏；NO：使用未实现盈亏

@property (nonatomic, strong) TBTradeAPIPositionItemModel *tradePositionItem; // 持仓盈亏金额、持仓盈亏率使用该model

@property (nonatomic, strong) TBTradeAssetTodayPnLShareInfoModel *todayPnLInfoModel;///< 只有老虎钱袋子持仓分享用他

@end

NS_ASSUME_NONNULL_END
#endif
