//
//  TBTwoFactorAuthSettingTextCellItem.h
//  Stock
//
//  Created by chenxin on 2021/12/3.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCellItem.h>
#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBTwoFactorAuthSettingTextCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *title;

@property (nonatomic, assign) BOOL isFooter;

@end

@interface TBTwoFactorAuthSettingTextCell : TBTableViewCell

@end

NS_ASSUME_NONNULL_END
