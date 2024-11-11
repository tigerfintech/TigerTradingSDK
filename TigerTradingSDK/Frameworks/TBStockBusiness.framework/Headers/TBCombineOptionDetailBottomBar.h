//
//  TBCombineOptionDetailBottomBar.h
//  TBStockBusiness
//
//  Created by mashanli on 2023/6/19.
//
#import "TBStockDetailBottomTabBarView.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBCombineOptionDetailBottomBar : UIView

@property (nonatomic, copy) bottomBarItemClicked bottomClicked;
@property (nonatomic, assign) BOOL isWithInWatchList;

@end


NS_ASSUME_NONNULL_END
