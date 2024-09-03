//
//  TBMarketListSectionHeaderItem.h
//  Stock
//
//  Created by liwt on 15/1/4.
//  Copyright (c) 2015年 com.tigerbrokers. All rights reserved.
//


#import "TBTableViewCellItem.h"
#import "TBTableViewCell.h"

#import "TBSingleLineView.h"

@interface TBMarketPackageSectionHeaderItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *headImageName;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *indicatorImageName;
@property (nonatomic, copy) NSString *desTitle;
@property (nonatomic, copy) NSString *packageId;
@property (nonatomic, copy) NSString *explainText;
@property (nonatomic, copy) NSString *pageURL;

@property (nonatomic, strong) NSAttributedString *attributedTitle;

@property (nonatomic, assign) BOOL showIndicator;
@property (nonatomic, assign) BOOL useIndicatorImageSize;
@property (nonatomic, assign) BOOL hasHeadImage;
@property (nonatomic, assign) NSInteger index;
@property (nonatomic, assign) BOOL isFolded;
@property (nonatomic, assign) BOOL hiddenLine;
@property (nonatomic, assign) BOOL showTopLine;//默认NO，不会对其他共用该组件的内容造成影响
@property (nonatomic, assign) BOOL showExpalinIcon; //标题旁边的小问号图标
@property (nonatomic, assign) BOOL isETF;///< 是否是 ETF
@property (nonatomic, assign) BOOL isShowShare;//是否展示分享按钮

@property (nonatomic, strong) UIImage *expalinIcon; //标题旁边的小问号图标
@property (nonatomic, strong) UIColor *contentColor;
@property (nonatomic, strong) UIFont *titleFont;
@property (nonatomic, strong) UIColor *titleColor;
@property (nonatomic, strong) UIImage *headeImage;

@property (nonatomic, assign) CGFloat totalHeight;///< 总高度，带着下面的各条目的高度

@property (nonatomic, copy) void(^handleShareBlock)(void);//分享回调

- (instancetype)applyTitle:(NSString *)inTitle;
- (instancetype)applyTitle:(NSString *)inTitle desTitle:(NSString *)inDesTitle;
- (instancetype)applyHeadImage:(NSString *)headImageName;
- (instancetype)applyShowIndicator:(BOOL)isShow;
- (instancetype)applyHasHeadImage:(BOOL)has;

- (instancetype)applyPackageId:(NSString *)packageId;


- (instancetype)applyTitle:(NSString *)title isShowIndicator:(BOOL) isShowIndicator;
- (instancetype)applyIndicatorImageName:(NSString *)indicatorImageName;


@end


@interface TBMarketPackageSectionHeaderView :  TBTableViewCell

@property (nonatomic, assign) BOOL hasHeadImage;
@property (nonatomic, assign) BOOL useIndicatorImageSize;

@property (nonatomic, copy) NSString *headImageName;
@property (nonatomic, copy) NSString *indicatorImageName;

@property (nonatomic, strong) UIImageView *headImageView;
@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UILabel *desTitleLabel;
@property (nonatomic, strong) UIView *lineView;
@property (nonatomic, strong) UIImageView *explainView;
@property (nonatomic, strong) UIView * mContentView;
@property (nonatomic, strong) UIImageView *bgView;
@property (nonatomic, strong) UIImageView *indicatorView;
@property (nonatomic, strong) UIButton *shareButton;//分享按钮
@property (nonatomic, strong) TBMarketPackageSectionHeaderItem *curCellItem;//cell数据源

@property (nonatomic, strong) TBSingleLineView *singlelineView;
@property (nonatomic, strong) TBSingleLineView *topSinglelineView;//上边线
- (void) tapContentViewGesture:(UITapGestureRecognizer *)gr;

@end
