//
//  TBSnsLoginManager.h
//  TBAccountSystemKit
//
//  Created by chenxin on 2023/5/9.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^TBSnsLoginCallback)(NSDictionary *_Nullable responseDict);

extern NSString * const kNOTIFICATION_KEY_SEND_TOKEN_BACK_FROM_TWITTER;

@interface TBSnsLoginManager : NSObject

@property (nonatomic, copy) NSArray *snsList; // 三方登录列表

- (void)saveSnsList:(NSArray *)snsList;

DECLARE_SHARED_INSTANCE(TBSnsLoginManager)

+ (BOOL)canHandleDeepLink:(NSURL *)url;

// 使用state和code等信息从auth获取id_token
- (void)requestSnsIdTokenWithType:(NSString *)type
                        parameter:(NSDictionary *)parameter
                          success:(void (^)(NSDictionary *dataDict))success
                          failure:(void (^)(NSString *errorMsg))failure;

/*
 使用WebAuthentication方式的三方登录
 type 目前支持singpass，twitter
 callback 登录成功返回code和state等信息，否则返回nil
 */
- (void)snsLoginWithType:(NSString *)type callback:(TBSnsLoginCallback)callback;

// singpass登录
- (void)startSingpassWithCallback:(TBSnsLoginCallback)callback;

// myinfo登录
- (void)startMyInfoWithCallback:(TBSnsLoginCallback)callback;
- (void)startMyInfoWithParameters:(nullable NSDictionary *)parameters callback:(TBSnsLoginCallback)callback;

@end

NS_ASSUME_NONNULL_END
