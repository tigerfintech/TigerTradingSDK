//
//  TBWatchListPositionDataTool.h
//  TBStockBusiness
//
//  Created by zhenglanchun on 2021/12/16.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBWatchListPositionDataTool : NSObject

DECLARE_SHARED_INSTANCE(TBWatchListPositionDataTool)

// MARK: TBPositionDataManager
/**
 根据symbol和secType查询是否在持仓

 @param symbol 正股对应symbol
 窝轮牛熊证对应localSymbol
 期权对应symbol拆分出的属性
 
 @param secType 市场类型
 @return BOOL 返回结果
 */
- (BOOL)isExitInPositionWithSymbol:(NSString *)symbol secType:(NSString *)secType;

/// 获取当前账户持仓
- (void)getPositionsWithSuccess:(void(^)(void))success
                        failure:(void(^)(NSError *error))failure;

/// 获取全部持仓数组
- (NSArray *)getAllPositions;

/// 处理TBTradeAPIPositionItemModel的数组，拿到callback里的参数
/// @param block stocks 为 NSArray <TBWatchListTableCellItem*> *
- (void)handleTradeAPIPositionItemModelWithCallback: (void(^)(NSArray *stocks, NSArray <NSDictionary *>* addQueryArray))block;


@end

NS_ASSUME_NONNULL_END
