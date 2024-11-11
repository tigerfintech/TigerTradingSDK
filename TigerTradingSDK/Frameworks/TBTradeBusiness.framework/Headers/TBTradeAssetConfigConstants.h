//
//  TBTradeAssetConfigConstants.h
//  Stock
//
//  Created by 王昌阳 on 2020/8/23.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, TBTradeAssetDataSourceType) {
    TBTradeAssetDataSourceTypeNone          = 0,
    TBTradeAssetDataSourceTypeAssetSummary  = 1 << 0,
    TBTradeAssetDataSourceTypeUsualTools    = 1 << 1,
    TBTradeAssetDataSourceTypeBanner        = 1 << 2,
    TBTradeAssetDataSourceTypeMyPositions   = 1 << 3,
    TBTradeAssetDataSourceTypeTodayOrders   = 1 << 4,
    
    TBTradeAssetDataSourceTypeAllSource     = 1 << 10,
};

FOUNDATION_EXTERN NSTimeInterval const kTradeAssetPollingRequestInterval;

/**
 *  是否显示总资产警告的key.
 */
extern NSString * const TBTradeAssetCellShowNetLiquidationWarning;
/**
 *  是否已显示过总资产警告的key
 */
extern NSString * const TBTradeAssetCellHaveShownNetLiquidationWarning;
/**
 *  是否显示T+0警告的key.
 */
extern NSString * const TBTradeAssetCellShowDayTradesRemainingWarning;
/**
 *  是否已显示过T+0警告的key
 */
extern NSString * const TBTradeAssetCellHaveShownDayTradesRemainingWarning;
/**
 *  是否显示风控值警告的key.
 */
extern NSString * const TBTradeAssetCellShowRiskWarning;


extern NSString * const NOTIFICATION_KEY_ASSET_CHANGED;

// 资产更新失败
extern NSString * const NOTIFICATION_KEY_ASSET_CHANGE_FAILED;

// 模拟账户重置成功
extern NSString * const NOTIFICATION_KEY_RESET_VIRTUALACCOUNT_SUCCESS;

extern NSString * const NOTIFICATION_KEY_OPEN_VIRTUALACCOUNT_SUCCESS;
extern NSString * const kNOTIFICATION_KEY_OMNIBUS_REPAY_LOAN_SUCCESS;

// 模拟账户开通成功
extern NSString * const TB_CASH_ASSETS_STATUS;

extern NSString * const TB_ASSET_INVISIBLE_PLACEHOLDER_TEXT;

extern NSString * const kTB_ASSET_LITE_INVISIBLE_PLACEHOLDER_TEXT;
extern NSString * const kTB_PNL_LITE_INVISIBLE_PLACEHOLDER_TEXT;


extern NSString * const kTB_USER_DEFAULT_KEY_LITE_PORTFOLIO_ASSETS_VISIBLE_STATUS;

// contra 额度管理的数据是否可见
extern NSString * const kTB_USER_DEFAULT_KEY_CONTRA_CREDIT_LIMIT_VISIBLE;

NS_ASSUME_NONNULL_END
