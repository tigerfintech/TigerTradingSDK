//
//  TBOmnibusAPIOrderPreviewModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBBaseKit/JSONModel.h>
#import <TBTradeBusinessBaseKit/TBOrderFeeCategoryModel.h>


NS_ASSUME_NONNULL_BEGIN

@interface TBOmnibusAPIOrderPreviewModel : JSONModel

@property (nonatomic, strong) NSNumber *margin;///< 预估增加保证金 initMargin
@property (nonatomic, strong) NSNumber *maintenanceMargin;///< 预估增加维持保证金

@property (nonatomic, copy) NSString *currency;///< 资产的货币类型
@property (nonatomic, copy) NSString *commissionCurrency;///< 佣金货币类型
/// 收费明细
@property (nonatomic, copy) NSArray<TBOrderFeeCategoryModel> *charges;

@property (nonatomic, strong) NSNumber *commission; // 佣金

@end

NS_ASSUME_NONNULL_END
