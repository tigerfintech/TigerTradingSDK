//
//  TBUserConfigManager.h
//  Pods
//
//  Created by zhengzhiwen on 2021/9/26.
//

#import <Foundation/Foundation.h>
#import <TBStockKit/TBStock.h>

NS_ASSUME_NONNULL_BEGIN

// 帮助宏
#define TBTableViewCellLineOne(nameCN, symbol) [TBUserConfigManager displayNameCNWithOriginalNameCN: (nameCN) andOriginalSymbol: (symbol)]

#define TBTableViewCellLineTwo(nameCN, symbol) [TBUserConfigManager displaySymbolWithOriginalNameCN: (nameCN) andOriginalSymbol: (symbol)]

#define TBSymbolFirst ([TBUserConfigManager isSymbolFirstEnable])

@interface TBUserConfigManager : NSObject

+ (NSNumber *)rawIsAllowAudioNotificationNumberValue;
+ (NSNumber *)isAllowAudioNotificationNumberValue;
+ (NSNumber *)phoneIsAllowAudioNotificationNumberValue;

+ (BOOL)isAllowAudioNotification;
+ (void)setIsAllowAudioNotification:(NSNumber *)value;
+ (void)updateIsAllowAudioNotification:(NSNumber *)value;


+ (BOOL)isAllowExponentItemNotification;
+ (void)setIsAllowExponentItemNotification:(NSNumber *)value;

// 是否显示千分位符号
+ (BOOL)isDisplayNumberThousand;
+ (void)setIsDisplayNumberThousand:(NSNumber *)value;

//是否震动提醒
+ (BOOL)isAllowVibrateNotification;
+ (void)setIsAllowVibrateNotification:(NSNumber *)value;

//下单搜索历史
+ (NSArray *)placeOrderSearchHistory;
+ (void)setPlaceOrderSearchHistory:(NSArray *)array;
//获取当前用户可开账户类型数量
//+ (NSUInteger)getUserOpenAccountTypeCount;

// 从登录返回的账户数据返回用于神策统计的status值, 多账户取最高值
// 取值为: 匿名, 注册, 开户, 入金
+ (NSString *)SA_getUserStatusFromSigninData:(NSDictionary *)data;
/**
 推送设置字典
 
 @return 推送设置字典
 */
+ (NSDictionary *)pushSettingDic;
+ (void)setPushSettingDic:(NSDictionary *)dict;
+ (void)updatePushSettingDic:(NSDictionary *)dict;

/// 是否设置盯盘推送
+ (BOOL)watchAlertsPushSetting;

/// key对应推送开关是否打开
+ (BOOL)isPushSettingOpenForKey:(NSString *)key;

/**
 是否设置股价异常提醒
 
 @return YES:设置股价异常提醒 NO:没设置
 */
+ (BOOL)setPriceWarningNotifation;

/// dev环境神策是否在输出栏显示log
/// @param enableLog 能否显示log
+ (void)setDevSensorsEnableLogger:(BOOL)enableLog;
+ (BOOL)fetchDevSensorsEnableLogger;

/**
 * 交易资产首页和盈亏分析用户选择的币种
 * @param accountType 品种类型，详见TBOmnibusCurrentAccountType
 * @param omnibus 是否是综合账户 目前区分综合账户(包括模拟账户)和环球账户
 * @return 返回accountType下用户选择的币种，目前没有区分accountType 预留此参数
 */
+ (NSString *)selectedCurrencyOfUserPreference:(TBOmnibusCurrentAccountType)accountType omnibus:(BOOL)omnibus virtualAccount:(BOOL)virtualAccount;

+ (void)setSelectedCurrencyOfUserPreference:(NSString *)currency accountType:(TBOmnibusCurrentAccountType)accountType omnibus:(BOOL)omnibus virtualAccount:(BOOL)virtualAccount;


+ (NSString *)displayNameCNWithOriginalNameCN:(NSString *)nameCN andOriginalSymbol:(NSString *)symbol;
+ (NSString *)displaySymbolWithOriginalNameCN:(NSString *)nameCN andOriginalSymbol:(NSString *)symbol;


//名称代码位置互换
/// symbol是否位于name区域
+ (BOOL)isSymbolFirstEnable; // symbol是否位于首位
+ (void)setSymbolFirstEnable:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
