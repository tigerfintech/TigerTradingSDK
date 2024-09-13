//
//  TBSortItemCollectionCell.h
//  Stock
//
//  Created by dull grass on 2019/11/29.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TBOptionChainDetailItemViewModel;

NS_ASSUME_NONNULL_BEGIN

@interface TBSortItemCollectionCell : UICollectionViewCell
@property (nonatomic, strong) UILabel *textLabel;
@property (nonatomic, strong) UILabel *subTitleLabel;
@property (nonatomic, strong) TBOptionChainDetailItemViewModel *viewModel;
@end

@interface TBSortTowItemCollectionCell : UICollectionViewCell
@property (nonatomic, strong) UILabel *upTitleLabel;
@property (nonatomic, strong) UILabel *upSubTitleLabel;
@property (nonatomic, strong) UILabel *downTitleLabel;
@property (nonatomic, strong) UILabel *downSubTitleLabel;
@property (nonatomic, strong) TBOptionChainDetailItemViewModel *topViewModel;
@property (nonatomic, strong) TBOptionChainDetailItemViewModel *bottomViewModel;
@end
 

NS_ASSUME_NONNULL_END
