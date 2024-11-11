//
//  TBStockDetailOptionChainViewController.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/11/13.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBStockDetailBottomItemViewController.h"
#import "TBStockDetailBottomTabBar.h"

NS_ASSUME_NONNULL_BEGIN
/*
 个股详情页-期权链tab
 
 */
@class TBOptionExpiryItemModel;
@interface TBStockDetailOptionChainViewController : TBStockDetailBottomItemViewController
@property (nonatomic, strong, readonly) UIScrollView *contentScrollView;

@property (nonatomic, strong) NSNumber *stockLatestPrice;
@property (nonatomic, strong) NSNumber *closePrice;

@property (nonatomic, copy) NSString *optionSymbol;
@property (nonatomic, assign) TBStockBottomBarEventType type;//当前在那个tab上
/// 选中期权
@property (nonatomic, strong) TBOptionExpiryItemModel *selectedExpiry;
//期权的底部栏
@property (nonatomic, strong) TBOptionChainBottomView *bottomView;

- (void)updateBottomView;
- (void)handleOptionChainBottom:(TBStockBottomBarEventType)type;
- (void)updateBottomTabbarStutus:(TBStockDetailBottomTabBar *)tabbar;

@property (nonatomic, copy) void(^optionChainNoData)(void);
@property (nonatomic, copy) void(^optionExpiryChanged)(void);
@property (nonatomic, copy) void(^bottomViewHiddenIfNeed)(TBStockBottomBarEventType type);

@end

NS_ASSUME_NONNULL_END
