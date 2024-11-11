//
//  TBStockSettingBasicCellItem.h
//  Stock
//
//  Created by liwt on 15/1/3.
//  Copyright (c) 2015年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCellItem.h>
#import <TBUIKit/TBTableViewCell.h>

@interface TBStockSettingBasicCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *headImageName;
@property (nonatomic, strong) UIImage *headImageIcon;
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, copy) id title;
@property (nonatomic, copy) NSString *subTitle; // 副标题, 用于客服cell显示时间
@property (nonatomic, copy) NSString *indicatorImg;//设置indicator图片
@property (nonatomic, strong) id desTitle; // 可以是 NSString 或 NSAttributeString
@property (nonatomic, strong) UIView *desView; // 右侧显示特殊视图
@property (nonatomic, strong) UIFont *titleFont;
@property (nonatomic, strong) UIFont *selectedTitleFont;
@property (nonatomic, strong) UIColor *titleColor;
@property (nonatomic, strong) UIColor *desColor;
@property (nonatomic, assign) BOOL titleCenterHorizontal;   //标题居中
@property (nonatomic, strong) UIColor *contentColor;
@property (nonatomic, strong) UIColor *selectedColor;

@property (nonatomic, assign) BOOL showIndicator;
@property (nonatomic, assign) BOOL hasRedIcon;
@property (nonatomic, assign) BOOL hasBottomLine;
@property (nonatomic, assign) CGFloat bottomLineLeft;
@property (nonatomic, assign) CGFloat bottomLineRight;

@property (nonatomic, assign) BOOL selected;
@property (nonatomic, assign) BOOL selectable;
@property (nonatomic, assign) CGFloat imageViewLeft; // 图片左边距

// 标题右边是否有info按钮，点击出现弹窗
@property (nonatomic, assign) BOOL hasInfoButton;
@property (nonatomic, strong) void(^infoButtonActionBlock)(void);

@property (nonatomic, assign) BOOL shouldJudgeLayout; ///< 是否需要判断布局 根据语言会区分为左右布局 和 上下布局

- (TBStockSettingBasicCellItem *)applyTitle:(NSString *)inTitle;
- (TBStockSettingBasicCellItem *)applyTitle:(NSString *)inTitle desTitle:(NSString *)inDesTitle;
- (TBStockSettingBasicCellItem *)applyHeadImage:(NSString *)headImageName;
- (TBStockSettingBasicCellItem *)applyHeadImageIcon:(UIImage *)headImage;
- (TBStockSettingBasicCellItem *)applyShowIndicator:(BOOL)isShow;
- (TBStockSettingBasicCellItem *)applyHasRedIcon:(BOOL)has;
- (TBStockSettingBasicCellItem *)applyIndicator:(NSString *)indicator;

@end

@interface TBStockSettingBasicCell :  TBTableViewCell

@property (nonatomic, strong) UIImageView *headImageView;   // 图标
@property (nonatomic, strong) UILabel *titleLabel;          // title
@property (nonatomic, strong) UILabel *subTitleLabel;       // left text
@property (nonatomic, strong) UILabel *desTitleLabel;       // right text
@property (nonatomic, strong) UIView *space; // 图标和标题之间的空隙

@property (nonatomic, strong) UIImageView *redIconImg;      // 红点
@property (nonatomic, strong) UIImageView *IconImg;         // 箭头

@property (nonatomic, strong) UIButton *infoButton;

@end
