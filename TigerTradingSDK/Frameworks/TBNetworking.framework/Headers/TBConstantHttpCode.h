//
//  ConstantHttpCode.h
//  Stock
//
//  Created by liwt on 10/8/15.
//  Copyright © 2015 com.tigerbrokers. All rights reserved.
//

#ifndef TBConstantHttpCode_h
#define TBConstantHttpCode_h

// TRADE SERVER ERROR CODE
// http://wiki.tigerbrokers.net/pages/viewpage.action?pageId=2883888
const static NSInteger ERROR_TRADE_TIME_OUT                   = -1001;            // 超时

const static NSInteger ERROR_TRADE_COMMON                   = 10000;            // 通用错误
const static NSInteger ERROR_TRADE_ERROR                    = 20001;            // 接口逻辑错误
const static NSInteger ERROR_TRADE_ACCOUNT_NOT_EXIST        = 20002;            // 通过 TradeToken 无法找到 account
const static NSInteger ERROR_TRADE_ORDER_NOT_EXIST          = 20003;            // 订单为空或者通过 account 和 orderId 找不到订单

const static NSInteger ERROR_TRADE_MARGIN                   = 20005;            // 校验订单异常, IB 无返回
const static NSInteger ERROR_TRADE_ACCOUNT_NOT_SAME         = 20006;            // 账户不一致. 订单, accessToken, tradeToken 对应的 account 信息不一致
const static NSInteger ERROR_TRADE_ACCOUNT_NOT_LOGIN        = 20007;            // 交易账号未登录, accessToken 无法找到 account
const static NSInteger ERROR_TRADE_ORDER_DUPLICATE          = 20008;            // 重复的订单 Id, orderId 已存在或者 orderId 不在已产生的 Id 列表中
const static NSInteger ERROR_TRADE_NO_TRADER                = 20009;            // account 找不到对应的 Gateway (account 未生效或者 gateway 断开)
const static NSInteger ERROR_TRADE_WHATIF_ORDER             = 20010;            // 校验订单异常, IB 返回错误码 (errorCode)
const static NSInteger ERROR_TRADE_ORDER_CANNOT_MODIFIED    = 20011;            // 订单不是有效订单 (有效订单指订单状态为 PreSubmitted, PendingCancel, Submitted, PendingSubmit; 取消订单时, 存在时间超过 10s 的 -1 订单, 也为有效订单)
const static NSInteger ERROR_TRADE_CANNOT_CONNECT_TO_IB     = 20013;            // 无法连接 IB, 停止接收订单操作, 一般是周末非交易时间
// 40xxx 校验订单异常, IB返回错误码 (errorCode)


const static NSInteger ERROR_TRADE_ORDER_NOT_MATCH                         = 20004;
const static NSInteger ERROR_TRADE_DAY_TRADE_LIMITED                       = 20012;

const static NSInteger ERROR_WATCHLIST_COMMON                              = 10001;
const static NSInteger ERROR_WATCHLIST_EMPTY                               = 10002;
const static NSInteger ERROR_WATCHLIST_EXIST                               = 10003;
const static NSInteger ERROR_MARKET_DATA_SUBSCIBE                          = 10004;
const static NSInteger ERROR_WATCH_LIST_EXCEED_LIMIT                       = 10005;

//
const static NSInteger ERROR_QUOTE_PERIOD                                  = 30000;
const static NSInteger ERROR_QUOTE_NO_DATA                                 = 30001;
const static NSInteger ERROR_QUOTE_UNKNOWN                                 = 30002;
const static NSInteger ERROR_QUOTE_SYMBOL_HAS_NO_QUOTE                     = 30003;
//
//

// OAUTH server error code.
const static NSInteger ERROR_CLIENTID_NOTEXIST                             = 10101;
const static NSInteger ERROR_CLIENTID_NOTMATCH                             = 10102;
const static NSInteger ERROR_POST_NOTALL                                   = 10201;
const static NSInteger ERROR_AUTH_GRANTTYPE_WRONG                          = 10301;
const static NSInteger ERROR_AUTH_USER_NOTEXIST                            = 10302;
const static NSInteger ERROR_AUTH_USER_IBNOTEXIST                          = 10303;
const static NSInteger ERROR_AUTH_USSER_PSD_WRONG                          = 10304;
const static NSInteger ERROR_USERNAME_OR_PASSWORD_WRONG                    = 11055;
const static NSInteger kERROR_AUTH_APPNAME_WRONG                            = 11093;//APP包错误：国外包用户在国内包进行登录

// 手机号未注册，跳转到一键注册
const static NSInteger ERROR_NOT_REGISTER                                  = 11087;
const static NSInteger ERROR_RESTRICT_LOGIN                                = 10317; //限制登录
const static NSInteger ERROR_NEW_DEVICE_PHONE                              = 11001;//新设备
const static NSInteger ERROR_NEW_DEVICE_EMAIL                              = 11002;//新设备

