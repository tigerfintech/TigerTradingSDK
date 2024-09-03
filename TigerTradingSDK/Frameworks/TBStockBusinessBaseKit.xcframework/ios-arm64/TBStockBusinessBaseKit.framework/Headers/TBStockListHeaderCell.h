//
//  TBStockListHeaderCell.h
//  Stock
//
//  Created by zhenglanchun on 2021/5/20.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
#import "TBStockListHeaderView.h"
@class TBStockListHeaderView;

NS_ASSUME_NONNULL_BEGIN

@interface TBStockListHeaderCellItem : TBTableViewCellItem

// MARK: get方法，子类实现
- (NSNumber *)displayColType;

- (NSString *)displayLeftText;

- (NSString *)displayMiddleOneText;

- (NSString *)displayMiddleTwoText;

- (NSString *)displayRightText;

- (BOOL)displayShowMiddleOneSort;
- (BOOL)displayShowMiddleTwoSort;
- (BOOL)displayShowRightSort;


/// 列的数量，默认3列 （TBStockListViewColType）
@property (nonatomic, strong) NSNumber * colType;

@property (nonatomic, assign) BOOL showAllSortIcon;
@property (nonatomic, assign) BOOL showMiddleOneSort;
@property (nonatomic, assign) BOOL showMiddleTwoSort;
@property (nonatomic, assign) BOOL showRightSort;

@property (nonatomic, copy) NSString *leftText;
@property (nonatomic, copy) NSString *middleOneText;
@property (nonatomic, copy) NSString *middleTwoText;
@property (nonatomic, copy) NSString *rightText;

@property (nonatomic, assign) TBStockListHeaderSortType displaySortType;

- (void)applyForDisplayProperty;

@end

@interface TBStockListHeaderCell : TBTableViewCell

@property (nonatomic, strong) TBStockListHeaderView *stockListHeaderView;

@end

NS_ASSUME_NONNULL_END
