//
//  TBModuleModel.h
//  TBBaseKit
//
//  Created by linbingjie on 2021/3/8.
//

#import <Foundation/Foundation.h>
#import "TBModuleDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBModuleModel : NSObject

@property (nonatomic, copy) NSString *moduleNameKey; // classname
@property (nonatomic, copy) NSNumber *priority; // 优先级，越大越优先
@property (nonatomic, copy) NSDictionary *params; // 初始化参数
@property (nonatomic, strong) id<TBModuleDelegate> targetObject; // 目标对象

@end

NS_ASSUME_NONNULL_END
