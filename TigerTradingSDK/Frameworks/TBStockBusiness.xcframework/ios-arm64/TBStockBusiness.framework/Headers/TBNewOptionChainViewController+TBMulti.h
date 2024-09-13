//
//  TBNewOptionChainViewController+TBMulti.h
//  TBStockBusiness
//
//  Created by mashanli on 2023/4/19.
//

@class TBMultiOptionChainItemModel;
@class TBOptionChainShoppingModel;

#import "TBNewOptionChainViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBNewOptionChainViewController (TBMulti)

- (void)selectStrategy;
- (void)selectPriceWidth;
- (void)selectCalendarWidth;
- (void)selectDiagonalWidth;
- (void)selectStrategyAnalytics;
- (void)addOrRemoveWatchList;
- (void)multiOptionTradeIfNeed;
- (BOOL)isWithinWatchList;

// request
- (void)fetchMultiOptionChainData:(BOOL)showLoading completion:(nullable void (^)(TBMultiOptionChainModel * _Nullable model, NSError * _Nullable error))completion;
- (void)fetchMultiOptionChainExpiryData:(BOOL)showLoading completion:(nullable void (^)(TBMultiOptionChainExpiryModel * _Nullable model, NSError * _Nullable error))completion;

- (void)handleMultiSimpleOption:(NSArray *)items scrollToStrike:(BOOL)scrollToStrike;

/// 计算组合展示数据，存放在 self.multiDataSource 中
- (void)calculateMultiDataSource;

- (void)calculateMultiSDKDataSource;

/// 根据下标获取 self.multiDataSource 中的数据，返回 all list 列表展示数据
/// - Parameters:
///   - itemsIndex: itemsIndex
///   - itemIndex: itemIndex
- (NSArray *)getMultiItemDataSourceWithItemsIndex:(NSInteger)itemsIndex itemIndex:(NSInteger)itemIndex;

//更新购物车高度
- (void)showShoppingPanel:(BOOL)animated;
- (void)dismissShoppingPanel;

- (void)showStrategyTipIfNeed;

- (void)showMlegSelectStrategyGuideIfNeeded;

- (void)handleMultiActionForCell:(nullable TBTableViewCell *)cell object:(nullable TBTableViewCellItem *)item info:(id)info;

- (void)changeRightWithModel:(TBOptionChainShoppingModel *)model;

- (void)removeWithModel:(TBOptionChainShoppingModel *)model;

- (void)refreshSelectedCell;

- (BOOL)checkSelectedWithKey:(NSString *)combinedKey;

/// 只支持 single 列表样式
- (BOOL)onlySingleTable;

@end

NS_ASSUME_NONNULL_END
