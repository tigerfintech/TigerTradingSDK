//
//  TBOpenAccountTextCell.h
//  Stock
//
//  Created by donggf on 2018/6/7.
//  Copyright © 2018年 TIGERBROKERS. All rights reserved.
//

#import "TBTableViewCell.h"
#import <UIKit/UIKit.h>

@interface TBOpenAccountTextCell : TBTableViewCell

@end

@interface TBOpenAccountTextCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *text;
@property (nonatomic, strong) NSMutableAttributedString *attText;

@property (nonatomic, strong) UIFont *font;
@property (nonatomic, strong) UIColor *color;
@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, assign) BOOL hasBottomBorder;
@property (nonatomic, assign) NSTextAlignment textAlignment;

@end
