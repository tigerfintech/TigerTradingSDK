//
//  TBLoggerFormater.h
//  StockGlobal
//
//  Created by swordzhou on 2020/11/17.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#if __has_include(<CocoaLumberjack/CocoaLumberjack.h>)
#import <CocoaLumberjack/CocoaLumberjack.h>
#endif
NS_ASSUME_NONNULL_BEGIN

@interface TBPlatformLoggerFormatter : NSObject
#if __has_include(<CocoaLumberjack/CocoaLumberjack.h>)
<DDLogFormatter>
#endif
@end

NS_ASSUME_NONNULL_END
