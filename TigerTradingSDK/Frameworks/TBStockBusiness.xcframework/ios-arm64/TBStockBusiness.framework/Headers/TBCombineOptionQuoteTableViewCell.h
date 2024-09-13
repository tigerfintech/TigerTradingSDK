//
//  TBCombineOptionQuoteTableViewCell.h
//  Stock
//
//  Created by mashanli on 2023/6/19.
//  Copyright © 2023年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
#import <TBStockBusinessBaseKit/TBMultiOptionItem.h>

@interface TBCombineOptionQuoteTableViewCell : TBTableViewCell

@end


@interface TBCombineOptionQuoteTableViewCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *arriveFrom;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSArray<TBOptionChainAskBidRetModel> *originalQuotes;

@end
