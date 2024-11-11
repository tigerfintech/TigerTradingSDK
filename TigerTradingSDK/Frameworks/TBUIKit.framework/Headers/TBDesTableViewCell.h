//
//  TBDesTableViewCell.h
//  Stock
//
//  Created by 骆鹏飞 on 2017/3/10.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import "TBTableViewCell.h"

@interface TBDesTableViewCell : TBTableViewCell

@end

@interface TBDesTableViewCellItem : TBTableViewCellItem

@property (nonatomic, strong) NSDictionary *highlightDescDic;

@property (nonatomic, copy) NSString *desText;

@property (nonatomic, assign) BOOL showBottomLine;
@property (nonatomic, assign) BOOL expand;                   ///Default:NO
@property (nonatomic, assign) BOOL showExpandAllIfNeeded;    ///Default:NO
@property (nonatomic, assign) BOOL showClose;                ///Default:NO
@property (nonatomic, assign) float fontSize;
@property (nonatomic, assign) float lineSpace;
@property (nonatomic, assign) float calculateWidth;

@property (nonatomic,  strong) UIColor *fontColor;

@property (nonatomic, strong) void(^closeBlock)(void);

@property (nonatomic, strong) void(^expandAllBlock)(void);

- (CGFloat)lineHeight;

- (CGFloat)textHeight;

@end
