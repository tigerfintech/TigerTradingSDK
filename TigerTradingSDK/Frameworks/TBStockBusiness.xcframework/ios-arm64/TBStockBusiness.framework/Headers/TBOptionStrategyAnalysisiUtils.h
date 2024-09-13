//
//  TBOptionStrategyAnalysisiUtils.h
//  AFNetworking
//
//  Created by zlc on 2024/5/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TBOptionInfoDetailItem;
@class TBOptionStrategyBuilderStrategyOptionModel;

@interface TBOptionStrategyAnalysisiUtils : NSObject

+ (BOOL)isSameWithOptionItem:(TBOptionInfoDetailItem *)optionItem optionModel:(TBOptionStrategyBuilderStrategyOptionModel *)optionModel;

+ (NSString *)uniqKeyWtihOptionItem:(TBOptionInfoDetailItem *)optionItem;

+ (NSString *)uniqKeyWtihStrategyOptionModel:(TBOptionStrategyBuilderStrategyOptionModel *)strategyOptionModel;

@end

NS_ASSUME_NONNULL_END
