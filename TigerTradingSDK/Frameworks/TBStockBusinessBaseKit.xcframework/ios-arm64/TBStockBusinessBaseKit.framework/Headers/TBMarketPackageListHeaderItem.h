//
//  TBMarketPackageListHeaderItem.h
//  Stock
//
//  Created by liwt on 11/26/15.
//  Copyright © 2015 com.tigerbrokers. All rights reserved.
//

//#import "TBWatchListSectionHeaderItem.h"
#import "TBStockListHeaderCell.h"
#import "TBStockListHelper.h"

@interface TBMarketPackageListHeaderItem : TBStockListHeaderCellItem

@property (nonatomic, copy) NSString *code;
@property (nonatomic, copy) NSString *price;
@property (nonatomic, copy) NSString *changeRate;

@property (nonatomic, assign) BOOL isRealTimeUser;
@property (nonatomic, assign) BOOL showSubcribeStatus;
@property (nonatomic, assign) BOOL hiddenBottomLine;
@property (nonatomic, assign) BOOL adjustSecondColumnLayoutInEnglish; /// Default:NO
@property (nonatomic, assign) TBWatchListMarketType marketType;
@property (nonatomic, assign) TBWatchListSortType sortType;

@property (nonatomic, assign) BOOL showSortTag;
@property (nonatomic, assign) BOOL showCodeSort;
@property (nonatomic, assign) BOOL showPriceSort;
@property (nonatomic, assign) BOOL showChangeRateSort;
@property (nonatomic, assign) BOOL showLandscapeMode;

@property (nonatomic, assign) BOOL userInteractionEnabled;

@property (nonatomic, assign) BOOL hasHourTradingData;

- (TBMarketPackageListHeaderItem*) applyShowSortTag:(BOOL)showSortTag;

- (TBMarketPackageListHeaderItem *)appplyTitle:(NSString *)code price:(NSString *)price changeRate:(NSString *)changeRate sortType:(TBWatchListSortType)sortType marketType:(TBWatchListMarketType)marketType;

- (TBMarketPackageListHeaderItem *)appplyTitle:(NSString *)code price:(NSString *)price changeRate:(NSString *)changeRate sortType:(TBWatchListSortType)sortType;

@end


@interface TBMarketPackageListHeaderView : TBStockListHeaderCell

@end
