//
//  TBMQTTCryptoCurrencyHttpManager.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/9/28.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBMQTTClientBaseManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBMQTTCryptoCurrencyHttpManager : TBMQTTClientBaseManager
+ (instancetype)sharedInstance;

@property (atomic, copy, nullable) void (^quoteCCDepthMessageHandler)(NSData *message, NSString *topic);
/// 数字货币Level2
/// @param symbol <#symbol description#>
/// @param quoteType <#quoteType description#>
/// @param usePB <#usePB description#>
/// @param callBack <#callBack description#>
- (void)subscribeCCQuoteDepth:(NSString *)symbol quoteType:(NSString *)quoteType usePB:(BOOL)usePB callBack:(void (^)(NSData * _Nonnull, NSString * _Nonnull))callBack;
- (void)unsubscribeCCQuoteDepth:(NSString *)symbol quoteType:(NSString *)quoteType usePB:(BOOL)usePB;

@end

NS_ASSUME_NONNULL_END
