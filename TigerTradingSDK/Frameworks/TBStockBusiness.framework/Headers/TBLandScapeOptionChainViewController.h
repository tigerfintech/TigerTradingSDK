//
//  TBLandScapeOptionChainViewController.h
//  Stock
//
//  Created by dull grass on 2019/12/4.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//
#import <TBUIKit/TBListTableViewController.h>
#import <TBUIKit/TBListTableViewController.h>
#import <TBStockBusinessBaseKit/TBOptionDatePickerView.h>
@class TBOptionDatePickerView;
@class TBOptionExpiryItemModel;
@class TBOptionStockModel;
@class TBOptionChainModel;
@class TBStockDetailCorporationModel;


NS_ASSUME_NONNULL_BEGIN

@interface TBLandScapeOptionChainViewController : TBListTableViewController<TBOptionDatePickerViewDelegate>

@property (nonatomic, strong) TBOptionDatePickerView *datePickerView;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *optionSymbol;

@property (nonatomic, copy) NSString *market;

@property (nonatomic, copy) NSString *symbolCN;
@property (nonatomic, copy) NSString *strategy;//当前策略key，行情用
@property (nonatomic, strong) TBOptionExpiryItemModel *currentExpiry;

@property (atomic, strong) TBOptionStockModel *stockInfoItem;

@property (nonatomic, strong) TBOptionChainModel *optionModel;

@property (nonatomic, strong, readonly) NSTimer *refreshTimer;

@property (nonatomic, assign) NSInteger nearestIndex;

@property (nonatomic, assign) NSInteger seperateIndex;  //!< 分隔cell的index

@property (nonatomic, strong) TBStockDetailCorporationModel *corporationModel;

@property (nonatomic, assign) CGPoint currentScrollViewContentOffset;

@property (nonatomic, assign) BOOL isTOptionMode;

@property (nonatomic, assign) BOOL isIndexOption;

- (BOOL)isScrollEnable;
/// 期权长连接推送列表全部数据缓存
@property (nonatomic, strong) NSMutableDictionary *pairOptionMDict;

- (NSArray *)optionViewTitles;

@end

NS_ASSUME_NONNULL_END
