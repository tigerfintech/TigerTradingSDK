//
//  TBOptionVolIntroCell.h
//  TBStockBusiness
//
//  Created by 王灵博 on 2021/12/16.
//

#import <TBUIKit/TBTableViewCell.h>
#import <TBStockBusinessBaseKit/TBStockDetailBaseTableViewCell.h>

@class TBOptionDetailIVIndexModel;
NS_ASSUME_NONNULL_BEGIN

@interface TBOptionVolIntroCell : TBStockDetailBaseTableViewCell

@end

@interface TBOptionVolIntroCellItem : TBStockDetailBaseTableViewCellItem
@property(nonatomic, copy) NSString *market;
@property(nonatomic, assign) BOOL isHistory;//是否为历史波动率
@property(nonatomic, copy) NSArray <TBOptionDetailIVIndexModel *> * ivIndexArray;
@end

NS_ASSUME_NONNULL_END
