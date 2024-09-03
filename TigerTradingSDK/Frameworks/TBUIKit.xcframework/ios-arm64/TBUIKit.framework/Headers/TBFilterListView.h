//
//  TBDatePeriodFilterView.h
//  Stock
//
//  Created by swordzhou on 2021/5/24.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBView.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBFilterListView : TBView

@property (nonatomic, copy) NSArray *titles;

@property (nonatomic, copy) NSString *selectedIconName;

@property (nonatomic, assign) NSInteger selectedIndex;

@property (nonatomic, assign) CGFloat customRowHeight;

@property (nonatomic, assign) CGFloat maxTableHeight; // 不设置默认是self.height

@property (nonatomic, strong) UIFont *customSelectedFont;

@property (nonatomic, strong) void (^indexDidChangeBlock)(NSInteger selectedIndex);

@property (nonatomic, strong) void (^dismissBlock)(void);

- (void)show;
- (void)hide;

- (void)registerCells;

@end

NS_ASSUME_NONNULL_END
