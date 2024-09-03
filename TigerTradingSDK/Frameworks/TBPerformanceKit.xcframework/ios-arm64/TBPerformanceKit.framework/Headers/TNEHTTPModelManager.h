//
//  TNEHTTPModelManager.h
//  TigerNetworkEye
//
//  Created by 骆朋飞 on 2017/6/14.
//  Refactored by donggongfu on 2021/12/29
//  Copyright © 2021 Tiger Brokers. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TNEHTTPEye.h"

NS_ASSUME_NONNULL_BEGIN

@class TNEHTTPModel;

@protocol TNEHTTPModelManagerDelegate;

@interface TNEHTTPModelManager : NSObject

@property (nonatomic, assign) NSUInteger saveRequestMaxCount;
@property (nonatomic, assign) BOOL errorOnly; // 只显示非200请求

@property (nonatomic, strong) NSMutableArray *allRequests;

@property (nonatomic, weak) id<TNEHTTPModelManagerDelegate> delegate;

/**
 *  get TNEHTTPModelManager's singleton object
 *
 *  @return singleton object
 */
+ (TNEHTTPModelManager *)defaultManager;

/**
 *  add a TNEHTTPModel object to SQLite
 *
 *  @param aModel a TNEHTTPModel object
 */
- (void)addModel:(TNEHTTPModel *)aModel;

/**
 *  get SQLite all TNEHTTPModel object
 *
 *  @return all TNEHTTPModel object
 */
- (NSMutableArray *)allobjects;

/// 列表页显示的网络请求日志, 可能是allobjects, 或errorOnly的请求
- (NSArray *)listObjects;

/**
 *  delete all SQLite records
 */
- (void)deleteAllItem;

@end

@protocol TNEHTTPModelManagerDelegate <NSObject>

@optional

- (NSMutableArray *)tneModelManagerLoadRequests;
- (void)tneModelManagerSaveRequests:(TNEHTTPModelManager *)manager;
- (void)tneModelManager:(TNEHTTPModelManager *)manager didAddModel:(TNEHTTPModel *)model;
- (void)tneModelManagerDidDeleteAllItems:(TNEHTTPModelManager *)manager;

@end

NS_ASSUME_NONNULL_END
