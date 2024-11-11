//
//  TBWatchlistModeCellItem.h
//  TBStockBusiness
//
//  Created by zhengzhiwen on 2023/1/10.
//

#import <TBUIKit/TBTableViewCellItem.h>
#import <TBStockBusinessBaseKit/TBWatchListDisplayItemManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBWatchlistModeCellItem : TBTableViewCellItem

@property (nonatomic, copy) void (^modeChange)(TBWatchlistMode mode);

@end

NS_ASSUME_NONNULL_END
