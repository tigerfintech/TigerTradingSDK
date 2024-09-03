//
//  TBQAXManager.h
//  TBHostManager
//
//  Created by linbingjie on 2024/6/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBQAXManager : NSObject

/// 获取qax列表数据
+ (NSArray *)fetchQAXList;
/// 请求测试环境获取所有qax列表数据
+ (void)updateQAXListConfigureWithCompletion:(nullable void(^)(NSArray * _Nullable result))completion;


/// 设置选中的qax（提供缓存使用的key）
+ (void)configSelectedQAXItem:(NSString *)selectedString;
/// 返回当前选中的qax
+ (NSString *)fetchSelectedQAXItem;


@end

NS_ASSUME_NONNULL_END
