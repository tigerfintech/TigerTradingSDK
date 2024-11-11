//
//  TUPOpenAccountFloatingTitlePickerCell.h
//  Stock
//
//  Created by CharmingQin on 2018/11/6.
//  Copyright © 2018 com.tigerbrokers. All rights reserved.
//

#import "TBTableViewCell.h"

NS_ASSUME_NONNULL_BEGIN

@interface TUPOpenAccountFloatingTitlePickerCell : TBTableViewCell

@end

@interface TBOpenAccountFloatingTitlePickerCellItem : TBTableViewCellItem
@property (nonatomic, copy) NSString *placeholder;
@property (nonatomic, copy) NSString *content;
@property (nonatomic) BOOL hideFloatingLabel; // 隐藏label
@property (nonatomic) BOOL isRightArrow;

@property (nonatomic) BOOL isHighlighted; // 红色线条状态
@end



NS_ASSUME_NONNULL_END
