//
//  TBSDKAccountPortfolioRatioShareCardView.h
//  TBTradeBusiness
//
//  Created by dulijun on 2023/4/19.
//
#if __has_include(<TBShareKit/TBCardShareView.h>)
#import <TBShareKit/TBCardShareView.h>

/*
 调用业务：账户收益分享
 分享图内容：持仓占比
 */

@class TBTradeAssetTodayPnLShareInfoModel;

NS_ASSUME_NONNULL_BEGIN

@interface TBSDKAccountPortfolioRatioShareCardView : TBCardShareView

@property (nonatomic, strong) TBTradeAssetTodayPnLShareInfoModel *todayPnLInfoModel;

@end

NS_ASSUME_NONNULL_END

#endif
