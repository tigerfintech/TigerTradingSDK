//
//  TBAuthAccountStatusModel.h
//  Stock
//
//  Created by charming on 2019/8/27.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

// permission 权限枚举
//extern NSString * const TBAuthAccountStatusPermissionUsStockQuote;    // 美股个股实时行情Level1权限, 入金用户
//extern NSString * const TBAuthAccountStatusPermissionUsStockQuoteLv0; // 美股个股实时行情Level0权限, 所有用户
//extern NSString * const TBAuthAccountStatusPermissionUsStockTrade;    // 美股股票交易权限, 入金用户
//extern NSString * const TBAuthAccountStatusPermissionUsOptionTrade;   // 美股期权交易权限, 入金用户
//extern NSString * const TBAuthAccountStatusPermissionUsOptionQuote;   // 美股期权行情权限, 入金用户
//extern NSString * const TBAuthAccountStatusPermissionHkStockTrade;    // 美股个股实时行情Level1权限, 入金用户
//extern NSString * const TBAuthAccountStatusPermissionHkStockQuoteLv0; // 港股股票行情Level0权限, 注册用户, 入金用户暂时去掉
//extern NSString * const TBAuthAccountStatusPermissionHkStockQuoteLv2; // 港股股票行情Level2权限, 入金用户
//extern NSString * const TBAuthAccountStatusPermissionUSStockTipRanks; // TipRank权限


// ib / bs 中的key value
@interface TBAuthAccountStatusItemModel : JSONModel

@property (nonatomic, copy) NSString *customerId;
@property (nonatomic, copy) NSString *accountId;
@property (nonatomic, copy) NSString *status;
@property (nonatomic, copy) NSString *accountType;
@property (nonatomic, copy) NSString *license; // 牌照信息, 可空

@end

// virtual 中的key value
@interface TBAuthAccountStatusVirtualModel : JSONModel

@property (nonatomic, copy) NSString *currentVirtualAccountId;
@property (nonatomic, copy) NSString *accountType;
@property (nonatomic, copy) NSArray *accounts;

@end

@interface TBAuthAccountStatusDataModel : JSONModel

@property (nonatomic, strong) TBAuthAccountStatusItemModel *ibStatus;
@property (nonatomic, strong) TBAuthAccountStatusItemModel *bsStatus;
@property (nonatomic, strong) TBAuthAccountStatusVirtualModel *virtualStatus;

@property (nonatomic, copy) NSString *currentTradeAccount;
@property (nonatomic, copy) NSString *proccessStatus; // 待确认，某个再开户进程中
@property (nonatomic, assign) BOOL signETF; // BOOL类型 是否签署etf风险协议
@property (nonatomic, copy) NSArray *permission;

@property (nonatomic, copy) NSString *location; // # BOOL类型 是否签署etf风险协议
@property (nonatomic, copy) NSString *HKQuoteType; // # INT类型 期权答题状态   1 未答题  2 答题通过未签协议 3 已签协议

@property (nonatomic, copy) NSString *errorMessage;
@property (nonatomic, copy) NSString *errorDescription;
@property (nonatomic, assign) NSInteger errorCode;

@end

@interface TBAuthAccountStatusModel : JSONModel

@property (nonatomic, strong) TBAuthAccountStatusDataModel *dataModel;
@property (nonatomic, assign) BOOL isSucc;

@end




