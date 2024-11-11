//
//  TBStockInfoDetailModel.h
//  Stock
//
//  Created by donggongfu on 15/11/17.
//  Copyright © 2015年 com.tigerbrokers. All rights reserved.
//

#import "TBAHAndHourStockCell.h"
#import "TBOrderHourTradingCell.h" // for @protocol TBOrderHourTradingCell
#import "TBStockDetailPriceTableViewCell.h"
#import "TBStockDetailViewControllerDelegate.h"
#import "TBStockFundamentalCell.h"
#import "TBUStockAskBidTableViewCell.h"
#import <TBBusinessSupportKit/TBStockDetailBaseModel.h>
#import <TBStockKit/TBStock.h>
@class TBStockDetailBriefModel;
@class TBStockDetailGreyMaketModel;
@class TBStockDetailIPODetailModel;
@class TBStockDetailInfoNoticeModel;
@class TBStockDetailNextMarketStatusModel;
@class TBStockDetailSplitModel;
@class TBStockInfoAskBidIPODataModel;
@class TBStockInfoDetailUlStockModel;
@class TBStockRightOfferModel;
/**
 个股详情页美港股model
 */
@interface TBStockSymbolChangeModel : JSONModel
@property (nonatomic, copy) NSString<Optional> *executeDate;
@property (nonatomic, copy) NSString<Optional> *snewSymbol;
@end

@interface TBStockBulkOrderModel : JSONModel
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *strike;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, strong) NSNumber *volume;
@property (nonatomic, strong) NSNumber *amount;
@property (nonatomic, assign) BOOL call;
@property (nonatomic, strong) NSNumber *expireDate;
@property (nonatomic, strong) NSNumber *price;
@property (nonatomic, strong) NSNumber *timestamp;
@end

@protocol TBStockBulkOrderModel;
@interface TBStockOptionDataModel :JSONModel
@property (nonatomic, copy) NSArray <TBStockBulkOrderModel> *bulkOrders;
@end



@interface TBStockInfoDetailItemHourTradingModel : TBStockDetailBaseModel

@property (nonatomic, copy) NSString<Optional> *tag;
@property (nonatomic, copy) NSString<Optional> *latestTime;
@property (nonatomic, strong) NSNumber<Optional> *volume;
@property (nonatomic, strong) NSNumber<Optional> *amount;
@property (nonatomic, strong) NSNumber<Optional> *timestamp;

@end

@interface TBStockDetailGreyMaketModel : JSONModel
@property (nonatomic, strong) NSNumber *showGreyQuote;     //是否展示暗盘行情
@property (nonatomic, strong) NSNumber *greyClosingTime;
@property (nonatomic, copy) NSString *greyDate;
@property (nonatomic, strong) NSNumber *greyClose;
@property (nonatomic, strong) NSNumber *greyOpeningTime;
@property (nonatomic, copy) NSString *openProspectusDate;
@property (nonatomic, copy) NSString *listingDate;

@end

@interface TBStockInfoDetailUlStockModel : TBStockDetailBaseModel<TBOrderHourTradingCell>

@property (nonatomic, assign) NSTimeInterval timestamp;
@property (nonatomic, assign) NSInteger delay;

@end

@interface TBStockRightOfferModel : JSONModel
@property (nonatomic, copy) NSString *rightsSymbol;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *firstDealingDate;
@property (nonatomic, copy) NSString *lastDealingDate;

@end

@interface TBStockRelateForexModel : TBStockDetailBaseModel
@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) NSNumber *timestamp;
@property (nonatomic, strong) NSNumber *avgPrice;

@end
@protocol TBStockRelateForexModel;
@protocol TBStockInfoDetailItemModel
@end

@interface TBStockInfoDetailItemModel : TBStockDetailBaseModel <TBStockDetailPriceTableViewCell, TBStockFundamentalCellDelegate, TBAHAndHourStockCellDelegate, TBUStockAskBidTableViewCell,TBStockDetailViewControllerDelegate>
@property (nonatomic, copy) NSString *optionSymbol;

@property (nonatomic, copy) NSString *nameEN;

