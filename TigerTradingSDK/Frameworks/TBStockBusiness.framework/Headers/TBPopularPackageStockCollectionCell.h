//
//  TBPopularPackageStockCollectionCell.h
//  Stock
//
//  Created by zhenglanchun on 2021/8/2.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBStockBusinessBaseKit/TBExcelTableCollectionCell.h>
#import <TBStockBusinessBaseKit/TBExcelTableConfigOptions.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBPopularPackageStockCollectionCell : TBExcelTableCollectionCell

@property (nonatomic, strong) UILabel * topLabel;
@property (nonatomic, strong) UILabel * bottomLabel;

@end

NS_ASSUME_NONNULL_END