const static NSInteger ERROR_GRANT_NOTSCOPES                               = 10401;
const static NSInteger ERROR_GRANT_PSDWRONG                                = 10402;
const static NSInteger ERROR_TOKEN_ACCESS_WRONG                            = 10501;
const static NSInteger ERROR_TOKEN_REFRESH_WRONG                           = 10502;
const static NSInteger ERROR_TOKEN_ACCESS_EXPIRED                          = 10503;


const static NSInteger ERROR_TOKEN_ACCESS_OTHER_LOGIN                      = 10504;
const static NSInteger ERROR_TOKEN_ACCESS_OTHER_REFRESH                    = 10505;
const static NSInteger ERROR_TOKEN_REFRESH_OTHER_LOGIN                     = 10506;
const static NSInteger ERROR_TOKEN_REFRESH_OTHER_REFRESH                   = 10507;
const static NSInteger ERROR_TOKEN_ACCESS_USER_CHANGE_PWD                  = 10508;
const static NSInteger ERROR_TOKEN_REFRESH_USER_CHANGE_PWD                 = 10509;


const static NSInteger ERROR_TRADE_PSD_WRONG                               = 10601;
const static NSInteger ERROR_TRADE_PSD_EXIST                               = 10602;
const static NSInteger ERROR_TRADE_PSD_FAIL                                = 10603;
const static NSInteger ERROR_TRADE_PSD_NOTSAME                             = 10604;
const static NSInteger ERROR_TRADE_PSD_NOTRIGHT                            = 10605;
const static NSInteger ERROR_TRADE_PSD_FROZEN                              = 10606;
const static NSInteger ERROR_ID_NUMBER_WRONG                               = 10607;
const static NSInteger ERROR_VERIFY_CODE_EXPIRED                           = 10608;
const static NSInteger ERROR_VERIFY_CODE_WRONG                             = 10609;
//

const static NSInteger ERROR_TRADE_SERVER_MAINTAIN                         = 10701;

// auth 服务维护中，暂时无法登录
const static NSInteger ERROR_AUTH_SERVER_MAINTAIN                         = 10702;

//注册.
const static NSInteger ERROR_USER_HAS_REGISTER                             = 11081;
const static NSInteger ERROR_USER_PASSWORD_LENGTH_WRONG                    = 11064;
const static NSInteger ERROR_INVITE_CODE_NOT_EXIST                         = 10804;
const static NSInteger ERROR_EVENT_CODE_NOT_EXIST                          = 10805;
const static NSInteger ERROR_SERVER_INTERNAL_ERROR                         = 10806;
const static NSInteger ERROR_SERVER_INTERNAL_ERROR2                        = 10807;
const static NSInteger ERROR_PHONE_PATTERN_WRONG                           = 10808;
const static NSInteger ERROR_VERIFY_TOO_FREQUENTLY                         = 11054;
const static NSInteger ERROR_PHONE_NUMBER_NOT_EXIST                        = 10810;
const static NSInteger ERROR_PHONE_NUMBER_UNREGISTERED                     = 10820;
const static NSInteger ERROR_VERIFICATION_CODE_EXPIRED                     = 11043;
const static NSInteger ERROR_VERIFICATION_CODE_WRONG                       = 11044;
const static NSInteger ERROR_NOT_BIND_SNS_ACCOUNT                          = 11202;
const static NSInteger ERROR_ACCOUNT_IS_EXISTED                            = 11203;
const static NSInteger ERROR_ACCESS_TOKEN_WRONG                            = 40504;
const static NSInteger ERROR_CAPTCHA_ERROR                                 = 11014;
const static NSInteger ERROR_CAPTCHA_EMPTY                                 = 11011;
const static NSInteger ERROR_CAPTCHA_GEN_ERROR                             = 11015;
const static NSInteger ERROR_CAPTCHA_INVALID                               = 11013;
const static NSInteger ERROR_CAPTCHA_TIMES_ERROR                           = 11012;

//动态密码
const static NSInteger ERROR_DYNAMIC_PASSWORD_EMPTY                        = 11401;
const static NSInteger ERROR_DYNAMIC_PASSWORD_WRONG                        = 11402;
const static NSInteger ERROR_DYNAMIC_PASSWORD_OPTION_EMPTY                 = 11403;
const static NSInteger ERROR_DYNAMIC_PASSWORD_WRONG_MUCH                   = 11406;

//
// 长连接推送的msg code.
const static NSInteger ORDER_MESSAGE_CANCELLED                             = 202;
//换汇错误
const static NSInteger ERROR_NOT_USE_EXCHANGE_DATA                         = 50000;
const static NSInteger ERROR_NOT_NEED_PAY_BACK                             = 50001;
const static NSInteger ERROR_HAS_BEEN_REPAID                               = 50002;
const static NSInteger ERROR_NOT_SUPPORT_OTHER_CURRENCY                    = 50003;
const static NSInteger ERROR_NOT_SUPPORT_REQUEST                           = 50004;
const static NSInteger ERROR_NOT_TRADE_TIME                                = 50005;
const static NSInteger ERROR_NOT_EXCHANGE_TIME                             = 50006;
const static NSInteger ERROR_NOT_PAY_OFF                                   = 50007;

const static NSInteger FT_REQUEST_SUCCESS_CODE = 60000000;

#endif /* ConstantHttpCode_h */
