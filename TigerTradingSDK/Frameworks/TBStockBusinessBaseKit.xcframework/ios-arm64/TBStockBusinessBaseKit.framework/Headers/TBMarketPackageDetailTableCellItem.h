//
//  TBMarketPackageDetailTableCellItem.h
//  Stock
//
//  Created by liwt on 6/25/15.
//  Copyright (c) 2015 com.tigerbrokers. All rights reserved.
//


#import <TBUIKit/TBTableViewCell.h>
#import <TBUIKit/TBTableViewCellItem.h>
//#import "TBWatchListTableCellItem.h"


@interface TBMarketPackageDetailTableCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *nameCN;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, strong) NSNumber *latestPrice;
@property (nonatomic, strong) NSNumber *changeRate;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, strong) NSNumber *preClose;

@property (nonatomic, strong) NSNumber *halted;


@property (nonatomic, copy) NSString *topic;
@property (nonatomic, copy) NSString *subTopic;
@property (nonatomic, copy) NSString *tagString;
@property (nonatomic, assign) BOOL isETF;
@property (nonatomic, assign) BOOL hiddeExchangeTag;
@property (nonatomic, assign) BOOL aStockInner;

- (TBMarketPackageDetailTableCellItem *)applyTitle:(NSString *)nameCN symbol:(NSString *)symbol price:(NSNumber *)latestPrice changeRate:(NSNumber *)changeRate marketType:(NSString *)marketType;

- (TBMarketPackageDetailTableCellItem *) applyTopic:(NSString *)topic;
- (TBMarketPackageDetailTableCellItem *) applySubTopic:(NSString *)subTopic;
- (TBMarketPackageDetailTableCellItem *) applyTag:(NSString *)tag;
- (TBMarketPackageDetailTableCellItem *) applyIsETF:(BOOL)isETF;
- (TBMarketPackageDetailTableCellItem *) applyHiddeExchangeTag:(BOOL)hiddeExchangeTag;
- (TBMarketPackageDetailTableCellItem *) applyisAStockInner:(BOOL)astockInner;

//期货特殊情况，五个字段
@property (nonatomic, copy) NSString * displayLastestPrice;
@property (nonatomic, copy) NSString * displayChangeRate;
@property (nonatomic, copy) NSString * displayChangeAmount;  //期货涨跌额


@property (nonatomic, copy) NSString *arriveFrom;

@end

@interface TBMarketPackageDetailTableCell : TBTableViewCell

@property (nonatomic, assign) BOOL isETF;
@property (nonatomic, assign) BOOL isAStockInner;
@property (nonatomic, assign) BOOL hiddeExchangeTag;
@property (nonatomic, copy) NSString *etfTag;
@property (nonatomic, strong) UIImageView *tagView;
@property (nonatomic, strong) UIImageView * watchedImageView;

@end
