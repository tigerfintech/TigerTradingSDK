//
//  TBStockDetailActiveOrderLiteTableViewCell.h
//  TBTradeBusiness
//
//  Created by wind on 2023/7/19.
//

#import "TBStockDetailActiveOrderTableViewCell.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBStockDetailActiveOrderLiteTableViewCell : TBStockDetailActiveOrderTableViewCell

@end

@interface TBStockDetailActiveOrderLiteTableViewCellItem : TBStockDetailActiveOrderTableViewCellItem

- (CGFloat)legViewHeight;

- (CGFloat)upperInfoViewHeight;

@property (nonatomic, assign) BOOL hiddenBottomLine;

@end

NS_ASSUME_NONNULL_END
