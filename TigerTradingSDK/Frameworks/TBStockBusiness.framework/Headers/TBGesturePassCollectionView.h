//
//  TBGesturePassCollectionView.h
//  Stock
//
//  Created by yangfan on 2019/6/20.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef CGFloat (^GetWatchListItemsBlock)(void);
@interface TBGesturePassCollectionView : UICollectionView
@property (nonatomic, strong) UIView * gestureAttachView;
@end

NS_ASSUME_NONNULL_END
