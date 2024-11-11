//
//  TBHomePageFractionalShareAlertManager.h
//  TBSwiftComponent
//
//  Created by zlc on 2022/9/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBHomePageFractionalShareAlertManager : NSObject

+ (void)ttShowFractionalShareOpenAccessAlert;

/// TT是否展示首页碎股引导弹窗
+ (BOOL)ttIsFractionalShareAlertShowEnable;

@end

NS_ASSUME_NONNULL_END
