//
//  TBOptionChainOptionDetailCell.h
//  Stock
//
//  Created by JustLee on 2020/12/22.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
@class TBOptionChainItemModel;

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionChainOptionDetailCell : TBTableViewCell

@end


@interface TBOptionChainOptionDetailCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *market;

@property (nonatomic, strong) TBOptionChainItemModel *chainItemModel;

@property (nonatomic, strong) NSNumber *estimatePrice;

@property (nonatomic, assign, getter=isShowEstimatePrice) BOOL showEstimatePrice;



@end

NS_ASSUME_NONNULL_END
