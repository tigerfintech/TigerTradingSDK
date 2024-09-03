//
//  TBShareHandler.h
//  Stock
//
//  Created by ChenXin on 2017/11/13.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>
#import "TBShareDefines.h"

@interface TBShareHandler : NSObject

DECLARE_SHARED_INSTANCE(TBShareHandler)

- (void)shareBackFromType:(NSString *)type result:(TBShareResult)result;

@end
