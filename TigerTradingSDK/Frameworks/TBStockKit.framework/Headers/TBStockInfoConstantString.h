//
//  TBStockInfoConstantString.h
//  Stock
//
//  Created by liwt on 9/24/15.
//  Copyright © 2015 com.tigerbrokers. All rights reserved.
//
#import "TBStockKitMacros.h"

static NSString *STOCK_TYPE_US                                                                = @"us";
static NSString *STOCK_TYPE_CN                                                                = @"cn";
static NSString *STOCK_TYPE_HK                                                                = @"hk";

static NSString *MARKET_US                                                                    = @"US";
static NSString *MARKET_HK                                                                    = @"HK";
static NSString *MARKET_CN                                                                    = @"CN";
static NSString *MARKET_SZ                                                                    = @"SZ";
static NSString *MARKET_SH                                                                    = @"SH";
static NSString *MARKET_MF                                                                    = @"MF";
static NSString *MARKET_SGX                                                                   = @"SGX";
static NSString *MARKET_UK                                                                    = @"UK";
static NSString *MARKET_ALL                                                                   = @"ALL";
static NSString *MARKET_SI                                                                    = @"SI";    /// 新加坡市场
static NSString *MARKET_SG                                                                    = @"SG";
static NSString *MARKET_JP                                                                    = @"JP";
static NSString *MARKET_AU                                                                    = @"AU";    /// 澳大利亚市场
static NSString *MARKET_NZ                                                                    = @"NZ";    /// 新西兰市场
static NSString *MARKET_OTHERS                                                                = @"Others";

static NSString *MARKET_UK_GBP                                                                = @"UK.GBP";
static NSString *MARKET_UK_USD                                                                = @"UK.USD";
static NSString *MARKET_UK_EUR                                                                = @"UK.EUR";

static NSString *EXCHANGE_SSE                                                                 = @"SSE"; //上交所
static NSString *EXCHANGE_SH                                                                  = @"SH";
static NSString *EXCHANGE_SZ                                                                  = @"SZ";
static NSString *EXCHANGE_US                                                                  = @"US";
static NSString *EXCHANGE_HK                                                                  = @"HK";

static NSString *SEG_TYPE_DIGI                                                                = @"DIGI";   //数字货币segType
static NSString *SEG_TYPE_CONSOLIDATED                                                        = @"CONSOLIDATED";
static NSString *SEG_TYPE_SEC                                                                 = @"SEC";
static NSString *SEG_TYPE_FUND                                                                = @"FUND";
static NSString *SEG_TYPE_FUT                                                                 = @"FUT";
static NSString *SEG_TYPE_CFD                                                                 = @"CFD";

static NSString *SEC_GROUP_TYPE_CASH                                                          = @"CASH";
static NSString *SEC_GROUP_TYPE_SEC                                                           = @"SECURITY"; // 证券
static NSString *SEC_GROUP_TYPE_BOND                                                          = @"BOND";
static NSString *SEC_GROUP_TYPE_NOTE                                                          = @"NOTE";
static NSString *SEC_GROUP_TYPE_VAULT                                                         = @"VAULT";
static NSString *SEC_GROUP_TYPE_FUND                                                          = @"FUND";
static NSString *SEC_GROUP_TYPE_PORTFOLIO                                                     = @"PORTFOLIO";

static NSString *SEC_TYPE_OPT                                                                 = @"OPT";    //期权
static NSString *SEC_TYPE_MLEG                                                                = @"MLEG";    //多腿组合期权
static NSString *SEC_TYPE_HKOPT                                                               = @"HKOPT";
static NSString *SEC_TYPE_USOPT                                                               = @"USOPT";
static NSString *SEC_TYPE_POS                                                                 = @"POS";
static NSString *SEC_TYPE_STK                                                                 = @"STK";    //正股
static NSString *SEC_TYPE_WAR                                                                 = @"WAR";    //窝轮
static NSString *SEC_TYPE_IOPT                                                                = @"IOPT";   //牛熊证
static NSString *SEC_TYPE_FUT                                                                 = @"FUT";    // 期货
static NSString *SEC_TYPE_SEC                                                                 = @"SEC";    // 证券
static NSString *SEC_TYPE_FUND                                                                = @"FUND";   //基金
static NSString *SEC_TYPE_DC                                                                  = @"CC";     //数字货币
static NSString *SEC_TYPE_PLATE                                                               = @"PLATE";   //板块
static NSString *SEC_TYPE_BOND                                                                = @"BOND";   //国债
static NSString *SEC_TYPE_BONDS                                                               = @"BOND_YIELD";   //债券收益率
static NSString *SEC_TYPE_FOREX                                                               = @"FOREX";  //外汇
static NSString *SEC_TYPE_CASH                                                                = @"CASH";  //外汇
static NSString *SEC_TYPE_SN                                                                  = @"FCN";   //结构化票据，使用 FCN 标识是 server 历史的坑
static NSString *SEC_TYPE_BTC_ETF_US                                                          = @"us_crypto_nonderivative"; // US BTC ETF
static NSString *SEC_TYPE_BTC_ETF_HK                                                          = @"hk_crypto_nonderivative"; // HK BTC ETF
static NSString *SEC_TYPE_TIGER_VAULT                                                         = @"VAULT";
static NSString *SEC_TYPE_ALL                                                                 = @"ALL";
static NSString *SEC_TYPE_NOTE                                                                = @"NOTE"; // 票据

