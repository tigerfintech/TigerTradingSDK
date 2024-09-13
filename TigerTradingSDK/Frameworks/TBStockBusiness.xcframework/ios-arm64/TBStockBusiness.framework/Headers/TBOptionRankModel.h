//
//  TBOptionRankModel.h
//  Stock
//
//  Created by 王灵博 on 2021/7/29.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>
#import "TBOptionAnalysisHeader.h"
#import <TBBaseKit/TBBaseModel.h>
#import <TBBaseKit/TBBaseUtility.h>
#import "TBOptionRankModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface TBOptionRankChangeModel : TBBaseModel
@property(nonatomic ,copy)NSString *market;
@property(nonatomic ,copy)NSString *symbol;
@property(nonatomic ,copy)NSString *strike;
@property(nonatomic ,copy)NSString *right;
@property(nonatomic ,strong)NSNumber *timestamp;
@property(nonatomic ,strong)NSNumber *amount;
@property(nonatomic ,strong)NSNumber *price;
@property(nonatomic ,strong)NSNumber *changeRate;
@property(nonatomic ,strong)NSNumber *volume;
@property(nonatomic ,strong)NSNumber *expireDate;
@property(nonatomic ,strong)NSNumber *latestPrice;
@property(nonatomic ,strong)NSNumber *volOIRatio;
@property (nonatomic, copy) NSString *type;
@property(nonatomic, assign)TBOptionChangeType optionType;
@end
@protocol TBOptionRankChangeModel;
@interface TBOptionRankDataModel : TBBaseModel
@property(nonatomic ,copy)NSString *market;
@property(nonatomic ,copy)NSString *symbol;
@property(nonatomic ,copy)NSString *name;
@property(nonatomic ,strong)NSNumber *latestPrice;
@property(nonatomic ,strong)NSNumber *changeRate;
@property(nonatomic ,copy)NSArray <TBOptionRankChangeModel>*options;
@property(nonatomic ,assign)BOOL select;
@property(nonatomic, assign)TBOptionChangeType optionType;
@end

@protocol TBOptionRankDataModel;
@interface TBOptionRankModel : TBBaseModel
@property(nonatomic ,strong)NSNumber *serverTime;
@property(nonatomic ,copy)NSArray <NSNumber *>*unusualDates;
@property(nonatomic ,copy)NSArray <TBOptionRankDataModel>*items;
@property(nonatomic, assign)TBOptionChangeType optionType;
@end

NS_ASSUME_NONNULL_END
