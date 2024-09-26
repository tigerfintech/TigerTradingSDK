//
//  TBWatchListSectionHeaderItem.h
//  Stock
//
//  Created by liwt on 14/12/29.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//



#import <TBUIKit/TBTableViewCellItem.h>
#import <TBUIKit/TBTableViewCell.h>
#import <TBStockBusinessBaseKit/TBStockListHelper.h>
#import <TBToolsKit/TBWatchListDisplayItem.h>

#define WATCH_LIST_CELL_HEIGHT 26.5


@interface TBWatchListSectionHeaderItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *code;
@property (nonatomic, copy) NSString *price;
@property (nonatomic, copy) NSString *changeRate;
@property (nonatomic, assign) BOOL showSortTag;
@property (nonatomic, assign) BOOL showCodeSort;
@property (nonatomic, assign) BOOL isRealTimeUser;
@property (nonatomic, assign) BOOL showSubcribeStatus;
@property (nonatomic, assign) BOOL hiddenBottomLine;

@property (nonatomic, assign) TBWatchListMarketType marketType;
@property (nonatomic, assign) TBWatchListSortType sortType;

@property (nonatomic, assign) BOOL showPriceSort;
@property (nonatomic, assign) BOOL showChangeRateSort;
@property (nonatomic, assign) BOOL showLandscapeMode;  //是否显示切换到landscape

- (TBWatchListSectionHeaderItem *)applyShowSortTag:(BOOL)showSortTag;

- (TBWatchListSectionHeaderItem *)applyShowCodeSort:(BOOL)showCodeSort;

- (TBWatchListSectionHeaderItem *)applyShowMarketSubscribeStatus:(BOOL)showSubscribeStatus;

- (TBWatchListSectionHeaderItem *)applyIsRealtimeMarketSubscribeUser:(BOOL)isRealtimeUser;

- (TBWatchListSectionHeaderItem *) appplyTitle:(NSString *)code price:(NSString *)price changeRate:(NSString *)changeRate sortType:(TBWatchListSortType) sortType;

- (TBWatchListSectionHeaderItem *)appplyTitle:(NSString *)code price:(NSString *)price changeRate:(NSString *)changeRate sortType:(TBWatchListSortType)sortType marketType:(TBWatchListMarketType)marketType;

- (CGRect)codeFrame;
- (CGRect)priceFrame;
- (CGRect)changeRateFrame;
- (CGRect)landScapeFrame;

@end


@interface TBWatchListSectionHeaderView : TBTableViewCell<UIGestureRecognizerDelegate>



@property (nonatomic, assign) BOOL showSortTag;
@property (nonatomic, assign) BOOL showCodeSort;
@property (nonatomic, assign) BOOL showPriceSort;
@property (nonatomic, assign) BOOL showChangeRateSort;

@property (nonatomic, strong) UIView *codeView;
@property (nonatomic, strong) UIView *priceView;
@property (nonatomic, strong) UIView *changeRateView;
@property (nonatomic, strong) UIView *bottomLine;
@property (nonatomic, strong) UIButton *landscapeButton;
@property (nonatomic, assign) BOOL isRealTimeUser;
@property (nonatomic, assign) BOOL showSubcribeStatus;

@property (nonatomic, assign) TBWatchListSortType sortType;
@property (nonatomic, assign) TBWatchListMarketType marketType;

@property (nonatomic, strong) UILabel *codeLabel;
@property (nonatomic, strong) UILabel *priceLabel;
@property (nonatomic, strong) UILabel *changeRateLabel;

@property (nonatomic, strong) UIImageView *codeSort;
@property (nonatomic, strong) UIImageView *priceSort;
@property (nonatomic, strong) UIImageView *changeRateSort;

@end
