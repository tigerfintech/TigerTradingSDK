//
//  TBHKOptionStockCell.h
//  Stock
//
//  Created by 王灵博 on 2020/8/13.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
@class TBHKOptionItemModel;
NS_ASSUME_NONNULL_BEGIN

@interface TBHKOptionStockCell : TBTableViewCell

@end


@interface TBHKOptionStockCellItem : TBTableViewCellItem
@property(nonatomic, strong) TBHKOptionItemModel *model;
@end

NS_ASSUME_NONNULL_END
