//
//  TBWatchListDisplayItem.h
//  Stock
//
//  Created by yangfan on 2018/8/23.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBObject.h>

typedef enum : NSInteger
{
    TBWatchListItemSortTypeNone = 0,
    TBWatchListItemSortTypeDes,     //降序
    TBWatchListItemSortTypeInc,     //升序
    
}TBWatchListItemSortType;


typedef NS_ENUM(NSUInteger) {
    TBWatchListDisplayItemTypePrice = 0,     //显示价格
    TBWatchListDisplayItemTypeChangeRate,//显示涨跌幅
    TBWatchListDisplayItemTypeChangeAmount,//涨跌额
    TBWatchListDisplayItemTypeYearToDateChangeRate,//年初至今涨跌幅
    TBWatchListDisplayItemType5DayChangeRate,//5日涨幅
    TBWatchListDisplayItemType20DayChangeRate,//20日涨幅
    TBWatchListDisplayItemTypeCommittee,     //委比
    TBWatchListDisplayItemTypeVolumeRatio,   //量比
    TBWatchListDisplayItemTypeTurnoverRate,  //换手率
    TBWatchListDisplayItemTypeAmplitude,    //振幅
    TBWatchListDisplayItemTypeVolume,       //成交量
    TBWatchListDisplayItemTypeAmount,       //成交额
    TBWatchListDisplayItemTypeShares,  //总股本
    TBWatchListDisplayItemTypeFloatShares,//流通股本
    TBWatchListDisplayItemTypeMarketValue,  //市值
    TBWatchListDisplayItemTypeFloatMarketValue,    //流通市值
    
    TBWatchListDisplayItemTypePERate,      //市盈率
    TBWatchListDisplayItemTypePBRate,       //市净率
    TBWatchListDisplayItemTypeEPS,          //每股收益
    TBWatchListDisplayItemTypeDividendRate, //股息率
    TBWatchListDisplayItemTypeHandNow,      //现手
    TBWatchListDisplayItemTypeCodeName,     //名称|Code
    TBWatchListDisplayItemTypeROA,          //roa
    TBWatchListDisplayItemTypeROE,          //roe
    
    TBWatchListDisplayItemTypeRealizedPnl,  //已实现盈亏
    TBWatchListDisplayItemTypeUnrealizedPnl,//未实现盈亏
    TBWatchListDisplayItemTypeTotalPnl,     //总盈亏
    TBWatchListDisplayItemTypeAverageCost,     //持仓成本
    TBWatchListDisplayItemTypeFilledCount,     //交易次数
    TBWatchListDisplayItemTypeHoldingDays,     //持仓天数
    TBWatchListDisplayItemTypeCurrency,        //币种
    TBWatchListDisplayItemTypeRiReturn1Yr,     //1年收益率
    TBWatchListDisplayItemTypeRiReturn2Yr,     //2年收益率
    TBWatchListDisplayItemTypeRiReturn3Yr,     //3年收益率
    TBWatchListDisplayItemTypeRiReturn5Yr,     //5年收益率
    TBWatchListDisplayItemTypeDivideRate,      //股息率
    TBWatchListDisplayItemTypeOperation,       //操作
    TBWatchListDisplayItemTypeRiPrice3Months,  //3月股价涨跌幅
    TBWatchListDisplayItemTypeRiPrice6Months,  //6月股价涨跌幅
    TBWatchListDisplayItemTypeRiPrice52Weeks,  //52周股价涨跌幅
    TBWatchListDisplayItemTypeIV,
    TBWatchListDisplayItemTypeIVPercent,
    TBWatchListDisplayItemTypeName = 999,     //名称代码
}TBWatchListDisplayItemType;

