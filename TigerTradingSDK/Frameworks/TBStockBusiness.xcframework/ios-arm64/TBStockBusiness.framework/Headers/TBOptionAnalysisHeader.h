//
//  TBOptionAnalysisHeader.h
//  Stock
//
//  Created by 王灵博 on 2021/1/14.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#ifndef TBOptionAnalysisHeader_h
#define TBOptionAnalysisHeader_h

static NSString *USER_DEFAULT_KEY_STATISTICAL_DATA                                     = @"settingStatisticalData";//期权链统计数据
static NSString *USER_DEFAULT_KEY_WEEKLY_OPTIONS                                    = @"settingWeeklyOptions";//周权标记
static NSString *USER_DEFAULT_KEY_FLUCTUATION_STANDARD                                    = @"settingFluctuationStandard";//股价期望波动标准值
static NSString *USER_DEFAULT_KEY_OLD_OPTION                                   = @"settingOldOption";//隐藏公司行动后期权

static NSString *USER_DEFAULT_KEY_COMPARE_IV                                     = @"settingCompareIV";//对比历史波动率（30日）

static NSString *USER_DEFAULT_KEY_IMPLIED_VOLATILITY                                     = @"settingImpliedVolatility";//隐含波动率的展示

static NSString *USER_DEFAULT_KEY_STRATEGY_BUILDER = @"settingStrategyBuilder";//期权组合工具展示

static NSString *USER_DEFAULT_KEY_IVSLIDER_CENTERX                                     = @"settingIVSliderCenterX";//隐含波动率滑块

static NSString *USER_DEFAULT_KEY_OPTION_CHANGE                                      = @"typesOfOptionChange";
static NSString *USER_DEFAULT_KEY_OPTION_KLINE_TYPE                                     = @"typesOfOptionKlineType";
static NSString *USER_DEFAULT_KEY_FIRST_OPTION_TOOL_BAR                                     = @"settingfirstOptionToolBar";//期权链统计数据
typedef NS_ENUM(NSUInteger, TBOptionChangeType) {
    TBOptionChangeBigSingle,//大单异动
    TBOptionChangeAbnormalTradingVolume,//成交量异动
    TBOptionChangeIV//IV异动
};

#endif /* TBOptionAnalysisHeader_h */
