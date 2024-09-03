//
//  Stock+Number.h
//  TBBaseUtils
//
//  Created by zhengzhiwen on 2021/4/12.
//

#import <TBStockKit/TBStock.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStock (TBFormat)

// --- 价格相关
// 价格formatter
+ (NSString *)formatterPrice:(double)price market:(NSString *)market;
+ (NSString *)formatterPrice:(double)price market:(NSString *)market secType:(NSString *)secType;         // secType 可能只有期权需要
+ (NSString *)formatterPrice:(double)price symbol:(NSString *)symbol market:(NSString *)market secType:(NSString *)secType;
+ (NSNumber *)formatterNumberPrice:(double)price market:(NSString *)market secType:(NSString *)secType;  // secType 可能只有期权需要,返回Number
+ (NSString *)formatterPrice:(double)price symbol:(NSString *)symbol;
+ (NSNumberFormatter *)sharedPriceFormatterSecType:(NSString *)secType market:(NSString *)market price:(NSNumber *)price;

// 默认两位
+ (NSString *)formatterDefaultPrice:(double)price;

+ (NSString *)formatterDefaultPriceValue:(NSNumber *)price;

/// 添加自带前缀符号的价格
+ (NSString *)formatterPrefixPrice:(NSNumber *)price market:(NSString *)market;

/// 获取买股票所需金额的formatter
+ (NSNumberFormatter *)transactionPriceFormatterWithSecType:(NSString *)secType market:(NSString *)market;

+ (NSNumberFormatter *)sharePriceFormatter;

+ (double)doubleValueWithString:(NSString *)string;

+ (NSDecimalNumber *)decimalNumberWithString:(NSString *)string;

// 将change changeRatio拼接一块
+ (NSString *)formatChange:(CGFloat)change ratio:(CGFloat)ratio latestPrice:(CGFloat)latestPrice market:(NSString *)market;
// 涨跌幅formatter
+ (NSString *)formatterChange:(double)change latestPrice:(double)price market:(NSString *)market;
+ (NSString *)formatterChange:(double)change latestPrice:(double)price market:(NSString *)market secType:(NSString *)secType ;
+ (NSString *)formatterDisplayChange:(double)change latestPrice:(double)price market:(NSString *)market secType:(NSString *)secType;
+ (NSNumberFormatter *)sharedChangeFormatter;

// 百分比
+ (NSNumberFormatter *)sharedPercentFormatter;
+ (NSString *)formatterOptionPrice:(NSNumber *)price market:(NSString *)market;


/**
 格式化百分数
 
 @param number 需要格式化的百分数
 @return 保留两位小数2.22%
 */
+ (NSString *)formatterFromPercentNumber:(NSNumber *)number needValuePrefix:(BOOL)needPrefix;

+ (NSString *)formatterFromPercentNumber:(NSNumber *)number factionDigits:(NSUInteger)factionDigits needValuePrefix:(BOOL)needPrefix;

// 格式化大数：（先使用原来的）
// 1、需要格式化万、亿、。。。
// 2、具体展示（使用NSNumberFormatter 进行formatter ）

+ (NSNumberFormatter *)marketValueFormatter;

+ (NSNumberFormatter *)sharedQuantityFormatter;

+ (NSString *)numberFormatterWithNumber:(NSNumber *)number factionDigits:(NSUInteger)factionDigits;

+ (NSString *)numberFormatterWithNumber:(NSNumber *)number factionDigits:(NSUInteger)factionDigits needValuePrefix:(BOOL)needPrefix;

+ (NSNumberFormatter *)numberFormatter;

+ (NSNumberFormatter *)numberFormatter:(BOOL)needPrefix;

+ (NSNumberFormatter *)numberFormatterWithFactionDigits:(NSUInteger)factionDigits;

+ (NSString *)numberFormatterWithNumberString:(NSString *)numberString;

/*
 数字格式化，Decimal or NoStyle
 */
+ (NSNumberFormatterStyle)normalNumberformatterStyle;

// format 成交量
+ (NSString *)formatPureVolumeCount:(long long)volume;
+ (NSString *)formatPureVolumeCountWithMultiplier:(long long)volume withMultiplier:(long)multiplier;
+ (NSString *)formatHKStockVolumeCount:(long long)volume;
+ (NSString *)formatVolumeCount:(long long)volume;
+ (NSString *)formatVolumeCountWithMultiplier:(long long )volume withMultiplier:(long)muliplier;
//数字货币成交量
+ (NSString *)formatVolumeDigitalCurrencyCount:(double)volume;
//深度、明细、分价数字货币成交量，用*省略
+ (NSString *)formatVolumeDigitalStarCount:(double)volume;

+ (NSString *)fortmatFloatNumber:(float) number;
+ (NSString *)fortmatFloatNumber:(float) number decimal:(BOOL)needDecimal;
+ (NSString *)fortmatAskBidNumber:(float)number;

//万亿，并带有小数点精度
+ (NSString *)fortmatFloatNumber:(float)number factionDigits:(NSUInteger)factionDigits;

// format money 相关.
+ (NSString *)emptyCurrencyStyleNumberIntegerFormatString:(double)value;
+ (NSString *)emptyCurrencyStyleNumberFormatString:(double)value;
+ (NSString *)emptyCurrencyPnlStyleNumberFormatString:(double)value;

/**
roundFloor 四舍五入
 @param roundFloor 四舍五入
 @return 四舍五入后的值
 */
+ (NSInteger )formateFromRoundFloor:(CGFloat)roundFloor;

+ (NSString *)formateMaxExchangeNumber:(double)number;

/**
 美元计价的手续费
 
 @param needExchangeCash 需要兑换的货币数目
 @param exchangeRate 汇率
 @return 美元计价的手续费
 */
