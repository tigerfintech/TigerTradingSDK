//
//  TBSearchStockViewController.h
//  Stock
//
//  Created by liwt on 14/12/31.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//  发帖界面-添加股票、帖子详情页发表评论添加股票 的搜索页面


#import <TBUIKit/TBListTableViewController.h>

@interface TBSearchStockViewController : TBListTableViewController<UISearchBarDelegate, TBTableViewDelegate>

@property (nonatomic, assign) BOOL isFirstRunIn;
@property (nonatomic, strong) UIButton *footView;

@end
