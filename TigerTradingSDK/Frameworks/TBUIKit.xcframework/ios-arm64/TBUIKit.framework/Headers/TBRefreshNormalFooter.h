//
//  TBRefreshNormalFooter.h
//  StockGlobal
//
//  Created by chenxin on 2019/10/23.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <MJRefresh/MJRefreshBackStateFooter.h>
#import <MJRefresh/MJRefresh.h>

@class LOTAnimationView;

@interface TBRefreshNormalFooter : MJRefreshBackStateFooter

//上拉时立即刷新
@property (nonatomic, assign) BOOL refreshAtPullingUp;

@property (nonatomic, assign) BOOL autoAdjustOffsetX;

@property (nonatomic, strong) LOTAnimationView *loadingAnimationView;

- (void)refreshFooterChangeColor;

- (CGFloat)heightForContentBreakView;

- (CGFloat)happenOffsetY;
@end
