//
//  TBCommonTableHeaderCell.h
//  Stock
//
//  Created by yangfan on 2019/7/24.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import "TBTableViewCell.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBCommonTableHeaderCellItem : TBTableViewCellItem

@property (nonatomic, assign) CGFloat  height;

@property (nonatomic, strong) NSNumber *centerYOffset;

@property (nonatomic, copy) NSString   *titleString;

@property (nonatomic, assign) CGFloat  titleFontSize;

@property (nonatomic, strong) UIFont   *titleFont;
@property (nonatomic, strong) UIColor  *titleColor;

@property (nonatomic, copy) NSString   *rightTitleString;

@property (nonatomic, strong) UIFont   *rightTitleFont;
@property (nonatomic, strong) UIColor  *rightTitleColor;

@property (nonatomic, assign) NSInteger extraTag;

@property (nonatomic, assign) BOOL showBottomLine;

@end

@interface TBCommonTableHeaderCell : TBTableViewCell

@end

NS_ASSUME_NONNULL_END
