//
//  TBStockHeatMapCollectionViewLayout.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/5/1.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBStockHeatMapModel.h"

static CGFloat minSpace = 0.;

NS_ASSUME_NONNULL_BEGIN

@interface TBStockHeatMapCollectionViewLayout : UICollectionViewLayout

@property (nonatomic, copy) NSArray<TBStockHeatMapItemModel> *items;


@property (nonatomic, assign, readonly) CGFloat collectionWidth;
@property (nonatomic, assign, readonly) CGFloat collectionHeight;

@property (nonatomic) CGFloat scale;
@property (nonatomic, assign) CGFloat maxScale;
@property (nonatomic, assign, readonly) CGFloat minScale;

@property (nonatomic, strong, readonly) NSMutableArray *cellLabelFonts;
@property (nonatomic, strong, readonly) NSMutableArray *cellChangeLabelFonts;

@property (nonatomic, assign) BOOL showChangeRatio;

@end

NS_ASSUME_NONNULL_END
