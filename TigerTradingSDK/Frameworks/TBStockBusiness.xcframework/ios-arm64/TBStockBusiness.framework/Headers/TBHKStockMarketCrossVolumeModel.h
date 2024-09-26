//
//  TBHKStockMarketCrossVolumeModel.h
//  Stock
//
//  Created by 骆鹏飞 on 2019/6/19.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>


NS_ASSUME_NONNULL_BEGIN

@protocol TBHKStockMarketCrossVolumeItemModel <NSObject>
@end

@interface TBHKStockMarketCrossVolumeItemModel : JSONModel

@property (nonatomic, strong) NSNumber *volume; // 持股量
@property (nonatomic, strong) NSNumber *changeVolume; // 较上日持股变化
@property (nonatomic, strong) NSNumber *rate; // 持股比

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *name;

@property (nonatomic, strong) NSNumber *holdMarketValue; //持股量变化占成交量比
@property (nonatomic, strong) NSNumber *changeVolumeRate; //持仓市值

@property (nonatomic, assign) BOOL header;

@end



@interface TBHKStockMarketCrossVolumeModel : JSONModel
@property (nonatomic, strong) NSNumber *ret;
@property (nonatomic, assign) NSTimeInterval serverTime;

@property (nonatomic, assign) NSInteger page;
@property (nonatomic, assign) NSInteger totalPage;
@property (nonatomic, copy) NSString *date;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSArray<TBHKStockMarketCrossVolumeItemModel> *items;
- (NSUInteger)refreshFooterType;
@end

NS_ASSUME_NONNULL_END
