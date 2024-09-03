//
//  BLBaseAPITarget.h
//  BLNetworking
//
//  Created by casa on 2017/1/18.
//  Copyright © 2017年 casa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBKURLRequest.h"

#import "TBKURLRequestDelegate.h"

extern NSString * const kCTBaseAPITargetAPIContextDataKeyParamsForAPI;
extern NSString * const kCTBaseAPITargetAPIContextDataKeyParamsAPIManager;
extern NSString * const kCTBaseAPITargetAPIContextDataKeyOriginActionParams;

@interface Target_H5API : NSObject <TBKURLRequestCompletionDelegate, /*TBAPIManagerParamSource,*/ TBKURLRequestDelegate>

- (id)Action_loadAPI:(NSDictionary *)params;

@end

// 未使用
// 把api manager的类型, 参数, url, 回调都存入字典, 交给这个对象执行
// 同时, 由于去model话, 得到的数据是字典类型, 可以被回调处理
// 是一种抽象网络请求的方式, 让网络请求能以字符串, 字典的形式下发, 自动执行.
// 去model话的好处在这里有体现, 只需要写好各参数, 就能执行各种网络请求
// TODO: 这种思想可以在写好正常的网络流程后测试一下
