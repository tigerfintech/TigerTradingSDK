//
//  TBExcelTableCell.h
//  Stock
//
//  Created by zhenglanchun on 2021/8/5.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
#import "TBExcelTableViewProtocol.h"

NS_ASSUME_NONNULL_BEGIN



@interface TBExcelTableCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSArray<NSDictionary *> *collectArray; // collectionView数据源

+ (CGFloat)cellHeight;

@property (nonatomic, copy) NSString *arriveFrom;


@end

@interface TBExcelTableCell : TBTableViewCell<TBExcelTablePropertyProtocol>

@property (nonatomic, strong)  CAGradientLayer *leftGradientLayer;

- (BOOL)collectionViewTapEnable; // collectionView整体添加点击能力

- (void)tapCollectionViewAction; // 点击整体collectionView的方法

- (BOOL)gradientLayerShowEnable; // 在collectionView滑动时，是否展示阴影

- (BOOL)gradientLayerShowForceEnable; // 阴影是否长驻，默认为NO


@end

NS_ASSUME_NONNULL_END
