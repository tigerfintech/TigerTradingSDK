//
//  TBHKOptionHeaderCell.h
//  Stock
//
//  Created by 王灵博 on 2020/8/13.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
@class TBHKOptionSortModel;
NS_ASSUME_NONNULL_BEGIN

@interface TBHKOptionHeaderCell : TBTableViewCell

@end

@interface TBHKOptionHeaderCellItem : TBTableViewCellItem
@property(nonatomic,strong)TBHKOptionSortModel *sortModel;
@end

NS_ASSUME_NONNULL_END
