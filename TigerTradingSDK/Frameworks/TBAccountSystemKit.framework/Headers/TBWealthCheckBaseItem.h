//
//  TBWealthCheckBaseItem.h
//  AFNetworking
//
//  Created by wind on 2023/11/1.
//

#import <Foundation/Foundation.h>
#import "TBWealthCheckDataSource.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBWealthCheckBaseItem : NSObject

@property (nonatomic, assign) TBWealthCheckType checkType;

@property (nonatomic, copy, nullable) NSDictionary *checkParams;

// 开始检查，子类必须实现
- (void)startCheckWithCompletion:(void(^)(BOOL next, NSDictionary * _Nullable resultInfo))completion;

@end

NS_ASSUME_NONNULL_END
