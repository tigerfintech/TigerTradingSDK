//
//  TBCollectionViewLeftAlignedLayout.h
//  TBUIKit
//
//  Created by chenxin on 2024/3/29.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Copy from https://github.com/mokagio/UICollectionViewLeftAlignedLayout
 */
@interface TBCollectionViewLeftAlignedLayout : UICollectionViewFlowLayout

@end

/**
 *  Just a convenience protocol to keep things consistent.
 *  Someone could find it confusing for a delegate object to conform to UICollectionViewDelegateFlowLayout
 *  while using UICollectionViewLeftAlignedLayout.
 */
@protocol TBCollectionViewDelegateLeftAlignedLayout <UICollectionViewDelegateFlowLayout>

@end

NS_ASSUME_NONNULL_END
