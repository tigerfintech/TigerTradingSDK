//
//  TBAllAccountHelper.h
//  Stock
//
//  Created by ChenXin on 2018/2/5.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBTradeBusinessBaseKit/TBAsset.h>
#import <TBStockKit/TBStock.h>
#import <TBBaseKit/TBBaseUtility.h>
#import <TBAccountSystemKit/TBUserInfoManager+AccountStatus.h>
#import <TBBusinessSupportKit/TBShortcutsModel.h>
@class TBAccountItemView;

@interface TBAllAccountHelper : NSObject

DECLARE_SHARED_INSTANCE(TBAllAccountHelper)

/// 处理账户可进行的操作
- (void)handleAccountAction:(TBAllAccountActionType)actionType;
- (void)handleAccountAction:(TBAllAccountActionType)actionType inAccount:(TBOmnibusCurrentAccountType)accountType;

/// 交易页面常用工具入口事件处理
/// @param actionType 入口类型
/// @param accountType 证券还是期货
/// @param locationType 位置 0:全部页面 1:交易(持仓)页面
- (void)handleAccountAction:(TBAllAccountActionType)actionType inAccount:(TBOmnibusCurrentAccountType)accountType location:(TBAllAccountActionFromLocationType)locationType;

- (void)handleAccountActionWithInfo:(NSDictionary *)infoDict;

- (NSArray *)actionItemViewsWithItemInfos:(NSArray *)itemInfos withLocation:(TBAllAccountActionFromLocationType)location;

// 账户页面-环球账户操作组件
- (NSArray *)ibAccountActionItemViews;

// 账户页面-综合账户操作组件
- (NSArray *)bsAccountActionItemViews:(BOOL)isContra;

// 模拟账户重置组件
- (UIView *)paperAccountActionItemViewWithAsset:(id <TBAsset>)asset;

// 环球账户交易页按钮
- (NSArray *)ibAccountTradeActionItems;
- (NSArray *)ibAccountTradeActionItemViews;

// 环球账户更多按钮
- (NSArray *)ibAccountMoreActionItems;
// 环球账户-交易页面-更多-全部分组页面
- (NSArray *)ibAccountMoreActionItemViews;

// 综合账户交易页按钮
- (NSArray *)bsAccountTradeActionItems:(TBOmnibusCurrentAccountType)accountType;
- (NSArray *)bsAccountTradeActionItemViews:(TBOmnibusCurrentAccountType)accountType;

// 综合账户更多按钮
- (NSArray *)bsAccountMoreActionItems;
// 环球账户-交易页面-更多-全部分组页面
- (NSArray *)bsAccountMoreActionItemViews;

// 模拟账户交易页按钮
- (NSArray *)paperAccountTradeActionItemsWithAward:(BOOL)hasAward accountType:(TBOmnibusCurrentAccountType)accountType;
- (NSArray *)paperAccountTradeActionItemViews;

+ (NSString *)saActionNameForType:(TBAllAccountActionType)actionName;

/**
 * TBAU TFNZ TBKIWI TBNZ_AFSL、TBMS 牌照的账户分析和个股盈亏分析入口分开显示
 * **update** 905 账户分析和盈亏分析入口合一，统一为分析（这些牌照下会有【分析】【盈亏】两个功能）
 * 1. 这些牌照默认进入个股盈亏tab
 * 2. 证券tab在有rsp权限时，替换为定投功能
 */
- (BOOL)useIndependentAnalysis;
/// 换汇功能是否可用
- (BOOL)currencyExchangeEnable;
/// IPO
- (NSDictionary *)ipoItem;

- (BOOL)transferBetweenAccountsEnable;

- (NSString *)accountTransformName;

@end
