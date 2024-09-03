//
//  TBTradeAccountModel.h
//  Stock
//
//  Created by chenxin on 2018/3/30.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, TBTradeAccountType) {
    TBTradeAccountTypeNone,     // 没有账户
    TBTradeAccountTypeIB,       // 环球账户(FD)
    TBTradeAccountTypeOmnibus,  // 综合账户
    TBTradeAccountTypeVirtual,  // 模拟账户
    TBTradeAccountTypeND        // 环球账户(ND)
};

@interface TBTradeAccountModel : NSObject

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *subtitle;
@property (nonatomic, copy) NSString *iconName;
@property (nonatomic, assign) TBTradeAccountType accountType;
@property (nonatomic, copy) NSString *tradeChannel; // account/status数据结构中的accountType
@property (nonatomic, copy) NSString *customerOrAccountId; // 对模拟账户是account_id，对实盘账户是customer_id
@property (nonatomic, copy) NSString *status;//开户入金状态
@property (nonatomic, assign) BOOL isContraAccount;
@end
