//
//  TBFundamentPriceLineCell.h
//  Stock
//
//  Created by 骆朋飞 on 2017/4/10.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBCollectionViewCell.h>
#import <TBUIKit/TBCollectionViewCellItem.h>
#import <TBThirdParty/IGListKit.h>
#import <TBUIKit/TBCollectionViewCellItem.h>

/**
 显示行情变动信息cell
 */
@interface TBFundamentPriceLineCell : TBCollectionViewCell

@end

@interface TBFundamentPriceLineCellItem : TBCollectionViewCellItem <IGListDiffable>

@property (nonatomic, assign) double minPrice;
@property (nonatomic, assign) double maxPrice;
@property (nonatomic, assign) double openPrice;
@property (nonatomic, assign) double close;

/**
 盘中为最新的价格，盘后为收盘价值
 */
@property (nonatomic, assign) double latestPrice;

@property (nonatomic, copy) NSString *descriptionString;

@property (nonatomic, copy) NSString *market;

@property (nonatomic, copy) NSString *secType;

@end
