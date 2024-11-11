//
//  TBOptionMarketPairTableCellItem.h
//  Stock
//
//  Created by liwt on 2/17/16.
//  Copyright © 2016 com.tigerbrokers. All rights reserved.
//

@class TBOptionChainItemModel;
#import <TBUIKit/TBTableViewCell.h>


@interface TBOptionMarketPairTableCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *strike;
@property (nonatomic, strong) NSNumber *expiry;

@property (nonatomic, copy) NSString *market;

/// 是否旧期权
@property (nonatomic, assign) BOOL isOld;

/// 对应的策略
@property (nonatomic, copy) NSString *strategy;

@property (nonatomic, copy) NSArray *callDataSource;
@property (nonatomic, copy) NSArray *putDataSource;

@property (nonatomic, strong) NSIndexPath *highlightedIndexPath;

@property (nonatomic, assign) BOOL scrollEnable;

@property (nonatomic, assign) BOOL callSelected;
@property (nonatomic, assign) BOOL putSelected;

//唯一标识
@property (nonatomic, copy) NSString *callCombinedKey;
@property (nonatomic, copy) NSString *putCombinedKey;

@end

@interface TBOptionMarketPairTableCell : TBTableViewCell <UIScrollViewDelegate,UICollectionViewDelegate,UICollectionViewDataSource>

@property (nonatomic, strong) UIView *callSelectedBackgroundView;
@property (nonatomic, strong) UIView *putSelectedBackgroundView;
@property (nonatomic, strong) UICollectionView *scrollPartView;
//
@property (nonatomic, strong) UIView *strikeLabelView;
@property (nonatomic, strong) UILabel *strikeLabel;
@property (nonatomic, strong) UILabel *callLabel;
@property (nonatomic, strong) UILabel *putLabel;

@end
