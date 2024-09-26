//
//  TBStockManyEntranceModel.h
//  Stock
//
//  Created by 王灵博 on 2020/7/15.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>

/// 行情-股票 各市场页, 图标工具栏中各图标的枚举类型
typedef NS_ENUM(NSUInteger,TBStockEntranceListType){
    TBStockEntranceNewShareSubscription = 1,//新股认购
    TBStockEntranceTigerLab,//老虎实验室
    TBStockEntranceFinancialReportDividend,//财报/分红
    TBStockEntranceHotETF,//热门etf
    TBStockEntranceStockPicker,//选股器
    TBStockEntranceSimilarKLine,//相似k线
    TBStockEntranceFormStockSelection,//形态选股
    TBStockEntranceSeatTracking,//席位追踪
    TBStockEntranceValuationAnalysis,//估值分析
    TBStockEntranceShortStatistics,//做空统计
    TBStockEntranceCapitalAnalysis,//资金分析
    TBStockEntranceHongKongStockOptions,//美股/港股期权
    TBStockEntranceTigerPrePostHourTrading,//盘前盘后榜
    TBStockEntranceRSP, //定投
    TBStockEntranceBond, // 债券
    TBStockEntranceETFMall, // ETF专区(港股)
    TBStockEntranceUSOverNight, //美股夜盘
    TBStockEntranceContra, // Contra榜单
};
NS_ASSUME_NONNULL_BEGIN
@interface TBStockEntranceListModel : TBBaseModel

@property(nonatomic, copy) NSString *imgName;
@property(nonatomic, copy) NSString *titleStr;
@property(nonatomic, copy) NSString *market;

@property(nonatomic, assign)TBStockEntranceListType type;

@end
@interface TBStockManyEntranceModel : TBBaseModel
+ (NSArray *)getManyEntranceWithMarket:(NSString *)market;
@end

NS_ASSUME_NONNULL_END
