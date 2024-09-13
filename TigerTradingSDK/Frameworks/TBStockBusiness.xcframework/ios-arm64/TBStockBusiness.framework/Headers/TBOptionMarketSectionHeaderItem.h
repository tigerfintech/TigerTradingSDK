//
//  TBOptionMarketSectionHeaderItem.h
//  Stock
//
//  Created by liwt on 2/15/16.
//  Copyright © 2016 com.tigerbrokers. All rights reserved.
//

#import "TBOptionMarketTableCellItem.h"

#define SECTION_SCROLLVIEW_TAG  (10020220)

@interface TBOptionMarketSectionHeaderItem : TBTableViewCellItem

@property (nonatomic, assign) BOOL oneOptionCell;

@property (nonatomic, copy) NSString *strike;
@property (nonatomic, copy) NSString *latestPrice;

@property (nonatomic, copy) NSArray *dataSource;
@property (nonatomic, assign) BOOL scrollEnable;

@property (nonatomic, copy) NSString *strategy;

@end


@interface TBOptionMarketSectionHeaderView : TBTableViewCell<UIScrollViewDelegate,UICollectionViewDelegate,UICollectionViewDataSource>

//
@property (nonatomic, strong) UICollectionView *scrollPartView;
//
@property (nonatomic, strong) UIView *strikeLabelView;
@property (nonatomic, strong) UILabel *strikeLabel;
@property (nonatomic, strong) UILabel *rightLabel;
@property (nonatomic, strong) UIButton *arrowButton;

//

@end
