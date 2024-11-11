//
//  NSTimer+Defender.h
//  Stock
//
//  Created by JustLee on 2021/1/19.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBDefenderKit.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBTimerProxy : NSObject

@property (nonatomic, weak) NSTimer *sourceTimer;
@property (nonatomic, weak) id target;
@property (nonatomic) SEL aSelector;

@end

@interface NSTimer (Defender)

@property (nonatomic, strong) TBTimerProxy *timerProxy;

@end

NS_ASSUME_NONNULL_END
