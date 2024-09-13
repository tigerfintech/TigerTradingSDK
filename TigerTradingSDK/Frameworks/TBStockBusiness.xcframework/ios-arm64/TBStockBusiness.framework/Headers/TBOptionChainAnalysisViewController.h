//
//  TBOptionChainAnalysisViewController.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/11/30.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBListTableViewController.h>
@class TBOptionExpiryItemModel;
@class TBOptionAnalysisChartTableViewCellItem;
@class TBOptionCallPutRatioHeaderViewItem;
@class TBMarketPackageSectionIndicatorHeaderItem;
@class TBOptionAnalysisModel;
@class TBOptionVolatilityChartCellItem;
@class TBStockBusinessBriefQuoteModel;
@class TBStockDetailCorporationModel;
@class TBOptionChainModel;
@class TBOptionIVInfoView;
#import "TBOptionAnalysisHeader.h"
@class TBOptionExpiryItemModel,TBOptionVolatilityChartCell,TBOptionAnalysisChartTableViewCellItem,TBOptionCallPutRatioHeaderViewItem,TBOptionAnalysisChartTableViewCellItem,TBMarketPackageSectionIndicatorHeaderItem,TBOptionAnalysisModel,TBOptionVolatilityChartCellItem,TBWatchListTableCellItem,TBStockDetailCorporationModel,TBOptionChainModel,TBStockBusinessBriefQuoteModel;
NS_ASSUME_NONNULL_BEGIN
/*
 期权链分析
 */
@interface TBOptionChainAnalysisViewController : TBListTableViewController
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *optionSymbol;
@property (nonatomic, copy) NSString *nameCN;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, strong) TBOptionExpiryItemModel *selectedExpiryDate;
@property (nonatomic, strong) TBOptionExpiryItemModel *currentExpiry;
@property (nonatomic, assign) BOOL isIndex;

@property (nonatomic, strong) TBOptionAnalysisChartTableViewCellItem *callPutRatioCellItem;
@property (nonatomic, strong) TBOptionCallPutRatioHeaderViewItem *callPutHeaderItem;
@property (nonatomic, strong) TBOptionAnalysisChartTableViewCellItem *volAnalysisCellItem;

@property (nonatomic, strong) TBMarketPackageSectionIndicatorHeaderItem *volAnalysisHeaderItem;
@property (nonatomic, strong) NSMutableArray *listMarray;
@property (nonatomic, strong) NSMutableArray *chartMarray;
@property (nonatomic, strong) NSMutableArray *volatilityMarray;
/// <#注释#>
@property (nonatomic, strong) NSMutableArray *volumeAnalysisMArray;
@property (nonatomic, strong) TBOptionAnalysisModel *response;
@property (nonatomic, strong) TBOptionVolatilityChartCellItem *volatilityCellItem;
@property (nonatomic, strong) TBStockBusinessBriefQuoteModel  *stockInfoItem;
@property (nonatomic, strong) TBStockDetailCorporationModel *corporationModel;
@property (nonatomic, strong) TBOptionChainModel *optionChainModel;
@property (nonatomic, assign) TBOptionChangeType changeType;
@property (nonatomic, strong) NSMutableDictionary *openStatusDic;//存储展开和收起的状态
@property (nonatomic, strong) TBOptionIVInfoView *optionIVView;
@property (nonatomic, assign) BOOL isIndexOption;
@property (nonatomic, assign) BOOL isFirt;//是否为初始化

@property (nonatomic, copy) NSString *ratioSetting;

@property (nonatomic, assign, readonly) BOOL showExplain; // 是否显示指标说明

@end

NS_ASSUME_NONNULL_END
