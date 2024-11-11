//
//  TBOptionIndicator.h
//  Stock
//
//  Created by 王灵博 on 2021/4/2.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
@import ChartKLineView;

NS_ASSUME_NONNULL_BEGIN

static NSString *USER_DEFAULT_KEY_OPTION_IV_SELECT                                      = @"optionIVSelect";
static NSString *USER_DEFAULT_KEY_OPTION_OPENINT_SELECT                                      = @"optionOpenIntSelect";

@interface TBOptionIndicatorModel : NSObject

@property (nonatomic, assign) TBKLineChartYAxisType chartType;
@property (nonatomic, assign) BOOL select;
@property (nonatomic, assign) BOOL zoomScale;
@property (nonatomic, copy) NSString *title;

@end
@interface TBOptionIndicator : NSObject

+ (NSArray *)getIndicatorList;

+ (void)saveOptionWithType:(TBKLineChartYAxisType)chartType select:(BOOL)select;

@end

NS_ASSUME_NONNULL_END
