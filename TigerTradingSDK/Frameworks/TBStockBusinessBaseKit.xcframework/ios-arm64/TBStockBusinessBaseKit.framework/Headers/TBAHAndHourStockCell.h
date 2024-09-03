//
//  TBAHAndHourStockCell.h
//  Stock
//
//  Created by Pengfei_Luo on 16/9/1.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

@class TBStockInfoDetailItemHourTradingModel;
#import <TBUIKit/TBTableViewCell.h>

@protocol TBAHAndHourStockCellDelegate <NSObject>


- (NSString *)AHlatestPriceStr;

/**
 *  🔙涨跌幅相关数组： index 0：str , index 1: color
 *
 */
- (NSArray *)AHchangeStr;

- (NSString *)AHTagStr;

- (NSString *)AHtimeStr;

- (NSString *)changeRateString;

- (NSString *)volumeString;
- (NSString *)amountString;

@optional
- (NSString *)ahSymbol;

- (NSString *)ahMarket;

- (NSString *)ahSecType;


@end

//
@interface TBAHAndHourStockCell : TBTableViewCell

@end

@interface TBAHAndHourStockCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *symbol;

@property (nonatomic, strong) id<TBAHAndHourStockCellDelegate> dataSource;
@property (nonatomic, strong) TBStockInfoDetailItemHourTradingModel *model;
@property (nonatomic, assign) BOOL isNeedResetRightView; //盘前盘后弹窗收起时，需要reset RightView

@end
