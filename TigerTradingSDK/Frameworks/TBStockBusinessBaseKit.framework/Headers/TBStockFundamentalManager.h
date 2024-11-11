//
//  TBStockFundamentalManager.h
//  Stock
//
//  Created by mashanli on 2023/1/9.
//  Copyright © 2023 com.tigerbrokers. All rights reserved.
//

#import <TBStockBusinessBaseKit/TBStockDetailViewControllerDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockFundamentalManager : NSObject

+ (NSDictionary *)fundamentalOriginDes;

+ (NSArray *)optionFundamental;

/// 个股详情页点击换手率查看多换手率
+ (void)handleStockTurnOverRate:(id<TBStockDetailViewControllerDelegate>_Nullable)delegate market:(NSString *_Nullable)market;

/// 个股详情页总市值点击查看更多币种市值
+ (void)handleStockDetailMTK:(id<TBStockDetailViewControllerDelegate>_Nullable)delegate;

//指标说明文案
+ (void)indicatorBtnAction:(NSString *)market secType:(NSString *)secType;

@end

NS_ASSUME_NONNULL_END
