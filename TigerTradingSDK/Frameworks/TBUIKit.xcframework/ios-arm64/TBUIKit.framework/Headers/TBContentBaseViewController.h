//
//  TBContentBaseViewController.h
//  Stock
//
//  Created by DepthFirst on 2019/6/12.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBBaseViewController.h>
#import <TBUIKit/JXCategoryView.h>
#import <TBUIKit/JXCategoryListContainerView.h>


// CategoryView位置的枚举
typedef NS_ENUM(NSInteger, TBCategoryViewStyle) {
    TBCategoryViewStyleDefault = 0,
    /// 导航栏下方 segmented control 样式
    TBCategoryViewStyleSegment = TBCategoryViewStyleDefault,
    /// 导航栏 titleview 居中
    TBCategoryViewStyleTitleView,
    /// 底部 TabBar
    TBCategoryViewStyleTab,
    
//    TBContentBaseViewControllerCategoryViewStyleZoom, // navbar占满可缩放
    /// 二级 tab?
    TBCategoryViewStyleSubject,
};

NS_ASSUME_NONNULL_BEGIN

@interface TBContentBaseViewController : TBBaseViewController <JXCategoryViewDelegate, JXCategoryListContainerViewDelegate, JXCategoryListContentViewDelegate>

// TODO: 改已有调用, 改为 readonly
@property (nonatomic, readonly) TBCategoryViewStyle categoryViewStyle;
@property (nonatomic, readonly) JXCategoryListContainerType containerType;
// navigationOrientation
// spineLocation

// 可以对外传的 delegate 方法, didSelect
@property (nullable, nonatomic, weak) id delegate;

@property (nonatomic, copy) NSArray *titles;
@property (nullable, nonatomic, copy) NSArray<__kindof UIViewController *> *viewControllers;

@property (nullable, nonatomic, weak) __kindof UIViewController *selectedViewController;
@property (nonatomic) NSUInteger selectedIndex;

// UI
@property (nonatomic, strong) JXCategoryBaseView *categoryView;
@property (nonatomic, strong) JXCategoryTitleView *categoryTitleView;
@property (nonatomic, strong) JXCategoryListContainerView *listContainerView;

// properties
/// 是否处理侧滑手势. 默认YES, 次级容器不用处理.
@property (nonatomic, assign) BOOL processInteractivePopGestureRecognizer;






// 容器类型(scrollview/collectionview)
- (instancetype)initWithCategoryStyle:(TBCategoryViewStyle)style containerType:(JXCategoryListContainerType)type NS_DESIGNATED_INITIALIZER;
// TODO: 方向支持竖向(如个股横屏翻页)
// TODO: 内容可以有边距?
- (instancetype)initWithContainerType:(JXCategoryListContainerType)type;

- (void)setViewControllers:(NSArray<__kindof UIViewController *> * _Nullable)viewControllers;

- (JXCategoryBaseView *)preferredCategoryView;
- (CGFloat)preferredCategoryViewHeight;

- (void)reloadData;

#pragma mark -

//// TODO: 处理子类和类型
//- (instancetype)initWithTitles:(NSArray *)titles;
//- (instancetype)initWithTitles:(NSArray *)titles style:(TBContentBaseViewControllerCategoryViewStyle)style;

@end

NS_ASSUME_NONNULL_END
