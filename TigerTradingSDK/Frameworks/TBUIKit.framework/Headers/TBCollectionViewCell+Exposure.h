//
//  TBCollectionViewCell+Exposure.h
//  Stock
//
//  Created by 王昌阳 on 2020/12/3.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBCollectionViewCell.h"
#import "TBViewExposureDataSource.h"
#import "TBViewExposureLogicModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBCollectionViewCell (Exposure)<TBViewExposureDataSource>

@property (nonatomic, weak) UICollectionView *collectionView;
@property (nonatomic, strong) TBViewExposureLogicModel * _Nullable viewExposureLogic;

- (void)addViewExposureLogic;

@end

NS_ASSUME_NONNULL_END
