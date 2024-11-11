//
//  TBOptionChainAnalysisViewController+HandleData.h
//  Stock
//
//  Created by 王灵博 on 2021/1/14.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import "TBOptionChainAnalysisViewController.h"
@class TBOptionExpiryItemModel;
@class TBOptionAnalysisModel;
@class TBOptionExpiryItemModel,TBOptionAnalysisModel;
NS_ASSUME_NONNULL_BEGIN

@interface TBOptionChainAnalysisViewController (HandleData)
- (void)handleChartLineData:(NSArray *)items;
- (void)handleExpires:(NSArray *)expires currentExpiry:(TBOptionExpiryItemModel *)currentExpiry;
- (void)getOptionChangeListByModle:(TBOptionAnalysisModel *) response select:(BOOL)select;
- (void)openIndicatorWithPost:(NSString *)post;
@end

NS_ASSUME_NONNULL_END
