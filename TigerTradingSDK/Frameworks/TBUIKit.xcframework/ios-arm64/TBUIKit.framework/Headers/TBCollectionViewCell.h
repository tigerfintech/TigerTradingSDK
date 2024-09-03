//
//  TBCollectionViewCell.h
//  Stock
//
//  Created by Pengfei_Luo on 2017/2/27.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBCommonAppColor.h"

@protocol TBCollectionViewCellDelegate;
@class TBCollectionViewCellItem;

@interface TBCollectionViewCell : UICollectionViewCell {
    TBCollectionViewCellItem *_collectionCellItem;
}

@property (nonatomic, weak) id<TBCollectionViewCellDelegate> delegate;

@property (nonatomic, assign, readonly) TBAppColorStyle colorStyle;

@property (nonatomic, strong) TBCollectionViewCellItem *collectionCellItem;

@end

@protocol TBCollectionViewCellDelegate <NSObject>

@required

- (void)handleActionForCollectionCell:(TBCollectionViewCell *)cell object:(TBCollectionViewCellItem *)item info:(id)info;

@end
