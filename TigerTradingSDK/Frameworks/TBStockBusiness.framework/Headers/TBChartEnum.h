//
//  TBChartEnum.h
//  Pods
//
//  Created by linbingjie on 2023/5/30.
//

#ifndef TBChartEnum_h
#define TBChartEnum_h

typedef NS_ENUM(NSInteger, TBChartSourceType) {
    TBChartSourceTypeStock = 0,
    TBChartSourceTypeOrder,
    TBChartSourceTypeTradingView
};

/// 个股详情页交易弹框类型
///
/// - normal: 只有买卖：A股，OMNIBUS
/// - normalSimu: 模拟账号
/// - close: 包含平仓：
/// - option: 包含期权：期权、牛熊证
typedef NS_ENUM(NSInteger, TBStockDetailTradeMenuType) {
    TBStockDetailTradeMenuTypeNormal,
    TBStockDetailTradeMenuTypeNormalSimu,
    TBStockDetailTradeMenuTypeClose,
    TBStockDetailTradeMenuTypeOption,
    TBStockDetailTradeMenuTypeHKWarrIopt,
    TBStockDetailTradeMenuTypeHKOption
};

#endif /* TBChartEnum_h */
