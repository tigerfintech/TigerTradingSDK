//
//  TNEURLSessionConfiguration.h
//  TigerNetworkEye
//
//  Created by 骆朋飞 on 2017/6/4.
//  Refactored by donggongfu on 2021/12/29
//  Copyright © 2021 Tiger Brokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TNEURLSessionConfiguration : NSObject

@property (nonatomic,assign) BOOL swizzled; // whether swizzle NSURLSessionConfiguration's protocolClasses method

/**
 *  get TNEURLSessionConfiguration's singleton object
 *
 *  @return singleton object
 */
+ (TNEURLSessionConfiguration *)defaultConfiguration;

/**
 *  swizzle NSURLSessionConfiguration's protocolClasses method
 */
- (void)load;

/**
 *  make NSURLSessionConfiguration's protocolClasses method is normal
 */
- (void)unload;

@end

NS_ASSUME_NONNULL_END
