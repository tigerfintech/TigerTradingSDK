//
//  TBStockPermissionConstant.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/5/18.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

/*
 股票行情、交易权限常量
 wiki:https://wiki.tigerbrokers.net/pages/viewpage.action?pageId=20620186
 */
#import <Foundation/Foundation.h>

// A股
/// A股股票行情Level0权限 - 香港
UIKIT_EXTERN NSString *const aStockQuoteLv0;
/// A股股票行情Level1权限 - 非香港
UIKIT_EXTERN NSString *const aStockQuoteLv1;



// 英股
/// 伦敦股票行情Level0权限
UIKIT_EXTERN NSString *const ukStockQuoteLv0;
/// 伦敦Lv1 延时
UIKIT_EXTERN NSString *const ukStockQuoteLv1Delay;
/// 伦敦股票行情Level1权限
UIKIT_EXTERN NSString *const ukStockQuoteLv1;


/// 港股
/// 港股股票行情Level0权限
UIKIT_EXTERN NSString *const hkStockQuoteLv0;
/// 港股股票行情Level1权限
UIKIT_EXTERN NSString *const kTBhkStockQuoteLv1;
/// 港股股票行情Level2权限
UIKIT_EXTERN NSString *const hkStockQuoteLv2;
/// 港股股票行情Level2 Limited权限
UIKIT_EXTERN NSString *const hkStockQuoteLv2Limited;



/// 美股
UIKIT_EXTERN NSString *const usStockQuoteLv0;
UIKIT_EXTERN NSString *const kUsStockQuoteDelay; // 美股延时
UIKIT_EXTERN NSString *const usQuoteBasic; // 旧
UIKIT_EXTERN NSString *const usStockQuote; // 旧
UIKIT_EXTERN NSString *const usStockQuoteLimited; // 旧

// 美股OTC权限
UIKIT_EXTERN NSString *const usOtcStockQuoteLv1;
UIKIT_EXTERN NSString *const usOtcStockQuoteLv2;
UIKIT_EXTERN NSString *const usOtcStockQuoteLv0;


// 澳股L2 ： auStockQuoteLv2
// 澳股手刷： auStockQuoteLv0
// 澳股L2 抢占： auStockQuoteLv2Limited
UIKIT_EXTERN NSString *const auStockQuoteLv0;
UIKIT_EXTERN NSString *const auStockQuoteLv2;
UIKIT_EXTERN NSString *const auStockQuoteLv2Limited;

// 新西兰股L2 ： nzStockQuoteLv2
// 新西兰股手刷： nzStockQuoteLv0
UIKIT_EXTERN NSString *const nzStockQuoteLv0;
UIKIT_EXTERN NSString *const nzStockQuoteLv2;

/// L2行情
UIKIT_EXTERN NSString *const usStockQuoteLv2Openbook; // 旧
UIKIT_EXTERN NSString *const usStockQuoteLv2Arca; // 旧
UIKIT_EXTERN NSString *const usStockQuoteLv2Totalview; // 旧


/// 抢占
UIKIT_EXTERN NSString *const usStockQuoteLv2OpenbookLimited; // 旧
UIKIT_EXTERN NSString *const usStockQuoteLv2ArcaLimited; // 旧
UIKIT_EXTERN NSString *const usStockQuoteLv2TotalviewLimited; // 旧


/// 期权
/// 美股期权Lv1
UIKIT_EXTERN NSString *const usOptionQuote; // 旧
UIKIT_EXTERN NSString *const usOptionQuoteLv1;
/// 美股期权Lv1 抢占
UIKIT_EXTERN NSString *const usOptionQuoteLv1Limited;
/// 美股期权Lv2
UIKIT_EXTERN NSString *const usOptionQuoteLv2;
/// 美股期权Lv2 抢占
UIKIT_EXTERN NSString *const usOptionQuoteLv2Limited;



/// 期货
/// 飞虎期货(老虎期货)行情Level0权限
UIKIT_EXTERN NSString *const tigerFuturesQuoteLv0; // 旧
///  Lv1 延时行情
UIKIT_EXTERN NSString *const FuturesQuoteLv1Delay;
/// 飞虎期货(老虎期货)行情Level1权限
UIKIT_EXTERN NSString *const tigerFuturesQuoteLv1; // 旧
/// Level 1 抢占
UIKIT_EXTERN NSString *const tigerFuturesQuoteLv1Limited; // 旧
///  期货LV2
UIKIT_EXTERN NSString *const tigerFuturesQuoteLv2; // 旧
/// 期货Lv2 抢占
UIKIT_EXTERN NSString *const tigerFuturesQuoteLv2Limited; // 旧
/// 飞虎期货(老虎期货)行情Level1+权限
UIKIT_EXTERN NSString *const tigerFuturesQuoteLv1Plus; // 即将废除

/// 新加坡
/// 新加坡实时行情
UIKIT_EXTERN NSString *const siStockQuoteLv1;
/// 新加坡延时行情-中国大陆，香港，台湾，澳门地区
UIKIT_EXTERN NSString *const siStockQuoteLv1Delay;
UIKIT_EXTERN NSString *const siStockQuoteLv2;
UIKIT_EXTERN NSString *const siStockQuoteLv2Limited;

