//
//  TBOmnibusAPIAssetPreviewModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBBaseKit/JSONModel.h>
@class TBOmnibusAPIAssetExcessLiquidityPreviewModel;

NS_ASSUME_NONNULL_BEGIN

// 下单检查
@interface TBOmnibusAPIAssetPreviewModel : JSONModel

@property (nonatomic, strong) NSNumber *equityWithLoan; // 可借贷
@property (nonatomic, strong) NSNumber *maintenceMargin; // initMarginReq 下单后初始保证金
@property (nonatomic, strong) NSNumber *maintenanceMarginReq; // 下单后维持保证金

@property (nonatomic, copy) NSString *currency;///< 货币类型
@property (nonatomic, strong) NSNumber *excessLiquidity; // 成交后风控值
@property (nonatomic, strong) NSNumber *overnightLiquidation; // 成交后隔夜风控值

@property (nonatomic, strong) NSNumber *availableEE; // 可用剩余资产

@property (nonatomic, strong) TBOmnibusAPIAssetExcessLiquidityPreviewModel *excessLiquidityPreview;///< EL 预览（保证金）

@end

NS_ASSUME_NONNULL_END
