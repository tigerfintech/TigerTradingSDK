//
//  TBAccountBindingManager.h
//  Stock
//
//  Created by ChenXin on 17/2/10.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
@class TBBaseViewController;

@protocol TBAccountBindingManagerDelegate;

@interface TBAccountBindingManager : NSObject

@property (nonatomic, copy) NSArray *accountBindingCellItems;

@property (nonatomic, weak) TBBaseViewController *viewController;

@property (nonatomic, weak) id <TBAccountBindingManagerDelegate> delegate;

- (void)refreshSnsStatus;

+ (void)fetchWechatUserInfoWithAccessToken:(NSString *)accessToken
                                    openid:(NSString *)openid
                                   success:(void(^)(NSDictionary *userinfo))success
                                   failure:(void(^)(NSError *error))failure;

@end

@protocol TBAccountBindingManagerDelegate <NSObject>

- (void)accountBindingInfoDidUpdate;

@end
