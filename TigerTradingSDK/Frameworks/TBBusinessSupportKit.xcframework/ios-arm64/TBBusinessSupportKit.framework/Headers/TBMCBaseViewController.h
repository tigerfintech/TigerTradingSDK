//
//  TBMCBaseViewController.h
//  Stock
//
//  Created by yangfan on 16/11/7.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

@import TBUIKit;
#import <TBUIKit/TBBaseViewController.h>

typedef void(^TBMessageCenterDidReadBlock)(void);

@class TBMCDataService;

@interface TBMCBaseViewController : TBBaseViewController

@property (nonatomic, copy) TBMessageCenterDidReadBlock didReadBlcok;

@property (nonatomic, strong, readonly) TBMCDataService *messageCenterDataService;

- (void)setMessageReaded:(NSInteger)columnId;
- (void)setMessageReaded:(NSInteger)columnId withSuccessBlock:(dispatch_block_t)success failureBlock:(void(^)(NSError *error))failure;

@end
