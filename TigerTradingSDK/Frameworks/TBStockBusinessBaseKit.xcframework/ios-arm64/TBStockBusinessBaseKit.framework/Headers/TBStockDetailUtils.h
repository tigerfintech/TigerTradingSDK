//
//  TBStockDetailUtils.h
//  Stock
//
//  Created by luopengfei on 2017/11/30.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

@import ChartKLineView;
#import "TBStockDetailTradeManager.h"
#import "TBStockDetailViewControllerDelegate.h"
#import <EventKit/EKSource.h>
#import <EventKitUI/EventKitUI.h>
#import <Foundation/Foundation.h>
#import <TBAccountSystemKit/TBStockPermissionManager.h>
#import <TBAccountSystemKit/TBAccountUtils+TBCustomerService.h>
#import <TBBaseKit/TBConstantUI.h>
#import <TBBaseKit/TBLanguageManager.h>
#import <TBToolsKit/TBUserBehaviorMarcro.h>
#import <TBUIKit/TBStockPrompView.h>
#import <TBUIKit/TBStockSettingChoiceCellItem.h>
#import <TBUIKit/TBUIKit.h>
#import <TBUIKit/TTHeader.h>


#define TB_SA_TRACK_STOCKDETAIL_ACTION(_COMPONENT, _ACTIONTYPE, _SYMBOL, _TYPE, _CUSTOMIZEPATAMS) [TBStockDetailUtils saTrackDetailAction:_COMPONENT actionType:_ACTIONTYPE symbol:_SYMBOL type:_TYPE extraParams:_CUSTOMIZEPATAMS]

#define TB_SA_TRACK_STOCKDETAIL_ACTION_CLICK(_COMPONENT, _SYMBOL, _TYPE, _CUSTOMIZEPATAMS) [TBStockDetailUtils saTrackDetailActionClick:_COMPONENT symbol:_SYMBOL type:_TYPE extraParams:_CUSTOMIZEPATAMS]

#define TB_SA_SYMBOL_TYPE( _MARKET, _SECTYPE) [TBStock getChineseNameWithMarket:_MARKET secType:_SECTYPE]

#define TB_STOCK_DETAIL_EXPOSURE_EVENT_INFO(_COMPONENT, _PAGE, _POSITION, _SYMBOL, _TYPE) [TBStockDetailUtils getExposureEventInfo:_COMPONENT page:_PAGE position:_POSITION symbol:_SYMBOL type:_TYPE]

#define kHKRightOfferPromptString(symbol, rts) [NSString stringWithFormat:TBLocalizedString(@"mobile_ios_common_a_rights_offering_issue_is", nil), symbol, rts, symbol, [TBAccountUtils getUserCustomerServiceNumber]];

typedef void(^SuccessedBlock)(void);
typedef void(^SuccessedWithResultBlock)(id _Nullable result);
typedef void(^SuccessedWithResultAndStringBlock)(id _Nullable result,NSString * _Nullable string);
typedef void(^FailedBlock)(NSError * _Nullable error);

//根据设置项刷新图的
static NSString * _Nullable NOTIFICATION_KEY_UPDATE_STOCK_DETAIL_SETTING                                            = @"notificationKeyUpdateStockDetailSetting";

//图表周期顺序刷新
static NSString * _Nullable NOTIFICATION_KEY_KLINE_TYPE_SORT                                  = @"kline_sort_refresh";

static NSString * _Nullable NOTIFICATION_KEY_CUSTOMDRAW_UPDATE = @"custom_data_update";

static NSString * _Nullable NOTIFICATION_KEY_RANGE_STATISTIC_DISMISS = @"rangeStatisticDismiss";

static NSString * _Nullable NOTIFICATION_KEY_TRADINGVIEW_DATA_REFRESH = @"NOTIFICATION_KEY_TRADINGVIEW_DATA_REFRESH"; ///盯盘模式刷新数据

static NSString * _Nullable NOTIFICATION_KEY_TRADINGVIEW_INDICATOR_REFRESH = @"NOTIFICATION_KEY_TRADINGVIEW_INDICATOR_REFRESH"; ///盯盘模式指标刷新

static NSString * _Nullable USER_DEFAULT_STOCK_DETAIL_V80_GUIDE_VIEW = @"USER_DEFAULT_STOCK_DETAIL_V80_GUIDE_VIEW";

