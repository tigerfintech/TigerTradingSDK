//
//  TBSendSMSUtils.h
//  StockGlobal
//
//  Created by chenxin on 2019/10/21.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>
#import <UIKit/UIKit.h>

typedef void (^TBSendSMSCompletion)(BOOL success);

@interface TBSendSMSUtils : NSObject

DECLARE_SHARED_INSTANCE(TBSendSMSUtils)

- (void)sendSMSWithMessage:(NSString *)message
          inViewController:(UIViewController *)viewCtrl
                completion:(TBSendSMSCompletion)completion;

@end
