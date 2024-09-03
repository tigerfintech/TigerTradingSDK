//
//  TBUtils+TBStockDetail.h
//  Stock
//
//  Created by 王灵博 on 2020/8/31.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseKit.h>
#import <TBStockKit/TBStock.h>
@import ChartKLineView;
NS_ASSUME_NONNULL_BEGIN

@interface TBUtils (TBStockDetail)

/**
获取market或者secType所属的image
@param market 市场
@param secType secType
@return image
*/
+ (UIImage *)marketImageWithMarket:(NSString *)market secType:(NSString *)secType;


/**
是否有深度、十档 or五档数据
@param market 市场
@param secType secType
@return bool
*/
+ (BOOL)haveDepthDataWithMarket:(NSString *)market
                        secType:(NSString *)secType
                   exchangeCode:(NSString *)exchangeCode
             isHKGreyMarketStep:(BOOL)isGreyMarketStep
                    isOTCMarket:(BOOL)isOTCMarket;

+ (BOOL)bigScreenHasTickData:(NSString *)market
                     secType:(NSString *)secType
                exchangeCode:(NSString *)exchangeCode
                 specialCase:(BOOL)specialCase;

// 获取涨跌 买入卖出图片
+ (NSString *)getTradeBuyImage;

+ (NSString *)getTradeSellImage;

+ (void)openOptionDoExerciseType:(TBDoExerciseOriginalType)doExerciseOriginalType parameter:(NSDictionary *)parameter status:(NSInteger)status;

+ (TBKLineChartYAxisType)chartYAxisTypeForKey:(NSString *)key;
+ (NSString *)keyForchartYAxisType:(TBKLineChartYAxisType)type;

// 美股市场无期权时，开通期权提示弹窗
+ (void)showOptionPermissionAlert;

/// 期权：现金账户开通保证金账户弹窗
+ (void)showOptionUpgradeMarginAccountAlertWithSelectedBlock:(void(^ __nonnull)(NSInteger index))selectedBlock;

+ (UIImage *)getIncreaseImage;
+ (UIImage *)getDecreaseImage;

@end

NS_ASSUME_NONNULL_END
