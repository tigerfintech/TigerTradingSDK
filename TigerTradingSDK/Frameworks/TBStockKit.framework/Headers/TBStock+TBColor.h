//
//  TBStock+TBColor.h
//  TBStockKit
//
//  Created by zhengzhiwen on 2021/6/9.
//

#import <TBStockKit/TBStock.h>

@interface TBStock (TBColor)

+ (UIColor *)colorForAction:(NSString *)action;

// 获取涨跌幅的color
+ (UIColor *) getIncreaseColor;
+ (NSString *) getIncreaseTradeMarkBuyImage;

/// 获取基金k线买卖打点，买入图片名称
/// - Parameter isAuto: 是否是系统买入
+ (NSString *)getFundIncreaseTradeMarkBuyImage:(BOOL)isAuto;
+ (UIColor *) getIncreaseMakeOrderColor;


+ (UIColor *) getDecreaseColor;


/*
1.根据change大于、等于，小于零 2.根据用户选择红章绿跌或者绿跌红涨，两个条件返回合适颜色
*/
+ (UIColor *) getIncreaseOrDecreaseColorWithRedColor:(UIColor *)redColor
                                           greenColor:(UIColor *)greenColor
                                           equalColor:(UIColor *)equalColor
                                               change:(double)change;

/**
 *  获取一个价格相对于昨收价的颜色
 *
 *  @param price    当前价
 *  @param preClose 昨收价
 *
 *  @return 涨跌颜色或 COLOR_TEXT_COMMON
 */
+ (UIColor *)colorForPrice:(CGFloat)price preClose:(CGFloat)preClose;
+ (UIColor *)colorForChange:(CGFloat)change;


// 盈亏颜色
+ (UIColor *)colorForPnl:(NSNumber *)pnl;
+ (UIColor *)colorForPnlStr:(NSString *)pnl;
/*
 1.根据change大于、等于，小于零 2.根据用户选择红章绿跌或者绿跌红涨，两个条件返回合适图片
 */
+ (NSString *) getIncreaseOrDecreaseImageWithRedImage:(NSString *)redImage
                                          greenImage:(NSString *)greenImage
                                           equalImage:(NSString *)equalImage
                                              change:(double)change;

+ (UIColor *) getIncreaseMakeOrderHighColor;
+ (UIColor *) getIncreaseMakeOrderUnableColor;
+ (NSString *) getDecreaseTradeMarkSellImage;

/// 获取基金k线买卖打点，卖出图片名称
/// - Parameter isAuto: 是否是系统卖出
+ (NSString *)getFundDecreaseTradeMarkSellImage:(BOOL)isAuto;
+ (UIColor *) getDecreaseMakeOrderColor;
+ (UIColor *) getDecreaseMakeOrderHighColor;
+ (UIColor *) getDecreaseMakeOrderUnableColor;

+ (UIColor *) getAskHistColor;
+ (UIColor *) getBidHistColor;

+ (UIColor *) getWhiteIncreaseColor;
+ (UIColor *) getWhiteDecreaseColor;

@end
