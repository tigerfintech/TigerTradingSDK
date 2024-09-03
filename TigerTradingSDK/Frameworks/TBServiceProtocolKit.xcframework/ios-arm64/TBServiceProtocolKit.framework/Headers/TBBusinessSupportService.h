//
//  TBBusinessSupportService.h
//  TBServiceProtocolKit
//
//  Created by linbingjie on 2023/1/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBBusinessSupportService <NSObject>

- (NSString *)tbBusinessSupport_formatVolumeCount:(long long )volume;


- (NSString *)tbBusinessSupport_formatFloatNumber:(float)number;

- (NSString *)tbBusinessSupport_formatPercentNumber:(NSNumber *)number needValuePrefix:(BOOL)prefix;


- (NSString *)tbBusinessSupport_formatVolumeDigitalCurrencyCount:(double)volume;

// 默认两位
- (NSString *)tbBusinessSupport_formatterDefaultPrice:(double)price;


// format 时间， 传入market确定是美东还是北京时间
- (NSString *)tbBusinessSupport_longToDateFormat:(long long)time
                                          format:(NSString *)formaterString
                                          market:(NSString *)market;

- (NSTimeZone *)tbBusinessSupport_timeZoneForMarket:(NSString *)market;

- (BOOL)tbBusinessSupport_isAllowAudioNotification;

- (NSString *)tbBusinessSupport_formatterPrice:(double)price
                                        market:(NSString *)market
                                       secType:(NSString *)secType;         // secType 可能只有期权需要

- (NSDateFormatter *)tbBusinessSupport_shareCNDateFormatter;

// format 时间, 中国区时间.
- (NSString *)tbBusinessSupport_longToNSDateCNFormat:(long long)time
                                              format:(NSString *)formaterString;

- (BOOL)tbBusinessSupport_fetchDevSensorsEnableLogger;

- (void)tbBusinessSupport_setDevSensorsEnableLogger:(BOOL)enableLog;

- (NSString *)tbBusinessSupport_bindBankCardUrl;

// 展示首页交易引导弹窗
- (void)tbBusinessSupport_showHomePagePopupForContratulateNewUserPlaceOrderWithData:(id)data;

// 展示首页交易引导完成弹窗
- (void)tbBusinessSupport_showHomePagePopupForNewUserPlaceorderWithData:(id)data;

// 跳转财报季页
- (void)tbBusinessSupport_gotoTradingSeasonPage;

@end

NS_ASSUME_NONNULL_END
