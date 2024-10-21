//
//  TBStockRightLikeView.h
//  Stock
//
//  Created by 王灵博 on 2020/4/30.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CCDraggableCardView.h"
NS_ASSUME_NONNULL_BEGIN
@class TBStockRightLikeModel;
@interface TBStockRightLikeView : CCDraggableCardView
@property(nonatomic,strong)TBStockRightLikeModel *cardModel;
@end

NS_ASSUME_NONNULL_END
