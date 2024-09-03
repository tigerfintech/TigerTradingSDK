//
//  TBTwoFactorAuthSettingCellItem.h
//  Stock
//
//  Created by chenxin on 2021/12/3.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCellItem.h>
#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TBTwoFactorAuthSettingCellType) {
    TBTwoFactorAuthSettingCellTypeText,
    TBTwoFactorAuthSettingCellTypeArrow,
    TBTwoFactorAuthSettingCellTypeSwitch,
};

@interface TBTwoFactorAuthSettingCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *title;

@property (nonatomic, assign) TBTwoFactorAuthSettingCellType type;

// Text类型设置右边文本
@property (nonatomic, copy) NSString *message;

// Switch类型设置开关是否开启
@property (nonatomic, assign) BOOL isSwitchOn;

// Switch类型开关状态改变回调
@property (nonatomic, strong) void(^switchActionBlock)(UISwitch *switchView);

@end

@interface TBTwoFactorAuthSettingCell : TBTableViewCell

@end

NS_ASSUME_NONNULL_END
