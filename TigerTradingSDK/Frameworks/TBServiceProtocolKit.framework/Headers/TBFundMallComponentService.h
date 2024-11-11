//
//  TBFundMallComponentService.h
//  Pods
//
//  Created by chenxin on 2022/5/26.
//

#ifndef TBFundMallComponentService_h
#define TBFundMallComponentService_h

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBFundMallComponentService <NSObject>

// 基金首页
- (UIViewController *)tbFund_fundHomeViewController;

// 无持仓视图
- (UIView *)tbFund_positionEmptyView;

// 获取基金超市持仓
- (void)tbFund_fetchFundMallPosition:(void(^)(id result))success failure:(void(^)(NSString *message))failure;

// 是否有资产
- (BOOL)tbFund_hasAssetWithModel:(id)model;

// 基金超市账户主币种
- (NSString *)tbFund_mainCurrencyWithModel:(id)model;

// 累计收益
- (NSNumber *)tbFund_accumulatedInterestWithModel:(id)model;

// 资产cellItem
- (id)tbFund_assetCellItemWithBlock:(void(^)(UIButton *currencyBtn))block;

// 处理持仓cellItem
- (NSArray *)tbFund_positionCellItemsWithModel:(id)model;

// 更新资产cell
- (void)tbFund_updateAssetCellItem:(id)cellItem model:(id)model currency:(NSString *)currency;

// 处理cell点击
- (void)tbFund_handleActionWithCellItem:(id)item info:(id)info listVC:(id)listVC;

///获取用户的基金风险得分
- (void)tbFund_fetchFundScore:(void(^)(id result))success failure:(void(^)(NSString *message))failure;

@optional

- (void)tbFund_openPurchasePageV2:(NSString *)symbol
                         name:(NSString *)fundName
                       amount:(nullable NSString *)amount
                        isRsp:(NSInteger)isRsp;

- (void)tbFund_gotoFundPositionPage;

- (NSDictionary *)tbFund_convertToDictionaryWithFundDetailItem:(id)item;

- (void)tbFund_openTigerVaultAutoSweepPage:(BOOL)isOpenAutoSweep;

- (NSDictionary *)tbFund_convertToDictionaryWithFundReturnItem:(id)item;

- (void)tbFund_setLabel:(UILabel *)label number:(CGFloat)number hundredTimes:(BOOL)hundredTimes showPercent:(BOOL)showPercent factionDigits:(NSInteger)factionDigits;

- (void)tbFund_fetchFundDetail:(NSDictionary *)params
                   success:(void(^_Nullable)(_Nullable id result))success
                   failure:(void(^_Nullable)(NSString * _Nullable message))failure;

// 获取一组基金的涨跌幅数据
- (void)tbFund_fetchFundComparisonData:(NSArray *)symbols success:(void(^)(NSArray *result))success failure:(void(^)(NSString *message))failure;

/// 钱袋子名称
- (NSString *)tbFund_TigerVaultName;

/// 管理钱袋子标题
- (NSString *)tbFund_TigerVaultAutoSweepTitle;

/// 币种对应颜色
- (UIColor *)tbFund_colorWithCurrenty:(NSString *)currency;

/// 取消基金交易
- (void)tbFund_cancelFundTrade:(NSNumber *)flowId success:(void(^)(void))success failure:(void(^)(BOOL isTradeTokenError, NSString * _Nullable message))failure;


/**
 * 跳转到老虎钱袋子首页
 * @param userInfo 可选预留参数，如后期传递arriveFrom等参数
 */
- (void)tbFund_gotoTigerValutHomePage:(nullable NSDictionary *)userInfo;

- (void)tbFund_isOpenAutoSweep:(nullable NSDictionary *)userInfo completion:(void(^)(BOOL isOpenAutoSweep, NSString *error))completion;

@end

NS_ASSUME_NONNULL_END

#endif /* TBFundMallComponentService_h */
