//
//  TBServerTimeDataManager.h
//  Stock
//
//  Created by liwt on 11/30/15.
//  Copyright © 2015 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TBServerTimeDataManager : NSObject

+ (instancetype)sharedInstance;

@property (atomic, strong) NSNumber *serverTime;

@end
