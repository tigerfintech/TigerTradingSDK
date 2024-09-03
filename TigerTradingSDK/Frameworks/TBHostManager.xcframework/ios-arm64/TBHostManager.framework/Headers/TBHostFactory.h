//
//  TBHostFactory.h
//  Pods
//
//  Created by linbingjie on 2021/2/22.
//

#import <Foundation/Foundation.h>
#import "TBBaseHost.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TBHostType) {
    TBHostTypeDefault,
    TBHostTypeTigerTrade,
    TBHostTypeTradeUP,
};

@interface TBHostFactory : NSObject
+ (TBBaseHost *)fetchHost:(TBHostType)type;
@end

NS_ASSUME_NONNULL_END
