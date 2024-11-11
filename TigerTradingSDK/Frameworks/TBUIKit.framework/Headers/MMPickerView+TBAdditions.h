//
//  MMPickerView+TBAdditions.h
//  Stock
//
//  Created by chenxin on 2018/4/19.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBThirdParty/MMPickerView.h>

@interface MMPickerView (TBAdditions)

+ (NSDictionary *)tb_optionsWithSelectedObjects:(NSArray *)selectedObjects;

// 用于设置开户过程中MMPickerView的options
+ (NSDictionary *)tb_openAccountOptionsWithSelectedObjects:(NSArray *)selectedObjects;

@end
