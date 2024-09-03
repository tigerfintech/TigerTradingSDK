//
//  TBStockListBaseView.h
//  Stock
//
//  Created by zhenglanchun on 2021/5/20.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, TBStockListViewColType) {
    TBStockListViewColTypeC3 = 3, ///< 3列
    TBStockListViewColTypeC4, ///< 4列
    TBStockListViewColTypeC3WithIcon, ///< 4列（对应C3带Icon的）
    TBStockListViewColTypeC4WithIcon ///< 5列（对应C4带Icon的）
};

typedef NS_ENUM(NSInteger, TBStockListViewContentType) {
    TBStockListViewContentTypeCompact,           ///< 宽松型
    TBStockListViewContentTypeLoose,             ///< 紧凑型
    TBStockListViewContentTypeHomePageProtfolio, ///< 首页持仓样式
    TBStockListViewContentTypeEquallyDivided,    ///< 平分
};

NS_ASSUME_NONNULL_BEGIN

@interface TBStockListBaseView : UIView

/// 列的数量，默认3列（可选4列）
@property (nonatomic, assign, readonly) TBStockListViewColType colType;

/// UI类型：Compact 宽松，Loose 紧凑。默认：Loose
@property (nonatomic, assign, readonly) TBStockListViewContentType contentType;

@property (nonatomic, assign) BOOL adjustSecondColumnLayoutInEnglish; /// Default:NO

@property (nonatomic, assign) CGFloat leftRatio;
@property (nonatomic, assign) CGFloat middleOneRatio;
@property (nonatomic, assign) CGFloat middleTwoRatio;
@property (nonatomic, assign) CGFloat rightRatio;
@property (nonatomic, assign) CGFloat rightIconRatio;

/** middleTwo 可变。当3列时，middleTwo隐藏；4列时，middleTwo显示
 ```
 | - leftV - (middleOne - middleTwo) - rightV - (rightIconV) - |
 ```
 
 cell中选中颜色有问题，又只用到位置信息，所以View的hidden属性都是YES
 */
@property (nonatomic, strong) UIView *leftV;
@property (nonatomic, strong) UIView *rightV;
@property (nonatomic, strong) UIView *middleOneV;
@property (nonatomic, strong) UIView *middleTwoV;
@property (nonatomic, strong) UIView *rightIconV; // 最后一个icon的位置，可隐藏

/// 设置col count，默认：C3
- (void)updateColType:(TBStockListViewColType)colType;

/// 设置UI样式：紧凑型、宽松型，只会改变内部的ratio，需要调用updateUILayouts后UI才会变化
- (void)updateContentType:(TBStockListViewContentType)contentType;

/// 设置完UI类型后，需要更新下layout
- (void)updateUILayouts;

// MARK: 子类初始化使用
- (void)setupViews;

- (void)setupLayouts;

// MARK: public
- (void)setBgColor:(UIColor * _Nonnull)bgColor;

// MARK: 便利方法
/// 设置UI样式为C31，对应的 contentType: Compact, ColType: C3
- (void)setC31UITheme;
/// 设置UI样式为C32，对应的 contentType: Loose, ColType: C3
- (void)setC32UITheme;
/// 设置UI样式为C41，对应的 contentType: Loose, ColType: C4
- (void)setC41UITheme;
/// 设置UI样式为C42，对应的 contentType: Compact, ColType: C4
- (void)setC42UITheme;
/// 设置UI样式为C43，对应的 contentType: xxx(目前无效), ColType: C4WithIcon
- (void)setC43UITheme;
/// 设置UI样式为首页持仓，对应 contentType: HomePageProtfolio, ColType: C3
- (void)setHomePagePortfolioUITheme;

@end

NS_ASSUME_NONNULL_END