typedef NS_ENUM(NSInteger, TBWatchListSortType){
    
    TBWatchListSortTypeNormal           = 0,
    TBWatchListSortTypePriceDes         = 1,
    TBWatchListSortTypePriceInc         = 2,
    TBWatchListSortTypeChangeRateDes    = 3,  //涨跌幅
    TBWatchListSortTypeChangeRateInc    = 4,
    
    TBWatchListSortTypeChangeAmountDes,  //涨跌额
    TBWatchListSortTypeChangeAmountInc,
    TBWatchListSortTypeTurnoverRateDes,  //换手率
    TBWatchListSortTypeTurnoverRateInc,  //换手率
    TBWatchListSortTypePERateDes,      //市盈率
    TBWatchListSortTypePERateInc,      //市盈率
    TBWatchListSortTypePBRateDes,       //市净率
    TBWatchListSortTypePBRateInc,       //市净率
    TBWatchListSortTypeAmplitudeDes,    //振幅
    TBWatchListSortTypeAmplitudeInc,    //振幅
    TBWatchListSortTypeVolumeDes,       //成交量降
    TBWatchListSortTypeVolumeInc,       //成交量升
    TBWatchListSortTypeAmountDes,       //成交额降
    TBWatchListSortTypeAmountInc,       //成交额升
    TBWatchListSortTypeMarketValueDes,  //总市值
    TBWatchListSortTypeMarketValueInc,  //总市值
    
    TBWatchListSortTypeHandNowDes,      //现手
    TBWatchListSortTypeHandNowInc,      //现手
    TBWatchListSortTypeVolumeRatioDes,   //量比
    TBWatchListSortTypeVolumeRatioInc,   //量比
    TBWatchListSortTypeCommitteeDes,     //委比
    TBWatchListSortTypeCommitteeInc,     //委比
    TBWatchListSortTypeFloatMarketValueDes,     //流通市值
    TBWatchListSortTypeFloatMarketValueInc,     //流通市值
    TBWatchListSortTypeMarketShareholdingRatioDesc,//持股比
    TBWatchListSortTypeMarketShareholdingRatioInc, //持股比
    TBWatchListSortTypeMarketShareholdingDesc,     //持股量
    TBWatchListSortTypeMarketShareholdingInc,      //持股量
    TBWatchListSortTypeMarketDayChangeDesc,        //较上日变化
    TBWatchListSortTypeMarketDayChangeInc,         //较上日变化
    TBWatchListSortTypeMarketNetflowDesc,          //净流入
    TBWatchListSortTypeMarketNetflowInc,           //净流入
    TBWatchListSortTypeEpsDesc,                    //每股收益
    TBWatchListSortTypeEpsDescInc,                 //每股收益
    TBWatchListSortTypeROADesc,                    //roa
    TBWatchListSortTypeROAInc,                     //roa
    TBWatchListSortTypeROEDesc,                    //roe
    TBWatchListSortTypeROEInc,                     //roe
    
    TBWatchListSortTypeYearToDateChangeRateDesc,//年初至今涨跌幅
    TBWatchListSortTypeYearToDateChangeRateInc,//年初至今涨跌幅
    TBWatchListSortType5DayChangeRateDesc, //5日涨幅
    TBWatchListSortType5DayChangeRateInc,  //5日涨幅
    TBWatchListSortType20DayChangeRateDesc,//20涨幅
    TBWatchListSortType20DayChangeRateInc,//20日涨幅
    TBWatchListSortTypeSharesDesc,  //总股本
    TBWatchListSortTypeSharesInc,  //总股本
    TBWatchListSortTypeFloatSharesDesc,//流通股本
    TBWatchListSortTypeFloatSharesInc,//流通股本
    TBWatchListSortTypeDividendRateDesc,//股息率
    TBWatchListSortTypeDividendRateInc,//股息率

    TBWatchListSortTypeVolumeChangeRateDesc,
    TBWatchListSortTypeVolumeChangeRateInc,
    
    TBWatchListSortTypeNameDes, //名称代码
    TBWatchListSortTypeNameInc, //名称代码
    
    TBWatchListSortTypeIVPercentDesc,
    TBWatchListSortTypeIVPercentInc,
    
    TBWatchListSortTypeIVDesc,
    TBWatchListSortTypeIVInc,
};

@interface TBWatchListDisplayItem : TBObject

@property (nonatomic, assign) BOOL selected;         //是否选中
@property (nonatomic, assign) BOOL useNameDirectly; //是否直接使用name

@property (nonatomic, copy) NSString                *name;
@property (nonatomic, copy) NSString                *keyName;

@property (nonatomic, assign) TBWatchListDisplayItemType itemType;

@end
