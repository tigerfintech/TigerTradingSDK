//
//  TBTradeTitleViewCell.h
//  Stock
//
//  Created by 马超 on 2017/10/27.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
#import "TBTradeAccountModel.h"

@interface TBTradeTitleViewCell : TBTableViewCell

@property (nonatomic, strong) TBTradeAccountModel *accountModel;

@property (nonatomic, assign) BOOL hasBottomLine;

@end
