//
//  TBGroupStockManagerViewControllerSearchDelegateObject.h
//  Stock
//
//  Created by zhenglanchun on 2021/7/2.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBStockSearchViewController.h"
#import "TBGroupStockSearchViewController.h"

NS_ASSUME_NONNULL_BEGIN

/*
 TBGroupStockManagerViewController 拆解到TBStockBusiness库里，依赖两个在壳工程搜索的代理
 搜索相关目前没有接耦，所以为了接耦TBGroupStockManagerViewController，创建一个DelegateObject，将代理转变为block形式，给IMPL使用
 
 代理：
 TBGroupStockSearchViewControllerDelegate,TBStockSearchViewControllerDelegate
 
 */

typedef void(^TBGroupStockManagerViewControllerSearchDelegateObjectCompleted)(void);

@class TBGroupStockSearchViewController;
@class TBStockSearchViewController;
@class TBStockInfoDetailItemModel;

@interface TBGroupStockManagerViewControllerSearchDelegateObject : NSObject <TBGroupStockSearchViewControllerDelegate>

@property (nonatomic, copy) void(^onTappedDismissButtonCallback)(TBGroupStockSearchViewController *searchViewController);

@property (nonatomic, copy) void(^didTappedAddOrRemoveButtonCallback)(TBStockSearchViewController *viewController, BOOL isAdd, TBStockInfoDetailItemModel *stockModel, TBGroupStockManagerViewControllerSearchDelegateObjectCompleted completed);


@end

NS_ASSUME_NONNULL_END
