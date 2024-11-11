//
//  TBComponentCollectionCell.h
//  TBComponentList
//
//  Created by JustLee on 2019/10/11.
//  Copyright © 2019 JustLee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBComponentCollectionCellItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBComponentCollectionCell : UICollectionViewCell

/**
 设置的cellItem，包含了外展属性，代理方法等
 */
@property (nonatomic, strong) TBComponentCollectionCellItem *collectionViewCellItem;

@property (nonatomic, assign) BOOL enableLongPressAction;

@end

NS_ASSUME_NONNULL_END
