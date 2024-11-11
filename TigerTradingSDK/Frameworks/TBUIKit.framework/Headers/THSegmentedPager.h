//
//  THSegmentedPager.h
//  THSegmentedPager
//
//  Created by Hannes Tribus on 25/07/14.
//  Copyright (c) 2014 3Bus. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBThirdParty/HMSegmentedControl.h>

// 放在pager里的vc可以实现该协议, 在vc切换的时机执行代码
@protocol THSegmentedPagerDelegate <NSObject>

- (void)segmentedPagerDidScrollToIndex:(NSUInteger)index;

@end

@interface THSegmentedPager : UIViewController<UIPageViewControllerDataSource,UIPageViewControllerDelegate>

@property (strong, nonatomic)UIPageViewController *pageViewController;
@property (strong, nonatomic) HMSegmentedControl *pageControl;
// TODO: 处理pageControl高度变化
@property (assign, nonatomic) CGFloat pageControlHeight; // 暂未使用
@property (strong, nonatomic) UIView *contentContainer;
@property (assign, nonatomic) BOOL hidePageControl;

@property (strong, nonatomic)NSMutableArray *pages;
@property (assign, nonatomic, getter=isShouldBounce)BOOL shouldBounce;

@property (strong, nonatomic) NSMutableArray *titleLabels;
@property (nonatomic, copy) void (^updateNewPostRedBlock)(void); // 点击红点后的block

@property (assign, nonatomic) BOOL needKeepTitle; ///< 是否需要保持title不刷新

/*! Instead of setting the pages manually you can give to the controller an array of identifiers which will be loaded from the storyboard at runtime
 * \param identifiers Array of identifiers to load
 */
- (void)setupPagesFromStoryboardWithIdentifiers:(NSArray *)identifiers;

- (void)setPageControlHidden:(BOOL)hidden animated:(BOOL)animated;
- (void)setSelectedPageIndex:(NSUInteger)index animated:(BOOL)animated;


/*! Get the selected viewcontroller
 * \returns The actual selected viewcontroller
 */
- (UIViewController *)selectedController;

/*! The control will ask from every viewcontroller an updated title string
 */
- (void)updateTitleLabels;

// vc切换后的回调, 可以在容器类执行代码
- (void)currentIndexDidSet:(NSUInteger)currentIndex;

- (void)scrollViewDidScroll:(UIScrollView *)scrollView;

- (void)scrollViewDidEndDecelerating:(UIScrollView *)scrollView;


@end
