//
//  TBOptionAnalysisChartTableViewCell.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/11/30.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
#import "TBCorporateActionsModel.h"

/*
 图表类型
 */
typedef NS_ENUM(NSUInteger, TBOptionAnalysisChartType) {
    TBOptionAnalysisChartTypeCallPutRatio,           // call put ratio
    TBOptionAnalysisChartTypePutCallRatio,           // put call ratio
    TBOptionAnalysisChartTypeVolumeAnalysis,         // 成交统计
    TBOptionAnalysisChartTypeImpliedVol,             // 隐含波动率
};
NS_ASSUME_NONNULL_BEGIN
@class TBOptionAnalysisModel;
@interface TBOptionAnalysisChartTableViewCell : TBTableViewCell

@end

@interface TBOptionAnalysisChartTableViewCellItem : TBTableViewCellItem

/// 将原始值传过来，根据type做处理
@property (nonatomic, strong) TBOptionAnalysisModel *analysisModel;

@property (nonatomic, assign) TBOptionAnalysisChartType chartType;

@property (nonatomic, copy) NSArray<TBCorporateActionsItemModel> *corporateActions;

@end

NS_ASSUME_NONNULL_END
