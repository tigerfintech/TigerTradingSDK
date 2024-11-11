//
//  TBWatchlistSettingLabelFoldCellItem.h
//  TBStockBusiness
//
//  Created by mashanli on 2024/5/10.
//

#import <TBUIKit/TBTableViewCellItem.h>
#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN


@interface TBWatchlistSettingLabelFoldCell : TBTableViewCell

@end



@interface TBWatchlistSettingLabelFoldCellItem : TBTableViewCellItem

@property (nonatomic, assign) BOOL isFold;
@property (nonatomic, strong) void(^arrowBlock)(BOOL isFold);

@end

NS_ASSUME_NONNULL_END
