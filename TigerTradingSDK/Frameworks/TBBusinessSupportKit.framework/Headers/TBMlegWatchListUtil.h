//
//  TBMlegWatchListUtil.h
//  TBBusinessSupportKit
//
//  Created by mashanli on 2024/6/13.
//  Copyright © 2024年 com.tigerbrokers. All rights reserved.
//

#import <TBBusinessSupportKit/TBMlegWatchListProtocol.h>

@interface TBMlegWatchListUtil : NSObject

//组合期权获取自选symbol，基于实现了TBMlegWatchListProtocol协议的model数组
+ (NSString *)mlegWatchListSymbol:(NSArray<id<TBMlegWatchListProtocol> > *)models
                           market:(NSString *)market;

@end
