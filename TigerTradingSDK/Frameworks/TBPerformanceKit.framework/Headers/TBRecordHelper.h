//
//  TBRecordHelper.h
//  Stock
//
//  Created by zhengzhiwen on 2022/6/23.
//  Copyright © 2022 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBRecordHelper : NSObject

@property (nonatomic, assign, readonly) BOOL isActive;

+ (instancetype)shared;

- (void)start:(SEL)command;
- (NSTimeInterval)end:(SEL)command;
- (void)appendLog:(NSString *)log;
- (void)upload;
- (void)upload:(NSString *)log fileName:(NSString *)fn;

- (void)changeActive:(BOOL)active;

@end

NS_ASSUME_NONNULL_END
