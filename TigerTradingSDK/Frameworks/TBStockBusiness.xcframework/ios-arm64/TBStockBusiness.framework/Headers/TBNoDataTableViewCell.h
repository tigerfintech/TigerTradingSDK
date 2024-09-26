//
//  TBNoDataTableViewCell.h
//  Stock
//
//  Created by PXJ on 2021/1/18.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN
@interface TBNoDataTableViewCellItem : TBTableViewCellItem
@property (nonatomic, strong) UIFont *defaultFont;
@property (nonatomic, strong) UIColor *defaultColor;
@property (nonatomic, assign)CGFloat defaultCellHeight;
@property (nonatomic, copy) NSString *defaultReminder;
@end

@interface TBNoDataTableViewCell : TBTableViewCell

@end

NS_ASSUME_NONNULL_END
