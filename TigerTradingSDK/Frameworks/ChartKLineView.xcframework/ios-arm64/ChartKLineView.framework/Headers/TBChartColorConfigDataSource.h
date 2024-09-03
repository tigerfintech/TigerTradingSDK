//
//  TBChartColorConfigDataSource.h
//  TBMixedChartView
//
//  Created by luopengfei on 2018/10/24.
//  Copyright © 2018年 luopengfei. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBChartColorConfigDataSource <NSObject>

+ (UIColor *)commonTextColor;

@end

NS_ASSUME_NONNULL_END
