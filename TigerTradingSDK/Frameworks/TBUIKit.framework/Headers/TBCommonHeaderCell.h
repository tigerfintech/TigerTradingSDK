//
//  TBCommonHeaderCell.h
//  Stock
//
//  Created by JustLee on 2019/3/20.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import "TBTableViewCell.h"

#define k_CommonHeaderContentTop                                    (15.f)
#define k_CommonHeaderTitleHeight                                   (25.f)

#define CommonHeaderTitleFont                                       BOLDFONTO(18.f)
#define CommonHeaderShowMoreFont                                    FONTO(12.f)

NS_ASSUME_NONNULL_BEGIN

@interface TBCommonHeaderCell : TBTableViewCell

@end

@interface TBCommonHeaderCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *titleString;
@property (nonatomic, strong) UIFont *titleFont;
@property (nonatomic, strong) UIColor *titleColor;
@property (nonatomic, copy) NSString *subtitle;
@property (nonatomic, copy) NSString *descriptionString;
@property (nonatomic, copy) NSString *showMoreString;
@property (nonatomic, strong, nullable) UIFont *showMoreFont;

@property (nonatomic, assign) BOOL showMoreText;
@property (nonatomic, assign) BOOL showMoreArrow;       //显示更多的右箭头
@property (nonatomic, strong) UIImage *moreArrowImage;  //更多箭头自定义样式，图片
@property (nonatomic, assign) BOOL showDetailButton;    //是否显示详情按钮箭头
@property (nonatomic, assign) BOOL detailMode;          //是否是详情模式
@property (nonatomic, assign) BOOL enableSelection;     //是否响应点击事件
@property (nonatomic, assign) NSInteger section;

@property (nonatomic, strong) void(^moreActionBlock)(void); // showMoreString对应的点击操作

@property (nonatomic, strong) void(^infoActionBlock)(void); // 问号图标对应的点击操作，不为nil时显示

@property (nonatomic, assign) CGFloat height;
@property (nonatomic, strong) NSNumber *titleLeading;
@property (nonatomic, strong) UIColor* backgroundColor;
@property (nonatomic, strong) UIColor* showMoreColor;

@property (nonatomic, assign) BOOL showMoreBorder;

//圆角设置
@property (nonatomic, assign) CGFloat cornerRadius;
@property (nonatomic, assign) UIRectCorner corners;

@property (nonatomic, strong) TTURLAction *action;

@end

NS_ASSUME_NONNULL_END
