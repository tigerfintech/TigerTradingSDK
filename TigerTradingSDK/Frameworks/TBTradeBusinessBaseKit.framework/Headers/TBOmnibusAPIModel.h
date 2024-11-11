//
//  TBOmnibusAPIModel.h
//  Stock
//
//  Created by donggongfu on 17/2/3.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#define TBFuturesRiskRedRate 0.8

#import <TBBaseKit/JSONModel.h>
#import "TBAsset.h"
#import <TBAccountSystemKit/TBUserInfoManager+AccountStatus.h>

//https://git.tigerbrokers.net/alpha/site-api-docs/blob/master/api/index.md#%E8%AF%B7%E6%B1%82%E5%92%8C%E5%93%8D%E5%BA%94%E6%A0%BC%E5%BC%8F
//https://git.tigerbrokers.net/alpha/site-api-docs/blob/master/api/data.md

NS_ASSUME_NONNULL_BEGIN

//1：待免佣；2：已免佣；0：默认值；11已申请免佣
typedef NS_ENUM(NSUInteger, TBOmnibusCommissionCardStatus) {
    TBOmnibusCommissionCardStatusDefault = 0,
    TBOmnibusCommissionCardStatusWaitting = 1,
    TBOmnibusCommissionCardStatusWaived = 2,
    TBOmnibusCommissionCardStatusPending = 11,
};

extern NSString * const TBOmnibusAPIStatusOK;
extern NSString * const TBOmnibusAPIStatusBadRequest;
extern NSString * const TBOmnibusAPIStatusUnauthorized;
extern NSString * const TBOmnibusAPIStatusNotFound;
extern NSString * const TBOmnibusAPIStatusSystemError;
extern NSString * const TBOmnibusAPIStatusOpenShort;
extern NSString * const TBOmnibusAPIStatusTradeUnauthorized;

@interface TBOmnibusAPIModel : JSONModel

@property (nonatomic, copy) NSString *status;
@property (nonatomic, copy, nullable) NSString *message;
@property (nonatomic, assign) NSTimeInterval timestamp;

- (BOOL)isSuccess;

@end

@interface TUPGFVInfoDetialModel : TBOmnibusAPIModel

@property (nonatomic, strong) NSNumber *liftingTimestamp;  //解禁日时间戳（美东时间0点）,GFV用户才有
@property (nonatomic, strong) NSNumber *triggerCount;      //GFV次数
@property (nonatomic, assign) BOOL restricted;            //是否为GFV用户

@end

@interface TUPGFVInfoModel : TBOmnibusAPIModel

@property (nonatomic, strong) TUPGFVInfoDetialModel *data;

@end


NS_ASSUME_NONNULL_END

