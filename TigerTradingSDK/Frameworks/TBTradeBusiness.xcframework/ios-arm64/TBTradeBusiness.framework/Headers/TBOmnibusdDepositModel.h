//
//  TBOmnibusdDepositModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>
#import "TBDepositHistoryTableViewCell.h"

NS_ASSUME_NONNULL_BEGIN

//出入金记录
@interface TBOmnibusdDepositItemModel : JSONModel<TBDepositHistoryTableViewCellItemDataSource>
@property (nonatomic, copy) NSString *amount;
@property (nonatomic, copy) NSString *currency;
@property (nonatomic, assign) NSTimeInterval createdAt; ///< 经后端同事 @王保民 确定，createdAt 和 updatedAt 一致
@property (nonatomic, assign) NSTimeInterval updatedAt; ///< 经后端同事 @王保民 确定，createdAt 和 updatedAt 一致
/**
 type 枚举值示意
 1 = 入金
 3 = 出金
 20 = 出金费用
 21 = 出金退款
 22 = 出金失败-退款
 23 =出金费用-退款
 */
@property (nonatomic, strong) NSNumber *type;
@property (nonatomic, copy) NSString *typeDesc;
//@property (nonatomic, strong) NSNumber *orderID;

@end

@protocol TBOmnibusdDepositItemModel <NSObject>

@end
@interface TBOmnibusdDepositModel : TBOmnibusAPIModel

@property (nonatomic, copy) NSArray <TBOmnibusdDepositItemModel> *data;

@end

NS_ASSUME_NONNULL_END
