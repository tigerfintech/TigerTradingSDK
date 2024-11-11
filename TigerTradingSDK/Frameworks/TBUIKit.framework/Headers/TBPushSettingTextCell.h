//
//  TBPushSettingTextCell.h
//  Stock
//
//  Created by donggongfu on 16/11/9.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import "TBTableViewCell.h"

@interface TBPushSettingTextCell : TBTableViewCell

@end

@interface TBPushSettingTextCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *text;
@property (nonatomic, strong) UIFont *font;
@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, copy) NSString *subText;
@property (nonatomic, strong) UIColor *subTextColor;

@end
