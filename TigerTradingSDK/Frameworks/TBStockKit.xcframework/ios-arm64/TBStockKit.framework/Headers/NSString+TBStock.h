//
//  NSString+TBStock.h
//  TBBaseUtils
//
//  Created by zhengzhiwen on 2021/4/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (TBStock)

- (BOOL)tb_isLimitOrder;
- (BOOL)tb_isMarketOrder;
- (BOOL)tb_isStopOrder;
- (BOOL)tb_isStopLimitOrder;
- (BOOL)tb_isTrailOrder;
- (BOOL)tb_isAmOrder;       //竞价单
- (BOOL)tb_isAlOrder;       //竞价限价单
/**
 是否是跟踪止损单价差
 */
- (BOOL)tb_isTrailOrderSpread;
/**
 是否是跟踪止损单百分比
 */
- (BOOL)tb_isTrailOrderPercantage;

- (BOOL)tb_isOcaOrder;
- (BOOL)tb_isConditonOrder;
- (BOOL)tb_isAttachOrder;
- (BOOL)tb_isAttachOcaOrder;
- (BOOL)tb_isTWAPOrder;
- (BOOL)tb_isVWAPOrder;
- (BOOL)tb_isMOCOrder;

- (BOOL)tb_isBuyAction;
- (BOOL)tb_isSellAction;
- (BOOL)tb_isCdpSellAction;

- (BOOL)tb_isDAY;
- (BOOL)tb_isGTC;
- (BOOL)tb_isOPG;

/**
 * 是否盘中交易时间段
 */
- (BOOL)tb_isIntradayTrading;
/**
 * 是否夜盘交易时间段
 */
- (BOOL)tb_isOvernightTrading;
/**
 * 是否盘前盘后盘中交易时间段
 */
- (BOOL)tb_isPreRTHPostTrading;

- (BOOL)tb_isGBX;

- (BOOL)tb_isGBP;

- (BOOL)tb_isEUR;

- (BOOL)tb_isUSD;

- (BOOL)tb_isHKD;

- (BOOL)tb_isCNH;

- (BOOL)tb_isAUD;

- (BOOL)tb_isSGD;

- (BOOL)tb_isNZD ;

- (BOOL)tb_isJPY;

- (BOOL)tb_isIDR;

- (BOOL)tb_isLowRISK;

- (BOOL)tb_HIGHRISK;

- (BOOL)tb_VERYHIGHRISK;

- (BOOL)tb_HIGHESTRISK;

- (BOOL)tb_isMarginAccount;
- (BOOL)tb_isCashAccount;

/**
 加入伦敦行情以后，symbol拼接market，产品要求symbol展示不展示market，
 这里处理展示symbol，去掉后面.UK/.UKI等

 @return 处理过展示symbol
 */
- (NSString *)tb_displaySymbol;

- (NSString *)tb_toSegType;

/**
 是否是港股以人民币结算

 @return 是否是港股以人民币结算
 */
- (BOOL)tb_isHKStockCNClose;

// 市场转币种 UK-GBX
- (NSString *)tb_toCurrency;

// 市场转币种UK_GBP
- (NSString *)tb_toCurrency_ukGBP;

/// 货币单位转换成货币名称  USD ---> 美元
- (nullable NSString *)tb_toCNCurrency;

/// @param exchange 是否是换汇
- (nullable NSString *)tb_toCNCurrency:(BOOL)exchange;

/// 货币符号转成文本, 如果没有对应文本返回货币符号.
- (NSString *)tb_toCurrencyTextString;

//货币名称转换成货币单位  美元 ---> USD
- (NSString *)tb_toENShortCurrency;

//将币种转换为全名 例如 USD--->United States dollar
- (NSString *)tb_toFullNameCurrency;
//将币种转换为全名 除 离岸人民币 为 人民币 外，其他与 tb_toFullNameCurrency 相同
- (NSString *)tb_portfolioLiteDisplayFullNameCurrency;
/**
 市场转换成货币符号

 @return  市场转换成货币符号
 */
- (NSString *)tb_toCurrencyUnit;

/**
 市场转EN->CN

 @return 市场中文
 */
- (NSString *)tb_marketToCnName;
// 货币对应符号，USD->$，CNH->¥
- (NSString *)tb_currencySymbol;

