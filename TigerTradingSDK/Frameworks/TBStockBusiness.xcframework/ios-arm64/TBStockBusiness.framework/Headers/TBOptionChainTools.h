//
//  TBOptionChainTools.h
//  TBOptionChain
//
//  Created by 王灵博 on 2021/5/25.
//

#import <Foundation/Foundation.h>
#import <TBStockBusiness/TBOptionChainTools.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionChainTools : NSObject
+ (BOOL)stockIsInTradeTime:(NSArray *)openAndCloseTimeList market:(NSString *)market;

+ (NSDictionary *)marketTimeZoneDesMap;

+ (NSDictionary *)marketTimeZoneMap;
@end

NS_ASSUME_NONNULL_END
