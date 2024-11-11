//
//  TBHKOpenIPOModel.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/2/20.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@class TBStockDetailIPODetailModel;
@interface TBHKOpenIPOModel : JSONModel

/// IPO类型：COMMON：普通IPO；PLACING：国际配售
@property (nonatomic, copy) NSString *type;

/// IPO唯一标识
@property (nonatomic, copy) NSString *ipoName;

/// 股票代码
@property (nonatomic, copy) NSString *symbol;

/// 公司名称(多语言)
@property (nonatomic, copy) NSString *companyName;

/// 市场
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *currency;

/*
 OpenIPO状态
 PENDING:尚未开始认购
 OPEN:开放认购中
 LOCKED:已锁定
 CLOSED:认购截止
 ALLOCATED:已完成分配
 CANCELED:已取消
 LIST:已上市
 */
@property (nonatomic, copy) NSString *status;
/// 招股书文件URL
@property (nonatomic, copy) NSString *prospectusUrl;

/// 价格区间-最低价
@property (nonatomic, strong) NSNumber *minPrice;

/// 价格区间-最高价
@property (nonatomic, strong) NSNumber *maxPrice;

/// 预计发行数量
@property (nonatomic, strong) NSNumber *expectedOfferingSize;

/// 最小认购数量
@property (nonatomic, strong) NSNumber *minQty;

/// 融资比例 eg 0.1表示10倍杠杆
@property (nonatomic, strong) NSNumber *marginRate;

/// 中签率
@property (nonatomic, strong) NSNumber *winningRate;


/// 开始认购时间
@property (nonatomic, strong) NSNumber *openingDate;

/** 结束认购时间（公开/国配最晚时间）
 *  - 811 综合账户拆分为commonClosingDate（公开）和financingInfosClosingDate（国配）
 *  - IB接口server未修改（IB没有国配），应然使用这个字段。会在接口处映射到commonClosingDate上
 */
@property (nonatomic, strong) NSNumber *closingDate;

/// 811新增公开配售结束时间
@property (nonatomic, strong) NSNumber *commonClosingDate;
/// 811国际配售结束时间，映射placingIpoInfo.closingDate
@property (nonatomic, strong) NSNumber *placingIpoInfoClosingDate;

/// 分配日期
@property (nonatomic, strong) NSNumber *allotmentDate;

/// 上市日期
@property (nonatomic, strong) NSNumber *listDate;

/// 上市价格
@property (nonatomic, strong) NSNumber *allocationPrice;

/// 基本信息
@property (nonatomic, copy, readonly) NSArray <NSArray *> *items;

@property (nonatomic, weak) TBStockDetailIPODetailModel *ipoDetail;

@property (nonatomic, strong) NSNumber *subscribed;

// IB接口返回的字段，再赋值的时候，会赋值给subscribed
@property (nonatomic, strong) NSNumber *isSubscribed;

/// 813 新增：保荐人
@property (nonatomic, copy) NSString <Optional> *underwriter;
/// 813 新增：最新价格
@property (nonatomic, strong) NSNumber <Optional> *latestPrice;
/// 813新增：预计市值下限（美股）
@property (nonatomic, strong) NSNumber *minForecastMarketValue;
/// 813新增：预计市值上限（美股）
@property (nonatomic, strong) NSNumber *maxForecastMarketValue;
/// 813 新增：是否是IB接口返回的数据
@property (nonatomic, assign) BOOL isIBModel;
/// 813 新增：是否签署过申购协议额
@property (nonatomic, assign) BOOL isSigned;
/// 813 新增：申购 ID
@property (nonatomic, copy) NSString *subscriptionId;

/// 902 新增tradable 是否可申购
@property (nonatomic, assign) BOOL tradable;

@end

NS_ASSUME_NONNULL_END
