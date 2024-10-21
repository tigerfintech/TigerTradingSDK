//
//  TBWatchlistSettingLabelArrayCellItem.h
//  TBStockBusiness
//
//  Created by mashanli on 2024/5/10.
//

#import <TBUIKit/TBTableViewCellItem.h>
#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBWatchlistSettingLabelCollectionCell : UICollectionViewCell

@end


@interface TBWatchlistSettingLabelArrayCell : TBTableViewCell

@end



@interface TBWatchlistSettingLabelArrayCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSArray<NSString *> *labelArray;

@end

NS_ASSUME_NONNULL_END
