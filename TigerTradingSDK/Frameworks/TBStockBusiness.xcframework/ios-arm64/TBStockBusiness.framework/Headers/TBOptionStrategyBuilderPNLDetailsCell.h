//
//  TBOptionStrategyBuilderPNLDetailsCell.h
//  TBStockBusiness
//
//  Created by zlc on 2022/8/8.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@class TBOptionStrategyBuilderStrategyModel;
@class TBOptionStrategyBuilderFundamentalModel;

@interface TBOptionStrategyBuilderPNLDetailsCellItem : TBTableViewCellItem

@property (nonatomic, strong) TBOptionStrategyBuilderFundamentalModel *greekModel;

@property (nonatomic, strong) TBOptionStrategyBuilderStrategyModel *moodStrategy;

@property (nonatomic, copy) NSArray <NSDictionary *> *detailDatas;

//@property (nonatomic, assign) BOOL isAllAddedToWatchList; //是否所有的期权组合都加到自选列表

@property (nonatomic, assign) BOOL isValidPrice;

@end


@interface TBOptionStrategyBuilderPNLDetailsCell : TBTableViewCell

@end

NS_ASSUME_NONNULL_END
