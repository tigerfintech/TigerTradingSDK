//
//  TBAccountGroupStyleBlankCell.h
//  Stock
//
//  Created by donggongfu on 16/1/21.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import "TBTableViewCell.h"

#pragma mark - TBAccountGroupStyleBlankCell
@interface TBAccountGroupStyleBlankCell : TBTableViewCell

@end

#pragma mark - TBAccountGroupStyleBlankCellItem
@interface TBAccountGroupStyleBlankCellItem : TBTableViewCellItem

@property (nonatomic, assign) BOOL hasTopBorder;
@property (nonatomic, assign) BOOL hasBottomBorder;
@property (nonatomic, assign) CGFloat theCellHeight;
@property (nonatomic, assign) CGFloat leftOffset;
@property (nonatomic, assign) CGFloat rightOffset;
@property (nonatomic, assign) CGFloat topOffset;

@end

