//
//  TBAppDateFormat.h
//  StockGlobal
//
//  Created by swordzhou on 2021/07/15.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

// 中英文日期格式不同，统一管理

@interface TBAppDateFormat : NSObject

@property (nonatomic, copy, readonly) NSString *ymdDateFormat;  //年月日
@property (nonatomic, copy, readonly) NSString *mdDateFormat;   //月日
@property (nonatomic, copy, readonly) NSString *mdhmDateFormat; //月日时分, 英文带上上下午
@property (nonatomic, copy, readonly) NSString *hmDateFormat;   //时分, 英文带上上下午
@property (nonatomic, copy, readonly) NSString *hmsFormat; // 时分秒格式，英文带上am/pm，中文24小时制

//消息中心消息列表 中文以/作为分割线
@property (nonatomic, copy, readonly) NSString *ymdDateFormat2;  //年月日
@property (nonatomic, copy, readonly) NSString *mdDateFormat2;   //月日
@property (nonatomic, copy, readonly) NSString *mdhmDateFormat2; //月日时分, 英文带上下午
@property (nonatomic, copy, readonly) NSString *hmDateFormat2;   //时分, 英文带上下午

@property (nonatomic, copy, readonly) NSLocale *locale;

@end
