//
//  TBOptionsEsitimatePriceTableViewCell.h
//  Stock
//
//  Created by JustLee on 2020/9/25.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBStockBusinessBaseKit/TBStockDetailBaseTableViewCell.h>

@class TBOptionInfoDetailItem;
@interface TBOptionsEsitimatePriceTableViewCell : TBStockDetailBaseTableViewCell
													
@end


@interface TBOptionsEsitimatePriceTableViewCellItem : TBStockDetailBaseTableViewCellItem

@property (nonatomic, strong) NSNumber *stockPrice;

@property (nonatomic, strong) NSNumber *expiryDate;

@property (nonatomic, strong) NSNumber *calculateDate;

@property (nonatomic, strong) NSNumber *strikePrice;

@property (nonatomic, strong) NSNumber *vixValue;

@property (nonatomic, strong) NSNumber *rateBonds;

@property (nonatomic, copy) NSString *market;

@property (nonatomic, copy) NSString *secType;

@property (nonatomic, copy) NSString *right;

@property (nonatomic, assign) BOOL isClose;

@property (nonatomic, strong) TBOptionInfoDetailItem *optionItem;

@property (nonatomic, assign) BOOL canResignFirstResponder;

@end
