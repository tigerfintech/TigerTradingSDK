//
//  TBSymbolDetailRouterFactory.h
//  TBTradeBusiness
//
//  Created by 王昌阳 on 2023/9/20.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@interface TBSymbolDetailRouterFactory : NSObject

+ (instancetype)factoryWithSecType:(NSString *)secType symbolItem:(id)symbolItem;

- (NSString *)actionUrlPath;

- (NSDictionary *)actionRequiredParams;

@end

NS_ASSUME_NONNULL_END
