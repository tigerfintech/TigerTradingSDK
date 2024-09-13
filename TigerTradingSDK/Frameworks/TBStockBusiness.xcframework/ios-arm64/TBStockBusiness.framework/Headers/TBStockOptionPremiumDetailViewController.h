//
//  TBStockOptionPremiumDetailViewController.h
//  AFNetworking
//
//  Created by zlc on 2024/3/29.
//

#import <TBUIKit/TBListTableViewController.h>

NS_ASSUME_NONNULL_BEGIN

@class TBStockDetailOptionPremiumOptionItemModel;

@interface TBStockOptionPremiumDetailViewController : TBListTableViewController

@property (nonatomic, strong) TBStockDetailOptionPremiumOptionItemModel *optionItemModel;

@end

NS_ASSUME_NONNULL_END
