//
//  TUPStockSettingBasicCellItem.h
//  Stock
//
//  Created by liwt on 15/1/3.
//  Copyright (c) 2015年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCellItem.h>
#import <TBUIKit/TBTableViewCell.h>

@interface TUPStockSettingBasicCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *headImageName;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *subTitle; // 副标题, 用于客服cell显示时间
@property (nonatomic, copy) NSString *otherLineSubTitle; // 第二行副标题, 用于美国活动
@property (nonatomic, copy) NSString *indicatorImg;//设置indicator图片
@property (nonatomic, strong) id desTitle; // 可以是 NSString 或 NSAttributeString
@property (nonatomic, strong) UIView *desView; // 右侧显示特殊视图

@property (nonatomic, strong) UIColor * titleColor;
@property (nonatomic, assign) BOOL titleCenterHorizontal;   //标题居中
@property (nonatomic, strong) UIColor * contentColor;
@property (nonatomic, strong) UIColor * selectedColor;

@property (nonatomic, strong) UIFont *titleFont;

@property (nonatomic, assign) BOOL showIndicator;
@property (nonatomic, assign) BOOL hasRedIcon;
@property (nonatomic, assign) BOOL hasBottomLine;
@property (nonatomic, assign) BOOL selectable;
@property (nonatomic, assign) CGFloat imageViewLeft; // 图片左边距

- (TUPStockSettingBasicCellItem *)applyTitle:(NSString *)inTitle;
- (TUPStockSettingBasicCellItem *)applyTitle:(NSString *)inTitle desTitle:(NSString *)inDesTitle;
- (TUPStockSettingBasicCellItem *)applyHeadImage:(NSString *)headImageName;
- (TUPStockSettingBasicCellItem *)applyShowIndicator:(BOOL)isShow;
- (TUPStockSettingBasicCellItem *)applyHasRedIcon:(BOOL)has;
- (TUPStockSettingBasicCellItem *)applyIndicator:(NSString *)indicator;

@end

@interface TUPStockSettingBasicCell :  TBTableViewCell

@property (nonatomic, strong) UIImageView *headImageView;   // 图标
@property (nonatomic, strong) UILabel *titleLabel;          // title
@property (nonatomic, strong) UILabel *subTitleLabel;       // left text
@property (nonatomic, strong) UILabel *desTitleLabel;       // right text
@property (nonatomic, strong) UILabel *otherLineSubTitleLabel; //换行 subTitle

@property (nonatomic, strong) UIImageView *redIconImg;      // 红点
@property (nonatomic, strong) UIImageView *IconImg;         // 箭头

@end
