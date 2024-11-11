//
//  TBWatchlistLabelVisibilityCellItem.h
//  TBStockBusiness
//
//  Created by mashanli on 2024/5/10.
//

#import <TBUIKit/TBTableViewCellItem.h>
#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBWatchlistLabelVisibilityCell : TBTableViewCell

@end



@interface TBWatchlistLabelVisibilityCellItem : TBTableViewCellItem

@property (nonatomic, strong) void(^arrowBlock)(void);
@property (nonatomic, assign) BOOL isSettingPage;//设置页

@end

NS_ASSUME_NONNULL_END
