//
//  TBStockOptionPremiumDetailTradeOrderCell.h
//  TBStockBusiness
//
//  Created by zlc on 2024/4/2.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@class TBStockOptionPremiumTradeOrderModel;

@interface TBStockOptionPremiumDetailTradeOrderCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *saPage;
@property (nonatomic, strong) TBStockOptionPremiumTradeOrderModel *model;

@end


@interface TBStockOptionPremiumDetailTradeOrderCell : TBTableViewCell

@end

NS_ASSUME_NONNULL_END
