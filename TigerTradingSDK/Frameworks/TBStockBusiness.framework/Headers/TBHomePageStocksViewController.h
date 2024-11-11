//
//  TBHomePageStocksViewController.h
//  TBStockBusiness
//
//  Created by wind on 2022/3/18.
//

#import <TBUIKit/TBBaseViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBHomePageStocksViewController : TBBaseViewController

@property (nonatomic, copy) NSArray *marketEns;
@property (nonatomic, copy) NSArray *marketNames;
@property (nonatomic, copy) NSArray *changeSelectionComponents;

@end

NS_ASSUME_NONNULL_END
