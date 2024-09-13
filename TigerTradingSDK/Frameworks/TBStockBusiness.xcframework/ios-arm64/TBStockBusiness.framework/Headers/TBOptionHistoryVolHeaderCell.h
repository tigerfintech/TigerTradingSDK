//
//  TBOptionHistoryVolHeaderCell.h
//  TBStockBusiness
//
//  Created by 王灵博 on 2021/12/13.
//

#import <TBStockBusinessBaseKit/TBStockDetailBaseTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionHistoryVolHeaderCell : TBStockDetailBaseTableViewCell

@end


@interface TBOptionHistoryVolHeaderCellItem : TBStockDetailBaseTableViewCellItem
@property (nonatomic, copy) NSString *market;

@property (nonatomic, assign) BOOL isStrategyBuilder;

@end

NS_ASSUME_NONNULL_END
