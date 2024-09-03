//
//  NSObject+Leak.h
//  Stock
//
//  Created by zhengzhiwen on 2021/11/10.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (Leak)

+ (void)hookInit;

- (instancetype)leakInit;

@end

NS_ASSUME_NONNULL_END
