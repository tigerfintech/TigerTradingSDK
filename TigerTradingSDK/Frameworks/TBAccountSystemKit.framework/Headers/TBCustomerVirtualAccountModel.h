//
//  TBCustomerVirtualAccountModel.h
//  TBAccountSystemKit
//
//  Created by 董恭甫 on 2021/8/16.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCustomerVirtualAccountModel : JSONModel

@property (nonatomic, copy) NSString *accountId;
@property (nonatomic, copy) NSString *templateId; // 100:标准模拟账户
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *accountDescription;
@property (nonatomic, copy) NSString *myselfURL; // 我的链接
@property (nonatomic, copy) NSString *rankURL; // 榜单排名链接

@property (nonatomic, assign) BOOL resettable; // 能否重置
@property (nonatomic, assign) BOOL tradable; // 该账户能否交易
@property (nonatomic, assign) BOOL expired; // 该账户是否过期

@property (nonatomic, assign) NSTimeInterval expiryTime; // 过期时间戳

@property (nonatomic, copy) NSArray<NSString *> *tradePermission; // 权限列表

@property (nonatomic, copy) NSString *accountType; // 账户类型：CASH / MARGIN

@end

@interface TBCustomerVirtualAccountModel (Utils)

/// 是否是保证金账号
- (BOOL)isMarginAccount;

/// 是否是现金账户
- (BOOL)isCashAccount;

@end

@class TBCustomerAvailableVirtualAccountDataModel;

@interface TBCustomerAvailableVirtualAccountModel : JSONModel

@property (nonatomic, assign) BOOL success;
@property (nonatomic, strong) TBCustomerAvailableVirtualAccountDataModel *data;

@end


@protocol TBCustomerVirtualAccountModel;

@interface TBCustomerAvailableVirtualAccountDataModel : JSONModel

@property (nonatomic, copy) NSArray<TBCustomerVirtualAccountModel> *accounts;
@property (nonatomic, copy) NSString *defaultAccountId; // 如果开通了模拟盘账户, 则为模拟盘账户id, 否则为空

@end


NS_ASSUME_NONNULL_END
