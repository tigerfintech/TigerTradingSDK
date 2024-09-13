//
//  TBOptionUtils.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/12/3.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBOptionAnalysisHeader.h"
#import <TBBaseKit/TBPhoneUtility.h>
NS_ASSUME_NONNULL_BEGIN

@interface TBOptionUtils : NSObject

//存储期权异动榜单
+ (void)saveOptionChange:(TBOptionChangeType)type;
+ (TBOptionChangeType)getOptionChangeType;

+ (CGFloat)getSafeAreaHeight;

+ (CGFloat)screenComprehensiveFit:(CGFloat)x;

//期权链统计数据
+(void)saveStatisticalData:(BOOL)select;
+ (BOOL)getStatisticalData;
//周权标记
+(void)saveWeeklyOptions:(BOOL)select;

/// 周期权是否显示"(W)"后缀
+ (BOOL)getWeeklyOptions;

//股价期望波动标准值
+(void)saveFluctuationStandard:(BOOL)select;
+ (BOOL)getFluctuationStandard;
//隐藏公司行动后期权
+(void)saveOldOption:(BOOL)select;
+ (BOOL)getOldOption;
/// 期权新手页是否展示价格预测
+ (BOOL)optionGuideIsOpeningEstimatePrice;
+ (void)setOptionGuideEstimatePrice:(BOOL)show;

+(void)saveCompareIV:(BOOL)select;
+ (BOOL)getCompareIV;

+(void)saveImpliedVolatilityIV:(BOOL)select;
+ (BOOL)getImpliedVolatilityIV;

+ (void)saveStrategyBuilder:(BOOL)isSelected;
+ (BOOL)getStrategyBuilder; // 默认为YES

+(void)saveIVSliderCenterX:(NSDictionary *)dic;
+ (NSDictionary *)getIVSliderCenterX;


+(void)saveFirstOptionToolBar:(BOOL)select;
+ (BOOL)getFirstOptionToolBar;

//交易所枚举
+ (NSDictionary *)optionExchangeDict;

@end

NS_ASSUME_NONNULL_END
