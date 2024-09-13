//
//  TBOptionChainGuideCell.h
//  Stock
//
//  Created by JustLee on 2020/12/22.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
@class TBOptionExpiryItemModel;
@class TBOptionChainModel;

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionChainGuideExpiryDateCell : TBTableViewCell

@end


@interface TBOptionChainGuideExpiryDateCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *market;

@property (nonatomic, strong) TBOptionExpiryItemModel *currentExpiryItem;

@property (nonatomic, strong) TBOptionChainModel *optionChainModel;

@property (nonatomic, assign, getter=isShowEstimatePrice) BOOL showEstimatePrice;

@property (nonatomic, assign, getter=isNoData) BOOL noData;

@end

NS_ASSUME_NONNULL_END
