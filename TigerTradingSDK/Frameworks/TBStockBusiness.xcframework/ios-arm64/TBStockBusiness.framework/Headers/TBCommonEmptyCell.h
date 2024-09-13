//
//  TBCommonEmptyCell.h
//  Stock
//
//  Created by 王灵博 on 2020/12/22.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCommonEmptyCell : TBTableViewCell

@end

@interface TBCommonEmptyCellItem : TBTableViewCellItem

@property (nonatomic, assign) CGFloat rowHeight;//cell高度
@property (nonatomic, assign) BOOL needShowImage;//是否展示空图片提示

@end

NS_ASSUME_NONNULL_END
