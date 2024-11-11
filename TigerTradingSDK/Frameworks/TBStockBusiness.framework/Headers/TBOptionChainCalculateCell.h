//
//  TBOptionChainCalculateCell.h
//  Stock
//
//  Created by JustLee on 2020/12/22.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
@class TBOptionChainOptionDetailCellItem;
@class TBOptionInfoDetailItem;

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionChainCalculateCell : TBTableViewCell
                                                    
@end


@interface TBOptionChainCalculateCellItem : TBTableViewCellItem

@property (nonatomic, strong) NSNumber *stockPrice;

@property (nonatomic, strong) NSNumber *expiryDate;

@property (nonatomic, strong) NSNumber *calculateDate;

@property (nonatomic, strong) NSNumber *vixValue;

@property (nonatomic, strong) NSNumber *rateBonds;

@property (nonatomic, copy) NSString *market;

@property (nonatomic, copy) NSString *secType;

@property (nonatomic, copy) NSString *right;

@property (nonatomic, strong) TBOptionInfoDetailItem *optionItem;

@property (nonatomic, copy) NSArray <TBOptionChainOptionDetailCellItem *> *calculateItems;

- (void)calculateOptionDetailCellItems;

@end

@interface TBOptionChainPlaceHolderTextCell : TBTableViewCell
                                                    
@end

@interface TBOptionChainPlaceHolderTextCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *text;

@end

NS_ASSUME_NONNULL_END
