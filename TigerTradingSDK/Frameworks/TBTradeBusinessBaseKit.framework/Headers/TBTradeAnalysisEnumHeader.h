//
//  TBTradeAnalysisEnumHeader.h
//  Pods
//
//  Created by zlc on 2022/5/5.
//

#ifndef TBTradeAnalysisEnumHeader_h
#define TBTradeAnalysisEnumHeader_h

/*
 * 名称/代码、数量/价格、金额/费用、已实现盈亏、成交时间、操作区间
 */
typedef NS_ENUM(NSUInteger, TBTradeAnalysisTransactionDetailHistoryDisplayType){
    TBTradeAnalysisTransactionDetailHistoryDisplayTypeNone, ///< 不展示
    TBTradeAnalysisTransactionDetailHistoryDisplayTypeNameCode,///< 名称代码
    TBTradeAnalysisTransactionDetailHistoryDisplayTypeDirection,///< 操作方向
    TBTradeAnalysisTransactionDetailHistoryDisplayTypeCountPrice,///< 数量/价格
    TBTradeAnalysisTransactionDetailHistoryDisplayTypeAmountFee,///< 金额/费用
    TBTradeAnalysisTransactionDetailHistoryDisplayTypePNL, ///< 已实现盈亏
    TBTradeAnalysisTransactionDetailHistoryDisplayTypeFilledDate, ///<  成交时间
    TBTradeAnalysisTransactionDetailHistoryDisplayTypeShare, ///<  分享
};

typedef NS_ENUM(NSUInteger, TBTradeAnalysisTransactionDetailHistorySortType){
    TBTradeAnalysisTransactionDetailHistorySortTypeNone,
    TBTradeAnalysisTransactionDetailHistorySortTypeUp,
    TBTradeAnalysisTransactionDetailHistorySortTypeDown,
};

/// header右侧操作区域类型
typedef NS_ENUM(NSUInteger, TBTradeAnalysisTransactionDetailHistoryActionType){
    TBTradeAnalysisTransactionDetailHistoryActionTypeNone, ///< 无
    TBTradeAnalysisTransactionDetailHistoryActionTypeSort, ///< 排序
    TBTradeAnalysisTransactionDetailHistoryActionTypeAlert,///< 叹号图标，点击alert
};

/// 页面来源枚举
typedef NS_ENUM(NSInteger, TBTradeAnalysisDetailVCSourceType) {
    TBTradeAnalysisDetailVCSourceTypeNone,
    TBTradeAnalysisDetailVCSourceTypeStockDetailPosition,       ///< 股票详情页-持仓入口
    TBTradeAnalysisDetailVCSourceTypeStockDetailMore,           ///< 股票详情页-更多入口
    TBTradeAnalysisDetailVCSourceTypeAnalysisCombinedVC,        ///< 盈亏总览页入口
    TBTradeAnalysisDetailVCSourceTypePosition,                  ///< 持仓tab-盈亏入口
    
};

#endif /* TBTradeAnalysisEnumHeader_h */
