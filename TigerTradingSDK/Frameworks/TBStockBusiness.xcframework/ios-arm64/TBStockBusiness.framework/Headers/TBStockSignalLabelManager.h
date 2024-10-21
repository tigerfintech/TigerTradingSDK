//
//  TBStockSignalLabelManager.h
//  StockBusiness
//
//  Created by liuhuan on 2024/5/21.
//  Copyright © 2024 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TBWatchListTableCellItem;

NS_ASSUME_NONNULL_BEGIN

@interface TBStockSignalLabelManager : NSObject

+ (instancetype)manager;

- (void)fetchStockSignalLabelWithArray:(NSArray *)array;

- (void)updateSettingConfig;
/// 获取自选标签图标数组，必须传入item，因为部分标签来自本地
- (NSArray<UIImage *> *)getImageArrayWithItem:(TBWatchListTableCellItem *)item;
/// 获取示例标签图标数组
- (NSArray<UIImage *> *)getExampleLabelImageArray;
/// 获取所有信号标签数组
- (NSArray<NSString *> *)getAllSignalLabelArray;
/// 获取所有状态标签数组
- (NSArray<NSString *> *)getAllStatusLabelArray;
/// 获取所有可设置标签数组
- (NSArray<NSString *> *)getAllSettingLabelArray;
/// 通过标签得到对应标签图标
- (UIImage *)getLabelImageWidthLabel:(NSString *)label;
/// 通过标签得到对应标签文案
- (NSString *)getLabelTextWidthLabel:(NSString *)label;
/// 通过标签得到对应设置图标
- (UIImage *)getSettingImageWidthLabel:(NSString *)label;
/// 通过标签得到对应设置选项文案数组
- (NSArray<NSString *> *)getSettingOptionArrayWidthLabel:(NSString *)label;
/// 通过标签得到对应设置选项已选择索引，从0开始
- (NSInteger)getSettingSelectedIndexWidthLabel:(NSString *)label;
/// 修改设置选项选择索引
- (void)setSettingSelectedIndex:(NSInteger)index label:(NSString *)label;

@end

NS_ASSUME_NONNULL_END
