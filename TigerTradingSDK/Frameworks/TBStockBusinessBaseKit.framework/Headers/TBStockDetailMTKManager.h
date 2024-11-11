//
//  TBStockDetailMTKManager.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/1/9.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/*
 个股详情页市值计算
 */

typedef enum : NSUInteger {
    TBStockDetailCurrencyUSD, // 美元
    TBStockDetailCurrencyHKD, // 港币
    TBStockDetailCurrencyGBP, // 英镑
    TBStockDetailCurrencyGBX, // 便士
    TBStockDetailCurrencyCNY, // RMB
    TBStockDetailCurrencyEUR, // 欧元
    TBStockDetailCurrencySGD, // 新加坡
    TBStockDetailCurrencyIDR, // 卢比
    TBStockDetailCurrencyMYR, // 马来币
    TBStockDetailCurrencyCHF, // 瑞士法郎
    TBStockDetailCurrencyJPY, // 日元
    TBStockDetailCurrencyAUD, // 澳元
    TBStockDetailCurrencyNZD, // 新西兰元
} TBStockDetailCurrency;
@protocol TBStockDetailViewControllerDelegate;
@interface TBStockDetailMTKManager : NSObject

+ (NSArray *)multiplierMTKWithSecInfo:(id<TBStockDetailViewControllerDelegate>)secInfo;

+ (NSString *)mktValueWithSecInfo:(id<TBStockDetailViewControllerDelegate>)secInfo title:(NSString *)title;

+ (NSString *)mktValueWithAHStockSecInfo:(id<TBStockDetailViewControllerDelegate>)secInfo title:(NSString *)title;

@end

NS_ASSUME_NONNULL_END
