//
//  TBStockNewCalendarCell.h
//  Stock
//
//  Created by 王灵博 on 2020/7/13.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
@class TBStockMarketCalendarModel;
NS_ASSUME_NONNULL_BEGIN

@interface TBStockNewCalendarCell : TBTableViewCell

@end

@interface TBStockNewCalendarCellItem : TBTableViewCellItem
@property(nonatomic, strong)TBStockMarketCalendarModel *model;
@property(nonatomic, copy)NSString *market;
@end

NS_ASSUME_NONNULL_END
