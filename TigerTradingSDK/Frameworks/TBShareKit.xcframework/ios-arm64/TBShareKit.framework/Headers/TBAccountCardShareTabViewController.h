//
//  TBAccountCardShareTabViewController.h
//  TBShareKit
//
//  Created by dulijun on 2024/4/19.
//

#import "TBBaseCardShareTabViewController.h"
#import <TBToolsKit/TBSensorsAnalyticsData.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBAccountCardShareTabViewController : TBBaseCardShareTabViewController

@property (nonatomic, strong) TBSensorsAnalyticsData *saData;

@end

NS_ASSUME_NONNULL_END
