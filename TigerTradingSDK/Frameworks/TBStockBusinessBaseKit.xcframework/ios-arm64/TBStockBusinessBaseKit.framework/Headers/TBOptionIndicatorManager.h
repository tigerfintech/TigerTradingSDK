//
//  TBOptionIndicatorManager.h
//  Stock
//
//  Created by JustLee on 2021/3/24.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

typedef NS_ENUM(NSUInteger, TBOptionDisplayType) {
    TBOptionDisplayTypeNone     = 0,
    TBOptionDisplayTypeList     = 1 << 1,   //列表
    TBOptionDisplayTypeTType    = 1 << 2, //T
    TBOptionDisplayTypeSettingType    = 1 << 3  //T
};

typedef NS_ENUM(NSUInteger, TBOptionDetailIndicator) {
    TBOptionDetailIndicatorStrike               = 0, //行权价
    TBOptionDetailIndicatorOrder                = 1 << 1,   //方向
    TBOptionDetailIndicatorPrice                = 1 << 2,   //最新价
    TBOptionDetailIndicatorBid                  = 1 << 3,     //买盘
    TBOptionDetailIndicatorAsk                  = 1 << 4,     //卖盘
    TBOptionDetailIndicatorVolume               = 1 << 5,   //成交量
    TBOptionDetailIndicatorChange               = 1 << 6, //涨跌额
    TBOptionDetailIndicatorChangeRate           = 1 << 7, //涨跌幅
    TBOptionDetailIndicatorOpenInt              = 1 << 8, //未平仓数
    TBOptionDetailIndicatorOpenIntChange        = 1 << 9, //未平仓数涨跌
    TBOptionDetailIndicatorBreakEvenPoint       = 1 << 10, //盈亏平衡点
    TBOptionDetailIndicatorDiscountPremiumRatio = 1 << 11, //溢价率
    TBOptionDetailIndicatorProfitMarginBuy      = 1 << 12,     //买入盈利率
    TBOptionDetailIndicatorIV                   = 1 << 13,     //隐含波动率 HK:引申波幅
    TBOptionDetailIndicatorIVOrHistVol          = 1 << 14, //隐含/历史波动 HK:引伸/历史波幅
    TBOptionDetailIndicatorIntrinsicValue       = 1 << 15, //内在价值
    TBOptionDetailIndicatorTimeValue            = 1 << 16, //时间价值
    TBOptionDetailIndicatorDelta                = 1 << 17, //delta
    TBOptionDetailIndicatorGamma                = 1 << 18, //gamma
    TBOptionDetailIndicatorTheta                = 1 << 19, //theta
    TBOptionDetailIndicatorVega                 = 1 << 20, //vaga
    TBOptionDetailIndicatorRho                  = 1 << 21, //rho
};

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionIndicatorManager : NSObject

DECLARE_SHARED_INSTANCE(TBOptionIndicatorManager)

///虽然数据项相同，但是两种形式需要不同的排序 列表、T型
- (NSArray <NSNumber *> *)listIndicatorArray;
//T型排序
- (NSArray <NSNumber *> *)tTypeIndicatorArray;
//列表排序在collection需要展示选项
- (NSArray <NSNumber *> *)displayListIndicatorArray;
//T排序在collection需要展示选项
- (NSArray <NSNumber *> *)displayTTypeIndicatorArray;
//对应名字
- (NSString *)displayNameWithIndicatorType:(TBOptionDetailIndicator)type;
//统计项名字
- (NSString *)displayLogEventNameWithIndicatorType:(TBOptionDetailIndicator)type;
// 缓存列表顺序
- (BOOL)cacheOptionListIndicatorSortArray:(NSArray <NSNumber *> *)sortArray;
// 缓存T型顺序
- (BOOL)cacheOptionTTypeIndicatorSortArray:(NSArray <NSNumber *> *)sortArray;

/// 重置设置
/// @param displayType 当前展示数据类型
- (BOOL)resetAllPeriodSettingWithDisplayType:(TBOptionDisplayType)displayType;

@end

NS_ASSUME_NONNULL_END
