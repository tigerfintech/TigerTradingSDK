//
//  TBStockMarketUntil.h
//  Stock
//
//  Created by 王灵博 on 2020/7/16.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>
@class TBQuotationPackage;
@class TBMarketConditionsModel;
@class TBStockDetailCalendarModel;
@class TBBaseModelBuryingPointModel;
#import "TBMarketSectorCell.h"

@class TBQuotationPackage,TBMarketSectionHeaderItem,TBStockMarketCalendarModel,TBStockDetailCalendarModel,TBBaseModelBuryingPointModel,TBMarketConditionsModel;


typedef void(^SuccessedBlock)(void);
typedef void(^SuccessedWithResultBlock)(id _Nullable result);
typedef void(^SuccessedWithResultAndStringBlock)(id _Nullable result,NSString * _Nullable string);
typedef void(^FailedBlock)(NSError * _Nullable error);

NS_ASSUME_NONNULL_BEGIN

@interface TBStockMarketUntil : TBBaseModel

+ (void)setImportantIndexWith:(id)responseObject  array:(NSMutableArray<TBQuotationPackage *> *)array;

+ (void)setTigerIndexWith:(id)responseObject array:(NSMutableArray<TBQuotationPackage *> *)array;

+ (void)loadImportantData:(NSString *)packageID  blockData:(void (^)(NSArray *array))blockData;
/*
 环球ipo接口：https://test-oauth.tigerfintech.com/ams/docs/Customer%20IPO/index#req_dbfc906c01bc45d4a70c92462b76e50e
 综合ipo接口文档：https://git.tigerbrokers.net/alpha/site-api-docs/blob/ipo_interaction_0619/api/ipo.md#2.1
 */
+ (void)loadCalendarListblockData:(void (^)(TBStockMarketCalendarModel *mainModel))blockData;

+ (NSArray *)getTigerIndexData:(TBMarketConditionsModel *)model;

//+ (TBMarketSectionHeaderItem *)getImportantListActionWith:(id)responseObject market:(NSString *)market;

+ (void)addGradientLayerByChange:(double)change view:(UIView *)view;
+ (void)addGradientLayerByChange:(double)change view:(UIView *)view frame:(CGRect)frame;

+ (void)addUpAndDownGradientLayer:(UIView *)view;

+ (UIColor *)getColorByChange:(double)change;

+ (CGFloat)getTodayChangesHeight:(NSString *)text;

+ (NSMutableAttributedString *)getTodayChangesAttributes:(NSString *)text;

+ (void)loadData:(NSString *)market packageId:(NSString *)packageId blockData:(void (^)(NSArray *array))blockData;

+ (void)openSubscription:(TBStockDetailCalendarModel *)ipoName;

+ (void)openUpAndDown:(NSDictionary *)itemDetail  market:(NSString *)market;

+ (UIColor *)getIncreaseColorByIndex:(NSInteger)index;

+ (UIColor *)getDecreaseColorByIndex:(NSInteger)index;

+ (void)marketStockBuryingPoint:(NSString *)market name:(NSString *)name;

+ (TBBaseModelBuryingPointModel *)buyPointWithModel:(NSString *)model type:(NSString *)type sector:(NSString *)sector;


/**
 窝轮牛熊证type对应的文案
 */
+ (NSString *)getWarrantNameWithTypeId:(NSInteger)typeId;

+ (BOOL)isShowNewCalendar;

/// 是否支持异动
/// @param market <#market description#>
+ (BOOL)supportStockActive:(NSString *)market;

@end

NS_ASSUME_NONNULL_END
