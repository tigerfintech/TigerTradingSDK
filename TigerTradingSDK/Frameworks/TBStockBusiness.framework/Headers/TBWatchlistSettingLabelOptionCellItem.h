//
//  TBWatchlistSettingLabelOptionCellItem.h
//  TBStockBusiness
//
//  Created by mashanli on 2024/5/10.
//

#import <TBUIKit/TBTableViewCellItem.h>
#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN


@interface TBWatchlistSettingLabelOptionCell : TBTableViewCell

@end



@interface TBWatchlistSettingLabelOptionCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *labelKey;

@end

NS_ASSUME_NONNULL_END
