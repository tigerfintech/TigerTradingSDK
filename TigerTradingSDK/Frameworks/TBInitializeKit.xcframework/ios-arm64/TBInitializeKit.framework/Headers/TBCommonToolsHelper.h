//
//  TBCommonToolsHelper.h
//  Stock
//
//  Created by chenxin on 2020/10/28.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

NS_ASSUME_NONNULL_BEGIN

/*
 独立组件有些功能无法自己实现，通过协议交给主工程实现
 */
@interface TBCommonToolsHelper : NSObject

DECLARE_SHARED_INSTANCE(TBCommonToolsHelper)

+ (void)configure;

@end

NS_ASSUME_NONNULL_END
