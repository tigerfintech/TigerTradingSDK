//
//  AXServiceFactory.h
//  RTNetworking
//
//  Created by casa on 14-5-12.
//  Copyright (c) 2014年 casatwy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CTService.h"
#import "CTServiceFactory.h"

// 辅助从字符串生成service类, 作用是加了一层内存缓存
// 如果不用"从字符串生成service类"的机制, 可以去掉
@protocol CTServiceFactoryDataSource <NSObject>

/*
 * key为service的Identifier
 * value为service的Class的字符串
 */
- (NSDictionary<NSString *,NSString *> *)servicesKindsOfServiceFactory;

@end

@interface CTServiceFactory : NSObject

@property (nonatomic, weak) id<CTServiceFactoryDataSource> dataSource;

+ (instancetype)sharedInstance;

- (CTService<CTServiceProtocol> *)serviceWithIdentifier:(NSString *)identifier;


@end
