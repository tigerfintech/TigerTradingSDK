//
//  TBWatchListDisplayItemManager.h
//  Stock
//
//  Created by yangfan on 2018/8/23.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBObject.h>
#import <TBToolsKit/TBWatchListDisplayItem.h>
@class TBWatchListDisplayItem;
@class TBWatchListSortItem;
@class TBWatchlistConfigModel;
//#import "TBWatchListSectionHeaderItem.h"
//#import "TBWatchListSectionHeaderItemCell.h"

typedef NS_ENUM(NSUInteger, TBWatchlistMode) {
    TBWatchlistModeClassical = 0,
    TBWatchlistModeA,
    TBWatchlistModeB
};

@interface TBWatchListSortItem : TBObject

@property (nonatomic, strong) TBWatchListDisplayItem  *item;
@property (nonatomic, assign) TBWatchListItemSortType itemSortType;    //排序类型，仅仅指升序还是降序
@property (nonatomic, assign) TBWatchListSortType     sortType;        //全局排序

@end

@interface TBWatchListDisplayItemManager : TBObject

+ (TBWatchListDisplayItem *)nameItem;            //名称代码
+ (TBWatchListDisplayItem *)priceItem;           //价格
+ (TBWatchListDisplayItem *)changeRateItem;      //涨跌幅
+ (TBWatchListDisplayItem *)changeAmountItem;    //涨跌额
+ (TBWatchListDisplayItem *)yearToDateChangeRate;//年初至今涨跌幅
+ (TBWatchListDisplayItem *)day5ChangeRate;      //5日涨幅
+ (TBWatchListDisplayItem *)day20ChangeRate;     //20日涨幅
+ (TBWatchListDisplayItem *)committeeItem;      //委比
+ (TBWatchListDisplayItem *)volumeRatioItem;    //量比
+ (TBWatchListDisplayItem *)turnoverRateItem;   //换手率
+ (TBWatchListDisplayItem *)amplitudeItem;      //振幅
+ (TBWatchListDisplayItem *)volumeItem;         //成交量
+ (TBWatchListDisplayItem *)amountItem;         //成交额
+ (TBWatchListDisplayItem *)sharesItem;         //总股本
+ (TBWatchListDisplayItem *)floatSharesItem;    //流通股本
+ (TBWatchListDisplayItem *)marketValueItem;      //总市值项
+ (TBWatchListDisplayItem *)floatMarketValueItem;    //流通市值

+ (TBWatchListDisplayItem *)PERateItem;        //市盈率
+ (TBWatchListDisplayItem *)PBRateItem;        //市净率
+ (TBWatchListDisplayItem *)epsItem;            //每股收益
+ (TBWatchListDisplayItem *)dividendRateItem;   //股息率
+ (TBWatchListDisplayItem *)handNowItem;        //现手

+ (TBWatchListDisplayItem *)roaItem;            //roa
+ (TBWatchListDisplayItem *)roeItem;            //roe

+ (TBWatchListDisplayItem *)ivItem;
+ (TBWatchListDisplayItem *)ivPercentItem;      


+ (instancetype)manager;

//重置所有选项
- (void)resetAllItems;
//保存当前选项
- (void)saveAllItems;
//在当前显示模式下（横屏或者竖屏），是否包含详细的除价格,涨跌幅,涨跌额,成交量以外的数据项
- (BOOL)containDetailItem;
//切换语言后刷新语言
- (void)changeLanguage;

@property (nonatomic, copy) NSArray <TBWatchListDisplayItem *> * allItems;            //所有可以被显示的项（包括已选择和未选择项）
@property (nonatomic, copy) NSArray <TBWatchListDisplayItem *> * selectedItems;       //已经被选择需要显示的项
@property (nonatomic, copy) NSArray <TBWatchListDisplayItem *> * portraitItems;       //竖屏下显示的项
@property (class, nonatomic, strong) TBWatchListSortItem         * sortItem;            //已经排序的类型
@property (nonatomic, assign) BOOL isDefaultItems; //是否是默认数据项

- (void)saveWatchlistMode:(TBWatchlistMode)mode;
- (TBWatchlistMode)watchlistMode;
- (BOOL)isModeB;
- (void)uploadWatchlistConfig;
- (TBWatchlistConfigModel *)clickSwitchClumnModel;
- (TBWatchlistConfigModel *)highlightModel;
- (TBWatchlistConfigModel *)modeConfigModel;
- (void)saveHighlight:(BOOL)isOn;
- (void)saveSwitch:(BOOL)isOn;

@end

#define TBWatchListDisplayKit [TBWatchListDisplayItemManager manager]
