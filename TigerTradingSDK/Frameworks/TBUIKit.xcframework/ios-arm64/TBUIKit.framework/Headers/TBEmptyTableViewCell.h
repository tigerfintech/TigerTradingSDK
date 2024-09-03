//
//  TBEmptyTableViewCell.h
//  Stock
//
//  Created by Pengfei_Luo on 16/9/5.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import "TBTableViewCell.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBEmptyTableViewCell : TBTableViewCell

@end

@interface TBEmptyTableViewCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *emptyStr;
@property (nonatomic, strong) UIImage *emptyImage;
@property (nonatomic, strong) UIFont *textFont;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, assign, getter=isLoading) BOOL loading;
@property (nonatomic, assign) BOOL hideEmptyImage;
@property (nonatomic, strong) NSNumber *emptyImageTopOffset;
@property (nonatomic, strong) NSValue *emptyImageSize;
@property (nonatomic, strong) NSNumber *textTopOffset;
@property (nonatomic, strong, nullable) NSNumber *textHorizontalOffset;

@end

NS_ASSUME_NONNULL_END
