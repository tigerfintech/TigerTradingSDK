//
//  TBSegmentedPageViewController.h
//  Stock
//
//  Created by ChenXin on 17/1/20.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/THSegmentedPager.h>
#import <TBUIKit/THSegmentedPageViewControllerDelegate.h>

#define kTBSegmentedControlTitleFontSize 16


@protocol TBSegmentedPageViewControllerDelegate;

@interface TBSegmentedPageViewController : THSegmentedPager

@property (nonatomic, weak) id <TBSegmentedPageViewControllerDelegate> _Nullable delegate;

@property (nonatomic, assign, readonly) NSInteger currentPageIndex;

//隐藏选中指示条
@property (nonatomic, assign) BOOL selectionIndicatorHidden;

// 隐藏底部线条
@property (nonatomic, assign) BOOL bottomLineHidden;

@property (nonatomic, assign) BOOL hiddenNav;

@property (nonatomic, assign) BOOL shouldAdjustContainerPosition; //Default YES

@property (nonatomic, strong, nullable) UIColor *pageControlBackgroundColor;
@property (nonatomic, strong, nullable) UIColor *backgroundColor;
@property (nonatomic, strong, nullable) NSNumber *selectionIndicatorHeight;
@property (nonatomic, strong, nullable) NSNumber *selectionIndicatorWidth;

//必须为传入的每个viewController设置title，否则需要调用setViewControllerTitles方法设置
- (instancetype _Nullable )initWithViewControllers:(NSArray *_Nullable)viewControllers;

//为每个viewController设置title
- (void)setViewControllerTitles:(NSArray * _Nullable)titles;

- (void)scrollViewDidScroll:(UIScrollView *_Nullable)scrollView;

@end

@protocol TBSegmentedPageViewControllerDelegate <THSegmentedPageViewControllerDelegate>

@optional

- (void)segmentedPageViewControllerDidSelectIndex:(NSInteger)index;

- (void)segmentedPageViewDidScroll:(UIScrollView *_Nullable)scrollView;

@end
