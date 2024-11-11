//
//  TBDanglingPonterService.h
//  TBDefenderDemo
//
//  Created by JustLee on 2021/1/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBDefenderKitService : NSObject

@property (nonatomic, copy) NSArray<NSString *> *danglingPointerClassArr;

@property (nonatomic, copy) NSArray<NSString *> *excludeControllerClassArray;

- (BOOL)foreThrowExceptionEnable;

+ (instancetype)shareInstance;

@end

NS_ASSUME_NONNULL_END
