//
//  TBETFHelper.h
//  TBStockBusinessBaseKit
//
//  Created by wind on 2023/11/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBETFManager : NSObject

@property (nonatomic, assign) BOOL isInWealthPage;

@property (nonatomic, copy) NSString *saPage;

@property (nonatomic, copy) void(^changeTopicBlock)(void);

- (NSArray *)etfModuleItems;

- (void)requestETFMallSuccess:(nullable void(^)(id responseObject))success failure:(nullable void(^)(NSError *error))failure;

- (void)requestETFMallWithTopicId:(nullable NSString *)etfTopicId
                            limit:(nullable NSString *)etfTopicLimit
                          success:(nullable void(^)(id responseObject))success
                          failure:(nullable void(^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
