//
//  TBExcelTableConfigOptions.h
//  Stock
//
//  Created by zhenglanchun on 2021/8/5.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const TB_EXCEL_TABLE_DIDSCROLL_NOTIFIDIC_KEY;

/** configOptions 配置项
 *  提供默认配置项，如果需要不同的配置项，需要子类TBExcelTableConfigOptions，并在其中修改get方法。
 */
@protocol TBExcelTableConfigOptionsDataSource <NSObject>

@optional
- (CGSize)tbexcelTableCollectionCellItemSizeAtIndexPath:(NSIndexPath *)indexPath;

- (CGSize)tbexcelTableCollectionHeaderCellItemSizeAtIndexPath:(NSIndexPath *)indexPath;

@end

@interface TBExcelTableConfigOptions : NSObject

@property (nonatomic, assign) BOOL customItemSizeWidthEnable; ///collectionViewItemSize可变配置
@property (nonatomic, assign) BOOL sizeProvidedByConfig; ///collectionViewItemSize信息由子类提供，配合customItemSizeWidthEnable使用

@property (nonatomic, weak, nullable) id<TBExcelTableConfigOptionsDataSource> delegate;

- (instancetype)initWithCustomItemSizeEnbale:(BOOL)isCustomItemSizeEnable delegate:(id<TBExcelTableConfigOptionsDataSource> __nullable)delegate;

- (CGFloat)leftContainerViewWidth;//左侧容器大小
- (CGFloat)leftContentViewWidth;//左侧内容区大小

- (CGFloat)leftHorizontalMargin; // 左侧间距大小
- (CGFloat)rightHorizontalMargin; // 右侧间距大小

- (CGFloat)defaultSizeWidth;
- (CGFloat)minimumLineSpacing;
- (CGFloat)itemSizeWidth;
- (CGFloat)itemSizeHeight;

// 子类实现，提供统一的size信息
- (NSValue * __nullable)collectionCellItemSizeAtIndexPath:(NSIndexPath *)indexPath;
- (NSValue * __nullable)collectionHeaderItemSizeAtIndexPath:(NSIndexPath *)indexPath;

+ (UICollectionView *)createCollectionViewWithCellClass: (nullable Class)cellClass itemSize: (CGSize)size minimumLineSpacing:(NSNumber *)minimumLineSpacing;

@end

NS_ASSUME_NONNULL_END