@property (nonatomic, strong) NSNumber<Optional> *timestamp;    // 发布时间
@property (nonatomic, strong) NSNumber<Optional> *adjPreClose;  // 盘前交易时段为调整后的昨日收盘价，其他时段与preClose相同
@property (nonatomic, strong) NSNumber<Optional> *floatShares;  // 流通股本
@property (nonatomic, strong) NSNumber<Optional> *shares;       // 总股本
@property (nonatomic, strong) NSNumber<Optional> *eps;          // 每股收益
@property (nonatomic, strong) NSNumber<Optional> *ttmEps;          // 每股收益(港股暗盘使用)

@property (nonatomic, strong) NSNumber<Optional> *tradingStatus;
@property (nonatomic, copy) NSString<Optional> *marketStatus;   // 市场状态 (未开盘, 交易中, 休市等)
@property (nonatomic, strong) NSNumber *overnightSupported;
@property (nonatomic, copy) NSString<Optional> *latestTime;
@property (nonatomic, strong) NSNumber<Optional> *open;         // 开盘价
@property (nonatomic, strong) NSNumber<Optional> *high;         // 最高价
@property (nonatomic, strong) NSNumber<Optional> *low;          // 最低价
@property (nonatomic, strong) NSNumber<Optional> *volume;       // 成交量
@property (nonatomic, strong) NSNumber<Optional> *amount;       // 成交额
@property (nonatomic, strong) NSNumber<Optional> *amplitude;    // 振幅
@property (nonatomic, strong) NSNumber<Optional> *askPrice;     // 卖一档价格
@property (nonatomic, strong) NSNumber<Optional> *askSize;      // 卖一档数量
@property (nonatomic, strong) NSNumber<Optional> *bidPrice;     // 买一档价格
@property (nonatomic, strong) NSNumber<Optional> *bidSize;      // 买一档数量
@property (nonatomic, strong) NSNumber<Optional> *shortable;
@property (nonatomic, strong) NSNumber<Optional> *etf;
@property (nonatomic, copy) NSString<Optional> *exchange;
@property (nonatomic, strong) NSNumber<Optional> *lotSize;      // 每手股数
@property (nonatomic, strong) NSNumber<Optional> *lotSizeScale;      // 小数量值（适用于数字货币中，realLotSize=lotSize/lotSizeScale)
@property (nonatomic, strong) NSNumber<Optional> *spreadScale;  // 报价精度, 0代表按价格区间决定精度, 1代表固定精度
@property (nonatomic, copy) NSString<Optional> *tradeCurrency;  // 交易货币代号
@property (nonatomic, copy) NSString<Optional> *symbolType;  // 跟A股一样加个字段  "symbolType": "index",  有这个字段且值是index就表示指数
@property (nonatomic, copy) NSString<Optional> *referMainSymbol;  //拆合股临时代码关联的主代码
@property (nonatomic, copy) NSString<Optional> *referTempSymbol;  //拆合股临时代码

@property (nonatomic, strong) NSNumber<Optional> *monthLow;       // 月最高
@property (nonatomic, strong) NSNumber<Optional> *monthHigh;
@property (nonatomic, strong) NSNumber<Optional> *weekHigh;       // 周最高
@property (nonatomic, strong) NSNumber<Optional> *weekLow;

@property (nonatomic, strong) TBStockDetailInfoNoticeModel<Optional> *notice;                       // 股票公告
@property (nonatomic, strong) TBStockDetailNextMarketStatusModel<Optional> *nextMarketStatus;   // 下一市场状态
@property (nonatomic, strong) TBStockInfoDetailItemHourTradingModel<Optional> *hourTrading;             // 盘前盘后行情条数据
@property (nonatomic, strong) TBStockInfoDetailItemHourTradingModel<Optional> *overnightTrading;             // 夜盘行情条数据

@property (nonatomic, strong) TBStockDetailBriefModel<Optional> *astockBrief;             // A-H股对应的A股行情
@property (nonatomic, strong) NSNumber<Optional> *serverTime;  // 服务器时间

@property (nonatomic, strong) TBStockSymbolChangeModel<Optional> *symbolChange;
@property (nonatomic, strong) TBStockDetailSplitModel<Optional> *split;

@property (nonatomic, strong) TBStockDetailGreyMaketModel *greyMarketDetail;

@property (nonatomic, assign) BOOL adr;
@property (nonatomic, strong) NSNumber<Optional> *adrRate;
@property (nonatomic, strong) NSNumber *volumeRation; // 量比

@property (nonatomic, copy) NSString *symbolChangeStr;

