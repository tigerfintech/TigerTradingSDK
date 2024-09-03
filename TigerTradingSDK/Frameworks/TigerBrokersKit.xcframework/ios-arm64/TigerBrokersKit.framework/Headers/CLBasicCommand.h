//
//  CLBasicCommand.h
//  CLNetWorkApiManager
//
//  Created by liang on 2017/8/11.
//  Copyright © 2017年 liang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBKURLRequest.h"

NS_ASSUME_NONNULL_BEGIN

@class CLBasicCommand;
@protocol CLCommandDataSource <NSObject>

-(NSDictionary *)paramsForcommand:(CLBasicCommand *)command;

@end


@protocol CLBasicCommandDelegate <NSObject>
@required
//如果是做串行调用，两个方法中只会执行一次
-(void)command:(CLBasicCommand *)commands didFaildWith:(TBKURLRequest *)apiManager;
-(void)command:(CLBasicCommand *)commands didSuccess:(TBKURLRequest *)apiManager;

//如果一个recvier关心这次数据，则可以实现这个方法，在这个方法中取数据
@optional
-(void)command:(CLBasicCommand *)commands successMessage:(TBKURLRequest *)apiManager;

@end

@interface CLBasicCommand : NSObject
@property (nonatomic, strong) CLBasicCommand *next;
@property (nonatomic, readonly) TBKURLRequest *apiManager;

//回调代理
@property (nonatomic, weak) id <CLBasicCommandDelegate> delegate;
//数据源
@property (nonatomic, weak) id <CLCommandDataSource> dataSource;

//这个参数对于做串行调用的时候，如果有值怎直接拿这个做参数，而不是通过代理
@property (nonatomic, copy) NSDictionary *params;


- (void)execute;
- (NSDictionary *)paramsForNextCommand:(TBKURLRequest *)apiManager;
@end

NS_ASSUME_NONNULL_END

