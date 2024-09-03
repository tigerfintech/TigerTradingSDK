//
//  TBIconMissingManager.h
//  TBUIKit
//
//  Created by 骆鹏飞 on 2021/7/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/*
 图片缺失类
 */
@interface TBIconMissingManager : NSObject

+ (BOOL)addMissingImageName:(NSString *)imgName;
+ (NSArray *)missingImageNames;
@end

NS_ASSUME_NONNULL_END
