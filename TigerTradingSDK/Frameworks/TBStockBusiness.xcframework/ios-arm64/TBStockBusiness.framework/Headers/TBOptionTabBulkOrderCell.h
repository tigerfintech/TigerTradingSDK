//
//  TBOptionTabBulkOrderCell.h
//  Stock
//
//  Created by mashanli on 2023/6/19.
//  Copyright © 2023年 com.tigerbrokers. All rights reserved.
//
@class TBOptionTabBulkOrderModel;
@class TBOptionTabBulkOrderContentCellItem;
#import <TBUIKit/TBTableViewCell.h>

@interface TBOptionTabBulkOrderCell : TBTableViewCell

@end


@interface TBOptionTabBulkOrderCellItem : TBTableViewCellItem

@property (nonatomic, strong) TBOptionTabBulkOrderModel *model;
@property (nonatomic, copy) NSArray<TBOptionTabBulkOrderContentCellItem *> *subItems;

@end
