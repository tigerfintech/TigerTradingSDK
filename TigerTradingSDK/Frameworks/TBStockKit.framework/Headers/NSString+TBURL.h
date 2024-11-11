//
//  NSString+TBURL.h
//  TBStockKit
//
//  Created by zhengzhiwen on 2021/6/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (TBURL)

// 根据symbol 来返回需要跳转到的个股的url,
// 美股是字母, A股是6位数字, 港股是5位数字, 暂时不支持港股.默认为跳美股.
+ (NSString *)getStockDetailUrlFromSymbol:(NSString *)symbol;

// 根据market 来判断个股页面的url,
// 美股 US,  A股 是 SH 或者 SZ:股票 or 基金, 港股是 HK.(港股暂不支持), 默认跳美股.
+ (NSString *)getStockDetailUrlFromMarket:(NSString *)market symbol:(NSString*)symbol;

@end

NS_ASSUME_NONNULL_END
