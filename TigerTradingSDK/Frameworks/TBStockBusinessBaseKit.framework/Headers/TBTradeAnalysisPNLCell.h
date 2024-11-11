//
//  TBTradeAnalysisPNLCell.h
//  Stock
//
//  Created by donggongfu on 16/1/4.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
@class TBFuturesContractModel;
typedef enum : NSUInteger {
    TBStockTradeAnalysisSortTypeNone,  //!<
    TBStockTradeAnalysisSortTypeAscending, //!< 根据日期升序
    TBStockTradeAnalysisSortTypeDesending, //!< 根据日期降序
} TBStockTradeAnalysisSortType;

@protocol TBTradeAnalysisPNLCellProtocol <NSObject>

- (NSString *)dateString;
- (NSString *)actionString;
- (NSString *)quantityString;
- (NSString *)priceString;
- (NSString *)profitLossString;
- (NSTimeInterval)sortDate;
@optional
- (double)priceDouble;
- (NSString *)currencyString;
- (UIColor *)actionColor;
- (UIColor *)priceColor;

- (NSString *)preciseDate;
- (NSString *)foundsStatus;

- (NSString *)dateStringWithFormatter:(NSString *)formatter;

@end

@interface TBTradeAnalysisPNLCell : TBTableViewCell

@end

@interface TBTradeAnalysisPNLCellItem : TBTableViewCellItem

@property (nonatomic, strong) id<TBTradeAnalysisPNLCellProtocol> dataSource;

@property (nonatomic, assign, getter=isHeader) BOOL header;
@property (nonatomic, assign) TBStockTradeAnalysisSortType sortType;

@property (nonatomic, strong) TBFuturesContractModel *contractModel;
@property (nonatomic, copy) NSString *segType;

@property (nonatomic, assign) BOOL showShare;
@property (nonatomic, assign) BOOL showProfitLoss;

@end

