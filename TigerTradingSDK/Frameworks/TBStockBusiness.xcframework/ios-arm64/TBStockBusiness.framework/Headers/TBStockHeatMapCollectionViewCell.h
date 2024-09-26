//
//  TBStockHeatMapCollectionViewCell.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/5/4.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockHeatMapCollectionViewCell : UICollectionViewCell

@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UILabel *changeRatioLabel;
@property (nonatomic, strong) UIImageView *backView;

@property (nonatomic, assign) BOOL showChangeRatio;

@end

NS_ASSUME_NONNULL_END
