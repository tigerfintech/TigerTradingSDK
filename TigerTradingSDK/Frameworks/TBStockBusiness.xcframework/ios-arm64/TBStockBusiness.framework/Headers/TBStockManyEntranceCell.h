//
//  TBStockManyEntranceCell.h
//  Stock
//
//  Created by 王灵博 on 2020/7/15.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
@class TBBaseModelBuryingPointModel;
NS_ASSUME_NONNULL_BEGIN

@interface TBStockManyEntranceCell : TBTableViewCell

@end

@interface TBStockManyEntranceCellItem : TBTableViewCellItem
@property(nonatomic, strong)TBBaseModelBuryingPointModel *buryingPointModel;
@property(nonatomic, copy)NSString *market;
@property (nonatomic, assign) NSInteger currentIndex;
@end

NS_ASSUME_NONNULL_END
