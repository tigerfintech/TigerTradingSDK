//
//  TBUsualRankSegmentedPageViewController.h
//  Stock
//
//  Created by PXJ on 2020/7/10.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBSegmentedPageViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBUsualRankSegmentedPageViewController : TBSegmentedPageViewController

@property (nonatomic, assign) BOOL setFixedPageControl; // 指定固定宽度的segment
@property (nonatomic, assign) CGFloat trailingSpace;
@property (nonatomic, copy) NSDictionary *titleTextAttributes;
@property (nonatomic, copy) NSDictionary *selectedTitleTextAttributes;

- (void)updateSegmentTabNames:(NSArray<NSString*>*)names;

@end

NS_ASSUME_NONNULL_END
