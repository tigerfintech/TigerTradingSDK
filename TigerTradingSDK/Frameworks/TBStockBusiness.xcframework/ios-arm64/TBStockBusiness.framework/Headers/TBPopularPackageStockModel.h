//
//  TBPopularPackageStockModel.h
//  Stock
//
//  Created by zhenglanchun on 2021/8/4.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN


@protocol TBPopularPackageStockItemsDataModel
@end

@protocol TBPopularPackageStockItemsModel
@end

@interface TBPopularPackageStockModel : JSONModel

@property (nonatomic, assign) NSTimeInterval serverTime;
@property (nonatomic, assign) NSInteger ret;

@property (nonatomic, copy) NSArray<TBPopularPackageStockItemsModel> *items;

@end

@interface TBPopularPackageStockItemsModel : JSONModel

@property (nonatomic, assign) NSInteger page;
@property (nonatomic, assign) NSInteger totalCount;
@property (nonatomic, assign) NSInteger totalPage;
@property (nonatomic, copy) NSString * name;
@property (nonatomic, assign) NSInteger ID;
@property (nonatomic, copy) NSArray<TBPopularPackageStockItemsDataModel> *data;

@end

@interface TBPopularPackageStockItemsDataModel : JSONModel

@property (nonatomic, copy) NSString * nameCN;            //名称
@property (nonatomic, copy) NSString * symbol;            //股票代码
@property (nonatomic, copy) NSString * market;            //股票代码
@property (nonatomic, strong) NSNumber * latestPrice;          //价格
@property (nonatomic, strong) NSNumber * preClose;          
@property (nonatomic, strong) NSNumber * changeRate;           //涨跌幅
@property (nonatomic, strong) NSNumber * change;               //涨跌额
@property (nonatomic, strong) NSNumber * volume;               //成交量
@property (nonatomic, strong) NSNumber * amount;               //成交额
@property (nonatomic, strong) NSNumber * turnoverRate;         //换手率
@property (nonatomic, strong) NSNumber * amplitude;            //振幅
@property (nonatomic, strong) NSNumber * volumeRatio;          //量比
@property (nonatomic, strong) NSNumber * peRate;               //市盈率
//辅助市盈率显示亏损时使用，peRate server 无法吐负数，目前只能通过eps<0来辅助显示
@property (nonatomic, strong) NSNumber * eps;
@property (nonatomic, strong) NSNumber * pbRate;               //市净率
@property (nonatomic, strong) NSNumber * marketValue;          //总市值
/** 换手率和流通市值需也可以计算获得
 流通市值=latestPrice*floatShares
 换手率=volume/floatShares
 */
@property (nonatomic, assign) CGFloat floatShares;          //流通股本





@end

NS_ASSUME_NONNULL_END
