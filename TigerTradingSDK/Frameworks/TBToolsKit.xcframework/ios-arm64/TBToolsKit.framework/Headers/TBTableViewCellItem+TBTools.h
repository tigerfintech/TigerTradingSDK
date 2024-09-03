//
//  TBTableViewCellItem+TBTools.h
//  TBToolsKit
//
//  Created by dulijun on 2024/5/21.
//

#import <TBUIKit/TBUIKit.h>
#import <TBToolsKit/TBSensorsAnalyticsData.h>
#import <TBUIKit/TBTableViewCellItem.h>

@interface TBTableViewCellItem (TBTools)

// 配置cell曝光时上报的数据
- (void)configCellImpressionSAData:(void(^)(TBSAExposureData *data))block;
// 配置cell click时上报的数据
- (void)configCellClickedSAData:(void(^)(TBSensorsAnalyticsData *data))block;


@property (nonatomic, strong) TBSensorsAnalyticsData *impressionSAData; // 曝光时上报的数据
@property (nonatomic, strong) TBSensorsAnalyticsData *clickedSAData;  // click时上报的数据

@end
