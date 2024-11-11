//
//  TBMarketOptionRankDetailListViewController.h
//  Stock
//
//  Created by JustLee on 2021/3/1.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBListTableViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBMarketOptionRankDetailListViewController : TBListTableViewController

@property (nonatomic, copy) NSString *optionRankingId;
@property (nonatomic, copy) NSString *market;

- (void)resetRefreshData;

@end

NS_ASSUME_NONNULL_END
