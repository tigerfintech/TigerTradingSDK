//
//  TBPollingManager.h
//  Stock
//
//  Created by donggongfu on 17/3/28.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TBNetworkStatus) {
    TBNetworkStatusConnected,
    TBNetworkStatusLow,
    TBNetworkStatusDisconnected,
    TBNetworkStatusReconnected
};

@protocol TBPollingManagerDelegate <NSObject>

@required
- (void)networkStatusChanged:(TBNetworkStatus)status;

@end

@interface TBPollingManager : NSObject

@property (nonatomic, assign, readonly) BOOL lastResult;
@property (nonatomic, assign, readonly) CGFloat failureRate;
@property (nonatomic, assign) NSTimeInterval pollingInterval;
@property (nonatomic, assign) NSInteger level;
@property (nonatomic, weak) id<TBPollingManagerDelegate> delegate;
@property (nonatomic, assign) TBNetworkStatus status;

- (void)succeed;
- (void)fail;
- (void)update;

@end
