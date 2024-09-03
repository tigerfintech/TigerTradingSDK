//
//  TBStockDetailCorporationModel.h
//  Stock
//
//  Created by luopengfei on 2018/8/9.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

/**
 个股详情页公司行动model
 公司行动类别：
 1、拆合股
 2、分红派息
 3、财报
 4、代码变更
 5、
 
 。。。。。
 */

@interface TBStockDetailDelistingModel : JSONModel

/// 默认提醒时间。美股财报分盘前盘后，其余市场、公司行动默认为开盘时间
@property (nonatomic, strong) NSNumber *defaultRemindTime;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *reason;
@property (nonatomic, copy) NSString *announcedDate;
@property (nonatomic, copy) NSString *effectiveDate;

@property (nonatomic, copy, readonly) NSString *delistingPrompt;

@end

/**
 代码变更 model
 */
@interface TBStockDetailSymbolChangeModel : JSONModel

/**
 执行日期，yyyy-MM-dd格式
 */
@property (nonatomic, copy) NSString *executeDate;

/**
 新的股票代码
 */
@property (nonatomic, copy) NSString *snewSymbol;

@property (nonatomic, copy) NSString *symbol; // 原来的symbol
@property (nonatomic, copy) NSString *market;

/// 默认提醒时间。美股财报分盘前盘后，其余市场、公司行动默认为开盘时间
@property (nonatomic, strong) NSNumber *defaultRemindTime;

@end

/**
 拆合股 model
 */
@interface TBStockDetailSplitModel : JSONModel

/**
 执行日期，yyyy-MM-dd格式
 */
@property (nonatomic, copy) NSString *executeDate;

/**
 公司行动后的因子
 */
@property (nonatomic, strong) NSNumber *toFactor;

/**
 公司行动前的因子
 */
@property (nonatomic, strong) NSNumber *forFactor;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *symbol;

@end

/**
 分红派息
 */
@interface TBStockDetailDividendModel: JSONModel
/// 默认提醒时间。美股财报分盘前盘后，其余市场、公司行动默认为开盘时间
@property (nonatomic, strong) NSNumber *defaultRemindTime;

@property (nonatomic, strong) NSNumber *amount; // 分红金额
@property (nonatomic, copy) NSString *payableDate; // 付款日期
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *currency;  // 货币单位
@property (nonatomic, copy) NSString *executeDate; // 执行日期

@end


/**
 个股详情页财报公布model
 */
@interface TBStockDetailEarningsModel : JSONModel
/// 默认提醒时间。美股财报分盘前盘后，其余市场、公司行动默认为开盘时间
@property (nonatomic, strong) NSNumber *defaultRemindTime;
@property (nonatomic, copy) NSString *time; // 财报公告时间

@property (nonatomic, assign) NSTimeInterval date;

@property (nonatomic, copy) NSString *expectedEPS; // 预期每股收益
@property (nonatomic, copy) NSString *reportTime; // 发布时间，可为：盘前、盘后、null
@property (nonatomic, copy) NSString *reportDate; //    财报发布日期


@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *nameCN;
@property (nonatomic, copy) NSString *symbol;


@end

/// 供股权
@interface TBStockDetailRightsModel : JSONModel
@property (nonatomic, copy) NSString *announcementDate;
@property (nonatomic, copy) NSString *date;
@property (nonatomic, copy) NSString *firstDealingDate;
@property (nonatomic, copy) NSString *lastDealingDate;
@property (nonatomic, copy) NSString *recordDate;
@property (nonatomic, copy) NSString *rightsSymbol;
@property (nonatomic, strong) NSNumber *defaultRemindTime;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *nameCN;
@property (nonatomic, copy) NSString *symbol;

@end

@interface TBStockOptionCorporateActionDataModel : JSONModel
@property (nonatomic, strong) TBStockDetailSplitModel *split; // 拆合股
@property (nonatomic, strong) TBStockDetailDividendModel *dividend; // 分红派息
@property (nonatomic, strong) TBStockDetailEarningsModel *earningsCalendar; // 财报公告

@property (nonatomic, strong) TBStockDetailSymbolChangeModel *symbolChange;

@property (nonatomic, strong) TBStockDetailDelistingModel *delisting;

@property (nonatomic, strong) TBStockDetailRightsModel *rights;

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *symbol;
@end


@interface TBStockDetailCorporationModel : JSONModel

@property (nonatomic, assign) NSInteger ret;

@property (nonatomic, assign) long long serverTime;

@property (nonatomic, copy) NSString *msg;

@property (nonatomic, strong) TBStockOptionCorporateActionDataModel *data;

@end
