//
//  TBOmnibusdApplyDepositModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>

NS_ASSUME_NONNULL_BEGIN

//出入金记录
@interface TBOmnibusdPayeeInfoModel : JSONModel

@property (nonatomic, copy) NSString *holderName;
@property (nonatomic, copy) NSString *bankName;
@property (nonatomic, copy) NSString *bankAddr;
@property (nonatomic, copy) NSString *swiftCode;
@property (nonatomic, strong) NSNumber *cardId;
@property (nonatomic, copy) NSString *cardNo;
@property (nonatomic, strong) NSNumber *clearingCode;
@property (nonatomic, copy) NSString *bankCountry;

@end

@interface TBOmnibusdApplyDepositItemModel : JSONModel

@property (nonatomic, assign) NSInteger orderID;    //!< ND ID
@property (nonatomic, strong) NSNumber *amount; // 金额
//@property (nonatomic, assign)  accountId; // 账户id, java long是64位? optional?
@property (nonatomic, strong) NSNumber *fee;
@property (nonatomic, copy) NSString *currency;
@property (nonatomic, copy) NSString *status; // 状态
@property (nonatomic, copy) NSString *statusDesc; // 状态, 多个语言描述
@property (nonatomic, strong) TBOmnibusdPayeeInfoModel *payeeInfo;      //!< 收款人信息
@property (nonatomic, assign) NSTimeInterval updatedAt;      //!< 更新时间
@property (nonatomic, assign) NSTimeInterval createdAt;      //!< 创建时间
//@property (nonatomic, copy) NSString *remarks; optional?
@property (nonatomic, copy) NSString *userName;
//@property (nonatomic, copy) NSString *message; optional?
@property (nonatomic, copy) NSString *rejectReason;                     //!< Omnibus拒绝原因
@property (nonatomic, assign) BOOL cancelable;      //!< 是否展示取消按钮 // canceled

@property (nonatomic, strong) NSNumber  *paidAt;         //!<  Omnibus汇款日期

@property (nonatomic, copy, readonly) NSString *payFormatTime;        //!<  汇款日期，ND返回patTime,Omnibus 返回paidAt
@property (nonatomic, assign) BOOL isheader;
@property (nonatomic, strong) NSNumber *refundAmount;                   //!< 退款金额

@end


@protocol TBOmnibusdApplyDepositItemModel <NSObject>

@end

@interface TBOmnibusdApplyDepositModel : TBOmnibusAPIModel

@property (nonatomic, copy) NSArray <TBOmnibusdApplyDepositItemModel> *data;

@end

@interface TBOmnibusdApplyDepositOrderModel : TBOmnibusAPIModel

@property (nonatomic, strong) TBOmnibusdApplyDepositItemModel *data;

@end

NS_ASSUME_NONNULL_END
