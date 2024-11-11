//
//  TBOptionStrategyAnalysisViewController.h
//  TBStockBusiness
//
//  Created by 王昌阳 on 2023/4/13.
//

#import <TBUIKit/TBListTableViewController.h>
#import "TBOptionStrategyAnalysisDataManager.h"
@class TBOptionInfoDetailItem, TBStockInfoDetailItemModel, TBPlaceOrderMLegModel;
NS_ASSUME_NONNULL_BEGIN

@interface TBOptionStrategyAnalysisViewController : TBListTableViewController

/// 来源
@property (nonatomic, copy) TBOptionStrategyAnalysisFromType fromType;

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *right;
@property (nonatomic, strong) NSNumber *expiry;
@property (nonatomic, copy) NSString *strike;
@property (nonatomic, copy) NSString *stockSecType;

@property (nonatomic, strong) NSNumber *netEstetmatedValue;
@property (nonatomic, strong, nullable) NSNumber *netSpread; /// 下单页 netValue - midPrice 的结果
@property (nonatomic, strong, nullable) NSNumber *netQuantity; /// 下单页quantity
@property (nonatomic, strong) TBPlaceOrderMLegModel *mlegModel;

@property (nonatomic, strong) TBOptionInfoDetailItem *optionItem;
@property (nonatomic, strong) TBStockInfoDetailItemModel *stockModel;

@property (nonatomic, copy) dispatch_block_t selectedStatusBlock;

@property (nonatomic, strong, readonly) NSMutableArray *strategyBuilderMlist;

- (BOOL)checkIsFromPlaceOrder;

@end

NS_ASSUME_NONNULL_END
