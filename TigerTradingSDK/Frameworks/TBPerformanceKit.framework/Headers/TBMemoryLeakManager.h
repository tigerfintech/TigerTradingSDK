//
//  TBMemoryLinkManager.h
//  Stock
//
//  Created by zhengzhiwen on 2021/11/10.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBMemoryObject : NSObject

@property (nonatomic, weak) NSObject *obj;
@property (nonatomic, copy) NSString *type;

@end

@interface TBMemoryLeakManager : NSObject

@property (nonatomic, assign, readonly) BOOL isWorking;

+ (instancetype)share;
- (void)addDetect:(NSObject *)obj;


@end

NS_ASSUME_NONNULL_END
