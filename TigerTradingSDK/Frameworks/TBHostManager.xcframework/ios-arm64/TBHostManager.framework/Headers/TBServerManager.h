//
//  TBServerManager.h
//  Stock
//
//  Created by ChenXin on 2017/8/3.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

@interface TBServerManager : NSObject

DECLARE_SHARED_INSTANCE(TBServerManager)

- (void)handleRequestURL:(NSURL *)URL error:(NSError *)error;

- (void)changeServerWithIndex:(NSInteger)serverIndex;

@end
