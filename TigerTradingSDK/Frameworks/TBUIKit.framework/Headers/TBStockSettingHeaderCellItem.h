//
//  TBStockSettingHeaderCellItem.h
//  Stock
//
//  Created by ChenXin on 17/2/10.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import "TBTableViewCellItem.h"
#import "TBTableViewCell.h"

@interface TBStockSettingHeaderCellItem : TBTableViewCellItem
@property (nonatomic, strong) UIColor *backColor;
@property (nonatomic, copy) NSString *title;

@end

@interface TBStockSettingHeaderCell :  TBTableViewCell

@end