//分时记忆
static NSString *_Nonnull kTBUSStockRealOneDayUserDefaultKey = @"TBUSSTOCK_REAL_ONE_DAY_DEFAULT_KEY";
//夜盘盘前盘中盘后全天
static NSString *_Nonnull kTBUSStockRealOneDayOverNight = @"usStockOverNight";
static NSString *_Nonnull kTBUSStockRealOneDayPre = @"usStockPre";
static NSString *_Nonnull kTBUSStockRealOneDayIn = @"usStockIn";
static NSString *_Nonnull kTBUSStockRealOneDayPost = @"usStockPost";
static NSString *_Nonnull kTBUSStockRealOneDayWholeDay = @"usStockWholeDay";
static NSString *_Nonnull kTBAStockRealOneDayPost = @"aStockSufMarket";

@protocol TBStockDetailPromptUtilsDataSource;

#define kChartAxisValueFont NUMFONTO(10)
#define kChartAxisValueFont_NOADJUST NUMFONTO_NOADJUST(10)

#define TB_SA_TRACK_APP_BEHAVIOR_STOCK_DETAIL(_NAME)  TB_SA_TRACK_APP_BEHAVIOR_STOCK_DETAIL_PARAM(_NAME, @"", @"")
#define TB_SA_TRACK_APP_BEHAVIOR_STOCK_DETAIL_PARAM(_NAME, _PARAM1, _PARAM2) TB_SA_TRACK_APP_BEHAVIOR_QUOTE_PARAM(@"标的详情页", _NAME, _PARAM1, _PARAM2)

static const CGFloat kTBStockDetailQuoteCardVerticalOffset = 12.0f;
static const CGFloat kTBStockDetailQuoteCardTopMargin = 16.0f;
static const CGFloat kTBStockDetailQuoteCardBottomMargin = 16.0f;

static const CGFloat kTBStockDetailQuoteCardTitleProHeight = 36.0f;
static const CGFloat kTBStockDetailQuoteCardTitleHeight = 36.0f;
static const CGFloat kTBStockDetailQuoteCardTitleBottomMargin = 10.0f;
static const CGFloat kTBStockDetailQuoteCardCornerRadius = 8.0f;

static const CGFloat kTBStockDetailV80BlankCellBlankHeightLite = 8;
static const CGFloat kTBStockDetailV80BlankCellBlankHeightPro = 8;
static const CGFloat kTBStockDetailV80BlankCellTopCornerHeightLite = 14;
static const CGFloat kTBStockDetailV80BlankCellTopCornerHeightPro = 14;
static const CGFloat kTBStockDetailV80BlankCellBottomCornerHeightLite = 14;
static const CGFloat kTBStockDetailV80BlankCellBottomCornerHeightPro = 14;
static const CGFloat kTBStockDetailV80BlankCellCornerRadius = 8.0;

static const CGFloat kTBStockDetailHeadPostHeightPro = 36.0f;
static const CGFloat kTBStockDetailHeadPostHeightLite = 40.0f;

#define kStockDetailCellTitleFontLite BOLDFONTO(18)
#define kStockDetailCellTitleFontPro BOLDFONTO(18)
#define kStockDetailCellTitleFontLite_NOADJUST BOLDFONTO_NOADJUST(18)
#define kStockDetailCellTitleFontPro_NOADJUST BOLDFONTO_NOADJUST(18)

#define kTBStockDetailQuoteCardBgColor [TBCommonAppColor themeColorA4]
#define kTBStockDetailQuoteCardContainerBgColor [TBCommonAppColor themeColorA1]
#define TB_SA_TRACK_APP_BEHAVIOR_STOCK_DETAIL_SYMBOL_MARKET(_NAME, SYMBOL, MARKET)  [TBUserBehaviorManager track:@"appBehavior" withProperties:@{@"model": @"行情", @"type": @"标的详情页", @"name": _NAME, @"symbol": SYMBOL, @"market": MARKET} extraMessage:nil]

@protocol TBStockDetailPromptUtilsDataSource <NSObject>

@property (nonatomic, readonly) TBStockPrompViewType promptType;
@property (nonatomic, copy, readonly) NSString * _Nullable title;
@property (nonatomic, readonly) NSString * _Nullable location;
@property (nonatomic, readonly) NSDate * _Nullable date;
@property (nonatomic, readonly) NSString * _Nullable closeKey;

