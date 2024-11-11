//
//  TBHKStockTurnOverTableViewCell.h
//  Stock
//
//  Created by luopengfei on 2019/1/29.
//  Copyright © 2019年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN
@protocol TBHKStockTurnOverTableViewCell <NSObject>

@property (nonatomic, readonly) NSString *stockName;
@property (nonatomic, readonly) NSString *stockSymbol;

@property (nonatomic, readonly) NSString *buyCount;
@property (nonatomic, readonly) NSString *sellCount;
@property (nonatomic, readonly) NSString *totalCount;
@property (nonatomic, readonly) NSString *rank;

@end

/**
 成交前十榜单
 */
@interface TBHKStockTurnOverTableViewCell : TBTableViewCell

@end

@interface TBHKStockTurnOverTableViewCellItem : TBTableViewCellItem
@property (nonatomic, strong) id<TBHKStockTurnOverTableViewCell> dataSource;

@property (nonatomic, assign, getter=isHeader) BOOL header;
@end

NS_ASSUME_NONNULL_END
