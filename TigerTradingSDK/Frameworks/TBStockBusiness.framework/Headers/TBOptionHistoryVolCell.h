//
//  TBOptionHistoryVolCell.h
//  TBStockBusiness
//
//  Created by 王灵博 on 2021/12/13.
//

#import <TBUIKit/TBTableViewCell.h>
@class TBOptionDetailIVIndexModel;
NS_ASSUME_NONNULL_BEGIN

@interface TBOptionHistoryVolCell : TBTableViewCell

@end


@interface TBOptionHistoryVolCellItem : TBTableViewCellItem
@property(nonatomic, copy) NSArray <TBOptionDetailIVIndexModel *> * ivIndexArray;
@property(nonatomic, copy) NSString *market;
@property(nonatomic, assign) BOOL loadData;
@end

NS_ASSUME_NONNULL_END