@end

@class MZFormSheetPresentationViewController;
/**
 个股详情页工具方法
 */
@interface TBStockDetailUtils : NSObject

/**
 购买LV2页面action
 */
+ (TTURLAction *_Nullable)gotoHKStockQuoteTradeAction;
+ (TTURLAction *_Nullable)gotoHKStockQuoteTradeAction:(NSString *_Nullable)selectType;//指定tab

/**
 个股详情页底部tab title
 @param type 标的symbol

 */
+ (NSArray * _Nullable)stockDetailBottomTabWithDetailType:(TBStockDetailType)type;

/**
 个股详情页设置信息
 */
+ (NSDictionary * _Nullable)stockDetailSettingDictionary;
/**
 是否绘制跳空
 */
+ (BOOL)drawJump;

/**
 设置跳空

 @param drawJump 跳空
 */
+ (void)setDrawJump:(BOOL)drawJump;


/**
 是否绘制公司行动
 */
+ (BOOL)stockActionWithMarket:(NSString * _Nullable)market;
+ (void)setDrawStockAction:(BOOL)stockAction market:(NSString * _Nullable)market;

/**
 K线图高度
 */
+ (double)chartHeight;

/**
 K线图高度设置

 @param chartHeight K线图高度
 */
+ (void)setChartHeight:(double)chartHeight;

/**
 是否绘制持仓成本线
 */
+ (BOOL)drawAvgCostLine;

/**
 持仓成本线绘制设置

 @param drawAvgCost 是否绘制持仓成本线
 */
+ (void)setDrawAvgCost:(BOOL)drawAvgCost;

+ (void)setKLineStyle:(TBStockKLineStyle)klineStyle;

+ (TBStockKLineStyle)klineStyle;

/**
 逐笔、买卖五档 or 买卖十档是否展开

 @param market 市场
 */
+ (BOOL)levelDetailWithMarket:(NSString * _Nullable)market;

/**
 各个市场买卖五档/十档、逐笔成交是否展示设置

 @param levelDetail 是否展示档位逐笔
 @param market 对应市场
 */
+ (void)setLevelDetail:(BOOL)levelDetail market: (NSString * _Nullable)market;

/**
 是否展示买卖席位
 */
+ (BOOL)askBidBroker;

/**
 买卖席位设置

 @param showAskBidBroker 是否展示买卖席位
 */
+ (void)setAskBidBroker:(BOOL)showAskBidBroker;

/**
 美股是否展示买卖盘对比图
 */
+ (BOOL)askBidLineChart:(NSString * _Nullable)market;

/**
 买卖盘对比图展示设置

 @param askBidChart 是否展示买卖盘对比图
 */
+ (void)setAskBidChart:(BOOL)askBidChart market:(NSString * _Nullable)market;

/**
 限制保证金账户下单提示
 */
+ (UIViewController *_Nullable)limitMarginTradePromptWithParams:(NSDictionary * _Nullable)params;

/**
 限制保证金账户下单，检验交易非主币种账户的交易标的是否有该币种的现金
 */
+ (BOOL)limitMarginAssetValiteWithCurrency:(NSString * _Nullable)currency;

/// 计价货币是否有对应现金资产
/// @param currency <#currency description#>
+ (BOOL)verifyCurrencyAssetCash:(NSString * _Nullable)currency;

/**
 窝轮牛熊证type对应的文案
 */
+ (NSString * _Nullable)getWarrantNameWithTypeId:(NSInteger)typeId;

+ (TBKLineChartYAxisType)chartYAxisTypeForKey:(NSString * _Nullable)key;
+ (NSString * _Nullable)keyForchartYAxisType:(TBKLineChartYAxisType)type;

/// 已选副图指标的枚举类型列表, 包含VOL及其默认值逻辑, 加上check==true的副图指标
+ (NSArray *)selectedSubChartIndicatorTypes;

/**
 根据TBLineType 获取NSInteger 周期，
 期货用
 */
+ (NSInteger)peroidIndexFromLineType:(TBLineType)lineType;

/**
 
 */
+ (NSString * _Nullable)periodStringFromLineType:(TBLineType)lineType secType:(NSString *)secType;

//+ (NSString *)detaiInfoWithMarket:(NSString *)market;

+ (NSDictionary * _Nullable)timeZone;

