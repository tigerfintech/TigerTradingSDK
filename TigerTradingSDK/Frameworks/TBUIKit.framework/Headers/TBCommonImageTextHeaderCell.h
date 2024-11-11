//
//  TBCommonImageTextHeaderCell.h
//  Stock
//
//  Created by swordzhou on 2024/01/11.
//  Copyright © 2023 com.tigerbrokers. All rights reserved.
//

#import "TBTableViewCell.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBCommonImageTextHeaderCellItem : TBTableViewCellItem

@property (nonatomic) UITableViewCellSelectionStyle   selectionStyle;             // default is UITableViewCellSelectionStyleNone.
@property (nonatomic, strong) UIImage *titleImage;
@property (nonatomic, strong) NSAttributedString *titleAttributedString;
@property (nonatomic, assign) BOOL showBottomLine;
@property (nonatomic, assign) CGSize titleImageSize;

@end

@interface TBCommonImageTextHeaderCell : TBTableViewCell

- (void)initSubViews;
- (void)initSubLayouts;

@end

NS_ASSUME_NONNULL_END
