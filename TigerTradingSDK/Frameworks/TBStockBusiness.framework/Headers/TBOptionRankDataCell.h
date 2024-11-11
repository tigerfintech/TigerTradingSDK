//
//  TBOptionRankDataCell.h
//  Stock
//
//  Created by 王灵博 on 2021/7/29.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
#import "TBOptionAnalysisHeader.h"
@class TBOptionRankDataModel;
NS_ASSUME_NONNULL_BEGIN

@interface TBOptionRankDataCell : TBTableViewCell

@end


@interface TBOptionRankDataCellItem : TBTableViewCellItem
@property(nonatomic ,strong)TBOptionRankDataModel *dataModel;
@property(nonatomic, assign)TBOptionChangeType optionType;
@end

NS_ASSUME_NONNULL_END
