//
//  TBOptionChainUtils.h
//  Stock
//
//  Created by mashanli on 2022/12/19.
//  Copyright © 2022 com.tigerbrokers. All rights reserved.
//

@class TBOptionPickListCellItem;
@class TBOptionChainWidthCellItem;
@class TBOptionStrategyBuilderStrategyModel;
@class TBMultiOptionChainItemModel;
@class TBMultiOptionExpiryWidthModel;
@class TBOptionChainDetailItemViewModel;

#import <TBBaseKit/TBObject.h>
#import <TBUIKit/TBNavigator.h>
#import <TBStockBusinessBaseKit/TBMultiOptionItem.h>

NS_ASSUME_NONNULL_BEGIN

/// 期权策略类型
static NSString * _Nullable kTBOptionChainStrategySingleOption = @"singleOption"; //单腿（默认）
static NSString * _Nullable kTBOptionChainStrategyCustom = @"custom"; //自定义
static NSString * _Nullable kTBOptionChainStrategyBullVertical = @"bullVertical"; //垂直
static NSString * _Nullable kTBOptionChainStrategyStraddle = @"straddle"; //跨式
static NSString * _Nullable kTBOptionChainStrategyStrangle = @"strangle"; //宽跨
static NSString * _Nullable kTBOptionChainStrategyCalendarSpread = @"calendarSpread"; //日历
static NSString * _Nullable kTBOptionChainStrategyDiagonalSpread = @"diagonalSpread"; //对角

static NSString * _Nullable kTBOptionChainDirectionBuy = @"buy";
static NSString * _Nullable kTBOptionChainDirectionSell = @"sell";

/// 期权策略记忆
static NSString * _Nullable kTBOptionChainStrategyKey = @"kTBOptionChainStrategyKey";
/// 期权日期差记忆
static NSString * _Nullable kTBOptionChainExpireWidthKey = @"kTBOptionChainExpireWidthKey";
/// 期权指定日期记忆
static NSString * _Nullable kTBOptionChainExpireDateKey = @"kTBOptionChainExpireDateKey";
/// 期权策略引导tip
static NSString * _Nullable kTBOptionChainStrategyTip = @"kTBOptionChainStrategyTip";

@interface TBOptionChainUtils : TBObject

/// 获取策略选择器cellItems
+ (NSArray <TBOptionPickListCellItem *> *)getStrategiesWithModels:(NSArray <TBOptionStrategyBuilderStrategyModel *> *)models
                                                 selectedStrategy:(NSString *)selectedStrategy;

//价差
+ (NSArray <TBOptionChainWidthCellItem *> *)generateStrikeWidth:(NSArray <NSNumber *> *)nums
                                                  selectedWidth:(NSNumber *)selectedWidth
                                                   defaultWidth:(NSNumber *)defaultWidth;

+ (NSArray <TBOptionChainWidthCellItem *> *)generateCalendarWidth:(NSArray<TBMultiOptionExpiryWidthModel *> *)models
                                                    selectedWidth:(TBMultiOptionExpiryWidthModel *)selectedWidth
                                                     defaultWidth:(TBMultiOptionExpiryWidthModel *)defaultWidth;

/// 是否是组合策略
+ (BOOL)isMultiOptionWithStrategy:(NSString *)strategy;

//是否是日历/对角策略
+ (BOOL)isExpiryStrategy:(NSString *)strategy;

/// 组合策略 & 支持 T 列表
+ (BOOL)isMultiOptionAndSupportTModelWithStrategy:(NSString *)strategy;

/// 使用组合接口
+ (BOOL)isUseMultiHttpWithStrategy:(NSString *)strategy;

/// 使用组合接口 & 支持 T 列表
+ (BOOL)isUseMultiHttpAndSupportTModelWithStrategy:(NSString *)strategy;

#pragma mark - 列表展示
/// 根据策略获取 all 列表 strikeView 宽度
+ (CGFloat)strikeViewWidthStrategy:(NSString *)strategy;

/// all 列表 call put label 宽度
+ (CGFloat)rightLabelWidth;

/// all 列表指标 label 宽度
+ (CGFloat)indicateLabelWidth;

/// all single T 列表指标最大宽度
+ (CGFloat)maxIndicateRowWidth;

/// 获取组合期权展示的 strike
/// - Parameter model: 组合期权的 model
+ (NSString *)getCombinedStrikeNameWithModel:(TBMultiOptionChainItemModel *)model;

/// 获取组合唯一标识
+ (NSString *)getCombinedKeyWithModel:(TBMultiOptionChainItemModel *)model symbol:(NSString *)symbol expriys:(NSArray<NSNumber *> *)expriys;


/// 根据 itemModel 计算生成展示需要的 dataSource
+ (NSArray *)generateCellDataSourceWithModel:(TBMultiOptionChainItemModel *)model market:(NSString *)market;

/// 更新 dataSource 中由 SDK 计算的指标
/// - Parameters:
///   - dataSource: dataSource
///   - model: 组合期权的 model
///   - expiry: 到期日
///   - stockPrice: 股票价格
///   - market: 市场
///   - openAndCloseTimeList: 市场的开市闭市时间
///   - isIndexOption: 是否是指数
///   - stockVolatility: 股票波动率
+ (NSArray *)updateSDKIndicateWithDataSource:(NSArray *)dataSource
                                       model:(TBMultiOptionChainItemModel *)model
                                     expirys:(NSArray <NSNumber *> *)expirys
                                  stockPrice:(double)stockPrice
                                      market:(NSString *)market
                        openAndCloseTimeList:(NSArray <NSArray <NSNumber *> *> *)openAndCloseTimeList
                               isIndexOption:(BOOL)isIndexOption
                                stockVolatility:(NSNumber *)stockVolatility;

+ (NSNumber *)getEarliestExpire:(NSArray <NSNumber *> *)expires;

/// 根据 generateCellDataSourceWithModel 方法计算的 dataSource 返回 list 列表需要的数据
/// - Parameter dataSource: dataSource
+ (NSArray *)getListIndicatorArrayWithDataSource:(NSArray *)dataSource;

/// 根据 generateCellDataSourceWithModel 方法计算的 dataSource 返回 T 列表需要的数据
/// - Parameter dataSource: dataSource
+ (NSArray *)getTTypeIndicatorArrayArrayWithDataSource:(NSArray *)dataSource;

//单腿和custom转成shop
+ (TBOptionChainShoppingModel *)generateShoppingWithDefault:(TBOptionChainItemModel *)model;

//垂直、跨样、宽跨转成shop
+ (TBOptionChainShoppingModel *)generateShoppingWithMulti:(TBMultiOptionChainItemModel *)model;

+ (NSString *)getStragyNameWithKey:(NSString *)key;

//获取日期差name，isShort：是否简称
+ (NSString *)getExpireNameWithModel:(TBMultiOptionExpiryWidthModel *)model isShort:(BOOL)isShort;

/// 根据需要展示的指标和市场类型，返回展示的指标 title viewModel
+ (NSArray <TBOptionChainDetailItemViewModel *>*)optionViewTitlesWithIndicators:(NSArray *)indicators market:(NSString *)market;

/// 社区帖子开通组合期权白名单权限
+ (void)gotoMultiLegsAbilityCommunityPost;

+ (BOOL)hasCombineOptionBottom:(NSString *)market specialCase:(BOOL)specialCase;

@end

NS_ASSUME_NONNULL_END
