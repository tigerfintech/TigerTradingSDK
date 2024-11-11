//
//  TBUtils+User.h
//  Stock
//
//  Created by ChenXin on 2017/9/19.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseKit.h>
#import <UIKit/UIKit.h>

@interface TBUtils (User)


//获取服务器配置信息，如用户设置的红涨绿跌等等
+ (void)fetchPersonalConfigInfoFromLogin:(BOOL)isFromLogin;

+ (void)uploadPersonalConfigInfo:(void (^)(BOOL success, NSString *message, NSError *error))callBack;

@end

