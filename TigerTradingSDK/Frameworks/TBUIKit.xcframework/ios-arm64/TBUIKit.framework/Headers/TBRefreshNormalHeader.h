//
//  TBRefreshNormalHeader.h
//  StockGlobal
//
//  Created by chenxin on 2019/10/22.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <MJRefresh/MJRefreshStateHeader.h>
#import <MJRefresh/MJRefresh.h>

@class LOTAnimationView;

#define kAnimationViewWidth 30.0
#define kAnimationViewHeight 57.0

@interface TBRefreshNormalHeader : MJRefreshStateHeader

@property (nonatomic, strong) LOTAnimationView *pullingAnimationView;
@property (nonatomic, strong) LOTAnimationView *loadingAnimationView;
@property (nonatomic, assign) BOOL needBackColor;

- (void)refreshHeaderChangeColor;

- (void)hideUpdateTime;

@end
