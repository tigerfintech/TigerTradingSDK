//
//  TBStockAttachSwitchCellItem.h
//  Stock
//
//  Created by liwt on 15/1/3.
//  Copyright (c) 2015年 com.tigerbrokers. All rights reserved.
//

#import "TBStockSettingBasicCellItem.h"

@interface TBStockAttachSwitchCellItem : TBStockSettingBasicCellItem

@property (nonatomic, assign, getter = isOn) BOOL on;
@property (nonatomic, strong) void(^switchChangedBlock)(BOOL isON);
@property (nonatomic, assign) BOOL enableSwitch;
@property (nonatomic, assign) BOOL fixSwitchPosition;

@property (nonatomic, assign) BOOL hasDetailInfo; // 是否包含bottom left第二行数据
@property (nonatomic, copy) NSString * detailInfo; // bottom left第二行数据信息

- (TBStockAttachSwitchCellItem *)applyOn:(BOOL) isON;
- (TBStockAttachSwitchCellItem *)applyHeadIcon:(UIImage *)image;

@end


@interface TBStockAttachSwitchCell : TBStockSettingBasicCell

@property (nonatomic, strong) UISwitch *switchBtn;
@property (nonatomic, assign) BOOL isOn;
@property (nonatomic, strong) void(^switchChangedBlock)(BOOL isON);

@end

