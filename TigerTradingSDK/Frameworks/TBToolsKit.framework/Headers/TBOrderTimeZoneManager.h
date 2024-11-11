//
//  TBOrderTimeZoneManager.h
//  Stock
//
//  Created by yangfan on 2019/9/11.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBObject.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger{
    TBOrderTimeZoneTypeLocal,   //显示本地时区
    TBOrderTimeZoneTypeMarket,  //显示股票市场时区
}TBOrderTimeZoneType;

@interface TBOrderTimeZoneManager : TBObject

+ (instancetype)manager;

- (NSTimeZone *)timeZoneWithMarket:(NSString *)market;

- (TBOrderTimeZoneType)timeZoneTypeWithMarket:(NSString *)market;

- (void)setTimeZoneTypeMarket:(NSString *)market timeZone:(TBOrderTimeZoneType)timeZone;

- (NSString *)timeZoneABBRWithMarket:(NSString *)market useUserPrefrence:(BOOL)useUserPrefrence;

- (NSString *)timeZoneDescription:(NSString *)market;

- (NSString *)timeZoneDescriptionForRspDetail:(NSString *)market;


@end

NS_ASSUME_NONNULL_END
