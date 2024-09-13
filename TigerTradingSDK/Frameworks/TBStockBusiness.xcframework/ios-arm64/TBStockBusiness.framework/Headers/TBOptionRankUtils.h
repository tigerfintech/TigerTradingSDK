//
//  TBOptionRankUtils.h
//  Stock
//
//  Created by chenxin on 2021/8/20.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionRankUtils : NSObject

//存储期权异动榜-是否只展示自选股票的异动
+ (void)saveOptionOptionalSelect:(BOOL)select;
+ (BOOL)getOptionOptionalSelect;

@end

NS_ASSUME_NONNULL_END
