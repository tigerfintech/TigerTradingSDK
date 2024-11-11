//
//  TBMissLanguageManager.h
//  TBBaseKit
//
//  Created by 骆鹏飞 on 2022/2/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBMissLanguageManager : NSObject

+ (BOOL)addMissingLanguageKey:(NSString *)key;
+ (NSArray *)missingLanguageKeys;

@end

NS_ASSUME_NONNULL_END
