//
//  TBNavigator.h
//  Stock
//
//  Created by liwt on 14/12/18.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//

#import "TTHeader.h"

@interface TBNavigator : TTBaseNavigator

+ (TBNavigator *)navigator;
+ (TBNavigator *)sharedInstance;

- (void) popToViewControllerWithClass:(Class)klass animated:(BOOL) animated;
- (void) popToRootViewController;
- (void) normalPopToViewControllerWithClass:(Class)cls animated:(BOOL)animated;

- (void)loadAllURLMap:(NSDictionary *)map;


@end
