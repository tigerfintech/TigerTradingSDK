//
//  TBDeviceId.h
//  Stock
//
//  Created by chenxin on 2019/7/3.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBDeviceId : NSObject

+ (NSString *)deviceId:(NSString *__nonnull)keyChainStoreWithService;

@end

NS_ASSUME_NONNULL_END
