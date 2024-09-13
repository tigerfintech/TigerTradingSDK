//
//  TBOptionChainGuideViewController.h
//  Stock
//
//  Created by JustLee on 2020/12/16.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBListTableViewController.h>
@class TBOptionExpiryItemModel;

NS_ASSUME_NONNULL_BEGIN

/// 期权连新手专区
@interface TBOptionChainGuideViewController : TBListTableViewController

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *optionSymbol;
@property (nonatomic, copy) NSString *nameCN;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, strong) NSNumber *stockLatestPrice;
@property (nonatomic, strong) NSNumber *closePrice;

@property (nonatomic, strong) TBOptionExpiryItemModel *selectedExpiryDate;

@end

NS_ASSUME_NONNULL_END
