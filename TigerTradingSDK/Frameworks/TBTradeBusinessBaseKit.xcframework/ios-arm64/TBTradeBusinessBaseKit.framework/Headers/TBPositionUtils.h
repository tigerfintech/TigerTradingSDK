//
//  TBPositionUtils.h
//  Stock
//
//  Created by ChenXin on 2017/8/25.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TBTradeAPIPositionItemModel;

extern NSString * const kTBFundPositionSortChangeNotification;

@interface TBPositionUtils : NSObject

+ (NSString *)getStatisticsAccountSuffix;

/**
 持仓UK排序

 @return 持仓UK排序
 */
+ (NSInteger)ukSelectedCategoryType;

+ (void)setUKSelectedCategoryType:(NSInteger)ukSelectedCategoryType;

/// 组合期权最大公约数, 最小1
+ (NSInteger)gcdWithLegPositions:(NSArray<TBTradeAPIPositionItemModel *> *)legPositions;

/**
 * 持仓action是否包含rollover？
 *
 * 美股期权+组合期权权限
 */
+ (BOOL)hasRolloverActionWithModel:(TBTradeAPIPositionItemModel *)positionModelItem;

@end
