//
//  UIResponder+Event.h
//  Stock
//
//  Created by zhengzhiwen on 2020/10/16.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIResponder (Event)

- (void)routerEventWithName:(NSString *)eventName userInfo:(NSDictionary *)userInfo;

@end

NS_ASSUME_NONNULL_END
