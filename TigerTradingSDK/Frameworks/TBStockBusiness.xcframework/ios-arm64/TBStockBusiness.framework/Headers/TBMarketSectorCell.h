//
//  TBMarketSectorCell.h
//  Stock
//
//  Created by yangfan on 16/10/14.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBUIKit/TBTableViewCell.h>

/// 行情-股票 各市场页, 大卡片collection view结构的枚举类型
typedef enum : NSUInteger
{
    Market_Sector_Indices,
    Market_Sector_Hot,
    Market_Sector_ETF,
    Market_Sector_Today,
    Market_Sector_Important_Indices, // 重要指数
    Market_Sector_HeatMap,
    Market_Sector_HK_Index_ETF, // 港股指数ETF

} MarketSectorType;

@class TBMarketSectorCellItem;

@protocol TBMarketSectorCellItemDelegate <NSObject>

- (void)sectorCellItem:(TBMarketSectorCellItem *)cell sectorType:(MarketSectorType)type didTappedItemAtIndex:(NSUInteger)index;

@end


@interface TBMarketSectorCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString                * market;         //股指类型，区分美股或者A股，港股
@property (nonatomic, assign) MarketSectorType          sectorType;
@property (nonatomic, copy) NSArray                 * itemArray;
@property (nonatomic, assign) BOOL                      isFolded;
@property (nonatomic, assign) BOOL                      chartEnable;

@property (nonatomic, weak) id<TBMarketSectorCellItemDelegate>  delegate;


@property (nonatomic, copy) NSString                * sector;

@end


@interface TBMarketSectorCell : TBTableViewCell

@property (nonatomic, copy) NSString                * market;         //股指类型，区分美股或者A股，港股
@property (nonatomic, assign) MarketSectorType          sectorType;
@property (nonatomic, copy) NSArray                 * itemArray;
@property (nonatomic, assign) BOOL                      isFolded;
@property (nonatomic, assign) BOOL                      chartEnable;

@property (nonatomic, weak) id<TBMarketSectorCellItemDelegate>  sectorDelegate;

+ (CGFloat)calculateHeight:(MarketSectorType)sectorType chartEnable:(BOOL)enbale itemArray:(NSArray *)itemArray isFolded:(BOOL)isFolded market:(NSString *)market;

@end
