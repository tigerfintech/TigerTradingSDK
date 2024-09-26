//
//  TBContraRankHttpManager.h
//  StockBusiness
//
//  Created by liuhuan on 2024/6/20.
//  Copyright © 2024 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBContraRankHttpManager : NSObject

+ (void)fetchTopicsArrayWithMarket:(NSString *)market success:(void(^)(NSArray * _Nullable topicArray))success fail:(void(^)(NSError *error))fail;

+ (void)fetchRankArrayWithMarket:(NSString *)market params:(NSDictionary *)params success:(void(^)(NSDictionary * _Nullable data))success fail:(void(^)(NSError *error))fail;

@end

NS_ASSUME_NONNULL_END
