//
//  TBApplePayActionManager.h
//  Stock
//
//  Created by 王昌阳 on 2020/5/12.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TBApplePayActionType) {
    TBApplePayActionTypeNone    = 0,
    TBApplePayActionTypeQuote   = 1,///< 行情购买
};


@interface TBApplePayPromoteProductAction : NSObject

@property (nonatomic, copy, readonly) NSString *productId;///< 商品ID
@property (nonatomic, assign, readonly) TBApplePayActionType actionType;///< 跳转事件类型
@property (nonatomic, copy, readonly) NSString *extraInfo;///< 额外信息

+ (instancetype)actionWithProductId:(NSString *)productId;

@end


@interface TBApplePayActionManager : NSObject

@property (nonatomic, copy) NSString *promoteProductId;///< 推广商品ID

+ (instancetype)manager;

- (void)checkApplePayAction;

@end

NS_ASSUME_NONNULL_END
