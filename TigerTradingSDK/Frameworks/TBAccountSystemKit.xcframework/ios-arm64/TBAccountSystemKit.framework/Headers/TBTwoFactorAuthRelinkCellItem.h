//
//  TBTwoFactorAuthRelinkCellItem.h
//  Stock
//
//  Created by chenxin on 2018/10/29.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCellItem.h>
#import <TBUIKit/TBTableViewCell.h>

@interface TBTwoFactorAuthRelinkCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSArray <NSDictionary *> *tips;
@property (nonatomic, copy) NSString *btnTitle;
@property (nonatomic, strong) void(^btnActionBlock)(void);

@end

@interface TBTwoFactorAuthRelinkCell : TBTableViewCell

@end
