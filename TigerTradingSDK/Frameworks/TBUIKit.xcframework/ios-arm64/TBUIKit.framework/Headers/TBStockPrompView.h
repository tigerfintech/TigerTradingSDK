//
//  TBStockPrompView.h
//  Stock
//
//  Created by Pengfei_Luo on 2017/2/20.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

#define kTBStockPrompViewHeight 35

#define kTBStockTradeTabPrompViewHeight 36

/// 优先级由高到底：港股免责、财报公告、APNS
/*
 优先级（从高到低）    对应操作     有效时间
 退市               没有任何操作  一直有效
 港股免责            关闭        关闭前有效
 沪港通停止交易       没有任何操作
 代码变更            跳转新的标的
 IPO               关闭提醒
 公司行动            提醒/关闭
 财报公告            提醒/关闭
 推送               关闭

 
 期权详情页
 港股免责           关闭      关闭前有效
 供股权交易         查看
 期权提醒（正股拆合股、分红派息） 查看
 
 */
typedef enum : NSUInteger {
    TBStockPrompViewTypeNone,
    TBStockPrompViewTypeCloseOnly,
    TBStockPrompViewTypeIPOLive, //IPO直播
    TBStockPrompViewTypeFutures, // 期货提醒
    TBStockPrompViewTypeAPNS, // APNS 推送
    TBStockPrompViewTypeOptionDividend, // 期权对应正股发生分红派息行动
    TBStockPrompViewTypeOptionSplit, // 期权对应正股发生拆合股行动
    TBStockPrompViewTypeFiance, // 财报提醒
    TBStockPrompViewTypeAction,//公司行动
    TBStockPrompViewTypeActionDividend,//公司行动--派息分红
    TBStockPrompViewTypeStockIPO, // 美股新股上市IPO
    TBStockPrompViewTypeSymbolChange, // 代码变更
    TBStockPrompViewTypeRightOffering, // 供股权查看
    TBStockPrompViewTypeRightOfferOrigin, // 供股权标的
    TBStockPrompViewTypeAHClosed, // 沪港通深港通交易通道关闭时候所有相关标的增加相应提醒
    TBStockPrompViewStockDetailLV0, // 详情页LV0基本报价行情提示
    TBStockPrompViewTypeDelisted, // 公司退市
    TBStockPromptViewTypeHKStockLastTradingDate, // 港股窝轮牛熊证最后交易日（退市处理）
    TBStockPromptViewTypeOptionWarDoExercise,    // 期权和窝轮牛熊证交易之前 必须做题
    TBStockPromptViewTypeWatchListMarrketClosedPrompt,    // 自选列表表市场关闭提醒
    TBStockPromptViewTypeCNMarketNullRegionQuote,    // 沪深报价为空提醒
    TBStockPromptViewTypeCNMarketHKRegionQuote,    // 香港地区沪深报价提醒
    TBStockPrompViewTypeCashAssetHoliday,   //现金宝美股休市提醒
    TBStockPrompViewTypeMarketDelay, //行情延迟提醒
    TBStockPrompViewTypeFundsInTransit,   //在途资金
    TBStockPrompViewTypeSystemCloseAlert, //强平提醒
    TBStockPrompViewTypeLastDayOptionAlert, //末日期权提醒
    TBStockPrompViewTypeIndexLastDayOptionAlert, // 指数期权末日期权提醒
    TBStockPrompViewTypeOptionLv2NoDataAlert, // 期权lv2无数据提醒
    TBStockPrompViewTypeFund, // 基金消息推送
    TBStockPrompViewTypePlaceOrderOptionMarketAlert, // 期权-市价单提示
    TBStockPrompViewTypeMaterial, // 物料下发的提醒
    
    TBStockPrompViewTypeGreyMarketReminder,
    // *****最高优先级，cms紧急通告****** //
    TBStockPrompViewTypeCMSAlert    = 9999,            // CMS提醒，用于个股详情、行情、下单、改单、持仓
    TBStockPrompViewHKStockPositionLV0, // 港股持仓LV0基本报价行情提示(只有模拟盘)
    TBStockPrompViewLitePortfolioAccountRisk,  //Lite持仓风控


} TBStockPrompViewType;

@class TBMarqueeView;

@interface TBStockPrompView : UIView

@property (nonatomic, strong, readonly) UILabel *promptView;

@property (nonatomic, strong, readonly) TBMarqueeView *marqueeView;

@property (nonatomic, strong, readonly) UIButton *closeButton;
@property (nonatomic, assign) BOOL unBlendedCloseImage;

@property (nonatomic, strong, readonly) UIButton *continueButton;
@property (nonatomic, strong) UIColor *continueBorderColor;

@property (nonatomic, strong, readonly) UIView *buttonBottomView;


- (instancetype)initWithPrompt:(NSString *)prompt promptType:(TBStockPrompViewType )promptType;

@property (nonatomic, strong) void (^continueBlock)(TBStockPrompViewType promptType);
@property (nonatomic, strong) void (^closeBlock)(TBStockPrompViewType promptType);

@property (nonatomic, strong) UIColor *backColor;
@property (nonatomic, strong) UIColor *textColor;

@property (nonatomic, assign) BOOL ignoreTheme;

/// 主要swift引用报错，这里加一个属性控制
@property (nonatomic, assign) BOOL navColor;

@property (nonatomic, assign) BOOL liteStyle; /// 默认NO 两种布局样式

/**
 提示View类型
 目前应该有两种，V4.6会增加几种
 */
@property (nonatomic, assign) TBStockPrompViewType promptType;

/**
 中间滚动显示的文案
 */
@property (nonatomic, copy) NSString *promptStr;
@property (nonatomic, strong) UIFont *promptFont;
@property (nonatomic, strong) UIFont *promptNumFont;
/**
确定按钮的文案
*/
@property (nonatomic, copy) NSString *continueStr;

@property (nonatomic, copy) NSString *closeIconName;

@property (nonatomic, copy) NSString *continueIconName;

@property (nonatomic, copy) NSString *sourceURL; ///< 跳转链接 仅用来判断是否已经点击过

@property (nonatomic, assign) BOOL hasAddEvent; // 是否已经将事件添加到日历中

/**
是否显示查看按钮，TBStockPrompViewTypeSystemCloseAlert时 综合账户显示查看按钮 环球账户不显示
*/
@property (nonatomic, assign) BOOL showContinueButton;
@property (nonatomic, strong) UIFont *buttonLabelFont;

- (instancetype)initWithFrame:(CGRect)frame isLiteStyle:(BOOL)isLiteStyle;

/**
 将提醒类型、提醒内容存放字典中

 @param value 提醒内容
 @param type 提醒类型
 */
- (void)setPromptValue:(id)value forType:(TBStockPrompViewType )type;

- (void)removeAllPrompt;

/**
 刷新提醒内容
 */
- (void)reloadPromptView;

/**
 删除TBStockPrompViewType 对应的value

 @param type TBStockPrompViewType
 */
- (void)removeValueForType:(TBStockPrompViewType)type;

/**
 获取type对应的提醒value

 @param type TBStockPrompViewType
 */
- (id)promptValueForType:(TBStockPrompViewType)type;

/**
 获取优先级最高的提醒
 */
- (NSDictionary *)highestPromptMessage;

- (void)setGid:(NSString *)gid promptType:(TBStockPrompViewType)type;

- (NSString *)gidWithPromptType:(TBStockPrompViewType)type;

- (void)changeNavBarColor;

@end
