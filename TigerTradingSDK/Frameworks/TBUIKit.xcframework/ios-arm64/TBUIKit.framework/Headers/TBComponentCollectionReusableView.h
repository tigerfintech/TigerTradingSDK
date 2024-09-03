//
//  TBComponentCollectionReusableView.h
//  TBComponentList
//
//  Created by JustLee on 2019/10/15.
//  Copyright © 2019 JustLee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBComponentCollectionCellItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBComponentCollectionReusableView : UICollectionReusableView

@property (nonatomic, strong) TBComponentCollectionCellItem *collectionViewCellItem;

@property (nonatomic, assign) BOOL enableTapAction;

@property (nonatomic, assign) BOOL enableLongPressAction;

@end

NS_ASSUME_NONNULL_END
