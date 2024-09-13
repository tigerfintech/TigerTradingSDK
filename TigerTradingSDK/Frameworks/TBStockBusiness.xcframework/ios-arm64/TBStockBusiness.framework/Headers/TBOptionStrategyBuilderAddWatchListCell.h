//
//  TBOptionStrategyBuilderAddWatchListCell.h
//  TBStockBusiness
//
//  Created by zlc on 2022/10/12.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionStrategyBuilderAddWatchListCellItem : TBTableViewCellItem

@property (nonatomic, assign) BOOL isAllAddedToWatchList; //是否所有的期权组合都加到自选列表

@end


@interface TBOptionStrategyBuilderAddWatchListCell : TBTableViewCell

@end

NS_ASSUME_NONNULL_END
