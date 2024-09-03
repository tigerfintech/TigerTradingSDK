//
//  TBOrderHourTradingCell.h
//  Stock
//
//  Created by donggongfu on 16/2/22.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

#pragma mark - TBOrderHourTradingCell

@interface TBOrderHourTradingCell : TBTableViewCell

@end

@protocol TBOrderHourTradingCell <NSObject>

@optional
- (NSString *)hourTradingCellTagString;

- (NSString *)latestPriceTag;

- (NSString *)hourTradingCellPriceString;
- (UIColor *)hourTradingCellPriceColor; // price, change, changePercent颜色逻辑相同
- (NSString *)hourTradingCellChangeString;
- (NSString *)hourTradingCellChangePercentString;
- (NSString *)hourTradingCellTimeString;

@end


#pragma mark - TBOrderHourTradingCellItem

@interface TBOrderHourTradingCellItem : TBTableViewCellItem

@property (nonatomic, weak) id<TBOrderHourTradingCell> dataSource;
@property (nonatomic, assign) BOOL showOptionChain;

@property (nonatomic, assign) BOOL isInPlaceOrder;///< 是否在下单页

@end

