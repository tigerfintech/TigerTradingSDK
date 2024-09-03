//
//  TBTextTableViewCell.h
//  TBUIKit
//
//  Created by dulijun on 2022/7/4.
//

#import "TBTableViewCell.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBTextTableViewCell : TBTableViewCell

@end

@interface TBTextTableViewCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *textString;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIFont *textFont;
@property (nonatomic, strong) NSNumber *lineSpacing;
@property (nonatomic, strong) UIColor *cellBackgroundColor;
@property (nonatomic, strong) NSNumber *topAndBottomSpacing;
@property (nonatomic, strong) UIColor *sepLineColor; // 分割线颜色, 如果赋值, 则展示分割线

@end

NS_ASSUME_NONNULL_END
