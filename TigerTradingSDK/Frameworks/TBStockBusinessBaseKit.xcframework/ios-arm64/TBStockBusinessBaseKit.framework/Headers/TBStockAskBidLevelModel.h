//
//  TBStockAskBidLevelModel.h
//  Stock
//
//  Created by 骆鹏飞 on 2019/5/17.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>
/*
 股票买卖档位 model
 */
NS_ASSUME_NONNULL_BEGIN

@protocol TBStockAskBidLevelItemModel <NSObject>
@end
@interface TBStockAskBidLevelItemModel : JSONModel
@property (nonatomic, assign) NSInteger count;
@property (nonatomic, assign) double volume;
@property (nonatomic, copy) NSString *displayVolume;
@property (nonatomic, strong) NSNumber *price;

@property (nonatomic, assign) NSInteger level;
@property (nonatomic, copy) NSString *displayTitle;

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *secType;

@property (nonatomic, copy) NSString *displayPrice;

@property (nonatomic, strong) NSNumber *timestamp;

/// 澳股展开每单成交量
@property (nonatomic, strong) NSArray *subVolume;

/// OTC
///
/// 市场参与者ID
@property (nonatomic, copy) NSString *mpid;
@property (nonatomic, copy) NSString *mmid;
@property (nonatomic, strong) NSNumber *u;
@property (nonatomic, strong) NSNumber *s;
@property (nonatomic, strong) NSNumber *priceType;
@property (nonatomic, copy) NSString *otcFormatTime;


@end

@interface TBStockAskBidLevelModel : JSONModel


@property (nonatomic, copy) NSArray<TBStockAskBidLevelItemModel> *ask;
@property (nonatomic, copy) NSArray<TBStockAskBidLevelItemModel> *bid;

@property (nonatomic, copy) NSArray<TBStockAskBidLevelItemModel> *askArray;
@property (nonatomic, copy) NSArray<TBStockAskBidLevelItemModel> *bidArray;

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *secType;

@property (nonatomic, assign, getter=isHKGreyMarketStep) BOOL hkGreyMarketStep;
@property (nonatomic, assign) NSInteger ret;

@property (nonatomic, assign) BOOL isLongLink;//是否是长链接

@property (nonatomic, strong, nullable) NSNumber <Optional> *preClose; /// 组合期权下单-preClose
@property (nonatomic, strong, nullable) NSNumber <Optional> *midPrice; /// 组合期权下单-midPrice

@end

NS_ASSUME_NONNULL_END
