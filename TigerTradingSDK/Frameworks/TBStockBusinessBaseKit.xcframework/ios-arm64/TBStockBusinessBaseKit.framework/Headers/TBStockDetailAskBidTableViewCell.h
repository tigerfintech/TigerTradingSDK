//
//  TBStockDetailAskBidTableViewCell.h
//  Stock
//
//  Created by mashanli on 2022/6/27.
//  Copyright © 2022年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
#import <TBStockBusinessBaseKit/TBUStockAskBidTableViewCell.h>

@interface TBStockDetailAskBidTableViewCell : TBTableViewCell

@end

@interface TBStockDetailAskBidTableViewCellItem : TBTableViewCellItem

@property (nonatomic, weak) id<TBUStockAskBidTableViewCell> dataSource;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, copy) NSString *exchangeCode;
@property (nonatomic, assign) BOOL isStockOTC;
@property (nonatomic, assign) BOOL isIndex;

@end
