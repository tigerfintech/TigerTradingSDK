//
//  TBStockDetailCommonModel.h
//  Stock
//
//  Created by luopengfei on 2018/8/9.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>
#import <TBBusinessSupportKit/TBStockDetailBaseModel.h>
@class TBStockDetailGreyMaketModel;
@class TBHKOpenIPOModel;
@class TBHKOpenIPOModel,TBStockDetailGreyMaketModel;

/**
 个股详情页 A/H股
 */
@interface TBStockDetailBriefModel : TBStockDetailBaseModel
@property (nonatomic, strong) NSNumber<Optional> *timestamp;
@property (nonatomic, copy) NSString<Optional> *premium;
@end

/**
 个股详情页距下一个市场状态时间
 */
@interface TBStockDetailNextMarketStatusModel : JSONModel
@property (nonatomic, copy) NSString<Optional> *tag;
@property (nonatomic, strong) NSNumber<Optional> *beginTime;
@end

@interface TBAStockAfterMarketModel : JSONModel

@property (nonatomic, strong) NSNumber *amount;
@property (nonatomic, strong) NSNumber *volume;
@property (nonatomic, strong) NSNumber *close;
@property (nonatomic, strong) NSNumber *buyVolume;
@property (nonatomic, strong) NSNumber *sellVolume;
@property (nonatomic, assign) NSTimeInterval time;

@property (nonatomic, strong) NSNumber *preClose;

@end

/**
 个股详情页公告通知
 目前只有美港股有此字段
 */
@interface TBStockDetailInfoNoticeModel : JSONModel

@property (nonatomic, copy) NSString<Optional> *title;
@property (nonatomic, copy) NSString<Optional> *content;
@property (nonatomic, strong) NSNumber<Optional> *type;

@end


@interface TBStockDetailIPODetailModel : JSONModel

@property (nonatomic, copy) NSString *name; // 标的名称
@property (nonatomic, copy) NSString *symbol; // 标的symbol

@property (nonatomic, copy) NSString *exchange; // 交易所
@property (nonatomic, copy) NSString *listingDate; // 上市日期 yyyy-MM-dd
@property (nonatomic, strong) NSNumber *listingDateTimestamp; // 上市日期 yyyy-MM-dd
@property (nonatomic, strong) NSNumber *sharesOutstanding; // 总股本

/// 813新增：预计市值下限（美股）
@property (nonatomic, strong) NSNumber *minForecastMarketValue;
/// 813新增：预计市值上限（美股）
@property (nonatomic, strong) NSNumber *maxForecastMarketValue;

@property (nonatomic, strong) NSNumber *sharesFloat; // 流通股本
@property (nonatomic, strong) NSNumber *offerAmount; // 发行股本
@property (nonatomic, copy) NSString *market; // 市场
@property (nonatomic, copy) NSString *priceRange; // 发行价格区间
@property (nonatomic, strong) NSNumber *listedPrice; // 发行价格

@property (nonatomic, copy) NSString *marketCapRange; // 市值区间


@property (nonatomic, copy, readonly) NSString *marketRangeStr;

@property (nonatomic, copy) NSString *openProspectusDate; // 公开招股日期,yyyy-MM-dd
@property (nonatomic, strong) NSNumber *openProspectusDateTimestamp; // 公开招股日期,yyyy-MM-dd
@property (nonatomic, copy) NSString *openProspectusUrl; // 公开招股书链接
@property (nonatomic, copy) NSString *openProspectusImageUrl; // 招股阶段运营图片链接
@property (nonatomic, copy) NSString *openProspectusOPUrl; // 招股阶段运营地址链接
@property (nonatomic, copy) NSString *purchaseBeginDate; // 申购开始日期,yyyy-MM-dd
@property (nonatomic, strong) NSNumber *purchaseBeginDateTimestamp; // 申购开始日期,yyyy-MM-dd
@property (nonatomic, copy) NSString *purchaseEndDate; // 申购截止日期, yyyy-MM-dd
@property (nonatomic, strong) NSNumber *purchaseEndDateTimestamp; // 申购截止日期, yyyy-MM-dd
@property (nonatomic, copy) NSString *purchaseImageUrl; // 申购图片链接
@property (nonatomic, copy) NSString *purchaseUrl; // 申购连接
@property (nonatomic, copy) NSString *winningDate; // 中签日期
@property (nonatomic, strong) NSNumber *winningDateTimestamp; // 中签日期
@property (nonatomic, copy) NSString *winningRatioDesc; // 中签率描述
@property (nonatomic, copy) NSString *winningImageUrl; // 中签图片链接
@property (nonatomic, copy) NSString *winningUrl; // 中签链接
@property (nonatomic, copy) NSString *listingImageUrl; // 上市图片连接
@property (nonatomic, copy) NSString *listingUrl; // 上市链接
@property (nonatomic, copy) NSString *currency; // 发行货币
@property (nonatomic, strong) NSNumber *minPurchaseQuantity; // 最小申购数量
@property (nonatomic, strong) NSNumber *leverageRatio; // 打新杠杆比例

@property (nonatomic, strong) NSNumber *subscribed; //认购倍数
@property (nonatomic, strong) NSNumber *investorPercent; // 基石投资者比例
@property (nonatomic, copy) NSString *winningRate; //中签率
@property (nonatomic, strong) NSNumber *totalNumber; //申购人数

@property (nonatomic, strong) NSNumber *peRate; // 市盈率
@property (nonatomic, strong) NSNumber *minimumCapital; // 入场费
@property (nonatomic, strong) NSNumber *lotSize; //每手股数
@property (nonatomic, assign) BOOL overAllotment; //是否有绿鞋
@property (nonatomic, copy) NSString *industryName; // 所属行业
@property (nonatomic, copy) NSString *industryId; // 行业ID
@property (nonatomic, copy) NSString *business; // 主营业务

/// 暗盘交易日期 yyyy-MM-dd
@property (nonatomic, copy) NSString *grayDate;
@property (nonatomic, strong) NSNumber *greyDateTimestamp;
@property (nonatomic, strong) NSNumber *grayPrice; // 暗盘价格
@property (nonatomic, strong) NSNumber *grayChgRate; // 暗盘涨跌幅
@property (nonatomic, strong) TBStockDetailGreyMaketModel *greyMarketDetail;

/// 用途
@property (nonatomic, copy) NSString *use;


@property (nonatomic, strong) TBHKOpenIPOModel *ipoModel;

@end