- (NSString *)tb_currencySymbol:(BOOL)shortSymbol;

/// market代码转为本地化名称
- (NSString *)tb_toLocalizedMarketName;

/**
 市场对应的icon图标名称
 */
- (NSString *)tb_marketImageName;

/**
 市场对应的icon图标
 */
- (UIImage *)marketImage;

/**
 货币对应的icon图标
 */
- (UIImage *)currencyImage;

/**
 市场对应的货币图标
 */
- (UIImage *)marketCurrencyImage;

/// 闲钱管家对应的货币图标
- (UIImage *)tigerVaultCurrencyImage;

/**
 该方法只能判断股票，期货不适用
 根据symbol判断市场
 */
+ (NSString *)getStockMarketFromSymbol:(NSString *)symbol;

/// 板块代码所属市场
@property (readonly) NSString *tb_bkCodeMarket;

/// 根据 currency 返回对应的 market
- (NSString *)marketForCurrency;

/// 是否为板块
/// 规则: BK前缀 + 1位数字市场代码 + 3位数字代码
- (BOOL)isMarketPlate;

/// 是否为行业
/// 可以根据bkCode里BK2X01里面的X判断，X<5是行业，X>=5是概念
- (BOOL)isMarketIndustry;

- (BOOL)tb_isStock;
- (BOOL)tb_isOption;
- (BOOL)tb_isMleg;
- (BOOL)tb_isUSOption;
- (BOOL)tb_isHKOption;
- (BOOL)tb_isPostion;  //是否是持仓
- (BOOL)tb_isDBSCC; // 是否是DBSCC的标的

/// 是否是现金
- (BOOL)tb_isCash;

/**
 是否是窝轮
 */
- (BOOL)tb_isWar;

/**
是否是基金
*/
- (BOOL)tb_isMF;

/**
 是否是牛熊证
 */
- (BOOL)tb_isIOPT;

/**
 是否为期货
 */
- (BOOL)tb_isFutures;

/**
 是否为证券
 */
- (BOOL)tb_isSecurities;

/**
 是否为板块
 */
- (BOOL)tb_isPlate;

/**
是否为数字货币
*/
- (BOOL)tb_isDigitalCurrency;

/**
是否为数字货币segment
*/
- (BOOL)tb_isDigitalSegType;

/**
 909版本及之前：BOND代表债券收益率
 910版本及之后：BOND代表国债，BONDS代表债券收益率
 是否为国债
*/
- (BOOL)tb_isBond;
- (BOOL)tb_isBondSymbol;//慎用，我们希望控制方法的使用范围

/**
是否为债券收益率
*/
- (BOOL)tb_isBonds;
- (BOOL)tb_isBondsSymbol;//慎用，我们希望控制方法的使用范围

/**
是否为外汇
*/
- (BOOL)tb_isForex;
- (BOOL)tb_isForexSymbol;

/**
 是否为窝轮/牛熊证
 */
- (BOOL)tb_isWarOrIOPT;


- (BOOL)tb_isStructedNote;
- (BOOL)tb_isFCN;
- (BOOL)tb_isSHF;
- (BOOL)tb_isELN;
- (BOOL)tb_isBtcEtf;
- (BOOL)tb_isUSBtcEtf;
- (BOOL)tb_isHKBtcEtf;
- (BOOL)tb_isFund;
- (BOOL)tb_isUsMarket;
- (BOOL)tb_isHkMarket;
- (BOOL)tb_isUkMarket;
- (BOOL)tb_isCnMarket;
- (BOOL)tb_isSIMarket;  /// 新加坡市场
- (BOOL)tb_isAUMarket;  /// 澳大利亚市场
- (BOOL)tb_isNZMarket;  /// 新西兰市场
- (BOOL)tb_isJPMarket;  /// 日本 东京交易所
- (BOOL)tb_isALL;

- (NSString *)tb_timeZoneString;

- (NSString *)tb_toDisplayAction;

/// secGroupType == SECURITY
- (BOOL)tb_isSecuritiesGroupType;

- (BOOL)tb_isTigerVaultGroupType;

/// 是否为票据note
- (BOOL)tb_isNote;

/// 是否是已支持的票据类型
- (BOOL)isSupportedStructedNote;

@end

NS_ASSUME_NONNULL_END
