//
//  TBWatchlistTopGroupView.h
//  TBStockBusiness
//
//  Created by wind on 2022/2/24.
//

#import <TBUIKit/TBView.h>
@class TBWatchListGroup;

NS_ASSUME_NONNULL_BEGIN

@interface TBWatchlistTopGroupView : TBView
@property (nonatomic, strong, nullable) TBWatchListGroup *selectedGroup;      //选中的分组
@property (nonatomic, copy) void (^showMoreBlock)(void);
@property (nonatomic, copy) void(^changeSelectedGroupIndexPathBlock)(TBWatchListGroup *group);

/// 刷新数据
/// @param indexPath 选中的分组
- (void)updateTopGroupMenu;

- (void)scrollToSelected;
- (void)scrollToNextGroup;
- (void)scrollToPreviouseGroup;

- (BOOL)hasNext;
- (BOOL)hasPreviouse;

@end

NS_ASSUME_NONNULL_END
