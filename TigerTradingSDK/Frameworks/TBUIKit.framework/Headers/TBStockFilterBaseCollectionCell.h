//
//  TBStockFilterBaseCollectionCell.h
//  Stock
//
//  Created by swordzhou on 2020/4/21.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBStockKit/UIImageView+TBStock.h>
#import "TBAPPColorMacro.h"

@class TBObject;
@protocol TBStockFilterBaseCollectionCellDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface TBStockFilterBaseCollectionCell : UICollectionViewCell

@property (nonatomic, weak) id<TBStockFilterBaseCollectionCellDelegate> delegate;

@end

@protocol TBStockFilterBaseCollectionCellDelegate <NSObject>

@optional
- (void) handleActionForCell:(TBStockFilterBaseCollectionCell *)cell item:(TBObject *)object info:(nullable id)info;

@end

NS_ASSUME_NONNULL_END
