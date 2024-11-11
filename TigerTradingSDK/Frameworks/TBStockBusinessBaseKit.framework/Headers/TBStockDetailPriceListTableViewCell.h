//
//  TBStockDetailPriceListTableViewCell.h
//  Stock
//
//  Created by luopengfei on 2018/5/24.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

@import TBSwiftComponent;
#import <TBUIKit/TBTableViewCell.h>
@class TBStockDetailPriceListItemModel;

@interface TBStockDetailPriceListTableViewCell : TBTableViewCell

@property (nonatomic, strong) NSNumber *max;
@property (nonatomic, strong) NSNumber *preClose;
@property (nonatomic, strong) NSNumber *latestPrice;
@property (nonatomic, strong) TBStockDetailPriceListItemModel *itemModel;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, copy) NSString *symbol;

@property (nonatomic, strong) UILabel *priceLabel;
@property (nonatomic, strong) UILabel *volumeLabel;
@property (nonatomic, strong) TBStockDetailPriceListView *listView;

@property (nonatomic, strong) UILabel *percentLabel;

// 更新UILayout
- (void)updateUILayout;

@end
