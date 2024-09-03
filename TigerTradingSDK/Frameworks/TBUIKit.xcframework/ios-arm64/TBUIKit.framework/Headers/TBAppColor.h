//
//  TBAppColor.h
//  Stock
//
//  Created by ChenXin on 16/11/22.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBCommonAppColor.h"

@interface TBAppColor : NSObject

+ (TBAppColorStyle)appColorStyle;

+ (UIStatusBarStyle)preferredStatusBarStyle;

//根据当前皮肤，从传入的颜色数组中返回对应颜色
+ (UIColor *)colorFromArray:(NSArray *)colorArray;

//根据多个色值返回颜色，balck,blue,white分别表示，黑色，蓝色，白色皮肤
+ (UIColor *)colorFromBlack:(int)black blue:(int)blue white:(int)white;

//根据多个色值返回颜色,Dark表示深色皮肤
+ (UIColor *)colorFromDark:(int)dark white:(int)white;

//根据多个色值返回颜色,Dark表示深色皮肤，并可设置透明度
+ (UIColor *)colorFromDark:(int)dark withAlpha:(CGFloat)darkAlpha white:(int)white withAlpha:(CGFloat)whiteAlpha;

+ (UIColor *)barTopLineColor;

+ (UIColor *)navBarBackgroundColor;

+ (UIColor *)navBarBottomLineColor;

// 对应颜色规范a1
+ (UIColor *)lightBackgroundColor;

// 对应颜色规范a2
+ (UIColor *)darkBackgroundColor;

// 对应颜色规范a3
+ (UIColor *)yellowColor;

// 白皮肤橘色
+ (UIColor *)orangeColor;

// 对应颜色规范a4
+ (UIColor *)singleLineColor;

// 对应颜色规范a5
+ (UIColor *)tabBarBackgroundColor;

+ (UIColor *)grayBackgroundColor;

// 对应颜色规范b1
+ (UIColor *)commonTextColor;

// 对应颜色规范b2
+ (UIColor *)titleColor;

// 对应颜色规范b3
+ (UIColor *)subtitleColor;

// 对应颜色规范b4
+ (UIColor *)blueTextColor;

// 对应颜色规范b5
+ (UIColor *)greenColor;


// 对应颜色规范b6
+ (UIColor *)redColor;

//tabbar文字未选中时颜色
+ (UIColor *)tabbarUnselectedTitleColor;

// 对应颜色规范c1
+ (UIColor *)klineBlueColor;
// 对应颜色规范c2
+ (UIColor *)klineDarkBlueColor;
// 对应颜色规范c3
+ (UIColor *)klineOrangeColor;

//导航栏上黄色文本颜色，白皮肤下为#333333
+ (UIColor *)yellowTextColor;

//用于css中的颜色，以#开头
+ (NSString *)cssColorFromArray:(NSArray *)array;

+ (NSString *)cssBlueColor;

+ (NSString *)cssGrayColor;

+ (NSString *)cssColorFromUIColor:(UIColor *)color;

+ (UIColor *)cellSelectedColor;

+ (UIColor *)tintColor;

+ (UIColor *)hintColor;

+ (UIColor *)hourTradingColor;

+ (UIColor *)hourTradingTextColor;

+ (UIColor *)tradeTitleColor;
//视图禁用时的颜色
+ (UIColor *)viewDisabledColor;

// 持有
+ (UIColor *)shallowBlueColor;

// 看多
+ (UIColor *)shallowOrangeColor;

// 看空
+ (UIColor *)darkBlueColor;

//特殊红色提醒
+ (UIColor *)specialRedALert;
/**
 下单页cell上的button的背景色
 */
+ (UIColor *)placeOrderCellButtonBackgroundColor;
+ (UIColor *)placeOrderCellButtonHighlightedColor;

//头部切换栏颜色
+ (UIColor *)segmentBackgroundColor;
+ (UIColor *)segmentNormalTextColor;
+ (UIColor *)segmentSeletedTextColor;

/**
 期权横屏call背景色
 */
+ (UIColor *)optionCallBackgroudColor;

/**
 期权横屏put背景色
 */
+ (UIColor *)optionPutBackgroundColor;

/**
 期权价内价格颜色
 */
+ (UIColor *)optionPriceInColor;

/**
 分时线渐变颜色

 @return 分时线渐变颜色
 */
+ (NSArray *)realTimeGradientColor;

/**
 横屏盘前盘后分时渐变色处理
 */
