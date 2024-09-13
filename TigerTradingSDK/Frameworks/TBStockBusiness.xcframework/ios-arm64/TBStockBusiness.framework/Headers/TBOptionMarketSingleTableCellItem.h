//
//  TBOptionMarketSingleTableCellItem.h
//  Stock
//
//  Created by liwt on 2/15/16.
//  Copyright © 2016 com.tigerbrokers. All rights reserved.
//

#import "TBOptionMarketTableCellItem.h"
@class TBOptionChainItemModel;
@class TBOptionExpiryItemModel;
#import <TBUIKit/TBTableViewCell.h>

@interface TBOptionMarketSingleTableCellItem : TBOptionMarketTableCellItem

@property (nonatomic, copy) NSString *optionType; // 期权类型, call 和 put 时有颜色
@property (nonatomic, assign) double latestPrice; // 股票价格, 用于和行权价比较, 标识不同颜色
@property (nonatomic, assign) BOOL isOld;//是否旧期权
@property (nonatomic, assign) BOOL showSeperate;
@property (nonatomic, assign) BOOL scrollEnable;

@property (nonatomic, assign) BOOL selected;

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, strong) NSNumber *expiry;
@property (nonatomic, copy) NSString *strike;
@property (nonatomic, copy) NSString *right;
@property (nonatomic, copy) NSString *strategy;
@property (nonatomic, copy) NSArray *dataSourceArray;

//唯一标识
@property (nonatomic, copy) NSString *combinedKey;

@end

@interface TBOptionMarketSingleTableCell : TBTableViewCell <UIScrollViewDelegate,UICollectionViewDelegate,UICollectionViewDataSource>

@property (nonatomic, strong) UIView *strikeLabelView;

@property (nonatomic, strong) UIView *optionSelectedBackgroundView;
@property (nonatomic, strong) UICollectionView *scrollPartView;
//
@property (nonatomic, strong) UILabel *strikeLabel;

@end
