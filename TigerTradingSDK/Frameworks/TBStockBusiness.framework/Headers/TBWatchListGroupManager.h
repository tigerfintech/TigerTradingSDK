//
//  TBWatchListGroupManager.h
//  Stock
//
//  Created by yangfan on 2017/3/14.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBObject.h>
#import "TBWatchListSectionHeaderItem.h"
#import <TBBaseKit/JSONModel.h>
//#import "TBStockMarketUntil.h"
#import "TBStockManager.h"
@class TBWatchListGroup;

#define TBGroupEnumTypeCustomValue -100

//813 不再区分系统和自定义分组之后，原系统分组groupId有值了并且和自定义分组做了区分，可以直接使用这些值进行存储，以前的注释作废被删除。
typedef NS_ENUM(NSInteger,TBGroupEnumType) {
    //因为自选分组可能有很多个，取决于用户自己创建了多少个，这里统一用TBGroupEnumType_Custom表示
    TBGroupEnumType_Custom = TBGroupEnumTypeCustomValue,
    TBSystemMarketEnumType_ALL = 0,
    TBSystemMarketEnumType_US = -1,       //美股
    TBSystemMarketEnumType_HK = -2,       //港股
    TBSystemMarketEnumType_CN = -3,       //沪深
    TBSystemMarketEnumType_UK = -4,       //伦敦
    TBSystemMarketEnumType_SI = -5,       // 新加坡
    TBSystemMarketEnumType_CC = -6,       // 数字货币
    TBSystemMarketEnumType_AU = -7,       // 澳洲
    TBSystemMarketEnumType_NZ = -8,       // 新西兰
    TBSystemMarketEnumType_USOPT = -9,    //美股期权
    TBSystemMarketEnumType_HKOPT = -10,    //港股期权
    TBSystemMarketEnumType_FUTURES = -11,  //期货
    TBSystemMarketEnumType_MF = -12,       //基金
    TBSystemMarketEnumType_Forex = -13, //外汇
    TBSystemMarketEnumType_Bond = -14, //债券
    TBSystemMarketEnumType_POSITION = -15, //持仓
};

typedef void(^WatchListGroupSuccessBlock)(id result);
typedef void(^WatchListGroupFailBlock)(void);
typedef void(^WatchListGroupFinishBlock)(BOOL isFinished);

@class TBWatchListTableCellItem;


@protocol TBWatchListGroupManagerDelegate <NSObject>
@optional
- (void)groupListUpdate;
@end


@interface TBWatchListGroupManager : TBObject

+ (instancetype)manager;

@property (nonatomic, weak) id<TBWatchListGroupManagerDelegate> delegate;

//所有分组，包括自定义分组，系统分组，ALL分组，持仓
@property (nonatomic, copy, readonly) NSArray<TBWatchListGroup *>  *validAllGroupList;
//系统分组中个数为0的分组，分组顺序调整的时候需要用到，存在的意义是后端要求全量上传，其实对客户端没有用到。
@property (nonatomic, copy, readonly) NSArray<TBWatchListGroup *>  *invalidSystemGroupList;

//判断当前分组是否是支持自选推荐
+ (BOOL)haveOptionalRecommendation:(TBWatchListGroup *)group;
+ (void)updateGroupInfo:(TBWatchListGroup *)group;

//自定义分组（包括全部）
- (NSArray<TBWatchListGroup *>  *)serverGroupList;//groupArray;
//系统默认创建的分组，包括所有的（不包括股票数为0的分组)
 - (NSArray<TBWatchListGroup *>  *)systemGroupList;//systemGroupArray;

- (TBWatchListGroup *)allGroup;
- (NSArray <TBWatchListGroup *> *)visiableGroups;

//通过组id获取自选分组对象
- (TBWatchListGroup *)getGroupWithId:(NSInteger)groupId;
//清空本地保存的分组数据，保留所有分组
- (void)removeGroupCache;

- (void)updateCountForDelete:(NSInteger)groupId deletedCount:(NSInteger)deletedCount;
//清空
#pragma mark ----更新初始化所有系统分组数据
- (void)updateSystemGroupsWithAllStocks:(NSArray<TBWatchListTableCellItem *> *)allStocks;

/// 轮询获取所有groupIds里的股票信息(最大并发数5）
- (void)fetchAllGroupWatchListStocksWithGroupIds:(NSArray <NSNumber *> *)groupIds successed:(SuccessedWithResultBlock)successed;

#pragma mark - 关于自选分组的操作
- (void)fetchWatchListGroups:(WatchListGroupSuccessBlock)success fail:(WatchListGroupFailBlock)fail;
- (void)setWatchListGroups:(NSArray *)groupNames success:(WatchListGroupSuccessBlock)success fail:(WatchListGroupFailBlock)fail;
//增加自选股分组
- (void)addWatchListGroups:(NSArray *)groupNames success:(WatchListGroupSuccessBlock)success fail:(WatchListGroupFailBlock)fail;
//删除自选股分组
- (void)removeWatchListGroups:(NSArray *)groupIds finish:(WatchListGroupFinishBlock)finish;
//更新自选股分组
- (void)updateWatchListGroups:(NSArray *)groups finish:(WatchListGroupFinishBlock)finish;
//更改分组名称
- (void)changeWatchListGroupsName:(NSArray *)groups finish:(WatchListGroupFinishBlock)finish;
//更新分组股票数量
//- (void)updateCustomGroupStockCount:(NSInteger)groupId count:(NSInteger)count;
//更新系统默认分组股票数量
//- (void)updateSystemGroupStockCount:(TBGroupEnumType)marketType count:(NSInteger)count;
//更新分组股票
- (void)updateGroupStockCountWithGroupId:(TBGroupEnumType)groupId count:(NSInteger)count;
//隐藏/展示分组
- (void)hideWatchListGroups:(NSArray<TBWatchListGroup *> *)groups finish:(WatchListGroupFinishBlock)finish;
- (NSArray *)readToAddGroupList;
- (BOOL)isSystemGroupID:(NSInteger)groupId;

#pragma mark ----用处不大
+ (BOOL)isAllStockGroup:(TBWatchListGroup *)grounp;
+ (BOOL)isPositionStockGroup:(TBWatchListGroup *)grounp;
- (void)updateSystemGroupNames;//应用语言改变，更新系统分组名称
#pragma mark ---待丢弃
+ (NSArray *)defaultWatchListGroupArray;
+ (NSString *)getMarketNameByType:(TBGroupEnumType)marketType;

@end



@interface TBWatchListGroup : JSONModel
@property (nonatomic, assign) NSInteger         group;      //自选股分组ID,这个名字沿用了服务器的名字，虽然取得很不好
@property (nonatomic, copy) NSString          * iconName;
@property (nonatomic, copy) NSString          * name;
@property (nonatomic, assign) NSInteger         count;      //自选股数量
@property (nonatomic, copy) NSString          * market;     //系统分组中才会有的字段，市场信息
@property (nonatomic, assign)TBGroupEnumType marketType;
@property (nonatomic, assign) BOOL hidden;

- (BOOL)isSystemGroup;
- (BOOL)isCustomGroup;
- (BOOL)isAllGroup;
- (BOOL)isPositionGroup;
- (void)updateNameByTheme;
- (void)updateMarket;

+ (NSString *)debugName:(NSInteger)groupId;

@end


