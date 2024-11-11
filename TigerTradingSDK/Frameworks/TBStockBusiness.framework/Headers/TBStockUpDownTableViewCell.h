//
//  TBStockUpDownTableViewCell.h
//  Stock
//
//  Created by 王灵博 on 2020/7/30.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN
@class TBMarketConditionsUpDownSummaryModel;
@interface TBStockUpDownTableViewCell : TBTableViewCell

@end


@interface TBStockUpDownTableViewCellItem : TBTableViewCellItem
@property(nonatomic, copy) NSArray *itemArray;

@property(nonatomic, strong) TBMarketConditionsUpDownSummaryModel *model;

@property(nonatomic, copy) NSString *market;

@end

NS_ASSUME_NONNULL_END