static NSString *SEC_SUB_TYPE_FCN                                                              = @"FCN";       //固定派息票据
static NSString *SEC_SUB_TYPE_SHF                                                              = @"SHARKFIN";  //鲨鱼鳍票据
static NSString *SEC_SUB_TYPE_ELN                                                              = @"ELN";       //股票挂钩票据

static NSString *ORDER_ACTION_BUY                                                             = @"BUY";
static NSString *ORDER_ACTION_SELL                                                            = @"SELL";
static NSString *ORDER_ACTION_CDP_SELL                                                        = @"CDP_SELL";
static NSString *ORDER_VALID_DATE_DAY                                                         = @"DAY";
static NSString *ORDER_VALID_DATE_GTC                                                         = @"GTC";
static NSString *ORDER_VALID_DATE_OPG                                                         = @"OPG";
static NSString *ORDER_VALID_DATE_GTD                                                         = @"GTD";
static NSString *ORDER_TRADING_SESSION_TYPE_RTH                                               = @"RTH";             // 盘中
static NSString *ORDER_TRADING_SESSION_TYPE_OVERNIGHT                                         = @"OVERNIGHT";       // 夜盘
static NSString *ORDER_TRADING_SESSION_TYPE_PRE_RTH_POST                                      = @"PRE_RTH_POST";    // 盘中+盘前盘后
static NSString *ORDER_TYPE_LMT                                                               = @"LMT";
static NSString *ORDER_TYPE_MKT                                                               = @"MKT";
static NSString *ORDER_TYPE_STP                                                               = @"STP";
static NSString *ORDER_TYPE_STP_LMT                                                           = @"STP_LMT";
static NSString *ORDER_TYPE_TRAIL                                                             = @"TRAIL";
static NSString *ORDER_TYPE_TRAIL_LIMIT                                                       = @"TRAIL_LIMIT";
static NSString *ORDER_TYPE_AM                                                                = @"AM";          //港股竞价单
static NSString *ORDER_TYPE_AL                                                                = @"AL";          //港股竞价限价单
static NSString *ORDER_TYPE_TWAP                                                              = @"TWAP";        //交易时间加权平均价算法单-Time Weighted Average Price
static NSString *ORDER_TYPE_VWAP                                                              = @"VWAP";        //成交量加权平均价算法单-Volume Weighted Average Price
static NSString *ORDER_TYPE_SN_MOC                                                            = @"MOC";         //结构化票据(Structured Notes)-订单类型-Market Close

static NSString *ORDER_TYPE_TRAIL_SPREAD                                                      = @"AMOUNT";  //跟踪止损单价差
static NSString *ORDER_TYPE_TRAIL_PERCANTAGE                                                  = @"PERCENT"; //跟踪止算单百分比

static NSString *ORDER_TYPE_CONDITION                                                         = @"CONDITION_ORDER";///< 条件订单
static NSString *ORDER_TYPE_ATTACHED                                                          = @"ATTACHED_ORDER";///< 附加订单
static NSString *ORDER_TYPE_OCA                                                               = @"OCA_ORDER";///< 括号订单
static NSString *ORDER_TYPE_ATTACHED_OCA                                                      = @"ATTACHED_OCA_ORDER";///< 附加括号订单
static NSString *ORDER_TYPE_MONETARY                                                          = @"MONETARY";///< 按金额下单属性

static NSString *ATTACH_ORDER_TYPE_PROFIT = @"PROFIT";
static NSString *ATTACH_ORDER_TYPE_LOSS = @"LOSS";

static NSString *MONEYNESS_OTM = @"OTM"; // 价外
static NSString *MONEYNESS_ITM = @"ITM"; // 价内

static NSString *RIGHT_CALL = @"CALL";
static NSString *RIGHT_PUT = @"PUT";

static NSString *CURRENCY_GBX = @"GBX";   //英国便士
static NSString *CURRENCY_GBP = @"GBP";   //英国英镑
static NSString *CURRENCY_AUD = @"AUD";   //澳元
static NSString *CURRENCY_SGD = @"SGD";   //新加坡元
static NSString *CURRENCY_EUR = @"EUR";   //欧元
static NSString *CURRENCY_USD = @"USD";   //美元
static NSString *CURRENCY_HKD = @"HKD";   //港币
static NSString *CURRENCY_CNH = @"CNH";   //人民币
static NSString *CURRENCY_CNY = @"CNY";   //人民币
static NSString *CURRENCY_NZD = @"NZD";   //新西兰元
static NSString *CURRENCY_JPY = @"JPY";   //日元
static NSString *CURRENCY_IDR = @"IDR";   //印尼盾

static NSString *HIGH_RISK         = @"HIGH";        //风控危险>90%
static NSString *VERY_HIGH_RISK    = @"VERY_HIGH";   //风控危险>95%
static NSString *HIGHEST_RISK      = @"HIGHEST";     //风控危险>100%
static NSString *LOW_RISK          = @"LOW";         //不危险

static NSString *TIGER_STOCKS_DEFAULT_CUSTOM_SERVICE_TIME                                                  = @"";


static NSString *USER_DEFAULT_KEY_CLOSE_HKSTOCK_FIANCE_PROMPT                                 =
@"userDefaultKeyCloseHKStockFiancePrompt";

static NSString *const USER_DEFAULT_KEY_STOCK_FIANCE_MARKED_KEY = @"userDefaultKeyStockFianceMarkedKey";
