//
//  TBDataTaskOperation.h
//  Stock
//
//  Created by ChenXin on 2017/4/18.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TBDataTaskOperation : NSOperation

@property (nonatomic, strong, readonly) NSURLSessionDataTask *dataTask;

+ (instancetype)operationWithTask:(NSURLSessionDataTask *)dataTask;

- (void)completeOperation;

@end
