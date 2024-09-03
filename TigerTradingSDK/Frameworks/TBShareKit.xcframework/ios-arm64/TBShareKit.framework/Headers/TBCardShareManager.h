//
//  TBCardShareManager.h
//  TBShareKit
//
//  Created by dulijun on 2023/4/13.
//

#import <Foundation/Foundation.h>
#import "TBCardShareModel.h"
#import <TBToolsKit/TBSensorsAnalyticsData.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCardShareManager : NSObject

+ (void)shareWithItems:(NSArray <TBCardShareModel*>*)items;

// 因为此manager有持仓、订单分享、今日盈亏共用，所以埋点参数需要从外部传递
+ (void)shareWithItems:(NSArray <TBCardShareModel*>*)items saData:(nullable TBSensorsAnalyticsData *)saData;

@end

NS_ASSUME_NONNULL_END
