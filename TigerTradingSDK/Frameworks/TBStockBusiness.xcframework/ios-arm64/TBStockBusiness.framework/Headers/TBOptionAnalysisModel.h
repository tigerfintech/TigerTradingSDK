//
//  TBOptionAnalysisModel.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/11/30.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>
/*
 期权分析model
 */
NS_ASSUME_NONNULL_BEGIN


@interface TBOptionUnusualDetailModel : JSONModel

@property (nonatomic, strong) NSNumber *volume;
@property (nonatomic, copy) NSString *strike;
@property (nonatomic, strong) NSNumber *expireDate;
@property (nonatomic, strong) NSNumber *changeRate;
@property (nonatomic, strong) NSNumber *latestPrice;
@property (nonatomic, strong) NSNumber *volOIRatio;
@property (nonatomic, strong) NSNumber *impliedVol;
@property (nonatomic, strong) NSNumber *impliedVolChange;
@property (nonatomic, strong) NSNumber *impliedVolChangeRate;
@property (nonatomic, strong) NSNumber *volPreVolumeRatio;
@property (nonatomic, strong) NSNumber *ivHvRatio;
@property (nonatomic, assign) NSTimeInterval timestamp;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *right;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, strong) NSNumber *price;
@property (nonatomic, strong) NSNumber *amount;
@property (nonatomic, strong) NSNumber *ulLatestPrice;
@property (nonatomic, copy) NSString *contract;

@end

@protocol TBOptionUnusualDetailModel;
@interface TBOptionUnusualModel : JSONModel

@property (nonatomic, copy) NSArray<TBOptionUnusualDetailModel> *volUnusual;

@property (nonatomic, copy) NSArray<TBOptionUnusualDetailModel> *ivUnusual;

@property (nonatomic, copy) NSArray<TBOptionUnusualDetailModel> *bulkOrderUnusual;
@end

@protocol TBOptionAnalysisSentimentItemModel <NSObject>
@end
@interface TBOptionAnalysisSentimentItemModel : JSONModel

@property (nonatomic, strong) NSNumber *ratio;
@property (nonatomic, assign) NSTimeInterval time;


@property (nonatomic, strong) NSNumber *actionType;


@end

@protocol TBOptionAnalysisVolumeAnalysisItemModel <NSObject>
@end
@interface TBOptionAnalysisVolumeAnalysisItemModel : JSONModel
@property (nonatomic, strong) NSNumber *openInt;
@property (nonatomic, strong) NSNumber *volOpenIntRatio;
@property (nonatomic, strong) NSNumber *volume;
@property (nonatomic, assign) NSTimeInterval time;

@property (nonatomic, strong) NSNumber *actionType;

@end

@interface TBOptionAnalysisModel : JSONModel

@property (nonatomic, assign) NSInteger ret;
@property (nonatomic, assign) NSTimeInterval serverTime;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *skewness;

@property (nonatomic, copy) NSString *market;



@property (nonatomic, copy) NSArray<TBOptionAnalysisSentimentItemModel> *sentiment;

@property (nonatomic, copy) NSArray<TBOptionAnalysisVolumeAnalysisItemModel> *volumeAnalysis;

@property (nonatomic, strong) TBOptionUnusualModel *unusualOptions;


@end







NS_ASSUME_NONNULL_END
