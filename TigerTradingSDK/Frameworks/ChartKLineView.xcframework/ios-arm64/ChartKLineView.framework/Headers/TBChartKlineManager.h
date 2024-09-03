//
//  TBChartKlineManager.h
//  ChartKLineView
//
//  Created by linbingjie on 2023/2/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBChartKlineManager : NSObject

@property (nonatomic, copy, class) NSArray *indicators;

+ (NSInteger)fetchIndicatorAtIndex:(NSInteger)index key:(NSString *)key;
+ (NSArray *)fetchindicators:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
