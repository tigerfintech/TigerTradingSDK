//
//  TBOptionRankingTableViewCell.h
//  TBStockBusiness
//
//  Created by 王昌阳 on 2023/8/3.
//

#import <TBUIKit/TBUIKit.h>
#import <TBUIKit/TBTableViewCell.h>
#import <TBUIKit/TBTableViewCellItem.h>
#import "TBOptionTabModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionRankingTableViewCell : TBTableViewCell

@end

@interface TBOptionRankingTableViewCellItem : TBTableViewCellItem

@property (nonatomic, strong) TBOptionTabRankModel *rankModel;

@end

NS_ASSUME_NONNULL_END
