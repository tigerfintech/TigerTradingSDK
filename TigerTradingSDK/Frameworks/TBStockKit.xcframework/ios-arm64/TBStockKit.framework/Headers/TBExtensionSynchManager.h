//
//  TBExtensionSynchManager.h
//  Stock
//
//  Created by yangfan on 2019/9/4.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBExtensionSynchManager : NSObject

+ (instancetype)manager;

- (void)synchUserDefaults:(NSString *)key value:(nullable id)value;

- (nullable id)valueForKey:(NSString *)key;

- (UIColor *)getIncreaseColor;

- (UIColor *)getDecreaseColor;

@end

#define TBExtensionSynchKit [TBExtensionSynchManager manager]

NS_ASSUME_NONNULL_END
