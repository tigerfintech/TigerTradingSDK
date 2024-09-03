//
//  JXCategoryTitleView+TigerTrade.h
//  Stock
//
//  Created by DepthFirst on 2020/1/8.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/JXCategoryTitleView.h>

NS_ASSUME_NONNULL_BEGIN

@interface JXCategoryTitleView (TigerTrade)

- (void)ttr_applyTitleViewStyle;
- (void)ttr_applyDefaultStyle; // 一级tab, 如个股页
- (void)ttr_applySubjectStyle; // 二级tab, 如个股下的新闻, 新帖页
- (void)ttr_applyZoomStyle;

- (void)ttr_applyTradeTabStyle:(BOOL)showSelectionIndicator;///< 交易页面 证券｜期货

- (void)ttr_applyOrderListStyle;///< 订单页面 订单｜条件订单

@end

NS_ASSUME_NONNULL_END