/**
 根据server返回时间戳和开收盘判断是否处于交易中

 @param openAndCloseTimeList 开收盘时间数组
 @param market 判断市场
 @return
 */
+ (BOOL)stockIsInTradeTime:(NSArray * _Nullable)openAndCloseTimeList market:(NSString * _Nullable)market;

+ (BOOL)stockIsInTradeTime:(NSArray * _Nullable)openAndCloseTimeList market:(NSString * _Nullable)market secType:(NSString * _Nullable)secType;

+ (NSArray * _Nullable)usStockLv2AskBidDepthFormat:(NSArray * _Nullable)depth;
+ (NSArray * _Nullable)l2DepthAskBidMqttDataFormat:(NSString * _Nullable)string;
+ (NSArray * _Nullable)l2CryptoDepthAskBidMqttDataFormat:(NSArray * _Nullable)array currencyOffset:(NSInteger)currencyOffset volumeOffset:(NSInteger)volumeOffset;

/**
 保存事件到日历

 @param eventStore eventStore description
 @param title title description
 @param location location description
 @param startDate startDate description
 @param alarmDate alarmDate description
 @param isSuccess isSuccess description
 */
+ (void)saveToCalendar:(EKEventStore *_Nullable)eventStore title:(NSString *_Nullable)title location:(NSString *_Nullable)location startDate:(NSDate *_Nullable)startDate alarmDate:(NSDate *_Nullable)alarmDate callBack:(void(^_Nullable)(BOOL isSuc, NSString * _Nullable message, EKEvent * _Nullable event))isSuccess;

+ (void)stockDetailHKStockLevelSwitch:(void (^_Nullable)(BOOL))sucess;

/// 设置股票颜色标题
+ (NSAttributedString * _Nullable)redDownGreenUp;
+ (NSAttributedString * _Nullable)redUpGreenDown;
+ (NSAttributedString * _Nullable)stockChangeColorAttributedString;

/// 返回形态选股解释说明页Action
+ (TTURLAction * _Nullable)candleSelectedIntroWebView;

/// 跳转到形态选股解释说明页
+ (void)gotoCandleSelectedIntroWebView;

//跳转去相似K线解释说明页
+ (void)gotoLikeKIntroWebView;

//跳转去经典解释说明页
+ (void)gotoClassicFormStockIntroWebView;

//跳转到订单列表
+ (void)gotoOrderListPage:(NSString *)segType secType:(NSString *)secType market:(nullable NSString *)market symbol:(NSString *)symbol;

/// 神奇九转解释说明
+ (void)magicPointIntroWebView;

/// 获取跳转H5 action
/// @param path path description
+ (TTURLAction * _Nullable)stockDetailToWebAction:(NSString * _Nullable)path;
/// 直接跳去H5
+ (void)stockDetailToWeb:(NSString * _Nullable)path;

/// X轴坐标
/// @param xaxisTimeStamp xaxisTimeStamp description
/// @param market market description
+ (NSDictionary * _Nullable)realTimeXAxisValues:(NSArray * _Nullable)xaxisTimeStamp market:(NSString * _Nullable)market;

/// 格式化价格
/// @param number number description
/// @param symbol symbol description
+ (NSString * _Nullable)validPriceFloatNumber:(NSNumber * _Nullable)number symbol:(NSString * _Nullable)symbol;

/// 是否含有逐笔、买卖档位
/// @param market market description
/// @param secType secType description
/// @param specialCase specialCase description
+ (BOOL)hasTickData:(NSString * _Nullable)market secType:(NSString * _Nullable)secType exchangeCode:(NSString * _Nullable)exchangeCode specialCase:(BOOL)specialCase;

/// 个股盈利分析的action
+ (TTURLAction * _Nullable)tradeAnalysisDetailAction:(NSString *)segType;

+ (NSNumber * _Nullable)klinePeriodLimitCount:(TBLineType)lineType market:(NSString * _Nullable)market;

/**
 画线绘制设置

 @param drawLine 是否绘制画线
 */
+ (void)setDrawLine:(BOOL)drawLine;
/**
是否绘制画线
*/
+ (BOOL)drawLine;

/**
 是否绘制现价线
 */
+ (void)setDrawLastestPriceLine:(BOOL)drawLastestPriceLine;
+ (BOOL)drawLastestPriceLine;
/// 是否绘制预警线
+ (BOOL)drawAlertLines;
+ (void)setDrawAlertLines:(BOOL)drawAlertLines;

