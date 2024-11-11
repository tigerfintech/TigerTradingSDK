//
//  TBFuturesModel.h
//  Stock
//
//  Created by WCP on 2018/12/13.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import "TBOmnibusAPIModel.h"
#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN


@interface TBFuturesTransferModel : JSONModel
/**New 已受理 转账请求已经受理
Proc 处理中转账或者撤销请求处理中
Succ 转账成功 已经转账成功
Fail 转账失败 转账失败,资金退回
Canc 已撤销 用户撤销*/
@property (nonatomic, copy) NSString *status;  //!< Succ转账成功 Proc 转账或者撤销请求处理中
@property (nonatomic, copy) NSString *message;
@property (nonatomic, assign) NSTimeInterval createdAt;
@property (nonatomic, assign) NSTimeInterval updatedAt;
@property (nonatomic, copy) NSString *fromSegment;
@property (nonatomic, copy) NSString *toSegment;
@property (nonatomic, copy) NSString *currency;
@property (nonatomic, strong) NSNumber *amount;
@property (nonatomic, assign) long long orderID;

@end

@interface TBFuturesTransferAPIModel : TBOmnibusAPIModel

@property (nonatomic, strong) TBFuturesTransferModel *data;

@end

@protocol TBFuturesTransferModel 
@end

@interface TBFuturesTransferOrdersModel : TBOmnibusAPIModel

@property (nonatomic, copy) NSArray<TBFuturesTransferModel> *data;

@end

NS_ASSUME_NONNULL_END
