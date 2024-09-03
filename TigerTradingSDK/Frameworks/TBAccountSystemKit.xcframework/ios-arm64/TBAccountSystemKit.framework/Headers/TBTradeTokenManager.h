//
//  TBTradeTokenManager.h
//  Stock
//
//  Created by toanso on 15/2/14.
//  Copyright (c) 2015年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBAccountSystemKit/ZCTradeView.h>
#import <TBBaseKit/TBBaseUtility.h>

extern NSString * const TBTradeTokenManagerHeaderKey;

extern NSString * const TBTradeTokenManagerCancelKey;

const static NSInteger kTBTradePasswordInputCancel = -90001;///< 输入交易密码弹窗 界面，用户选择 取消 后的标志

typedef void (^TBTradeTokenFetchCompletion)(BOOL success, NSString *errorMsg);

@interface TBTradeTokenManager : NSObject

@property (atomic, copy) NSString *tradeToken;

@property (atomic, assign) BOOL onlyVerifyTradePassword;  //!< 只是校验交易密码

@property (nonatomic, assign) BOOL hasShowLimitedAlert;  //!< 是否弹出过提示, 内存缓存

@property (nonatomic, assign) BOOL userTouchIDAuth;

@property (nonatomic, assign) BOOL hasShowGuideTouchIDView;  //!< 是否引导用户去开启TouchID

// 强引用VC，用于二次验证
@property (nonatomic, strong) UIViewController * secondVerifyfromViewController;

DECLARE_SHARED_INSTANCE(TBTradeTokenManager);

// 是否需要获取交易token
- (BOOL)needTradeToken;

// 隐藏交易密码视图
- (void)hideTradeView;

//开启TouchID解锁，交易密码验证
- (void)openTouchIDUnlockInViewController:(UIViewController *)viewController
                               completion:(TBTradeTokenFetchCompletion)completion;

// 获取交易token
- (void)fetchTradeTokenInViewController:(UIViewController *)viewController
                             completion:(TBTradeTokenFetchCompletion)completion;

- (void)fetchTradeTokenInViewController:(UIViewController *)viewController
                                 cancel:(dispatch_block_t)cancel
                             completion:(TBTradeTokenFetchCompletion)completion;

// 指定是否只通过密码方式获取tradeToken，比如亲友账户等业务
- (void)fetchTradeTokenInViewController:(UIViewController *)viewController
                              passwordOnly:(BOOL)passwordOnly
                             completion:(TBTradeTokenFetchCompletion)completion;

// 指定是否只通过密码方式获取tradeToken，比如亲友账户等业务,customView指在密码输入框中显示自定义内容
- (void)fetchTradeTokenInViewController:(UIViewController *)viewController
                             customView:(UIView *)customView
                              passwordOnly:(BOOL)passwordOnly
                             completion:(TBTradeTokenFetchCompletion)completion;

// 使用交易密码获取交易token，并检查交易密码是否正确
- (void)fetchTradeTokenWithPassword:(NSString *)password
                          tradeView:(ZCTradeView *)tradeView
                     needDynamicPSD:(BOOL)needDynamicPSD
                            success:(void(^)(BOOL success))success
                            failure:(void(^)(NSString *errorMsg))failure;

@end
