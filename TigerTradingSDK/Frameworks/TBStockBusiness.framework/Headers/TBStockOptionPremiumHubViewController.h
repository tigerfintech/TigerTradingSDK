//
//  TBStockOptionPremiumHubViewController.h
//  AFNetworking
//
//  Created by zlc on 2024/3/29.
//

#import <TBUIKit/TBListTableViewController.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,TBStockOptionPremiumHubVCType) {
    TBStockOptionPremiumHubVCTypeShortPut,
    TBStockOptionPremiumHubVCTypeCoveredCall,
};

@class TBStockDetailOptionPremiumHubModel;

@interface TBStockOptionPremiumHubViewController : TBListTableViewController

@property (nonatomic, assign) TBStockOptionPremiumHubVCType type;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *right;

@end

NS_ASSUME_NONNULL_END
