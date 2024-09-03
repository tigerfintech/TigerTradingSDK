//
//  TBListTableViewController.h
//  Stock
//
//  Created by liwt on 14/12/18.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//

#import "TBTableViewController.h"

@interface TBListTableViewController : TBTableViewController
{
    NSMutableArray *_items;
}

@property (atomic, strong) NSMutableArray *items;
@property (nonatomic, assign) NSInteger curPage;

@end
