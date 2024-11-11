//
//  TBOpenAccountComponentService.h
//  Pods
//
//  Created by chenxin on 2022/6/1.
//

#ifndef TBOpenAccountComponentService_h
#define TBOpenAccountComponentService_h

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBOpenAccountComponentService <NSObject>

/// 开户引导页
- (UIViewController *)tbOpenAccount_guideViewController;

- (NSString *)tbOpenAccount_TBFaceVerifyResultNotification;

@end

NS_ASSUME_NONNULL_END

#endif /* TBOpenAccountComponentService_h */
