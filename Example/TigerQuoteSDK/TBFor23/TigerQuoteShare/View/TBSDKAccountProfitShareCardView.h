//
//  TBSDKAccountProfitShareCardView.h
//  TBTradeBusiness
//
//  Created by dulijun on 2023/4/18.
//
#if __has_include(<TBShareKit/TBCardShareView.h>)

#import <TBShareKit/TBCardShareView.h>
@class TBTradeAssetTodayPnLShareInfoModel;

NS_ASSUME_NONNULL_BEGIN

/*
 调用业务：账户收益分享
 分享图内容：今日盈亏比例、今日盈亏金额、持仓盈亏、持仓占比、证券总价值、交易笔数
 */

@interface TBSDKAccountProfitShareCardView : TBCardShareView

@property (nonatomic, strong) TBTradeAssetTodayPnLShareInfoModel *todayPnLInfoModel;

@end

NS_ASSUME_NONNULL_END
#endif
