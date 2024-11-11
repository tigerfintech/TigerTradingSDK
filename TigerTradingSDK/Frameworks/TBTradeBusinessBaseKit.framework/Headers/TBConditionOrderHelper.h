//
//  TBConditionOrderHelper.h
//  TBTradeBusiness
//
//  Created by 王昌阳 on 2022/3/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBConditionOrderHelper : NSObject

+ (NSString *)conditionTypeDesFromType:(NSString *)type;

+ (NSString *)conditionDesFromConditionType:(NSString *)type operatorStr:(NSString *)operatorStr;

/// 条件订单符合：≤，≥，≠，=，<，>
/// @param type <#type description#>
/// @param operatorStr <#operatorStr description#>
+ (NSString *)conditionDesSymbolFromConditionType:(NSString *)type operatorStr:(NSString *)operatorStr;

@end

NS_ASSUME_NONNULL_END
