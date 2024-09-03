//
//  TBResourcesManager.h
//  Pods
//
//  Created by linbingjie on 2023/5/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBResourcesManager : NSObject

+ (NSBundle *)fetchResourcesBundle;

+ (nullable UIImage *)resources_xcassetImageNamed:(NSString *)name;

@end

NS_ASSUME_NONNULL_END
