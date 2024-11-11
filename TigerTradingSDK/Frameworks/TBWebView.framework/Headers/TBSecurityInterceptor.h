//
//  TBSecurityInterceptor.h
//  Stock
//
//  Created by donggongfu on 17/3/24.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>
#import <TBBaseKit/TBBaseUtility.h>

@interface TBSecurityInterceptor : NSObject

@property (nonatomic, copy) NSString *token;

DECLARE_SHARED_INSTANCE(TBSecurityInterceptor);

/**
 拦截请求, 加入安全token参数

 @param requestString 原请求URLString
 @return 添加安全token参数的URLString
 */
+ (NSString *)interceptRequest:(NSString *)requestString;

/**
 拦截响应, 跳转到安全验证页面

 @param response 请求响应
 @return 需要跳转的安全验证URLString
 */
+ (NSString *)securityUrlWithResponse:(NSHTTPURLResponse *)response;

/**
 安全验证js触发的回调, 保存token

 @param string 安全验证返回的JSON字符串
 @return YES 验证成功, NO 验证失败
 */
+ (BOOL)securityCheck:(NSString *)string;

+ (void)cancelSecurityCheck;

@end

@interface TBSecurityCheckModel : JSONModel

@property (nonatomic, copy) NSString *token;
@property (nonatomic, assign) NSInteger code;

@end
