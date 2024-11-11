//
//  TBCommonContentTextTableViewCell.h
//  TBUIKit
//
//  Created by dulijun on 2024/1/4.
//

#import <TBUIKit/TBUIKit.h>
#import <TBUIKit/TBTableViewCell.h>
#import <TBUIKit/TBTableViewCellItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCommonContentTextTableViewCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *text;
@property (nonatomic, strong) UIFont *textFont;
@property (nonatomic, strong) UIColor *textColor;

@property (nonatomic, strong) NSNumber *textAlignment; // 默认left
@property (nonatomic, strong) NSNumber *lineSpacing; // 行间距，默认2
@property (nonatomic, strong) NSNumber *textLeading; // 默认k_LeftOffset
@property (nonatomic, strong) NSNumber *textTrailing; // 默认k_LeftOffset


@end

@interface TBCommonContentTextTableViewCell : TBTableViewCell

@end

NS_ASSUME_NONNULL_END