@property (nonatomic, assign) BOOL structuredFlag;//是否有FCN

//ETF对应属性
@property (nonatomic, strong) NSNumber<Optional> *sharesOutstanding;  // ETF流通份额
@property (nonatomic, strong) NSNumber<Optional> *nav;  // ETF资金净值
@property (nonatomic, strong) NSNumber<Optional> *bidAskSpread;  // ETF日均差价
@property (nonatomic, strong) NSNumber<Optional> *dividendRate;  // 股息收益率

//窝轮牛熊证属性
@property (nonatomic, strong) NSNumber<Optional> * type;            //窝轮牛熊证具体类型 1：认购证 2：认沽证 3： 牛证 4： 熊证
@property (nonatomic, copy) NSString<Optional> *typeString;
@property (nonatomic, strong) NSNumber<Optional> * inOutPrice;      //价内/价外
@property (nonatomic, strong) NSNumber<Optional> * strike;          //行权价
@property (nonatomic, strong) NSNumber<Optional> * callPrice;       //回收价（仅牛熊证），该key可能不存在
@property (nonatomic, strong) NSNumber<Optional> * iv;              //引申波幅（仅窝轮），该key可能不存在
@property (nonatomic, strong) NSNumber<Optional> * beforeCallLevel; //距回收价（仅牛熊证），该key可能不存在
@property (nonatomic, strong) NSNumber<Optional> * premium;         //溢价
@property (nonatomic, strong) NSNumber<Optional> * breakevenPoint;  //打和点
@property (nonatomic, strong) NSNumber<Optional> * entitlementPrice;//换股价
@property (nonatomic, strong) NSNumber<Optional> * delta;           //对冲值（仅窝轮），该key可能不存在
@property (nonatomic, strong) NSNumber<Optional> * entitlementRatio;//换股比率
@property (nonatomic, strong) NSNumber<Optional> * gearing;         //杠杆比例
@property (nonatomic, strong) NSNumber<Optional> * os;              //街货比
@property (nonatomic, strong) NSNumber<Optional> * effectiveGearing;//有效杠杆
@property (nonatomic, strong) NSNumber<Optional> * expireDate;      //到期日
@property (nonatomic, strong) NSNumber<Optional> * lastTradingDate; //最后交易日
@property (nonatomic, copy) NSArray *openAndCloseTimeList; // 交易时间区间

//国债属性
@property (nonatomic, strong) NSNumber<Optional> * ytm; //国债到期收益率
@property (nonatomic, strong) NSNumber<Optional> * askYield;
@property (nonatomic, strong) NSNumber<Optional> * bidYield;
@property (nonatomic, strong) NSNumber<Optional> * remainYears;//剩余年期
@property (nonatomic, strong) NSNumber<Optional> * accruedInterest;//应付利息
@property (nonatomic, strong) NSNumber<Optional> * macDuration;//麦考利久期
@property (nonatomic, strong) NSNumber<Optional> * modDuration;//修正久期
@property (nonatomic, strong) NSNumber<Optional> * convexity;//凸性
@property (nonatomic, strong) NSNumber<Optional> * parValue;//票面价值
@property (nonatomic, strong) NSNumber<Optional> * issueSize;//发行规模
@property (nonatomic, strong) NSNumber<Optional> * issueDate;//发行日期
@property (nonatomic, strong) NSNumber<Optional> * cusip;

//lastTradingDate;
@property (nonatomic, copy) NSString *remains; // 剩余年期(已格式化了，格式为：1Y+30D)
@property (nonatomic, copy) NSString *bondType; ///< 债券类型
@property (nonatomic, copy) NSString *bondTypeName; ///< 债券类型name
@property (nonatomic, copy) NSString *couponFrequency;//派息频率
@property (nonatomic, copy) NSString *issuer;//发行人
@property (nonatomic, copy) NSString *currency;//交易货币
@property (nonatomic, copy) NSString *subType;
@property (nonatomic, copy) NSString *timeZone;
@property (nonatomic, copy) NSString *priority;
@property (nonatomic, copy) NSString *sector;//所属行业
@property (nonatomic, copy) NSString *riskLocation;//风险所在地
@property (nonatomic, copy) NSString *riskRating;  //风险等级R1 R2 R5
@property (nonatomic, assign) BOOL redeemable;
/// 国债属性end

