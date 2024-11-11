//
//  TBShareMemoryDataManager.h
//  Stock
//
//  Created by F.S. on 2021/1/7.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const TBCommunityNewPostShare;
extern NSString * const TBCommunityNewPostShareTime;

extern NSString * const TBCommunityHKIPOShare;
extern NSString * const TBCommunityUSIPOShare;

extern NSString * const TBCommunityNewPostShareOmni;
extern NSString * const TBCommunityNewPostShareIB;

@interface TBShareMemoryModel : NSObject

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, assign) NSTimeInterval time;
@property (nonatomic, copy) NSString *account;

@end

@interface TBShareMemoryDataManager : NSObject

// 持仓 & 当日买卖
+ (void)updateShareObjTime:(NSTimeInterval)time;
+ (void)archiveShareObject:(NSString *)symbol market:(NSString *)market;
+ (BOOL)showShareItem:(NSString *)symbol market:(NSString *)market;

// 港股ipo相关
+ (void)archiveHKIPOShareObject:(NSString *)symbol deadTime:(NSTimeInterval)deadTime;
+ (BOOL)showHKIPOShareCard:(NSString *)symbol deadTime:(NSTimeInterval)deadTime;

// 美股ipo相关
+ (void)archiveUSIPOShareObject:(NSString *)symbol listingTime:(NSTimeInterval)listingTime;
+ (BOOL)showUSIPOShareCard:(NSString *)symbol listingTime:(NSTimeInterval)listingTime;
+ (BOOL)isUSIPODay:(NSTimeInterval)ipoTime;

@end

NS_ASSUME_NONNULL_END
