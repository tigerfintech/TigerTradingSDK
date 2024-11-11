//
//  TBOptionTabBulkOrderUtils.h
//  Stock
//
//  Created by mashanli on 2023/8/20.
//  Copyright © 2023 com.tigerbrokers. All rights reserved.
//

@class TBOptionTabHeaderModel;
@class TBOptionTabIndicatorModel;
@class TBOptionUnusualDetailModel;
#import <Foundation/Foundation.h>
#import "TBOptionAnalysisHeader.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionTabBulkOrderUtils : NSObject

+ (NSArray<TBOptionTabIndicatorModel *> *)generateIndicators:(NSArray<TBOptionTabHeaderModel *> *)headers
                                                    inValues:(NSArray<TBOptionTabIndicatorModel *> *)values;


+ (NSArray<TBOptionTabIndicatorModel *> *)generateIndicatorsWithModel:(TBOptionUnusualDetailModel *)model
                                                           changeType:(TBOptionChangeType)changeType
                                                               market:(NSString *)market
                                                               secType:(NSString *)secType;

@end

NS_ASSUME_NONNULL_END
