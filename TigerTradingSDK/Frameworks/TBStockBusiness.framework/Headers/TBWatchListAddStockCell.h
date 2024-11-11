//
//  TBWatchListAddStockCell.h
//  Pods
//
//  Created by zhenglanchun on 2021/7/15.
//  
//

#import <TBUIKit/TBTableViewCell.h>
@class TBWatchListTableCellItem;
@class TBSearchTableCellItem;
@class TBWatchListParamObject;
#import "TBMarketConditionsUntils.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TBWatchListAddStockCellType) {
    TBWatchListAddStockCellTypeTips,    ///< 左侧只显示一个tipsLabel
    TBWatchListAddStockCellTypeSystem,  ///< 系统分组的添加股票页面，添加按钮是icon
    TBWatchListAddStockCellTypeCustom   ///< 自选分组的添加股票cell, 添加按钮是文字
};

typedef NS_ENUM(NSInteger, TBWatchListAddStockCellAction) {
    TBWatchListAddStockCellActionWatchStock, ///<  添加或者删除股票
    TBWatchListAddStockCellActionDeleteHistory ///< 移除搜索记录
};

@interface TBWatchListAddStockCellItem : TBTableViewCellItem
@property (nonatomic, assign) TBWatchListAddStockCellType cellType;

// MARK: TBWatchListAddStockCellTypeTips
@property (nonatomic, copy) NSString * tips;
@property (nonatomic, assign) BOOL hasRemoveBtn;

// MARK: TBWatchListAddStockCellTypeCustom
@property (nonatomic, strong, readonly) TBWatchListTableCellItem *watchlistItem;

// MARK: TBWatchListAddStockCellTypeSystem
@property (nonatomic, strong, readonly) TBSearchTableCellItem *searchItem;

// MARK: 基础属性
@property (nonatomic, strong) NSNumber *type;   //type: 数据类型 0代表股票，1代表板块，2代表窝轮牛熊证链表，3代表窝轮，4代表牛熊证，5代表期货，6代表OTC， 8代表基金
@property (nonatomic, strong) NSNumber * halted;
@property (nonatomic, copy) NSString * nameCN; // 股票名称
@property (nonatomic, copy) NSString * market; // 市场
@property (nonatomic, copy) NSString * symbol;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, assign) BOOL isInWatchList; // 是否在自选里（当前分组）

// 从自选
- (void)applyForCellItem: (TBWatchListTableCellItem *)cellItem;

// 从搜索记录里更新自己的属性
- (void)applyForSearchCellItem: (TBSearchTableCellItem *)cellItem;

- (TBWatchListParamObject *)convertToWatchListParamObject;

@end

@interface TBWatchListAddStockCell : TBTableViewCell

@end

NS_ASSUME_NONNULL_END
