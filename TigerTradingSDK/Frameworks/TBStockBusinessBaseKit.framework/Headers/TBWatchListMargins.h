//
//  TBWatchListMargins.h
//  Stock
//
//  Created by zhenglanchun on 2021/4/29.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBWatchListMargins : NSObject

- (void)configCalculatedViewShortSide:(CGFloat)calculatedWidth;
- (CGFloat)fetchCalculatedWidth;


// MARK: 竖屏下自选cell布局
// | - hSpace - leftOne - | - leftTwo - | - rightTwo - | - rightOne - hSpace -|

- (CGFloat)horizontalSpace;

// 占比34%
- (CGFloat)portraitLeftOneAreaSpace;

// 占比18
- (CGFloat)portraitLeftTwoAreaSpace;

// 占比26
- (CGFloat)portraitRightOneAreaSpace;

// 占比22
- (CGFloat)portraitRightTwoAreaSpace;

// 左侧整体占比大小：horizontalSpace + leftOne + leftTwo
- (CGFloat)totalPortraitLeftSpace;

// MARK: 横屏下自选cell布局
// | - hSpace - leftOne - | - leftTwo - | - right...  - hSpace -|
// 占比44
- (CGFloat)landscapeLeftOneSpace;

// 占比29
- (CGFloat)landscapeLeftTwoSpace;

// 横屏的1/4大小
- (CGFloat)landscapeRightWidth;

/// 占比1/100
- (CGFloat)getSplitWidth;

/// 获取横屏时collectionView的宽度
- (CGFloat)getLandscapeCollectionViewWidthWithCount: (NSInteger)count;

@end

NS_ASSUME_NONNULL_END
