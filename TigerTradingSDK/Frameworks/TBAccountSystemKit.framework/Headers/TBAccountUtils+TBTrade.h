//
//  TBAccountUtils+TBTrade.h
//  TBAccountSystemKit
//
//  Created by chenxin on 2021/8/11.
//

#import "TBAccountUtils.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBAccountUtils (TBTrade)


/**
 是否显示指纹解锁页面
 */
+ (BOOL)showTouchIDUnlockView;

// 是否有期权交易权限
+ (BOOL)hasOptionTradePermission;

+ (BOOL)virtualHasFuturesTradePermission:(nullable NSNumber *)accountID;
// 是否有期货交易权限
+ (BOOL)hasFuturesTradePermission;

// 是否展示模拟盘开户引导底部图片
// 显示模拟盘底部该引导图的依据，1 符合新人福利保存的bool值，2 标准账户未开户 3 当前是模拟账户 4 非模拟炒股大赛账户(rank_url为空)
+ (BOOL)showVirtualAccountBottomGuideView;

/// 开通交易权限
/// @param permission 具体开通权限
+ (void)showOpenTradePemissionAlert:(NSString *)permission;

/// 开通交易权限
/// @param permission 具体开通权限
/// @param newUI 是否是8.0的样式
+ (void)showOpenTradePemissionAlert:(NSString *)permission withNewUI:(BOOL)newUI;

+ (void)showOpenTradePemissionAlert:(NSString *)permission withNewUI:(BOOL)newUI callBack:(nullable void(^)(NSInteger idx))callBack;

/// 判断是否需要签署澳洲协议
+ (BOOL)checkShouldSignAuStockTradeAgreement;

/// 判断是否需要签署cn协议
+ (BOOL)checkShouldSignCnStockTradeAgreement;

/// 判断当前操作是否需要切换至综合账户
/// @param secType 期货、港股期权、新加坡、澳洲、港股暗盘、数字货币
/// @param specialCondition  闲钱管家、 基金超市、现金打新、资金质押、碎股卖出、OTC标的、港股暗盘等特殊情况
/// @param contraTradable 合约是否支持contra账户交易（当前contra账户时生效，不支持展示提示弹窗）
/// @param eventId 事件来源id
+ (BOOL)omnibusTradeConditionWithSecType:(NSString *)secType 
                                  market:(NSString *)market
                        specialCondition:(BOOL)specialCondition
                          contraTradable:(nullable NSNumber *)contraTradable
                                 eventId:(NSString *)eventId;

+ (BOOL)tradeConditionWithEventId:(NSString *)eventId title:(NSString *)title message:(NSString *)message;

/// 闲钱管家和基金超市判断是否需要切换到综合账户
+ (BOOL)cashPlusOrFundMallConditionWithEventId:(NSString *)eventId;

/// 跳转到开通澳洲股票交易权限协议界面
+ (void)openSignAuStockTradeAgreementPage;

/// 显示切换到某个账户的弹窗
+ (void)showChangeAccountAlertWithAccountType:(nullable NSString *)accountType
                                    accountId:(NSString *)accountId
                                   completion:(void(^)(BOOL isSuccess))completion;

/// 跳转到开通cn股票交易权限协议界面
+ (void)openSignCnStockTradeAgreementPage;

@end

NS_ASSUME_NONNULL_END
