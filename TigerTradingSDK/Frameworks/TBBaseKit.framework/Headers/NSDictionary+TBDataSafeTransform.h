//
//  NSDictionary+TBDataSafeTransform.h
//  StockGlobal
//
//  Created by linbingjie on 2019/11/27.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDictionary (TBDataSafeTransform)

- (NSString *)tbStringForKey:(id)key;
- (NSNumber *)tbNumberForKey:(id)key;
- (NSDictionary *)tbDictionaryForKey:(id)key;
- (NSArray *)tbArrayForKey:(id)key;

@end

NS_ASSUME_NONNULL_END
