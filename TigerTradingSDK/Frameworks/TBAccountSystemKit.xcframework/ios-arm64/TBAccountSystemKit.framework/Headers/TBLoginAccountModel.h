//
//  TBLoginAccountModel.h
//  Stock
//
//  Created by chenxin on 2018/9/11.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/JSONModel.h>

@interface TBLoginAccountModel : JSONModel

@property (nonatomic, copy) NSString *username; // phone/email账号
@property (nonatomic, copy) NSString *nickName; // 昵称
@property (nonatomic, copy) NSString *accessToken;
@property (nonatomic, copy) NSString *refreshToken;
@property (nonatomic, copy) NSString *groupName; // 分组名
@property (nonatomic, copy) NSString *route; // auth对应的路由：CHN或GLOBAL
@property (nonatomic, copy) NSString *uuid;
@property (nonatomic, copy) NSNumber *accessTokenExpiresAt;
@property (nonatomic, copy) NSNumber *refreshTokenExpiresAt;
@property (nonatomic, assign) BOOL isInstitution; //是否是机构账户

@end
