//
//  TBOptionTabModel.h
//  TBStockBusiness
//
//  Created by mashanli on 2023/7/19.
//

#import <TBBaseKit/TBObject.h>
#import <TBBaseKit/TBBaseModel.h>

///期权表头
@interface TBOptionTabHeaderModel : TBBaseModel

@property (nonatomic, copy) NSString *c;//key，用于match
@property (nonatomic, copy) NSString *n;//name，用于展示
@property (nonatomic, assign) BOOL o; //是否支持排序

@property (nonatomic, assign) NSComparisonResult sortType;

- (BOOL)isIgnoreDisplayHeaderItem;

- (NSString *)sortTypeString;

@end


///期权指标
@interface TBOptionTabIndicatorModel : TBBaseModel

@property (nonatomic, copy) NSString *c;//key，用于match
@property (nonatomic, copy) NSString *v;//value
@property (nonatomic, strong) NSNumber *ev; //"ev": -1;额外的属性返回，涨跌幅的涨（1）、跌（-1）和没变（0）

@property (nonatomic, copy) NSString *n;//name，用于展示，非server返回

@end


///期权异动item
@interface TBOptionTabBulkOrderItemModel : TBBaseModel

@property (nonatomic, copy) NSString *code;//没使用
@property (nonatomic, copy) NSString *contract; //"CIFR 20230915 5.0 PUT"
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, copy) NSString *right; //"PUT"
@property (nonatomic, copy) NSString *strike;
@property (nonatomic, copy) NSString *symbol;

@property (nonatomic, strong) NSNumber *optionPrice; //期权成交价
@property (nonatomic, copy) NSString *stockPrice;//正股价
@property (nonatomic, copy) NSString *ivHvRatio;//隐含波动率/历史波动率
@property (nonatomic, copy) NSString *VolOI;//成交量/未平仓量
@property (nonatomic, copy) NSString *changeRate;//涨跌幅
@property (nonatomic, copy) NSString *volume;//成交量 size
@property (nonatomic, copy) NSString *expiry;//如20230818,注意是string,不是时间戳
@property (nonatomic, copy) NSString *tradeDate;//交易日
@property (nonatomic, copy) NSString *tradeTimeStamp;//交易时间
@property (nonatomic, copy) NSString *expireTimeStamp;//距离到期日

@property (nonatomic, copy) NSString *bidAskRatio;//买单/卖单比
@property (nonatomic, copy) NSString *impliedVol;//隐含波动率
@property (nonatomic, strong) NSNumber *tickUp;//买卖方向: "1":买 "2":卖 "3":无
@property (nonatomic, copy) NSArray<NSNumber *> *unusualTag;//异动标签，1.财报单 2.买入 3.卖出

@property (nonatomic, copy) NSArray<TBOptionTabIndicatorModel *> *extValues;

@end


///期权异动
@interface TBOptionTabBulkOrderModel : TBBaseModel

@property (nonatomic, strong) NSNumber *page;
@property (nonatomic, strong) NSNumber *totalPage;
@property (nonatomic, strong) NSNumber *totalCount;
@property (nonatomic, strong) NSNumber *pageSize;

@property (nonatomic, copy) NSString *latestTime;
@property (nonatomic, copy) NSString *marketStatus;

@property (nonatomic, copy) NSArray<TBOptionTabHeaderModel *> *headers;
@property (nonatomic, copy) NSArray<TBOptionTabBulkOrderItemModel *> *results;

@end

@interface TBOptionRankTypeModel : TBBaseModel

@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) NSNumber *rankID;

@end


@interface TBOptionTabBulkOrderFilterItemModel : TBBaseModel

@property (nonatomic, copy) NSString *n;//name
@property (nonatomic, copy) NSString *v; //传参值（用于SINGLE）
@property (nonatomic, copy) NSNumber *min; //传参值（用于RANGE）
@property (nonatomic, copy) NSNumber *max; //传参值（用于RANGE）
//非server返回
@property (nonatomic, assign) BOOL isSelected;//选中并生效（用于指示是否最终确定选中了该指标）
@property (nonatomic, assign) BOOL isHighlight;//选中（用于指示cell是否高亮）

@end

///期权异动filter
@interface TBOptionTabBulkOrderFilterModel : TBBaseModel

@property (nonatomic, copy) NSString *c;//指标唯一编号
@property (nonatomic, copy) NSString *n;//指标名称
@property (nonatomic, copy) NSString *t;//筛选类型，multi：多选 single：单选 range：范围 boolean:布尔
@property (nonatomic, copy) NSString *st; //展示类型，search：搜索
@property (nonatomic, assign) BOOL sd; //是否默认展示筛选项
@property (nonatomic, copy) NSArray<TBOptionTabBulkOrderFilterItemModel *> *vs;

@end


//榜单
@interface TBOptionTabRankModel : TBBaseModel

@property (nonatomic, strong) NSNumber *page;
@property (nonatomic, strong) NSNumber *totalPage;
@property (nonatomic, strong) NSNumber *totalCount;
@property (nonatomic, strong) NSNumber *pageSize;

@property (nonatomic, copy) NSArray<TBOptionRankTypeModel *> *rankings;
@property (nonatomic, copy) NSArray<TBOptionTabHeaderModel *> *headers;
@property (nonatomic, copy) NSArray<TBOptionTabBulkOrderItemModel *> *results;

@property (nonatomic, strong) TBOptionRankTypeModel *selectedRankType;

@end
