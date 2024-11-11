//
//  TBMlegWatchListProtocol.h
//  TBBusinessSupportKit
//
//  Created by mashanli on 2024/6/13.
//  Copyright © 2024年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TBMlegWatchListProtocol <NSObject>

@optional

//避免重名
@property (nonatomic, copy, readonly) NSString *watchListSymbol;//正股symbol
@property (nonatomic, strong, readonly) NSNumber *watchListExpiry;//过期日
@property (nonatomic, copy, readonly) NSString *watchListStrike;//行权价
@property (nonatomic, copy, readonly) NSString *watchListRight;//call put
@property (nonatomic, copy, readonly) NSString *watchListDirection;//买卖方向buy sell
@property (nonatomic, strong, readonly) NSNumber *watchListSize;//数量

@end
