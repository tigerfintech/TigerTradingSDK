//
//  UIEmptyWatchListView.h
//  Stock
//
//  Created by toanso on 15/1/15.
//  Copyright (c) 2015年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBUIKit/TBTableEmptyView.h>

@class UIEmptyWatchListView;
@protocol UIEmptyWatchListViewDelegate <NSObject>

- (void)searchAndAddStockToWatchList;

@end

@interface UIEmptyWatchListView : TBTableEmptyView

@property (nonatomic, strong) UILabel *message;
@property (nonatomic, strong) UIButton *addStockBtn;
@property (nonatomic, strong) UIImageView *logoView;
@property (nonatomic, weak) id<UIEmptyWatchListViewDelegate> tapDelegate;

- (id)initWithFrame:(CGRect)frame withMsg:(NSString *)msgString hasLogo:(BOOL)hasLogo;

- (void)updateTheme;

@end
