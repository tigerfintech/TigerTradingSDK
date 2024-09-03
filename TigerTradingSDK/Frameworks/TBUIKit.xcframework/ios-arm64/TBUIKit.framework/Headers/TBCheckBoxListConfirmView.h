//
//  TBCheckBoxListConfirmView.h
//  Stock
//
//  Created by yangfan on 2019/9/18.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBCommonConfirmView.h>
#import <TBUIKit/TBTableViewCell.h>
#import <TBUIKit/TBTableViewCellItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCheckBoxTableCell : TBTableViewCell

@property (nonatomic, strong) UIButton        * checkboxButton;
@property (nonatomic, strong) UILabel         * titleLabel;

@end

@interface TBCheckBoxTableCellItem : TBTableViewCellItem

@property (nonatomic, assign) BOOL selected;
@property (nonatomic, assign) BOOL editEnable;        //default YES
@property (nonatomic, assign) CGFloat marginLeft;
@property (nonatomic, strong) UIFont *textFont;
@property (nonatomic, strong) UIColor *textColor;

@property (nonatomic, copy) NSString *text;
@property (nonatomic, copy) NSString *iconName;
@property (nonatomic, copy) NSString *selectedIconName;

@end

@interface TBCheckBoxListConfirmView : TBCommonConfirmView

@property (nonatomic, copy) NSArray<NSString *> * options;
@property (nonatomic, assign) NSInteger           selectedIndex;

@end

NS_ASSUME_NONNULL_END
