//
//  NSString+TBPlatformLogger.h
//  TBPlatformLogger
//
//  Created by JustLee on 2021/1/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (TBPlatformLogger)

- (NSString *)tb_log_aesEncryptString:(NSString *)keyString iv:(NSData *)iv;
- (NSString *)tb_log_aesDecryptString:(NSString *)keyString iv:(NSData *)iv;

@end

NS_ASSUME_NONNULL_END
