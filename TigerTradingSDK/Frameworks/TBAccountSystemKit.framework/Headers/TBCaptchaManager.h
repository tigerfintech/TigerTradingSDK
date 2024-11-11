//
//  TBCaptchaManager.h
//  StockGlobal
//
//  Created by chenxin on 2019/9/4.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

typedef void (^TBCaptchaCompletion)(NSDictionary *dataDict);


typedef void (^TBCaptchaSuccessBlock)(NSString *response);

typedef void (^TBCaptchaFailureBlock)(NSDictionary *errorDic);


@interface TBCaptchaManager : NSObject

DECLARE_SHARED_INSTANCE(TBCaptchaManager)

// 这两个属性是提供给h5 bridge获取recaptcha参数
@property (nonatomic, copy) NSString *process;
@property (nonatomic, copy) NSString *recaptchaWebSiteKey;
@property (nonatomic, copy) NSString *recaptchaSiteKey;

- (void)startCaptchaWithParameters:(NSDictionary *)parameters isVoice:(BOOL)isVoice withCompletion:(TBCaptchaCompletion)completion;

// 从server 获得极验验证相关code后， 拼接成相应的参数传递url
- (NSString *)generateGTEncodedUrlStringWithDictionary:(NSDictionary *)dict;

// 从server 获得极验验证相关code后， 生成相应的post 参数字典 （接口支持json）
- (NSDictionary *)generateGTEncodedUrlParamWithDictionary:(NSDictionary *)dict;

- (void)stopCaptcha;

// 成功、失败block置空。（外部调用：关闭web验证弹框的时候会调用）
- (void)updateBlockToNil;

/*
 海外包验证码登录触发验证需要根据账号区分用哪个auth域名，
 parameters需包含grant_type，username和tel_code（可选）
 验证码登录接口必须传parameters，其他接口可不传
 */
- (void)startCaptchaWithParameters:(NSDictionary *)parameters process:(NSString *)process isVoice:(BOOL)isVoice withSuccess:(TBCaptchaSuccessBlock)successBlock failure:(TBCaptchaFailureBlock)failureBlock;

@end
