//
//  TBStockSettingImageViewCellItem.h
//  Stock
//
//  Created by PXJ on 2020/6/8.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCellItem.h>
#import <TBUIKit/TBTableViewCell.h>
#import <TBUIKit/TBTableViewCellItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockSettingImageViewCellItem : TBTableViewCellItem

@property (nonatomic, assign) CGFloat height;
@property (nonatomic, assign) BOOL hasBottomLine;

@end

@interface TBStockSettingImageViewCell : TBTableViewCell

@end

NS_ASSUME_NONNULL_END
