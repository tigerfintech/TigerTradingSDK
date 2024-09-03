//
//  TBStockWarningManager.h
//  Stock
//
//  Created by yangfan on 2020/2/12.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBObject.h>
#import <TBBaseKit/TBBaseUtility.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^StockWarningSuccessBlock)(_Nullable id result);
typedef void(^StockWarningSuccessWithPageBlock)(id result,NSInteger page,NSInteger totalPage);
typedef void(^StockWarningFailureBlock)(NSString * _Nullable message);

/// 获取单支股票股价提醒成功的通知
extern NSString * const TBStockWarningDidFetchNotification;

@interface TBStockWarningManager : TBObject

/// 最近访问的单只股票的提醒价格, 用于K线图绘制预警线.
/// 暂未以market和symbol为索引储存为字典, 只简单保存最近一次请求的数据,
/// 用于个股页请求股价提醒后的个股/横屏/大屏页, 个股页析构时清除数据.
@property (nonatomic, copy, nullable) NSArray *thresholds;

DECLARE_SHARED_INSTANCE(TBStockWarningManager);

//获取单支股票股价提醒
- (void)fetchStockWarningList:(NSDictionary *)params success:(StockWarningSuccessWithPageBlock)success failure:(StockWarningFailureBlock)failure;
//获取股价提醒今日触发次数
- (void)fetchWarningCount:(StockWarningSuccessBlock)success failure:(StockWarningFailureBlock)failure;
//修改股价提醒
- (void)updateStockWarning:(NSDictionary *)params success:(StockWarningSuccessBlock)success failure:(StockWarningFailureBlock)failure;
//获取提醒列表
- (void)fetchMarketWarningList:(NSDictionary *)params success:(StockWarningSuccessWithPageBlock)success failure:(StockWarningFailureBlock)failure;
//创建新的预警
- (void)createNewStockAlert:(NSDictionary *)params success:(StockWarningSuccessBlock)success failure:(StockWarningFailureBlock)failure;
//删除预警
- (void)removeStockAlert:(NSDictionary *)params success:(StockWarningSuccessBlock)success failure:(StockWarningFailureBlock)failure;
//删除某支股票的全部预警
- (void)clearStockAllAlert:(NSArray<NSString *> *)stocks success:(StockWarningSuccessBlock)success failure:(StockWarningFailureBlock)failure;

//关闭一个或多个股票的股价提醒
- (void)closeStockAlert:(id)params success:(StockWarningSuccessBlock)success failure:(StockWarningFailureBlock)failure;

@end

NS_ASSUME_NONNULL_END
