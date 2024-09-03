//
//  TBHomePageResourceManager.h
//  TBHomePage
//
//  Created by linbingjie on 2023/6/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBHomePageResourceManager : NSObject

/// 从tbuikit内读取图片（提供给swift文件使用）
+ (UIImage *)fetchImageFromTBUIKit:(NSString *)imageName;

@end

NS_ASSUME_NONNULL_END
