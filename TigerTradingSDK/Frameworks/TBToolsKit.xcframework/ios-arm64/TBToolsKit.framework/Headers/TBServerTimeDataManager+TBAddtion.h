//
//  TBServerTimeDataManager+TBAddtion.h
//  Stock
//
//  Created by chenxin on 2021/5/20.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBServerTimeDataManager.h>

NS_ASSUME_NONNULL_BEGIN

/*
 和服务端时间保持同步，以防系统时间手动更改
 TODO: 相关逻辑移到TBServerTimeDataManager中
 */

@interface TBServerTimeDataManager (TBAddtion)

// 保存服务端时间
- (void)updateServerTime:(NSNumber *)serverTime;

// 获取精确的服务端时间
- (long)accurateServerTime;

@end

NS_ASSUME_NONNULL_END