+ (NSArray *)hourRealTimeGradientColor;

/**
 分时线颜色

 @return 分时线颜色
 */
+ (UIColor *)realTimeLineColor;
+ (UIColor *)realTimePreSuffColor;
/**
 分时图成交量颜色 V5.10

 @return 分时图成交量颜色
 */
+ (UIColor *)realTimeVolumeColor;

/**
 分时图X轴圆点颜色

 @return <#return value description#>
 */
+ (UIColor *)realTimeXAxisCircleColor;

/**
 K线图、分时图border color，axis line color， grid line color

 @return border color
 */
+ (UIColor *)klineRealBorderLineColor;

/**
 盈亏分析、图表分析渐变色数组
 */
+ (NSArray *)tradeLineChartColor;


/**
 @return 交易图表line view
 */
+ (UIColor *)tradeLineColor;

/**
 @return 返回textfield placeholder色值
 */
+ (UIColor *)placeHolderColor;

+ (UIColor *)loginDarkBackgroundColor;

+ (UIColor *)askBidSelectedColor;

+ (UIColor *)viewLayerAnimateColor;

+ (UIColor *)viewLayerColor;

+ (UIColor *)smsTextAnimateColor;

+ (UIColor *)popBackGroundColor;

//工具栏新样式的文字颜色
+ (UIColor *)toolbarTextColor;

#pragma mark - 特殊文字颜色
+ (UIColor *)menuTextColor;

+ (UIColor *)menuSelectedTextColor;

+ (UIColor *)todayFocusTimeColor;

+ (UIColor *)todayFocusTimeBgColor;

+ (UIColor *)todayFocusPictureBgColor;

+ (UIColor *)screenshotShareBottomBgColor;

+ (UIColor *)stockGroupManagerCreateColor;

+ (UIColor *)refrenceBgColor;

+ (UIColor *)communityContentColor;

+ (UIColor *)communityContentColor2;

#pragma mark - 下单页特殊颜色
+ (UIColor *)placeOrderTextFieldButtonNormalColor;
+ (UIColor *)placeOrderTextFieldButtonHighlightedColor;
+ (UIColor *)loginTextFieldBackgroundColor;

#pragma mark - 订单页特殊颜色
+ (UIColor *)orderHistoryToolbarBackgroundColor;

#pragma mark - 交易->盈亏分析->账户分析
+ (UIColor *)accountAnalysisLineChartColor:(NSInteger)lineNumber;
+ (UIColor *)accountAnalysisPNLBackgroundColor;
+ (UIColor *)accountAnalysisXYLabelBackgroundColor;
+ (UIColor *)accountAnalysisButtonBorderColor;

#pragma mark - 模拟盘颜色
// 模拟账户背景色，用于导航栏和交易tab头部
+ (UIColor *)virtualAcountBackgroundColor;

// 模拟账户文字颜色，用于导航栏标题和交易tab头部文字
+ (UIColor *)virtualAcountTextColor;

#pragma mark - 仓位分析页特殊颜色
+ (UIColor *)positionRiskTextColor2;

/**
 个股详情页按钮border 背景色
 */
+ (UIColor *)stockDetailPromptButtonBorderColor;

+ (UIColor *)accountSwitchBackgroundColor;

+ (UIColor *)speedMakeOrderSwitchBackgroundColor;

+ (UIColor *)dataVaneBlueLineColor;

+ (UIColor *)dataVaneOrangeLineColor;
//toolBarColor开户滚动选择框的toolBarColor
+ (UIColor *)selectToolBarColor;


/**
 横屏设置text field 背景颜色

 @return <#return value description#>
 */
+ (UIColor *)horizontalSettingTextFieldBackgroundColor;
/**
 横屏设置选择字体颜色

 @return <#return value description#>
 */
+ (UIColor *)horizontalSettingSelectedTextColor;

+ (UIColor *)tradeTaskCellBgColor;

+ (UIColor *)tradeTaskCellTitleColor;

+ (UIColor *)tradeTaskCellDisableButtonTitleColor;

+ (UIColor *)tradeTaskCellDisableButtonBgColor;

+ (UIColor *)tradeMakeOrderTitleColorForRealTrade;

+ (UIColor *)tradeMakeOrderHourTradingColorForRealTrade;

+ (UIColor *)tradeMakeOrderTitleColorForVirtualTrade;

+ (UIColor *)tradeMakeOrderHourTradingColorForVirtualTrade;

+ (UIColor *)tradePNLAnalysisTitleColor;

