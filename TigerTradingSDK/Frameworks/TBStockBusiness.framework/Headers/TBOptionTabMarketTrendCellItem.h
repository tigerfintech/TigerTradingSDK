//
//  TBOptionTabMarketTrendCellItem.h
//  AFNetworking
//
//  Created by chenxin on 2023/8/4.
//

#import <TBUIKit/TBTableViewCell.h>
#import <TBUIKit/TBTableViewCellItem.h>
#import "TBOptionTabMarketTrendModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionTabMarketTrendCell : TBTableViewCell

@end

@interface TBOptionTabMarketTrendCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSArray<TBOptionTabMarketTrendModel *> *marketTrends;

@end

NS_ASSUME_NONNULL_END