@property (nonatomic, copy, class) NSDictionary * _Nullable marketTimeZoneDesMap;
@property (nonatomic, copy, class) NSDictionary * _Nullable marketTimeZoneMap;

+ (void)setRightType:(NSString * _Nullable)rightType;

+ (NSString * _Nullable)rightType;

+ (BOOL)hasAskBidCell:(NSString * _Nullable)market secType:(NSString * _Nullable)secType exchangeCode:(NSString *_Nullable)exchangeCode specialCase:(BOOL)specialCase;
+ (NSNumber * _Nullable)stockDetailOpenAccountGuideTime;

+ (void)setStockDetailOpenAccountGuideTime:(NSNumber * _Nullable)dayTime;

/// 是否展示入金开户提示
+ (BOOL)stockDetailShowOpenAccountGuide;

/// 是否展示筹码分布
+ (BOOL)stockDetailShowCYQView;
+ (void)setStockDetailShowCYQView:(BOOL)show;

/// 期权新手页是否展示价格预测
+ (BOOL)optionGuideIsOpeningEstimatePrice;
+ (void)setOptionGuideEstimatePrice:(BOOL)show;

/// 是否需要签署协议开启权限。默认不需要
/// 为避免未来拆分方法耦合，个股详情页和下单页各写了一个，修改业务判断注意都要改到
+ (BOOL)shouldRegisterPemission:(id<TBStockDetailInfoDataSource>  _Nullable)secInfo;

/** 是否需要签署协议开启权限
 *  - 校验条件不依赖tradeType
 *  - 校验条件不依赖contractSupportFractionalShare
 */
+ (BOOL)shouldRegisterPemission:(id<TBStockDetailInfoDataSource>  _Nullable)secInfo innerNextActionHandler:(BOOL)isInnerActionEnable;

/** 是否需要签署协议开启权限
 *  - 校验条件不依赖tradeType
 */
+ (BOOL)shouldRegisterPemission:(id<TBStockDetailInfoDataSource>  _Nullable)secInfo innerNextActionHandler:(BOOL)isInnerActionEnable contractSupportFractionalShare:(BOOL)contractSupportFractionalShare;

/** 是否需要签署协议开启权限。默认不需要。如果需要开启权限时，会弹出签署协议弹窗
 *  是否内部处理弹窗，可以由isInnerActionEnable控制
 *  目前只有 805版本-SG用户，开启碎股权限（依赖tradeType，非TBTradeTypeSpeedMakeOrder类型时校验） 需要外部处理，其他按需修改。
 *  @param isInnerActionEnable 内部处理开启权限弹窗（默认应该为YES）
 *  @param tradeType 交易方式（目前只在SG碎股权限弹窗用到，其他校验忽略）
 *  @param contractSupportFractionalShare 是否支持碎股（目前只在SG碎股权限弹窗用到，其他校验忽略）
 */
+ (BOOL)shouldRegisterPemission:(id<TBStockDetailInfoDataSource> _Nullable)secInfo innerNextActionHandler:(BOOL)isInnerActionEnable tradeType:(TBTradeType)tradeType contractSupportFractionalShare:(BOOL)contractSupportFractionalShare;

// 是否需要开通碎股权限
+ (BOOL)shouldOpenFractionalShareTradePermission:(id<TBStockDetailInfoDataSource>_Nullable)secInfo contractSupportFractionalShare:(BOOL)contractSupportFractionalShare;

+ (BOOL)stockIsOTC:(NSString * _Nullable)exchange;

// 行情购买链接，后面根据不同跳转地址拼接#/
+ (NSString *)marketPurchaseUrl;

+ (TTURLAction * _Nullable)quotePermissionDes:(TBStockQuotePromptType)type;

+ (BOOL)useNewkLineTipStyle:(NSString * _Nullable)market
                    secType:(NSString * _Nullable)secType
                   lineType:(TBLineType)lineType;

+ (BOOL)autoRefresh:(NSString * _Nullable)market secType:(NSString * _Nullable)secType stockExchange:(NSString * _Nullable)stockExchange;

/// 跳转板块详情页的path
/// @param market A股、英股跳转列表页
+ (NSString * _Nullable)packageDetailPath:(NSString * _Nullable)market;

