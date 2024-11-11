//
//  TUPAnalytics.h
//  StockGlobal
//
//  Created by DepthFirst on 2019/8/9.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TUPAnalyticsEventNames.h"
#import "TUPAnalyticsParameterNames.h"
#import "TUPAnalyticsUserPropertyNames.h"

//@import Firebase;

#define TUP_ANALYTICS_LOG_EVENT(_NAME)  [TUPAnalytics logEventWithName:_NAME]
#define TUP_ANALYTICS_LOG_EVENT_WITH_PARAMETERS(_NAME, _PARAMETERS) [TUPAnalytics logEventWithName:_NAME parameters:_PARAMETERS];

NS_ASSUME_NONNULL_BEGIN

@interface TUPAnalytics : NSObject

+ (void)logEventWithName:(NSString *)name;
+ (void)logEventWithName:(NSString *)name parameters:(nullable NSDictionary<NSString *, id> *)parameters;

@end

NS_ASSUME_NONNULL_END
