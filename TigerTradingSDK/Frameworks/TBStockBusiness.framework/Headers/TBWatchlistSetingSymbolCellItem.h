//
//  TBWatchlistSetingSymbolCellItem.h
//  TBStockBusiness
//
//  Created by zhengzhiwen on 2023/1/10.
//

#import <TBUIKit/TBTableViewCellItem.h>
#import <TBToolsKit/TBWatchListDisplayItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBWatchlistSetingSymbolCellItem : TBTableViewCellItem

@property (nonatomic, copy) void (^sortChange)(TBWatchListItemSortType type);

@property (nonatomic, assign) TBWatchListSortType sortType;
@property (nonatomic, assign) TBWatchListItemSortType nameItemSortType;

@end

NS_ASSUME_NONNULL_END
