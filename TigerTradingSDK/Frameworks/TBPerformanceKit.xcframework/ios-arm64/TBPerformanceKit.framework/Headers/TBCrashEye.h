//
//  TBCrashEye.h
//  CrashEyeOC
//
//  Created by 骆朋飞 on 2017/6/8.
//  Copyright © 2017年 骆朋飞. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "TBDebugLogTableViewCell.h"

typedef NS_ENUM(NSUInteger, TBCrashModelType) {
    TBCrashModelTypeSignal,
    TBCrashModelTypeException,
};

@class TBCrashModel;
@protocol TBCrashEyeDelegate <NSObject>

- (void)crashEyeDidCatchCrash:(TBCrashModel *)model;

@end

@interface TBCrashModel : NSObject <NSCoding, TBDebugLogTableViewCell>

@property (nonatomic, assign) TBCrashModelType type;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *reason;
@property (nonatomic, copy) NSString *appInfo;
@property (nonatomic, copy) NSString *callStack;

@property (nonatomic, copy) NSString *date;

- (instancetype)initWithType:(TBCrashModelType )type name:(NSString *)name reason:(NSString *)reason appInfo:(NSString *)appInfo callStack:(NSString *)callStack;

@end

@interface TBCrashEye : NSObject

+ (instancetype)shareInstance;

/**
 注册crash 回调
 */
- (void)open;

- (NSArray <TBCrashModel *>*)crashLogs;

- (BOOL)removeCrashLogs;

- (NSString *)reportCrashLogString;

@end



