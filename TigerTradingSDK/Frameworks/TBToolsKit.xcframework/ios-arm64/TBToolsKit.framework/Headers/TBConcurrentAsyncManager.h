//
//  TBConcurrentAsyncManager.h
//  Stock
//
//  Created by yangfan on 2017/3/31.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBObject.h>

typedef void(^AsyncBlock)(void);

@class TBConcurrentAsyncManager;

@protocol TBConcurrentAsyncManagerDelegate <NSObject>

- (void)ayncManagerDidFinishAllOperations:(TBConcurrentAsyncManager *)manager;

@end

@interface TBConcurrentAsyncManager : TBObject

//添加一个异步对象
- (void)addOperation:(AsyncBlock)block;
//添加一个异步对象，使用Selector,目前只支持1个参数的函数
- (void)addSelectorOperation:(id)object selector:(SEL)selector withParams:(id)params;
//一个异步操作处理完成
- (void)operationComplete;
//设置所有异步操作完成后的回调
- (void)setFinishBlock:(AsyncBlock)block;
//启动所有操作
- (void)concurrentAsyncStart;
//清空所有操作
- (void)concurrentAsyncClear;

@property (nonatomic, weak) id<TBConcurrentAsyncManagerDelegate>        delegate;

@end
