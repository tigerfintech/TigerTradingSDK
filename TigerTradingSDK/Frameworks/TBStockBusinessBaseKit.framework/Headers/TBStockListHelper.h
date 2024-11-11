//
//  TBStockListHelper.h
//  Stock
//
//  Created by zhenglanchun on 2021/5/21.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "TBWatchListSectionHeaderItem.h"
#import "TBStockListHeaderView.h"
#import <TBToolsKit/TBWatchListDisplayItem.h>

#define TAG_MARKET_VIEW        110110110
#define TAG_PRICE_VIEW         101010111
#define TAG_CHANGERATE_VIEW    111010110
#define TAG_CHANGESCREEN_VIEW  111010111
#define TAG_SKIPGROUPMANAGE_VIEW  111010222
#define TAG_LANDSCAPE_VIEW     111010112
#define TAG_CHANGETHUMBNAIL_VIEW     111010122

typedef NS_ENUM(NSInteger, TBWatchListSmartSortingType) {
    TBWatchListSmartSortingTypeWeekDayTime      = 0,
    TBWatchListSmartSortingTypeWeekNightTime    = 1,
    TBWatchListSmartSortingTypeWeekendTime      = 2
};

typedef NS_ENUM(NSInteger, TBWatchListMarketType) {
    TBWatchListMarketTypeNormal         = 0,
    TBWatchListMarketTypeUSMarket       = 1,
    TBWatchListMarketTypeCNMarket       = 2,
    TBWatchListMarketTypeHKMarket       = 3,
    TBWatchListMarketTypeOPTMarket      = 4,
    TBWatchListMarketTypeFutures        = 5,
    TBWatchListMarketTypePosition       = 6,
    TBWatchListMarketTypeOther          = 7,
    TBWatchListMarketTypeUKMarket       = 8,
    TBWatchListMarketTypeSIMarket       = 9,
    TBWatchListMarketTypeAUMarket       = 10,
    TBWatchListMarketTypeNZMarket       = 11,
    TBWatchListMarketTypeFund           = 12,
    TBWatchListMarketTypeOPTHKMarket      = 13,
    TBWatchListMarketTypeDigitalCurrency       = 14,
    TBWatchListMarketTypeForex          = 15,
    TBWatchListMarketTypeBond           = 16,
    TBWatchListMarketTypeUSStockAndOptionMarket = 10000,
    TBWatchListMarketTypeHKStockAndOptionMarket = 10001,
};


NS_ASSUME_NONNULL_BEGIN

@interface TBStockListHelper : NSObject

+ (TBStockListHeaderSortType)convertWatchListSortType: (TBWatchListSortType) watchListSortType;

@end

NS_ASSUME_NONNULL_END
