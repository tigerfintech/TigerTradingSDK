//
//  TBOpenOptionManager.h
//  StockGlobal
//
//  Created by wind on 2020/4/8.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TUPASDKUserDataModel.h"
#import "TUPOpenOptionAgreementModel.h"

typedef NS_ENUM(NSUInteger, TBOpenOptionState) {
    TBOpenOptionNotApply = 0,  //期权未申请开通
    TBOpenOptionPending,       //期权开通审核中
    TBOpenOptionSuccess,       //期权开通成功
    TBOpenOptionRejected,      //期权开通被拒
};

@interface TUPOpenOptionRequestManager : NSObject

/// 获取用户信息
/// @param success 获取成功回调
/// @param failure 获取失败回调
+ (void)getUserInfoWithSuccess:(void(^)(TUPASDKUserDataModel *userInfoModel))success failure:(void(^)(NSString *errorString))failure;

/// 获取用户期权开通进度
/// @param success 获取成功回调
/// @param failure 获取失败回调
+ (void)getOpenOptionStateSuccess:(void(^)(TBOpenOptionState state))success failure:(void(^)(NSString* errorString))failure;

/// 获取期权开通协议
/// @param success 获取成功回调
/// @param failure 获取失败回调
+ (void)getOpenOptionAgreementsWithSuccess:(void(^)(NSArray<TUPOpenOptionAgreementModel *> *agreements))success failure:(void(^)(NSString *errorString))failure;


/// 期权开通申请
/// @param parameters 参数
/// @param success 成功回调
/// @param failure 失败回调
+ (void)openOptionApplyWithParams:(NSDictionary *)parameters success:(void(^)(void))success failure:(void(^)(NSString* errorString))failure;

@end
