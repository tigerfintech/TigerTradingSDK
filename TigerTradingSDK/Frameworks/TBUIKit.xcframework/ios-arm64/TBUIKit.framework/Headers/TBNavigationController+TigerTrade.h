//
//  TBNavigationController+TigerTrade.h
//  Stock
//
//  Created by zhengzhiwen on 2021/4/27.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import "TBNavigationController.h"

NS_ASSUME_NONNULL_BEGIN


//TTNavigator替换成了TBKNavigator
//TTNavigator没有这两个方法，TBKNavigator有，现在为了适配之前的逻辑，给TBNavigationController添加这两个方法，覆盖TBK里面的方法
//如果不这样适配，业务层有一些地方会有bug，改动会大一些。
//需要等彻底整理弄明白navigator逻辑才能完全替换成TBKNavigator的实现，可能还需要改业务层的navigation实现
@interface TBNavigationController (TigerTrade)

- (BOOL)canContainControllers;

- (UIViewController*)topSubcontroller;

@end

NS_ASSUME_NONNULL_END
