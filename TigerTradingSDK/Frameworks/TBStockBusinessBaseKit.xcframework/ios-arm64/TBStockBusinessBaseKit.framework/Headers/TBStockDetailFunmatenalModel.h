//
//  TBStockDetailFunmatenalModel.h
//  Stock
//
//  Created by Pengfei_Luo on 16/9/8.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

@interface TBStockDetailFunmatenalModel : JSONModel
@property (nonatomic, copy) NSString *open;
@property (nonatomic, copy) NSString *preClose;
@property (nonatomic, copy) NSString *high;
@property (nonatomic, copy) NSString *low;
@property (nonatomic, copy) NSString *latestPrice;

// MARK-振幅
@property (nonatomic, copy) NSString *amplitude;
// MARK-成交量
@property (nonatomic, copy) NSString *volume;

// MARK-52周最高
@property (nonatomic, copy) NSString *week52High;
// MARK-52周最低
@property (nonatomic, copy) NSString *week52Low;

// MARK-总股本
@property (nonatomic, copy) NSString *shares;

// MARK-流通股本
@property (nonatomic, copy) NSString *floatShares;

// MARK-每股收益
@property (nonatomic, copy) NSString *eps;
@property (nonatomic, copy) NSString *lyrEps;
@property (nonatomic, strong) NSNumber *ttmEps; // 每股收益(TTM)
@property (nonatomic, strong) NSNumber *volumeRatio; // 量比


// MARK-股息
@property (nonatomic, copy) NSString *dividePrice;

// MARK-股息率
@property (nonatomic, copy) NSString *divideRate;

// MARK-机构持有比例
@property (nonatomic, copy) NSString *institutionHeld;

// MARK-公司描述
@property (nonatomic, copy) NSString *descriptions;

// MARK-公司网站
@property (nonatomic, copy) NSString *websiteUrl;

// MARK-主营业务
@property (nonatomic, copy) NSString *business;


/**
 市净率
 */
@property (nonatomic, copy) NSString *pbRate;

/**
 市销率
 */
@property (nonatomic, copy) NSString *psRate;

/**
 资产收益率（ROA）=净利润/总资产
 */
@property (nonatomic, copy) NSString *roa;

// 净资产收益率（ROE）=净利润/总股东权益
@property (nonatomic, copy) NSString *roe;

/**
 *  市盈率
 */
@property (nonatomic, copy) NSString *PE;

@property (nonatomic, strong) NSNumber *forwardPe;//预测pe
@property (nonatomic, strong) NSNumber *forwardEps;//预测eps

#pragma mark --- 伦敦行情使用
@property (nonatomic, copy) NSString *tradeService; // 交易系统
@property (nonatomic, assign) NSInteger exchangeMarketSize; // 市场规模


@end
