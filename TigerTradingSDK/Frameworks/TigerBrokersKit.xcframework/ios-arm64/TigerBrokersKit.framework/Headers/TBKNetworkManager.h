//
//  TBKNetworkManager.h
//  TigerBrokersKit
//
//  Created by DepthFirst on 2018/10/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBKNetworkManager : NSObject

/**
 Whether or not the network is currently reachable.
 */
@property (readonly, nonatomic, assign, getter = isReachable) BOOL reachable; // 网络是否联通, 调用afn的类来实现, 因为网络调用afn, 判断网络状态的代码也使用afn, 保持统一性

@end

NS_ASSUME_NONNULL_END
