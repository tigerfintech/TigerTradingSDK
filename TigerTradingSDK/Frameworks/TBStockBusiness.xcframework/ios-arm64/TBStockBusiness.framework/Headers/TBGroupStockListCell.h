//
//  TBGroupStockListCell.h
//  Stock
//
//  Created by yangfan on 2017/3/13.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
@class TBWatchListTableCellItem;

@class TBGroupStockListCell;

@protocol TBGroupStockListCellDelegate <NSObject>

@required

- (void)stockListDidTappedSelectedButton:(TBGroupStockListCell *)cell;

- (void)stockListDidTappedGoTopButton:(TBGroupStockListCell *)cell;
- (void)stockListDidTappedToEndButton:(TBGroupStockListCell *)cell;

@end

@interface TBGroupStockListCell : UITableViewCell

@property (nonatomic, strong) TBWatchListTableCellItem          * cellItem;
@property (nonatomic, weak) id<TBGroupStockListCellDelegate>      delegate;
@property (nonatomic, assign)BOOL canEditGroupCell;

@end
