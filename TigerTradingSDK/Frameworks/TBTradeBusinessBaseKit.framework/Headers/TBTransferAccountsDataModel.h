//
//  TBTransferAccountsDataModel.h
//  Stock
//
//  Created by 王灵博 on 2020/10/15.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>
#import "TBAsset.h"
#import <TBStockKit/TBStock.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBTransferAccountsDataModel : TBBaseModel
/*
 根据枚举获取相应账户文字
 */
+ (NSString *)getDisplayTransferAccountTextByType:(TBOmnibusCurrentAccountType)type;

/*
 根据枚举获取盈亏分析文字
 */
+ (NSString *)getDisplayAnalysisTextByType:(TBOmnibusCurrentAccountType)type;

/*
 根据枚举获取相应账户seg_type
 */
+ (NSString *)getSegType:(TBOmnibusCurrentAccountType)type;

/*
 * 根据枚举获取相应账户seg_type
 * @param combined 否是合并购买力
 */
+ (NSString *)getSegType:(TBOmnibusCurrentAccountType)type combined:(BOOL)combined;

/*
 通过sec_type获取seg_type
 */
+(NSString *)getSegTypeBySecType:(NSString *)secType;


/*
 获取所有账户
 */
+ (NSDictionary *)geTransferAccountDic;


/*
 获取账户的枚举
 */
+ (TBOmnibusCurrentAccountType)geTypeByAccountDic:(NSString *)text;


///*
// 获取划转方向字典,用于账户页面中的跳转
// */
//+ (NSDictionary *)getAccountQueryByType:(TBOmnibusCurrentAccountType)type;

/*
 获取划转方向字典,用于交易页面中的跳转
 */
+ (NSDictionary *)getTradeQueryByType:(TBOmnibusCurrentAccountType)type;

/*
 获取资金数据
 */
+ (id<TBAsset>)getTradeAsset:(TBOmnibusCurrentAccountType)type;



/*
 是否显示新加坡元现金
 */
+ (BOOL)getSGPCash:(TBOmnibusCurrentAccountType)type;



/*
 资金不足，提示去划转资金
 */
+ (void)transferFundFromSecType:(NSString *)secType continueBlock:(void (^)(void))continueBlock;

/*
 根据type获取文字
 */
+ (NSString *)getTransferTextByType:(TBOmnibusCurrentAccountType)type;
@end

NS_ASSUME_NONNULL_END
