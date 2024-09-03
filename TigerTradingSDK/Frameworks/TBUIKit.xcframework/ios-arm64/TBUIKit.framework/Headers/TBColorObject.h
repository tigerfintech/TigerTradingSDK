//
//  TBColorObject.h
//  TBUIKit
//
//  Created by zhengzhiwen on 2021/5/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBColorObject : NSObject

@property (nonatomic, assign) CGSize gradientSize;
@property (nonatomic, strong) UIColor *defaultColor;

- (UIColor *)resultWithColorInfo:(NSDictionary *)colorInfo size:(CGSize)size;

@end

NS_ASSUME_NONNULL_END
