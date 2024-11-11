//
//  TBStockLandSearchModel.h
//  Stock
//
//  Created by Pengfei_Luo on 16/10/13.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

@class TBTableViewCellItem;
@interface TBStockLandSearchModel : JSONModel

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *nameCN;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, strong) NSNumber *contractId;

@property (nonatomic, strong) NSNumber *preClose;
@property (nonatomic, strong) NSNumber *latestPrice;
@property (nonatomic, strong) NSNumber *halted;
@property (nonatomic, strong) NSNumber *timestamp;

@property (nonatomic, strong) NSNumber *type;   //type: 数据类型 0代表股票，1代表板块，2代表窝轮牛熊证链表，3代表窝轮，4代表牛熊证，5代表期货，6代表OTC， 8代表基金

@property (nonatomic, strong) NSNumber *changeRate;

@property (nonatomic, strong) NSNumber *maxScale;

@property (nonatomic, strong) NSNumber *isInWatchList;

@property (nonatomic, copy) NSString *volume;
@property (nonatomic, copy) NSString *latestTime;

@property (nonatomic, copy) NSString *displayLatestPrice;
@property (nonatomic, copy) NSString *displayChangeRatio;

/**
 是否在叠加列表
 */
@property (nonatomic, strong) NSNumber *isInCompareList;
- (void)updateWithTableViewCellItem:(TBTableViewCellItem *)tableViewCellItem;

@end
