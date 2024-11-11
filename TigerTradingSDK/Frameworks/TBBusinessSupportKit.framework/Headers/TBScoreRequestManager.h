//
//  TBScoreRequestManager.h
//  Stock
//
//  Created by chenxin on 2019/4/15.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBScoreTaskModel.h"
#import <TBBaseKit/TBBaseUtility.h>

@interface TBScoreRequestManager : NSObject

DECLARE_SHARED_INSTANCE(TBScoreRequestManager)

- (void)getScoreInfoWithSuccess:(void (^)(NSDictionary *dataDict))success
                    failure:(void (^)(NSString *errorMsg))failure;

/// 用户积分任务列表，dailyTasksOnly为YES时只返回每日未完成任务
- (void)getUserTaskWithDailyTasksOnly:(BOOL)dailyTasksOnly
                              success:(void (^)(NSDictionary *dataDic))success
                              failure:(void (^)(NSString *errorMsg))failure;

@end
