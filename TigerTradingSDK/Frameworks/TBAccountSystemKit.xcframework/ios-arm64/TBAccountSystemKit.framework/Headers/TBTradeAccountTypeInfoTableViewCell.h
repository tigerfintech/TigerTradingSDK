//
//  TBTradeAccountTypeInfoTableViewCell.h
//  Stock
//
//  Created by 王昌阳 on 2020/8/19.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
#import "TBTradeAccountModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBTradeAccountTypeInfoTableViewCell : TBTableViewCell

@end

@interface TBTradeAccountTypeInfoTableViewCellItem : TBTableViewCellItem

@property (nonatomic, strong) TBTradeAccountModel *accountModel;///< 账户信息

@property (nonatomic, assign) BOOL isSelected;///< 是否是当前的账户类型

@end

NS_ASSUME_NONNULL_END
