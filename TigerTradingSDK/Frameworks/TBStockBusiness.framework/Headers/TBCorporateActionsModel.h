//
//  TBCorporateActionsModel.h
//  Stock
//
//  Created by luopengfei on 2017/10/31.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>
//#import "TBNewFinanceTableViewCell.h"
#import "TBFinanceUpdateCell.h"
#import "TBCorporateActionsDetailTableViewCell.h"

/// 公司行动类型
typedef NS_ENUM(NSInteger, TBChartActionType) {
    TBChartActionTypeNone = 0,
    TBChartActionTypeSplit, // 拆股
    TBChartActionTypeReverseSplit, // 合股
    TBChartActionTypeDividend, // 分红
    TBChartActionTypeEarning, // 财报
    TBChartActionTypeChange, // 代码变更
    TBChartActionTypeDelisting, // 退市
    TBChartActionTypeRights // 供股权
};


@protocol TBCorporateActionsItemModel <NSObject>
@end
@interface TBCorporateActionsItemModel : JSONModel <TBFinanceUpdateCell, TBRecommendTableViewCell>
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *date;

/**
 数据类型：
 split为拆和股，
 symbolChange为代码变更，
 dividend为分红，
 delisting为退市，
 earning为财报
 rights为供股权
 */
@property (nonatomic, copy) NSString *type;

/**
 分红字段
 */
@property (nonatomic, assign) double amount;
@property (nonatomic, copy) NSString *currency;


/**
 财报
 */
@property (nonatomic, assign) double expectedEps;
@property (nonatomic, assign) double actualEps;
@property (nonatomic, copy) NSString *time; // 盘前 or 盘后

/**
 退市
 */
@property (nonatomic, copy) NSString *reason;

/**
 代码变更
 */
@property (nonatomic, copy) NSString *snewSymbol;

/**
 拆合股
 */
@property (nonatomic, assign) NSInteger forFactor;
@property (nonatomic, assign) NSInteger toFactor;


/*
 供股权
 */
@property (nonatomic, copy) NSString *announcementDate;
@property (nonatomic, copy) NSString *firstDealingDate;
@property (nonatomic, copy) NSString *lastDealingDate;
@property (nonatomic, copy) NSString *recordDate;
@property (nonatomic, copy) NSString *rightsSymbol;
@property (nonatomic, strong) NSNumber *defaultRemindTime;


@property (nonatomic, readonly) NSString *typeString;
@property (nonatomic, readonly) NSString *actionDes;
@property (nonatomic, readonly) TBChartActionType actionType;

@end

@interface TBCorporateActionsDataModel : JSONModel
@property (nonatomic, copy) NSArray<TBCorporateActionsItemModel> *items;

@end

@interface TBCorporateActionsModel : JSONModel

@property (nonatomic, assign) NSInteger ret;
@property (nonatomic, assign) NSTimeInterval serverTime;
@property (nonatomic, copy) NSString *msg;

@property (nonatomic, copy) NSString *symbol;


@property (nonatomic, strong) TBCorporateActionsDataModel *data;

@property (nonatomic, readonly) NSArray *detailActionArray;

@property (nonatomic, readonly) NSArray *actionsArray;

@property (nonatomic, strong, readonly) NSMutableArray <TBCorporateActionsItemModel *>* dividendItems;

@property (nonatomic, assign) BOOL isETF;///< 是否是 ETF，曝光统计有用到

@end
