//
//  TBOptionTabBulkOrderContentCell.h
//  Stock
//
//  Created by mashanli on 2023/6/19.
//  Copyright © 2023年 com.tigerbrokers. All rights reserved.
//
@class TBOptionTabIndicatorModel;
#import <TBUIKit/TBTableViewCell.h>

@interface TBOptionTabBulkOrderContentCell : TBTableViewCell

@end


@interface TBOptionTabBulkOrderContentCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *dayTime; // MM/dd
@property (nonatomic, copy) NSString *tradeTimeStamp; // hh:mm:ss
@property (nonatomic, copy) NSString *contract;
@property (nonatomic, copy) NSArray<NSNumber *> *unusualTag;//异动标签，1.财报单 2.买入 3.卖出
@property (nonatomic, copy) NSArray<TBOptionTabIndicatorModel *> *indicators;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *strike;
@property (nonatomic, copy) NSString *right;
@property (nonatomic, copy) NSNumber *expiry;
@property (nonatomic, assign) BOOL isTab;//tab页，还是二级页
@property (nonatomic, assign) BOOL hiddenUpLine;

@property (nonatomic, copy) NSString *arriveFrom;

@end
