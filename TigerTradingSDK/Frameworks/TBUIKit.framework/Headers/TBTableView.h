//
//  TBTableView.h
//  Stock
//
//  Created by liwt on 14/12/18.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TBTableView : UITableView
- (void) showEmptyView;
- (void) hideEmptyView;

@property (nonatomic, copy) UIView* (^emptyViewBlock)(TBTableView *inTableView);
@property (nonatomic, copy) BOOL (^isLoading)(TBTableView *inTableView);
@property (nonatomic, strong) UIView *emptyView;
@property (nonatomic, assign) BOOL disableAutoSetEmptyView;

@end
