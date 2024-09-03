//
//  TBRSPFilterModel.h
//  TBTradeBusiness
//
//  Created by swordzhou on 2022/11/2.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *TBRSPFilterType;
typedef NSString *TBRSPFilterItemAttr;
typedef NSString *TBRSPFilterTagCode;

FOUNDATION_EXPORT TBRSPFilterType const _Nonnull kTBRSPFilterTypeTag;               //标签类型
FOUNDATION_EXPORT TBRSPFilterType const _Nonnull kTBRSPFilterTypeMultipleTag;       //组合标签类型
FOUNDATION_EXPORT TBRSPFilterType const _Nonnull kTBRSPFilterTypeType;              //类型类型
FOUNDATION_EXPORT TBRSPFilterType const _Nonnull kTBRSPFilterTypePrimarySector;     //一级行业类型
FOUNDATION_EXPORT TBRSPFilterType const _Nonnull kTBRSPFilterTypeConcept;           //概念类型
FOUNDATION_EXPORT TBRSPFilterType const _Nonnull kTBRSPFilterTypeIndustry;          //行业类型
FOUNDATION_EXPORT TBRSPFilterType const _Nonnull kTBRSPFilterTypeMarketValue;       //市值类型
FOUNDATION_EXPORT TBRSPFilterType const _Nonnull kTBRSPFilterTypeMarket;            //市场类型

FOUNDATION_EXPORT TBRSPFilterItemAttr const _Nonnull kTBRSPFilterItemAttrStock;
FOUNDATION_EXPORT TBRSPFilterItemAttr const _Nonnull kTBRSPFilterItemAttrETF;

FOUNDATION_EXPORT TBRSPFilterTagCode const _Nonnull kTBRSPFilterTagHighYieldDividened;         ///< 高股息率
FOUNDATION_EXPORT TBRSPFilterTagCode const _Nonnull kTBRSPFilterTagWarrenBuffett;              ///< 巴菲特策略
FOUNDATION_EXPORT TBRSPFilterTagCode const _Nonnull kTBRSPFilterTagHighQuality;                ///< 绩优大盘股
FOUNDATION_EXPORT TBRSPFilterTagCode const _Nonnull kTBRSPFilterTagUnderValuedEnterprise;      ///< 低估值
FOUNDATION_EXPORT TBRSPFilterTagCode const _Nonnull kTBRSPFilterMultiTagHKStock ;
FOUNDATION_EXPORT TBRSPFilterTagCode const _Nonnull kTBRSPFilterMultiTagHKETF;
FOUNDATION_EXPORT TBRSPFilterTagCode const _Nonnull kTBRSPFilterMultiTagUSStock;
FOUNDATION_EXPORT TBRSPFilterTagCode const _Nonnull kTBRSPFilterMultiTagUSETF;

@protocol TBRSPFilterItemModel;
@protocol TBRSPFilterItemAdditionInfoModel;

@interface TBRSPFilterItemAdditionInfoModel : JSONModel

@property (nonatomic, copy) TBRSPFilterType type;         ///< 类型
@property (nonatomic, copy) NSString *code;               ///< type类型对应的取值

- (BOOL)multiValuesSupported;

@end

@interface TBRSPFilterItemModel : JSONModel

@property (nonatomic, copy) TBRSPFilterType type;         ///< 所属类型

@property (nonatomic, copy) NSString *value;              ///< 条件名称
@property (nonatomic, copy) NSString *code;               ///< 请求该条件传递参数
@property (nonatomic, copy, nullable) NSString *tagIconName;        ///< 副标题：只有type=tag有
@property (nonatomic, copy, nullable) NSString<Optional> *desc;     ///< 副标题：只有type=tag有

@property (nonatomic, copy) NSArray<TBRSPFilterItemAttr> *attrs;
@property (nonatomic, copy) NSArray<TBRSPFilterItemAdditionInfoModel> *additionalInfo; ///< 只有type=multiTag有

@property (nonatomic, assign) BOOL selected;

- (BOOL)isAllFilterItem;
- (BOOL)isMultiTag;

@end

@interface TBRSPFilterModel : JSONModel

@property (nonatomic, copy) TBRSPFilterType type;

@property (nonatomic, copy) NSArray<TBRSPFilterItemModel> *items;

- (NSString *)filterNameKey;


@end

NS_ASSUME_NONNULL_END
