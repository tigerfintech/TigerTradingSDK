//
//  TBCMSAlertInfoManager.h
//  Stock
//
//  Created by JustLee on 2020/7/8.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBCMSAlertInfoModel.h"
#import <TBBaseKit/TBBaseKit.h>

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN NSString * const kNOTIFICATION_KEY_CMS_ALERT;

@interface TBCMSAlertInfoManager : NSObject

DECLARE_SHARED_INSTANCE(TBCMSAlertInfoManager);

- (void)fetchCMSInfoWithSuccess:(void(^ _Nullable )(NSArray <TBCMSAlertInfoModel *> *info))success
                        failure:(void(^ _Nullable )(void))failure;

- (void)startLoopTask;

- (void)recordClosedId:(NSString *)gid;

- (void)addObserver:(id)target
          seclector:(SEL)selector
   fetchDataSuccess:(void(^ _Nullable )(NSArray <TBCMSAlertInfoModel *> *info))success
            failure:(void(^ _Nullable )(void))failure;

- (NSArray <TBCMSAlertInfoModel *> *)watchlistAlertDataWithClass:(Class)cls;

- (NSArray <TBCMSAlertInfoModel *> *)stockDetailAlertDataWithClass:(Class)cls market:(NSString *)market symbol:(NSString *)symbol;

- (NSArray <TBCMSAlertInfoModel *> *)marketQuoteAlertDataWithClass:(Class)cls;

- (NSArray <TBCMSAlertInfoModel *> *)marketQuoteAlertDataWithClass:(Class)cls market:(NSString *)market;

- (NSArray <TBCMSAlertInfoModel *> *)orderAlertDataWithClass:(Class)cls modify:(BOOL)modify;

- (NSArray <TBCMSAlertInfoModel *> *)positionAlertDataWithClass:(Class)cls;

- (NSArray <TBCMSAlertInfoModel *> *)orderListAlertDataWithClass:(Class)cls;

- (NSArray <TBCMSAlertInfoModel *> *)assetsAlertDataWithClass:(Class)cls;
@end

NS_ASSUME_NONNULL_END
