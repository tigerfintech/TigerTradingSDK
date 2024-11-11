//
//  TBDoubleRollCell.h
//  Stock
//
//  Created by dull grass on 2019/12/4.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
@class TBOptionChainDetailItemViewModel;
@class TBDoubleRollCell;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TBHideLineType) {
    TBHideLineTypeBottom,    //!< 一条线，展示全
    TBHideLineTypeBothCall,  //!< 一条线，call
    TBHideLineTypeBothPut,   //!< 一条线，Put
    TBHideLineTypeBothNode,  //!< 没有线
};

typedef void(^updateCellDataBlock)(NSIndexPath *cellIndexPath, UICollectionView *collectionView,void(^complete)(TBOptionChainDetailItemViewModel * _Nullable model));

typedef NSInteger(^numberOfItemsInSectionBlock)(NSInteger section);
typedef CGSize(^sizeForItemAtIndexPathBlock)(UICollectionViewLayout * collectionViewLayout, NSIndexPath *indexPath);
typedef void(^ContentViewCellDidScrollBlock)(UIScrollView *scroll);
typedef void(^cellDidSelectedBlock)(BOOL call, NSString *strike,NSString *symbol);

@interface TBDoubleRollCell : UITableViewCell <UICollectionViewDelegate, UICollectionViewDataSource,UIScrollViewDelegate>

@property (nonatomic, strong) UICollectionView *leftContentView;

@property (nonatomic, strong) UICollectionView *rightContentView;

@property (nonatomic, strong) UIView *leftBackView;

@property (nonatomic, strong) UIView *rightBackView;

@property (nonatomic, strong) UIView *callSelectedView;
@property (nonatomic, strong) UIView *putSelectedView;

@property (nonatomic, strong) UIView *strikeBack;
@property (nonatomic, strong) UILabel *strikeLabel;

@property (nonatomic, copy) NSString *symbol;//旧期权symbol 与期权链所用symbol不一样

@property (nonatomic, strong)  CAGradientLayer *leftGradientLayer;

@property (nonatomic, strong)  CAGradientLayer *rightGradientLayer;

@property (nonatomic, copy) NSArray *dataSource;

@property (nonatomic, copy) NSArray *downDataSource;

@property (nonatomic, assign) BOOL hideBottomView;

@property (nonatomic, assign) TBHideLineType lineType;

@property (nonatomic, copy) CGFloat(^strikeWidthBlock)(void);
@property (nonatomic, strong) updateCellDataBlock updateDataBlock;
@property (nonatomic, copy) numberOfItemsInSectionBlock numberOfItemsBlock;
@property (nonatomic, strong) sizeForItemAtIndexPathBlock sizeForItemBlock;
@property (nonatomic, strong) ContentViewCellDidScrollBlock contentViewCellDidScrollBlock;
@property (nonatomic, strong) cellDidSelectedBlock cellDidSelectedBlock;
@property (nonatomic, assign) BOOL scrollEnable;

@property (nonatomic, strong) UIImageView *oldImg;

- (void)reloadData;

@end

NS_ASSUME_NONNULL_END