+ (double)feeExchangeCurrencyNumber:(double)needExchangeCash exchangeRate:(double)exchangeRate;

/**
 格式化货币兑换的数据，保留2位小数

 @param number 需要格式化的数据
 @return 返回保留2位小数后的数据
 */
+ (NSString *)formateFromExchangeNumber:(double)number;

/// 格式化货币兑换的数据，保留2位小数
/// @param number number 需要格式化的数据,向下取整
+ (NSString *)formateFromExchangeFloorNumber:(double)number;

/// 格式化货币兑换的数据，保留2位小数
/// @param number number 需要格式化的数据,向下取整
/// @param truncate 格式化是否截断处理，不四舍五入
+ (NSString *)formateFromExchangeFloorNumber:(double)number truncate:(BOOL)truncate;

+ (NSString *)formateFromExchangeFloorNumber:(double)number truncate:(BOOL)truncate roundMode:(NSNumberFormatterRoundingMode)roundingMode;

/**
 * 格式化数字货币【下单页-常用数量】显示，目前只有数字货币的常用数量包含至多2位小数
 */
+ (NSString *)formateCCQuickQuantityNumber:(double)number;

+ (NSNumberFormatter *)ccquickQuantityFormatter;

/// 数字货币不同币对输入数量的maximumFractionDigits值
+ (NSInteger)getDigitialCurrencyCountMaximumFractionDigitsWithSymbol:(NSString *)symbol;

/// 格式化碎股数量
+ (NSString *)formateFractionalShareCountNumber:(NSNumber *)number;
/// 获取碎股小数最大有效位数
+ (NSInteger)getFractionalShareMaximumFractionDigits;
#pragma mark - DateFormat

+ (NSDate *)dateFromString:(NSString *)string;

/*
 格式化手机系统时区时间
 */
+ (NSString *)longToNSDateLocalFormat:(long long)time format:(NSString *)formaterString;
/// 格式化新加坡时区时间
+ (NSString *)longToNSDateSIFormat:(long long)time format:(NSString *)formaterString;
+ (NSString *)longToNSDateAUFormat:(long long)time format:(NSString *)formaterString;
+ (NSString *)longToNSDateNZFormat:(long long)time format:(NSString *)formaterString;
+ (NSString *)longToNSDateJPFormat:(long long)time format:(NSString *)formaterString;

/// 格式化零时区时间
/// - Parameters:
///   - time: <#time description#>
///   - formaterString: <#formaterString description#>
+ (NSString *)longToNSDateZeroFormat:(long long)time format:(NSString *)formaterString;
// 格式化英国伦敦时区时间
+ (NSString *)longToNSDateUKFormat:(long long)time format:(NSString *)formaterString;
// format 时间， 传入market确定是美东还是北京时间
+ (NSString *)longToDateFormat:(long long)time format:(NSString *)formaterString market:(NSString *)market;
+ (NSString *)formatedDateStringFromTimestamp:(NSTimeInterval)milliseconds withFormat:(NSString *)format market:(NSString *)market;
// format 时间, 美股EST时间
+ (NSString *)longToNSDateFormat:(long long)time format:(NSString *)formaterString;
// format 时间, 中国区时间.
+ (NSString *)longToNSDateCNFormat:(long long)time format:(NSString *)formaterString;
+ (NSTimeInterval)timeStampFormDate:(NSString *)date formatter:(NSString *)formatter market:(NSString *)market;
// 美国区时间
+ (NSString *)enMonthStringFormat:(long long)time;

+ (NSString *)formateExpiryString:(NSString *)expiry market:(NSString *)market;

// 把按照EST时间 format 成的 yyyyMMdd string 转成 timestamp longlong 值.
+ (long long)estNSDateStringToLongLongTimeStamp:(NSString *)formatedString withDateFormat:(NSString *)dateFormat;
+ (long long) hkdNSDateStringToLongLongTimeStamp:(NSString *)formatedString withDateFormat:(NSString *)dateFormat;


#pragma mark - 获取对应时区的dateformatter
+ (NSDateFormatter *)shareUKDateFormatter;
+ (NSDateFormatter *)shareAUDateFormatter;
+ (NSDateFormatter *)shareNZDateFormatter;
+ (NSDateFormatter *)shareHKDateFormatter;
+ (NSDateFormatter *)shareSIDateFormatter;
+ (NSDateFormatter *)shareUSESTDateFormatter;
+ (NSDateFormatter *)shareCNDateFormatter;
+ (NSDateFormatter *)shareJPDateFormatter;
+ (NSDateFormatter *)shareLocalDateFormatter;
+ (NSDateFormatter *)dateFormatterWithZoneID:(NSString *)zoneID formatString:(NSString *)formatString;

#pragma mark - 获取市场所在的时区
/**
 获取市场所在的时区
 
 @param market 市场
 @return 返回时区
 */
+ (NSTimeZone *)timeZoneForMarket:(NSString *)market;

/**
 格式化汇率货币兑换的数据，Omnibus保留4位小数，IB保留2位小数
 
 @param number 需要格式化的数据
 @return Omnibus保留4位小数，IB保留2位小数
 */
+ (NSString *)formateRateExchangeNumber:(double)number;

+ (NSString *)formateStockPrice:(double)price withFractionDigits:(NSUInteger)digits;

+ (NSString *)formatedLocaleDateStringFromTimestamp:(NSTimeInterval)milliseconds format:(NSString *)format market:(NSString *)market;

+ (NSString *)longToNSDateLocalLanguageFormat:(long long)time format:(NSString *)formaterString;

/**
 * 根据sectype 持仓数量获取单位:手
 */
+ (NSString *)unitString:(NSString *)secType position:(double)position;
@end

NS_ASSUME_NONNULL_END
