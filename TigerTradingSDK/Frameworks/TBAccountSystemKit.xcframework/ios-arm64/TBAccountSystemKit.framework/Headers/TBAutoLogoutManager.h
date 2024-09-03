//
//  TBAutoLogoutManager.h
//  Stock
//
//  Created by chenxin on 2018/11/1.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

typedef NS_ENUM(NSUInteger, TBAutoLogoutTimeType) {
    TBAutoLogout5Minutes,
    TBAutoLogout15Minutes,
    TBAutoLogout30Minutes,
    TBAutoLogoutNever
};

@interface TBAutoLogoutManager : NSObject

DECLARE_SHARED_INSTANCE(TBAutoLogoutManager)

@property (nonatomic, copy, readonly) NSArray *timeTypeTitles;

@property (nonatomic, copy, readonly) NSString *currentTimeTypeTitle;

@property (nonatomic, assign) TBAutoLogoutTimeType currentTimeType;

// 判断是否需要登出
- (BOOL)shouldLogout;

// 重置登出时间
- (void)reset;

@end
