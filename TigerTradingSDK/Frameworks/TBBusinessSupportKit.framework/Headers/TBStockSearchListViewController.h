//
//  TBStockSearchListViewController.h
//  TBBusinessSupportKit
//
//  Created by swordzhou on 10/15/23.
//

#import <TBUIKit/TBListTableViewController.h>

NS_ASSUME_NONNULL_BEGIN

@class TBStockLandSearchModel;

@interface TBStockSearchListViewController : TBListTableViewController

@property (nonatomic, copy) NSString *keyword;

@property (nonatomic, strong)  void(^didSelectedStockModelBlock)(TBStockLandSearchModel *stockModel);
@property (nonatomic, strong)  void(^cancelSearchBlock)(void);

@end

NS_ASSUME_NONNULL_END
