//
//  TBTradeActionGenerator.h
//  TBTradeBusiness
//
//  Created by swordzhou on 2021/8/4.
//

#import <Foundation/Foundation.h>
#import <TBUIKit/TTHeader.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBTradeActionGenerator : NSObject

+ (TTURLAction *)tradeAnalysisDetailAction;

+ (TTURLAction *)tradeAnalysisDetailAction:(NSString *)segType;

@end

NS_ASSUME_NONNULL_END
