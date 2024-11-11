//
//  TBStockQuoteLoopTimerManager.h
//  Stock
//
//  Created by 骆鹏飞 on 2021/2/18.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockQuoteLoopTimerManager : NSObject


/// 轮询时间，默认值为6s
/// @param className className description
+ (NSTimeInterval)quoteLoopTime:(NSString *)className;

@property (nonatomic, copy, readonly, class) NSDictionary *loopTimeDict;

@end

NS_ASSUME_NONNULL_END
