//
//  TBStockDetailCorporationModel+StockDetailProtocol.h
//  Stock
//
//  Created by JustLee on 2021/5/31.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBStockBusinessBaseKit/TBStockDetailCorporationModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockDetailCorporationModel (StockDetailProtocol)

@end

@interface TBStockDetailSymbolChangeModel (StockDetailProtocol)

@property (nonatomic, readonly) NSString *symbolChangeDescription; // 代码变更文案

@end

@interface TBStockDetailSplitModel (StockDetailProtocol)

/// 默认提醒时间。美股财报分盘前盘后，其余市场、公司行动默认为开盘时间
@property (nonatomic, readonly) NSNumber *defaultRemindTime;

/**
 展示拆合股文案描述
 */
@property (nonatomic, readonly) NSString *splitDescription;

@property (nonatomic, readonly) NSString *splitKey;

@end


@interface TBStockDetailDividendModel (StockDetailProtocol)

@property (nonatomic, readonly) NSString *dividendDescription; // 分红文案描述
@property (nonatomic, readonly) NSString *dividendKey; // 记录分红事件标识（关闭 提醒）
@property (nonatomic, readonly) NSDate *dividendDate;// 添加日历提醒记录时间

@end


@interface TBStockDetailRightsModel (StockDetailProtocol)


@property (nonatomic, readonly) NSString *rightsDes; // 供股权提示描述
@property (nonatomic, readonly) NSString *rightsKey;
@property (nonatomic, readonly) NSDate *rightsDate;

@end


@interface TBStockDetailEarningsModel (StockDetailProtocol)


@property (nonatomic, readonly) NSString *earningDescription; // 财报公告提示描述
@property (nonatomic, readonly) NSString *earningKey;

@end






NS_ASSUME_NONNULL_END
