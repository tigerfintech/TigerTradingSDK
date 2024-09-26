//
//  TBStockQuoteHeatMapTableViewCell.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/5/3.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
#import "TBStockHeatMapView.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBStockQuoteHeatMapTableViewCell : TBTableViewCell

@end

@interface TBStockQuoteHeatMapTableViewCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSArray<TBStockHeatMapItemModel> *heatMapModels;
@property (nonatomic, copy) NSString *market;

@end

NS_ASSUME_NONNULL_END