@property (nonatomic, strong) NSArray <TBStockRelateForexModel> *relateForexBriefs;//外汇关联条
/**
 期权数据
 */
@property (nonatomic, strong)TBStockOptionDataModel *optionData;

/**
 窝轮牛熊证 对应正股行情摘要
 */
@property (nonatomic, strong) TBStockInfoDetailUlStockModel *ulStockBrief;

/**
 ipo详情，如果detail数据中有该项数据，则说明该股票处于ipo阶段，则显示ipo详情页，股票上市之后该项数据会消失
 */
@property (nonatomic, strong) TBStockDetailIPODetailModel *ipoDetail;


/**
 股权信息
 */
@property (nonatomic, strong) TBStockRightOfferModel *rights;

/**
 是否为供股权
 */
@property (nonatomic, readonly) BOOL isRights;

/**
 股权提醒文案
 */
@property (nonatomic, readonly) NSString *rightString;

/**
 最后交易时间文案
 */
@property (nonatomic, readonly) NSString *lastTradingTimeString;
@property (nonatomic, readonly) NSString *lastTradingTimeKey;

/*
 拆合股提示字符串
 */
- (NSString *)splitStr;
- (NSString *)splitKey;

/*
 是否退市
 */
- (BOOL)isDelisted;

- (TBStockQuotePromptType)stockSplitOrJoinType;

/**
 Long   上市日期时间戳（该市场当地时间零点），该key可能不存在
 */
@property (nonatomic, strong) NSNumber<Optional> *listingDate;

/**
 是否为IPO当天
 */
@property (nonatomic, assign,readonly, getter=isIPODay) BOOL ipoDay;

/**
 ipo 提醒显示关闭key
 */
@property (nonatomic, readonly) NSString *ipoDayKey;

@property (nonatomic, strong) TBStockInfoAskBidIPODataModel *ipoAskBidModel;

// MARK-52周最高
@property (nonatomic, copy) NSString *week52High;
// MARK-52周最低
@property (nonatomic, copy) NSString *week52Low;

#pragma mark -新加坡DLCs字段

/// 是否是DLC
@property (nonatomic, assign) BOOL dlc;

/// 杠杆倍数
@property (nonatomic, strong) NSNumber *leverage;

/// 方向 long/short
@property (nonatomic, copy) NSString *direction;

/// 安全气囊
@property (nonatomic, strong) NSNumber *airbag;

/// 结算日
@property (nonatomic, strong) NSNumber * finalSettlementDate;
@property (nonatomic, strong) NSNumber<Optional> *intrinsicClose;  // 内部收盘价

#pragma mark -- 板块相关
@property (nonatomic, copy) NSString *bkCode;
@property (nonatomic, copy) NSString *packageId;
@property (nonatomic, copy) NSString *packageName;

/// 涨家数
@property (nonatomic, strong) NSNumber * up;

/// 平家数
@property (nonatomic, strong) NSNumber * flat;

/// 跌家数
@property (nonatomic, strong) NSNumber * down;

/// 市盈率
@property (nonatomic, strong) NSNumber * peRate;

/// 市净率
@property (nonatomic, strong) NSNumber * pbRate;

/// 总市值
@property (nonatomic, strong) NSNumber * marketCap;

/// 流通市值
@property (nonatomic, strong) NSNumber * floatMarketCap;

/// 均价
@property (nonatomic, strong) NSNumber * avgPrice;

/// 换手率
@property (nonatomic, strong) NSNumber * turnoverRate;

/// 为行情添加埋点，用于优化股票搜索
@property (nonatomic, copy) NSString *sid;

/// 发行日期
@property (nonatomic, strong) NSNumber * couponDate;
/// 发行利率
@property (nonatomic, strong) NSNumber * couponRate;
/// 过期日期
@property (nonatomic, strong) NSNumber * maturityDate;
/// 发行价
@property (nonatomic, strong) NSNumber * issuePrice;

// 股价提醒价格. 用于绘制预警线.
@property (nonatomic, copy) NSArray<NSNumber *> *thresholds;

@end


@interface TBStockInfoDetailModel : JSONModel

@property (nonatomic, assign) NSInteger ret;    // 错误码
@property (nonatomic, assign) long long serverTime;  // 服务器时间
@property (nonatomic, copy) NSArray<TBStockInfoDetailItemModel> *items;

@end
