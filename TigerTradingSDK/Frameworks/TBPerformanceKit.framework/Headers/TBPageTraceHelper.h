//
//  TBPageTraceHelper.h
//  TBPerformanceKit
//
//  Created by zhengzhiwen on 2022/11/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface TBPageTraceHelper : NSObject

@property (nonatomic, strong, nullable) id trace;
@property (nonatomic, assign) NSUInteger loadTaskCount;
@property (nonatomic, strong) NSMutableDictionary *params;


//页面测速
- (void)traceStartWithPage:(NSString *)page;
- (void)completeTask;
- (void)customLoadStart:(NSString *)name;
- (void)customLoadEnd:(NSString *)name;

//配置网络请求，这里记录path，用于统计
- (void)configNetworkReuqest:(NSArray *)path;
//提供一个上报处理页面无数据的接口
- (void)recordPageEmptyError:(NSString *)reason code:(NSInteger)code;


@end

NS_ASSUME_NONNULL_END
