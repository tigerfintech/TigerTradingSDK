//
//  TBMarketPackageTableCellItem.h
//  Stock
//
//  Created by liwt on 15/1/4.
//  Copyright (c) 2015年 com.tigerbrokers. All rights reserved.
//


#import <TBUIKit/TBTableViewCell.h>
#import <TBUIKit/TBTableViewCellItem.h>

//#import "TBWatchListSectionHeaderItem.h"
#import "TBStockListTwoRowCell.h"


typedef NS_ENUM(NSInteger, MarketPackageTableCellNextTarget) {
    MarketPackageTableCellNextTargetStockDetail,    //!< 股票详情
    MarketPackageTableCellNextTargetFilterStock,     //!< 选股器交互
    MarketPackageTableCellNextTargetOptionChain     //!< 选股器交互

};

@interface TBMarketPackageTableCellItem: TBStockListTwoRowCellItem

@property (nonatomic, copy) NSString *nameCN;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, strong) NSNumber *latestPrice;
@property (nonatomic, strong) NSNumber *preClose;
@property (nonatomic, strong) NSNumber *changeRate;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, copy) NSString *value;
@property (nonatomic, assign) NSInteger maxScale;
@property (nonatomic, strong) NSNumber *close; // 盘前价/盘后价，从美股市场-盘前盘后榜进入
@property (nonatomic, assign) BOOL      changeColor;
@property (nonatomic, assign) MarketPackageTableCellNextTarget nextTarget;   //!< 下一页目的地
@property (nonatomic, assign) BOOL hideBottomLine;

- (TBMarketPackageTableCellItem *)applyTitle:(NSString *)nameCN
                                      symbol:(NSString *)symbol
                                       price:(NSNumber *)latestPrice
                                  changeRate:(NSNumber *)changeRate
                                  marketType:(NSString *)marketType
                                     secType:(NSString *)secType
                                    maxScale:(NSInteger)maxScale;

- (TBMarketPackageTableCellItem *)applyTitle:(NSString *)nameCN symbol:(NSString *)symbol price:(NSNumber *)latestPrice changeRate:(NSNumber *)changeRate marketType:(NSString *)marketType;

- (TBMarketPackageTableCellItem *)applyTitle:(NSString *)nameCN symbol:(NSString *)symbol price:(NSNumber *)latestPrice value:(NSString *)value marketType:(NSString *)marketType;

- (void)applyForDisplayProperty;

@property (nonatomic, assign) BOOL hiddenPriceContent;

//
@property (nonatomic, copy) NSString *exposureSector;

@end

@interface TBMarketpackageTableCell : TBStockListTwoRowCell

@end
