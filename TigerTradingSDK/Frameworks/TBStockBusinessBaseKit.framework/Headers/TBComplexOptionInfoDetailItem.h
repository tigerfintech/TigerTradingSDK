//
//  TBComplexOptionInfoDetailItem.h
//  TBStockBusiness
//
//  Created by zlc on 2023/4/18.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@class TBOptionInfoDetailItem;

@interface TBComplexOptionInfoDetailItem : JSONModel

// MARK: - server属性
@property (nonatomic, assign) NSInteger ret;
@property (nonatomic, assign) NSTimeInterval serverTime;

@property (nonatomic, strong) NSNumber *bidPrice;
@property (nonatomic, strong) NSNumber *bidSize;

@property (nonatomic, strong) NSNumber *askPrice;
@property (nonatomic, strong) NSNumber *askSize;

@property (nonatomic, strong) NSNumber *latestPrice;
@property (nonatomic, strong) NSNumber *preClose;
@property (nonatomic, strong) NSNumber *midPrice;


// MARK: - 补全属性
@property (nonatomic, copy) NSString <Optional> *localSymbol; // 底层股票symbol,默认为nil

@property (nonatomic, copy) NSString <Optional> *market; // 默认：US

@property (nonatomic, copy) NSString <Optional> *secType; // 默认：MLEG

@property (nonatomic, strong) NSNumber <Optional> *multiplier; // 乘数-外界补全

@property (nonatomic, copy, nullable) NSArray <TBOptionInfoDetailItem *><Ignore> *options; // 子期权信息

@end

NS_ASSUME_NONNULL_END