+ (UIColor *)timeLineDotColor;

+ (UIColor *)timeLineColor;

+ (UIColor *)contentSubTitleColor;

+ (UIColor *)contentTitleColor;

// 黄底黑字按钮标题颜色
+ (UIColor *)loginButtonTitleColor;

+ (UIColor *)lineBorderColor;

+ (UIColor *)indicationYellowColor;
/**
 chart 单线 颜色

 */
+ (UIColor *)chartSingleLineColor;

/**
 股价变动为0颜色
 */
+ (UIColor *)zeroChangePriceColor;

+ (UIColor *)rateDefaultColor;

+ (UIColor *)verifyCodeLineBorderColor;

+ (UIColor *)emptyViewBackgroundColor;

/**
 开户引导页新UI颜色
 */

+ (UIColor *)openAccountGuideViewCellTitleColor;
+ (UIColor *)openAccountGuideViewCellSubTitleColor;

+ (UIColor *)openAccountGuideProgressTextColor;
+ (UIColor *)openAccountGuideProgressHighlightTextColor;

+ (UIColor *)openAccountGuideProgressLineColor;
+ (UIColor *)openAccountGuideProgressHightlightLineColor;

+ (UIColor *)pageIndicatorTintColor;
+ (UIColor *)currentPageIndicatorInitColor;

+ (UIColor *)tagBackGroundColor;
+ (UIColor *)tagTextColor;

+ (UIColor *)checkMoreColor;

+ (UIColor *)buttonBorderColor;
// 快捷下单 键盘背景色
+ (UIColor *)quickOrderKeyboardBackground;

+ (UIColor *)quickOrderKeyboardButtonNormalBackground;

+ (UIColor *)quickOrderKeyboardButtonHighLightBackground;

+ (UIColor *)giveStockColor;
#pragma mark - 6.5.9 全新颜色规范，替换完成后可完全删除之前的颜色

//品牌通用色（当前黄色）
+ (UIColor *)themeColorB4;
//图表蓝色(B5）
+ (UIColor *)themeColorB5;
//涨跌绿(B6）
+ (UIColor *)themeColorB6;
//涨跌红(B7）
+ (UIColor *)themeColorB7;
//fcn票据金色
+ (UIColor *)themeColorB8;
//常用背景色值(A1)，包括VC.view背景色，UITableView背景色，UITableViewCell背景色
+ (UIColor *)themeColorA1;
//通知横条背景色值(A2)
+ (UIColor *)themeColorA2;
//分隔线色值(A3)
+ (UIColor *)themeColorA3;
//分栏条色值(A4)
+ (UIColor *)themeColorA4;
//小卡片色值(A5)
+ (UIColor *)themeColorA5;
+ (UIColor *)themeColorA6;

/// 背景色/特殊分段线色值
+ (UIColor *)themeColorA7;

#pragma mark - 6.5.9 新规范文字颜色
//主文字色值(B1)
+ (UIColor *)themeColorB1;
//二级文字色值(B2)
+ (UIColor *)themeColorB2;
//三级文字色值(B3)
+ (UIColor *)themeColorB3;
//常规按钮点击
+ (UIColor *)themeColorB24;

/// 主色辅助色/图表蓝色
+ (UIColor *)themeColorB25;

#pragma mark - 6.5.9 新版新增的图表及外链颜色，之前已经定义过的颜色则直接进行了修改

//图表紫色
+ (UIColor *)purpleColor;
//图表红色
+ (UIColor *)chartRedColor;
//图表黄色
+ (UIColor *)chartYellowColor;
//链接点击后的颜色
+ (UIColor *)linkClickedColor;
//链接颜色
+ (UIColor *)linkColor;
//角标背景颜色
+ (UIColor *)badgeBackgroundColor;
//角标文字颜色
+ (UIColor *)badgeTextColor;
//猜你喜欢背景颜色
+ (UIColor *)rightLikeBackColor;

#pragma mark - 6.5.9 新规范特殊文字颜色

/**
 主题特殊颜色样式1，分组的卡片颜色 (0x262732,0x262732,0xFFFFFF)
 
 @return spicial color
 */
+ (UIColor *)themeColorS1;

/**
 主题特殊颜色样式2，点赞后文字颜色 (0x2C2E3B,0x2C2E3B,0xF8CC00)
 
 @return spicial color
 */
+ (UIColor *)themeColorS2;

/**
 登录页面分割线lineColor
*/
+ (UIColor *)loginBottomLineColor;

@end
