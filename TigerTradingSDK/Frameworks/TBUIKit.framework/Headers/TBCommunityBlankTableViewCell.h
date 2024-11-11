//
//  TBCommunityBlankTableViewCell.h
//  Stock
//
//  Created by dulijun on 2019/5/16.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import "TBTableViewCell.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBCommunityBlankTableViewCell : TBTableViewCell

@end


@interface TBCommunityBlankTableViewCellItem : TBTableViewCellItem

@property (nonatomic, assign) BOOL hasBottomBorder;
@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, assign) CGFloat theCellHeight;

@end
NS_ASSUME_NONNULL_END
