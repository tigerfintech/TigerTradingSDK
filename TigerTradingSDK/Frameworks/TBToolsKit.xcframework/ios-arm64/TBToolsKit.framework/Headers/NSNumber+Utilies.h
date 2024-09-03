//
//  NSNumber+Utilies.h
//  Stock
//
//  Created by WCP on 2019/2/27.
//  Copyright © 2019年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSNumber (Utilies)

- (NSString *)clearNumberToString;

/**
 //价格%g 在期货有'的价格会只取三位，另外解决小数00000000000001等问题

 @param hasCast 期货s并且带有pie
 @return 转换后的string
 */
- (NSString *)clearNumberToStringHasCast:(BOOL)hasCast;

/// 1、当金额大于0，保留两位小数，千位之后如果有数字，直接舍掉；
/// 2、当金额小于0，保留两位小数，千位之后如果有数据，直接向前进一位；
- (NSNumber *)handleCashNumber;

@end

NS_ASSUME_NONNULL_END
