//
//  TBKeepLiveObject.h
//  Stock
//
//  Created by zhengzhiwen on 2021/3/17.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBKeepLiveObject : NSObject

@property (nonatomic, assign) NSTimeInterval deallocTs;
@property (nonatomic, strong) NSValue *zombie;
@property (nonatomic, copy) NSString *p;
@property (nonatomic, copy) NSString *originClassName;
@property (nonatomic, assign) BOOL hasReport;

- (BOOL)canKill;

@end

NS_ASSUME_NONNULL_END
