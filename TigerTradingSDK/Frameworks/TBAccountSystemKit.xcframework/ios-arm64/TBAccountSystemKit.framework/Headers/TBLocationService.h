//
//  TBLocationService.h
//  TBAccountSystemKit
//
//  Created by mashanli on 2023/11/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBLocationService : NSObject

/// 获取用户的location
+ (void)getIPLocation:(void (^)(id responseObject))success failure:(void (^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
