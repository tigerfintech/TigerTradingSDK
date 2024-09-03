//
//  TBTableViewCell+Exposure.h
//  Stock
//
//  Created by chenxin on 2020/9/15.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "TBTableViewCell.h"
#import "TBViewExposureDataSource.h"
#import "TBViewExposureLogicModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBTableViewCell (Exposure) <TBViewExposureDataSource>

@property (nonatomic, strong, nullable) TBViewExposureLogicModel *viewExposureLogic;///< 曝光统计

// 添加曝光统计方法
- (void)addViewExposureLogic;
+ (void)preload;

@end

NS_ASSUME_NONNULL_END
