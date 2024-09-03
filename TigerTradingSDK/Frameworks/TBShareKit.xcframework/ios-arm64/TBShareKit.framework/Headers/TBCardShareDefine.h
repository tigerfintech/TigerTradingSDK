//
//  TBCardShareDefine.h
//  TBShareKit
//
//  Created by dulijun on 2023/4/13.
//

#ifndef TBCardShareDefine_h
#define TBCardShareDefine_h

typedef NS_ENUM(NSUInteger, TBCardShareType) {
    TBCardShareTypeNone,
    TBCardShareTypePortfolioUnrealizedProfitLossRatio, ///< 持仓分享-未实现盈亏比例
    TBCardShareTypePortfolioShareProfitLossRatio, ///< 持仓分享-盈亏比例
    TBCardShareTypePortfolioShareProfitLossAmount, ///< 持仓分享-盈亏金额
    TBCardShareTypePortfolioUnrealizedProfitLossAmount, ///< 持仓分享-未实现盈亏金额
    TBCardShareTypePortfolioRealizedProfitLossAmount, ///< 持仓分享-已实现盈亏金额
    TBCardShareTypeTigerVaultPortfolioShare, ///< 老虎钱袋子持仓分享（累计收益）
    
    TBCardShareTypeOrderProfitLossAmount, ///< 订单分享-盈亏金额
    TBCardShareTypeOrderProfitLossRatio, ///< 订单分享-盈亏比例
    
    TBCardShareTypeAccountShareTodayProfitLossRatio, ///< 账户分享-今日盈亏比例
    TBCardShareTypeAccountShareTodayProfitLossAmount, ///< 账户分享-今日盈亏金额
    TBCardShareTypeAccountSharePortfolioProfitLoss, ///< 账户分享-持仓盈亏
    TBCardShareTypeAccountShareSecuritiesTotal, ///< 账户分享-证券总价值
    TBCardShareTypeAccountSharePortfolioRatio, ///< 账户分享-持仓占比
    TBCardShareTypeAccountShareTradeCount, ///< 账户分享-今日交易笔数
    TBCardShareTypeAccountSharePnLAndRatio,///< 盈亏比例 + 盈亏金额
    
    TBCardShareTypeFundPortfolioDailyProfitLossAmount, ///< 基金持仓昨日收益
    TBCardShareTypeFundPortfolioProfitLossRatio,///< 基金持仓未实现盈亏比率
    TBCardShareTypeFundPortfolioProfitLossAmount,///< 基金持仓未实现盈亏
    TBCardShareTypeFundPortfolioAccumulatedProfitLossAmount,///< 基金持仓总收益
};

typedef NS_ENUM(NSUInteger, TBCardShareValueType) {
    TBCardShareValueTypeNone,
    TBCardShareValueTypeAmount, ///< 分享金额
    TBCardShareValueTypeRatio, ///< 分享比例
    TBCardShareValueTypeCount, ///< 分享数量（如：交易笔数）
};

// a为透明度（卡片这里的文字颜色是固定特殊色值，加透明度来设计的）
#define COLOR_CARD_SHARE(a) RGBACOLOR_HEX(0X1F1F1F, a)

// 分享卡片宽度
#define TB_CARD_SHARE_VIEW_WIDTH(width) (width-2*33)

// 分享卡片表情总个数
#define TB_CARD_SHARE_STICKER_COUNT 26

// 是否开启测试表情包工具（打开后，卡片页面会展示输入框，可输入值，测试对应表情包是否展示正确）
#define TB_CARD_SHARE_STICKER_TEST_TOOL_ENABLE NO

static NSString *kCardShareImageCode = @"share_pnl"; // 卡片表情图片对应的接口code
static NSString *kCardShareImageName = @"account_share_pnl"; //分享卡片上的表情图片对应的本地图片名字


#endif /* TBCardShareDefine_h */
