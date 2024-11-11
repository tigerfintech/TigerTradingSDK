//
//  TBExcelTableViewProtocol.h
//  TBStockBusiness
//
//  Created by zhenglanchun on 2021/8/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBExcelTableViewProtocol <NSObject>

@end


@protocol TBExcelTableCollectionCellProtocol;
/// 类似excel所需要的属性，定义在协议里
@protocol TBExcelTablePropertyProtocol <NSObject>

@property (nonatomic, strong) UIView *leftContainerView; // 左侧容器大小，含遮挡区域
@property (nonatomic, strong) UIView *leftContentView; // 左侧内容区大小，不含遮挡区域
@property (nonatomic, strong) UIView *rightContainerView; // 右侧内容区大小
@property (nonatomic, strong) UICollectionView * collectionView; // 右侧collectinoView

@property (nonatomic, assign) BOOL isNotification;

- (void)setupViews;
- (void)setupLayouts;

- (Class<TBExcelTableCollectionCellProtocol>)collectionCellCls; // collectionCell类型

- (void)handleCollectionCellActionWithCell: (UICollectionViewCell *)cell info: (NSDictionary *)info;

@end


@protocol TBExcelTableCollectionCellProtocol <NSObject>

@property (nonatomic, copy) NSDictionary * dic;
@property (nonatomic, copy) void(^actionBlock)(UICollectionViewCell *cell, NSDictionary *info);

- (void)updateDictionary: (NSDictionary *)dic;

@end

NS_ASSUME_NONNULL_END
