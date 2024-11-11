//
//  TBRefreshView.h
//  Stock
//
//  Created by liwt on 11/4/15.
//  Copyright © 2015 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MJRefresh/MJRefresh.h>

@protocol TBRefreshViewDelegate <NSObject>

@required
- (void)refreshButtonPressed;
@end

@interface TBRefreshView : UIView

@property (nonatomic, strong) UIActivityIndicatorView *refreshIndicatorView;
@property (nonatomic, strong) UIButton *refreshButton;
@property (nonatomic, weak) id<TBRefreshViewDelegate> delegate;

- (void) showRefreshIndicator;
- (void) hideRefreshIndicator;

@end
