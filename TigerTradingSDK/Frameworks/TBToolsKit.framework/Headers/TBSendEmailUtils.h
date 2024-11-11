//
//  TBSendEmailUtils.h
//  StockGlobal
//
//  Created by chenxin on 2019/5/28.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>
#import <UIKit/UIKit.h>

typedef void (^TBSendEmailCompletion)(BOOL success, NSString *message);

@interface TBSendEmailUtils : NSObject

DECLARE_SHARED_INSTANCE(TBSendEmailUtils)

- (void)sendEmailWithToRecipients:(NSArray <NSString *>*)recipients
                          Subject:(NSString *)subject
                          message:(NSString *)message
                       isFeedback:(BOOL)isFeedback
                             tags:(NSArray<NSString *> *)tags
                           images:(NSArray<UIImage *> *)images
                             logs:(NSArray<NSString *> *)logs
                 inViewController:(UIViewController *)viewCtrl
                       completion:(TBSendEmailCompletion)completion;

- (void)sendEmailWithSubject:(NSString *)subject
                     message:(NSString *)message
            inViewController:(UIViewController *)viewCtrl
                  completion:(TBSendEmailCompletion)completion;

// 指定邮件收件人
- (void)sendEmialToRecipients:(NSArray *)recipients
             inViewController:(UIViewController *)viewCtrl;

#pragma mark - TUP Send Email

- (void)tup_sendEmailWithToRecipients:(NSArray <NSString *>*)recipients
                              Subject:(NSString *)subject
                              message:(NSString *)message
                           isFeedback:(BOOL)isFeedback
                                 tags:(NSArray<NSString *> *)tags
                               images:(NSArray<UIImage *> *)images
                                 logs:(NSArray<NSString *> *)logs
                     inViewController:(UIViewController *)viewCtrl
                           completion:(TBSendEmailCompletion)completion;
@end
