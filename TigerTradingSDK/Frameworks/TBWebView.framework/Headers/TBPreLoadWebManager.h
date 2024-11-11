//
//  TBPreLoadWebManager.h
//  
//
//  Created by linbingjie on 2023/10/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBPreLoadWebManager : NSObject

/// 预加载（内部也会调用isPreLoadFunctionSupport 进行判断）
/// - Parameter url: url
+ (void)preLoadWebUrl:(NSString *)url;

/// 判断是否支持预加载
+ (BOOL)isPreLoadFunctionSupport;

@end

NS_ASSUME_NONNULL_END

