//
//  TBFunctionObj.h
//  Stock
//
//  Created by 丁佳婷 on 15/4/9.
//  Copyright (c) 2015年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBFunctionObj.h"
#import <TBBaseKit/TBBaseUtility.h>

@interface TBFunctionObj : NSObject

DECLARE_SHARED_INSTANCE(TBFunctionObj);

/**
 auth服务的错误码对应的消息

 @param errorDic
 @return 
 */
+ (NSString*)ErrorCodeMsg:(NSDictionary*)errorDic;
+ (BOOL)needLogin:(NSDictionary*)errorDic;
+ (void)showHint:(UIView*)showView content:(NSString *)hint hide:(CGFloat)delay;


@end
