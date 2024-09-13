//
//  TBOptionMarketTableCellItem.h
//  Stock
//
//  Created by liwt on 2/15/16.
//  Copyright © 2016 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCellItem.h>
@class TBOptionChainItemModel;
@class TBOptionExpiryItemModel;
#import <TBUIKit/TBTableViewCell.h>


@interface TBOptionMarketTableCellItem : TBTableViewCellItem


@property (nonatomic, strong) TBOptionChainItemModel *callItem;
@property (nonatomic, strong) TBOptionChainItemModel *putItem;
@property (nonatomic, strong) TBOptionChainItemModel *item;
@property (nonatomic, copy) NSString *market;

@end


@interface TBOptionMarketTableCell : TBTableViewCell

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, strong) TBOptionExpiryItemModel *expiry;
@property (nonatomic, copy) NSString *strikeValue;

//
@property (nonatomic, strong) UIView *callView;
@property (nonatomic, strong) UIView *putView;
@property (nonatomic, strong) UIScrollView *scrollPartView;
//
@property (nonatomic, strong) UILabel *callAskPrice;
@property (nonatomic, strong) UILabel *callAskSize;
@property (nonatomic, strong) UILabel *callBidPrice;
@property (nonatomic, strong) UILabel *callBidSize;
@property (nonatomic, strong) UILabel *callChangeRate;
@property (nonatomic, strong) UILabel *callLatestPrice;
@property (nonatomic, strong) UILabel *callVolume;
@property (nonatomic, strong) UILabel *callOpenInt;
//
@property (nonatomic, strong) UILabel *strike;
@property (nonatomic, strong) UIView *strikeView;
//
@property (nonatomic, strong) UILabel *putLatestPrice;
@property (nonatomic, strong) UILabel *putChangeRate;
@property (nonatomic, strong) UILabel *putAskPrice;
@property (nonatomic, strong) UILabel *putAskSize;
@property (nonatomic, strong) UILabel *putBidPrice;
@property (nonatomic, strong) UILabel *putBidSize;
@property (nonatomic, strong) UILabel *putVolume;
@property (nonatomic, strong) UILabel *putOpenInt;
//

@end
