//
//  TBOmnibusAPIOrderPushModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>
#import <TBTradeBusinessBaseKit/TBOmnibusAPIOrderModel.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark  客户端推送
@interface TBOmnibusAPIPushModel : JSONModel

@property (nonatomic, copy) NSString *account;          // 用户ID
@property (nonatomic, copy) NSString<Optional> *symbol; // 股票代码
@property (nonatomic, copy) NSString *type;             // orderstatus/position/asset 目前只推送订单数据
@property (nonatomic, assign) BOOL omnibus;            // 表示消息来自omnibus账号 用于区分FD账号的推送消息
@property (nonatomic, assign) NSTimeInterval timestamp; // 时间戳

@end

@interface TBOmnibusAPIOrderPushModel : TBOmnibusAPIPushModel

@property (nonatomic, strong) TBOmnibusAPIOrderModel *data;

@end

NS_ASSUME_NONNULL_END
