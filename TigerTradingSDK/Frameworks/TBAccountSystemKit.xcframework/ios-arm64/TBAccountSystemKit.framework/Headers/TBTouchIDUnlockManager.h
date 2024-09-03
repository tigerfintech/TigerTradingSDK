//
//  TBTouchIDUnlockManager.h
//  Stock
//
//  Created by WCP on 2018/11/19.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

/*
 枚举值代表没有进行生物验证返回tabbar index
 */
typedef NS_ENUM(NSUInteger, TBTouchIDUnlockFrom) {
    TBTouchIDUnlockFromTrade = 0,            //!< 从交易进来
    TBTouchIDUnlockFromQuote = 1,            //!< 从行情进来
    TBTouchIDUnlockFromAsset = 4,            //!< 从资产进来
};

NS_ASSUME_NONNULL_BEGIN

@interface TBTouchIDUnlockManager : NSObject

+ (TBTouchIDUnlockManager *)sharedInstance;

@property (nonatomic, assign) BOOL hasOpenTouchIDUnlock;     //!< 是否开启了指纹解锁

/**
 是否需要验证指纹

 @return YES NO
 */
- (BOOL)shouldVerifyTouchID;

/**
 标记上次验证时间
 */
- (void)recordCurrentTime;

// 重置验证时间
- (void)resetRecordTime;

@property (nonatomic, strong) NSNumber *verifyLimitTime;
@property (nonatomic, copy, readonly) NSString *verifyLimitTimeKey;

@end

NS_ASSUME_NONNULL_END