#pragma --mark <交易权限>
/// cn股票交易权限
UIKIT_EXTERN NSString *const cnStockTrade;
/// 新加坡股票交易权限
UIKIT_EXTERN NSString *const sgStockTrade;
/// 伦敦股票交易权限
UIKIT_EXTERN NSString *const ukStockTrade;
/// 港股股票交易权限
UIKIT_EXTERN NSString *const hkStockTrade;
/// 美股股票交易权限
UIKIT_EXTERN NSString *const usStockTrade;
/// 美股期权交易权限
UIKIT_EXTERN NSString *const usOptionTrade;
/// 期货交易权限
UIKIT_EXTERN NSString *const futuresTrade;
/// 碎股交易权限
UIKIT_EXTERN NSString *const usFracShareTrade;
/// 数字货币交易权限
UIKIT_EXTERN NSString *const digitalcurrencyTrade;
/// 新西兰股票交易权限
UIKIT_EXTERN NSString *const nzStockTrade;

/// 澳洲股票交易权限
UIKIT_EXTERN NSString *const auStockTrade;
// 美股OTC交易权限
UIKIT_EXTERN NSString *const usOTCTrade;

// 是否开通了syep权限
UIKIT_EXTERN NSString *const syepTrade;

// 港股暗盘交易权限
UIKIT_EXTERN NSString *const hkGreyTrade;

UIKIT_EXTERN NSString *const sgDLCTrade;

// TBHK窝轮牛熊证交易权限(只用于TBHK)
UIKIT_EXTERN NSString *const warrantsTrade;
UIKIT_EXTERN NSString *const ioptTrade;

// 数字货币ETF美股交易权限
UIKIT_EXTERN NSString *const kUSBtcETFTrade;

// 数字货币ETF港股交易权限
UIKIT_EXTERN NSString *const kHKBtcETFTrade;

/// 基金超市
UIKIT_EXTERN NSString *const fundMallTrade;
/// 闲钱3.0 auto-sweep 权限
UIKIT_EXTERN NSString *const fundAutoSweep;
/// 数字货币期货权限
UIKIT_EXTERN NSString *const digiFuturesTrade;


/// fcn 交易权限
UIKIT_EXTERN NSString *const fcnTrade;

/// 国债交易权限
UIKIT_EXTERN NSString *const kTreasuryTrade;

/// 港股期权权限
UIKIT_EXTERN NSString *const hkOptionQuoteLv0;
UIKIT_EXTERN NSString *const kHkOptionQuoteLv1Delay;
UIKIT_EXTERN NSString *const hkOptionQuoteLv1;
UIKIT_EXTERN NSString *const hkOptionQuoteLv1Limited;
UIKIT_EXTERN NSString *const hkOptionQuoteLv2;
UIKIT_EXTERN NSString *const hkOptionQuoteLv2Limited;


UIKIT_EXTERN NSString *const quoteTypeCoupon;
UIKIT_EXTERN NSString *const quoteTypeBuy;


/// 改名后的key

UIKIT_EXTERN NSString *const usStockQuoteLv1Basic;
UIKIT_EXTERN NSString *const usStockQuoteLv1;
UIKIT_EXTERN NSString *const usStockQuoteLv1Limited;


UIKIT_EXTERN NSString *const usOpenbookStockQuoteLv2;
UIKIT_EXTERN NSString *const usTotalviewStockQuoteLv2;
UIKIT_EXTERN NSString *const usArcaStockQuoteLv2;

///  港股Lv2 非大陆地区
UIKIT_EXTERN NSString *const hkStockQuoteLv2AreaLimited;

UIKIT_EXTERN NSString *const usOpenbookStockQuoteLv2Limited;
UIKIT_EXTERN NSString *const usTotalviewStockQuoteLv2Limited;
UIKIT_EXTERN NSString *const usArcaStockQuoteLv2Limited;

UIKIT_EXTERN NSString *const FuturesQuoteLv1;
UIKIT_EXTERN NSString *const FuturesQuoteLv1Limited;
UIKIT_EXTERN NSString *const FuturesQuoteLv2;
UIKIT_EXTERN NSString *const FuturesQuoteLv2Limited;


/// 数字货币

UIKIT_EXTERN NSString *const dbsDigiccyQuoteLv1;
UIKIT_EXTERN NSString *const dbsDigiccyQuoteLv2;

UIKIT_EXTERN NSString *const kHKCryptoQuoteLv1;

/// 未使用. 用`kCryptoQuoteLv1`代替
UIKIT_EXTERN NSString *const kSICryptoQuoteLv1;

// 整合Binance、OKex等多家交易所的成交数据，行情报价更有代表性
UIKIT_EXTERN NSString *const kCryptoQuoteLv1;


/// TUP marsco 期权交易等级
UIKIT_EXTERN NSString *const usMarscoStockOptionLV1;
UIKIT_EXTERN NSString *const usMarscoStockOptionLV2;
UIKIT_EXTERN NSString *const usMarscoStockOptionLV3;
UIKIT_EXTERN NSString *const usMarscoStockOptionLV4;

/// CFD 权限
UIKIT_EXTERN NSString *const kCFDTrade;
