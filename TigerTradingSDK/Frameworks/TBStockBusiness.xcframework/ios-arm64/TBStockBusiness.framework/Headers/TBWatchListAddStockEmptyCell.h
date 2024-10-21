//
//  TBWatchListAddStockEmptyCell.h
//  Pods
//
//  Created by zhenglanchun on 2021/7/23.
//  
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBWatchListAddStockEmptyCellItem : TBTableViewCellItem
@property (nonatomic, copy) NSString    * emptyText;
@end

@interface TBWatchListAddStockEmptyCell : TBTableViewCell
@property (nonatomic, strong) UILabel * emptyLabel;
@end

NS_ASSUME_NONNULL_END