/**
 绘制K线类型

 @return 0：高山图；1：蜡烛图；2：竹节图/美国线
 */
+ (NSInteger)drawLineStyle;
+ (void)setLineStyle:(NSInteger)lineStyle;

+ (void)dismissCompletion:(void (^ __nullable)(void))completion;

+ (void)saTrackDetailActionClick:(NSString *_Nullable)component symbol:(NSString *_Nullable)symbol type:(NSString *_Nullable)type extraParams:(NSDictionary *_Nullable)extraParams;

+ (void)saTrackDetailAction:(NSString *_Nullable)component actionType:(NSString *_Nullable)actionType symbol:(NSString *_Nullable)symbol type:(NSString *_Nullable)type extraParams:(NSDictionary *_Nullable)extraParams;

+ (NSDictionary * _Nullable)getExposureEventInfo:(NSString *_Nullable)component
                                  page:(NSString *_Nullable)page
                              position:(NSString *_Nullable)position
                                symbol:(NSString *_Nullable)symbol
                                  type:(NSString *_Nullable)type;

+ (NSDictionary * _Nullable)getExposureEventInfo:(NSString *_Nullable)component
                            actionType:(NSString *_Nullable)actionType
                                  page:(NSString *_Nullable)page
                              position:(NSString *_Nullable)position
                                symbol:(NSString *_Nullable)symbol
                                  type:(NSString *_Nullable)type;

+ (NSString *)paramLocalizable:(NSString *_Nullable)name;

//适用品种：美股,非指数
//用途：盘前盘后夜盘的接口入参
//TBLineType：分时类型
//marketType：分时子类型，夜盘盘前盘中盘后全天
//isSymbolSupportOverNight：标的是否支持夜盘
//market：标的市场
//secType：标的品种
+ (NSDictionary *_Nullable)getPrePostOverParams:(TBLineType)currentLineType
                                     marketType:(TBChartDrawMarketType)marketType
                       isSymbolSupportOverNight:(BOOL)isSymbolSupportOverNight
                                         market:(NSString *_Nullable)market
                                        secType:(NSString *_Nullable)secType;

//string到MarketType的映射
+ (NSDictionary *_Nonnull)StringToMarketTypeDic;

//适用品种：美股,非指数
//用途：获取分时tab的记忆逻辑
//hasOverNight:是否支持夜盘
//onlyCache:只取本地记忆
+ (TBChartDrawMarketType)getUsStockMarketType:(NSNumber*_Nullable)hasOverNight;
+ (TBChartDrawMarketType)getUsStockMarketType:(NSNumber*_Nullable)hasOverNight
                                    onlyCache:(BOOL)onlyCache;

//适用品种：美股,非指数
//用途：写入分时tab的记忆逻辑
+ (void)saveUsStockOneDayDrawMarketType:(TBChartDrawMarketType)currentType;

//适用品种：美股,非指数
//选择框的文案和对应的枚举值，三者要严格对应
+ (NSArray *_Nonnull)prePostTagArray:(BOOL)hasOverNight;//用TBChartDrawMarketType作为key
+ (NSArray *_Nonnull)prePostShortNameArray:(BOOL)hasOverNight;//简称，tab使用
+ (NSArray *_Nonnull)prePostFullNameArray:(BOOL)hasOverNight;//全称，弹窗使用

//适用品种：美股,非指数
//美股成交明细参数，区分不同时段
+ (NSDictionary *_Nullable)getTickTradingStatusParams:(TBChartDrawMarketType)marketType
                                               market:(NSString *_Nullable)market
                                              secType:(NSString *_Nullable)secType;

//美股数据源type
+ (NSArray *_Nonnull)usLV2SwitchTypes:(BOOL)hasOverNight;

//美股数据源UI的对应title
//needRightTitle:只有弹窗才可能需要
+ (NSArray *_Nonnull)usLV2SwitchTitles:(NSArray *_Nonnull)types
                          hasOverNight:(BOOL)hasOverNight
                        needRightTitle:(BOOL)needRightTitle;
    
//美股深度数据源type接口入参
+ (NSString *_Nullable)getUsLV2TypeParam:(TBStockQuotePromptType)type;

+ (TBStockQuotePromptType)getUsLV2QuotePromptType:(NSString *_Nullable)lv2TypeParam;

@end
