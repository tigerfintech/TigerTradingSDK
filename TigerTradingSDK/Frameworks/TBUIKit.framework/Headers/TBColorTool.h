//
//  TBBaseUITool.h
//  TBBaseUI
//
//  Created by wind on 2021/4/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBColorTool : NSObject

- (id)getUserDefaultObjectForKey:(NSString *)key defaultValue:(id)value;

- (void)setUserDefaultObject:(id)object forKey:(NSString *)key;

- (BOOL)getUserDefaultBoolForKey:(NSString *)key defaultValue:(BOOL)value;

- (UIViewController *)getTopVC;

@end

NS_ASSUME_NONNULL_END
