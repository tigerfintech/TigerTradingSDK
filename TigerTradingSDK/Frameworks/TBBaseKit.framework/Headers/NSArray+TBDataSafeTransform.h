//
//  NSArray+TBDataSafeTransform.h
//  StockGlobal
//
//  Created by linbingjie on 2019/11/27.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSArray (TBDataSafeTransform)

- (NSString *)tbStringAtIndex:(NSInteger)index;
- (NSNumber *)tbNumberAtIndex:(NSInteger)index;
- (NSDictionary *)tbDictionaryAtIndex:(NSInteger)index;
- (NSArray *)tbArrayAtIndex:(NSInteger)index;

@end

NS_ASSUME_NONNULL_END
