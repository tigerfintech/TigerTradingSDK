//
//  TBDoubleRollHeader.h
//  Stock
//
//  Created by dull grass on 2019/12/4.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef void(^ContentViewCellDidScrollBlock)(UIScrollView *scroll);

@interface TBDoubleRollHeader : UIView <UICollectionViewDelegate, UICollectionViewDataSource,UIScrollViewDelegate>

/**
 左边title
 */
@property (nonatomic, strong) UICollectionView *leftTitleView;

/**
 右边title
 */
@property (nonatomic, strong) UICollectionView *rightTitleView;

@property (nonatomic, strong) UILabel *strikeLabel;

@property (nonatomic, copy) NSArray *dataSource;

@property (nonatomic, copy) ContentViewCellDidScrollBlock contentViewCellDidScrollBlock;

@property (nonatomic, assign) BOOL scrollEnable;

- (void)reloadData ;
@end

NS_ASSUME_NONNULL_END
