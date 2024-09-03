//
//  TBImageTextTableViewCell.h
//  Stock
//
//  Created by 骆朋飞 on 2017/5/12.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import "TBTableViewCell.h"

/*
 
 cell样式
 **********************************
 * image text               image *
 **********************************
 
 image 默认宽度为0
 */


@interface TBImageTextTableViewCell : TBTableViewCell

@end

@interface TBImageTextTableViewCellItem : TBTableViewCellItem
@property (nonatomic, copy) NSString *leftImage;
@property (nonatomic, copy) NSString *rightImage;
@property (nonatomic, copy) NSString *titleString;
@property (nonatomic, assign) BOOL hideLine;
@property (nonatomic, strong) UIColor *titleColor;
@property (nonatomic, assign) CGFloat customerHeight;  //!< 定制高度
@end
