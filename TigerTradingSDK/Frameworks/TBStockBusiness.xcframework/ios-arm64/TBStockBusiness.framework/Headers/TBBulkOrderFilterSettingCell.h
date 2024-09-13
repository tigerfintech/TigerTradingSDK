//
//  TBStockFilterSettingCell.h
//  StockBusiness
//
//  Created by mashanli on 2022/10/12.
//  Copyright © 2022 com.tigerbrokers. All rights reserved.
//
@class TBOptionTabBulkOrderFilterModel;
#import <TBUIKit/TBTableViewCell.h>

@interface TBBulkOrderFilterSettingCell : TBTableViewCell

@end


@interface TBBulkOrderFilterSettingCellItem : TBTableViewCellItem

@property (nonatomic, strong) TBOptionTabBulkOrderFilterModel *model;

@end

