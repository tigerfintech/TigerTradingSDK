//
//  TBTabItemCreator.h
//  TBInitializeKit
//
//  Created by 董恭甫 on 2024/1/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TBTabItem;
@class TBStockProLiteManager;

/// 创建Tab类的简单工厂
@interface TBTabItemCreator : NSObject

+ (nullable __kindof TBTabItem *)createTabItemWithName:(NSString *)name;

// 根据BFF配置创建全部tab
+ (NSArray<__kindof TBTabItem *> *)createTabItemsWithConfig:(TBStockProLiteManager *)manager;

@end

NS_ASSUME_NONNULL_END
