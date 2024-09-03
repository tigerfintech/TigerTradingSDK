//
//  TBIntroDigitalCurrencyModel.h
//  Stock
//
//  Created by 王灵博 on 2020/8/21.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBIntroDigitalDataProductInfoModel: TBBaseModel

/// 产品的性质. eg: 比特币现货ETF
@property (nonatomic, copy) NSString *type;
/// 复杂产品的主要条款及特点. eg: 投资单一比特币现货，价格与比特币现货价格线性挂钩
@property (nonatomic, copy) NSString *feature;
/// 复杂产品是否只提供专业投资者买卖. eg: 否
@property (nonatomic, copy) NSString *professionOnly;
/// 复杂产品的主要风险. eg: 损失所有本金，比特币价值为0
@property (nonatomic, copy) NSString *mainRisk;
/// 结构性产品的最坏情况分析. eg: 不适用
@property (nonatomic, copy) NSString *worstCaseAnalysis;
/// 潜在利益是否有上限或限制. eg: 无上限
@property (nonatomic, copy) NSString *benefitLimit;
/// 复杂产品是否保本. eg: 不保本
@property (nonatomic, copy) NSString *guaranteed;
/// 是否有提早终止的特点. eg: 无
@property (nonatomic, copy) NSString *earlyTermination;
/// 提示赎回的任何惩罚. eg: 不适用
@property (nonatomic, copy) NSString *penaltyHit;
/// 该复杂产品是否有二级市场. eg: 有二级市场
@property (nonatomic, copy) NSString *secondaryMarket;

@end

@interface TBIntroDigitalDataModel : TBBaseModel
@property(nonatomic, copy) NSString *name;
@property(nonatomic, copy) NSString *currencyDescription;
@property(nonatomic, strong) NSNumber *shares;
@property(nonatomic, strong) NSNumber *floatShares;
@property(nonatomic, strong) NSNumber *listedPrice;
@property(nonatomic, copy) NSString *listingDate;
@property(nonatomic, copy) NSString *websiteUrl;
@property(nonatomic, copy) NSString *whitePaperUrl;
@property(nonatomic, copy) NSString *explorerUrl;
@property(nonatomic, copy) TBIntroDigitalDataProductInfoModel *productInfo;
@end

@interface TBIntroDigitalCurrencyModel : TBBaseModel

@property(nonatomic, strong) TBIntroDigitalDataModel *data;
@property(nonatomic, copy) NSString *message;
@property(nonatomic, strong) NSNumber *serverTime;

@end


@interface TBIntroDigitalCellModel : TBBaseModel
@property(nonatomic, copy) NSString *title;
@property(nonatomic, copy) NSString *detail;
@property(nonatomic, copy) NSString *urlStr;
@end
NS_ASSUME_NONNULL_END
