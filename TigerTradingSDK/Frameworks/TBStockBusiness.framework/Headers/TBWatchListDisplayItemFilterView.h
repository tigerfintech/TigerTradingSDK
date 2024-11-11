//
//  TBWatchListDisplayItemsFilterView.h
//  Stock
//
//  Created by yangfan on 2018/8/23.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TBWatchListDisplayItemFilterView : UIView

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)frame;

- (instancetype)initWithLandscapeMode:(BOOL)isLandscapeMode;


@property (nonatomic, copy) void(^updatedBlock)(void);
@property (nonatomic, copy) void(^resetBlock)(void);


- (void)onTappedResetButton:(UIButton *)sender;

- (void)updateTableViewOrginY: (CGFloat)originY;

- (void)setResetBtnHidden: (BOOL)isHidden;

@property (nonatomic, assign) CGFloat ipad_viewWidth;
@end
