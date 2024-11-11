//
//  TBCouponDelegate.h
//  TBTradeBusiness
//
//  Created by swordzhou on 2022/3/14.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSInteger, TBCouponEligible) {
    TBCouponEligibleNone = 0,
    TBCouponEligibleUsable = 1,
    TBCouponEligibleUnavailable = 2,
    TBCouponEligibleDisable = 3, ///< 不可交互，遮罩覆盖
};

typedef NS_ENUM(NSInteger, TBCouponCardType) {
    TBCouponCardTypeTimesNone = -1,
    TBCouponCardTypeTimes = 0,        //0:次数卡
    TBCouponCardTypeAmount = 1,       //1:额度卡
};

typedef NSString *TBCouponCategory;
typedef NSString *TBCouponFreeCardScope;
typedef NSString *TBCouponCombinationDesc;
typedef NSString *TBCouponStaus;

@class TBPlanCouponsInfoModel;
@class TBPlanBindedCouponsInfoModel;

FOUNDATION_EXPORT TBCouponCategory const _Nonnull kTBCouponCategoryAll;
FOUNDATION_EXPORT TBCouponCategory const _Nonnull kTBCouponCategoryCommissionFreeCard;   /// 免佣卡
FOUNDATION_EXPORT TBCouponCategory const _Nonnull kTBCouponCategoryStockVoucher;         /// 代金券
FOUNDATION_EXPORT TBCouponCategory const _Nonnull kTBCouponCategoryFundAll;              /// 基金优惠券-全部
FOUNDATION_EXPORT TBCouponCategory const _Nonnull kTBCouponCategoryFundYeildVoucher;     /// 基金-收益券
FOUNDATION_EXPORT TBCouponCategory const _Nonnull kTBCouponCategoryFundCashVoucher;      /// 基金-代金券 == 等同于（StockVoucher）
FOUNDATION_EXPORT TBCouponCategory const _Nonnull kTBCouponCategoryEffective;
FOUNDATION_EXPORT TBCouponCategory const _Nonnull kTBCouponCategoryExpired;
FOUNDATION_EXPORT TBCouponCategory const _Nonnull kTBCouponCategoryUsed;


FOUNDATION_EXPORT TBCouponStaus const _Nonnull kTBCouponStausEffective;
FOUNDATION_EXPORT TBCouponStaus const _Nonnull kTBCouponStausExpired;
FOUNDATION_EXPORT TBCouponStaus const _Nonnull kTBCouponStausUsed;

FOUNDATION_EXPORT TBCouponFreeCardScope const _Nonnull kTBCouponFreeCardScopeCommission; /// 免佣卡-免佣金
FOUNDATION_EXPORT TBCouponFreeCardScope const _Nonnull kTBCouponFreeCardScopePlatformFee;/// 免佣卡-免平台费
FOUNDATION_EXPORT TBCouponFreeCardScope const _Nonnull kTBCouponFreeCardScopeTradingFee; /// 免佣卡-免交易费 TFNZ独有

FOUNDATION_EXPORT TBCouponCombinationDesc const _Nonnull kTBCouponCombinationDescFreecardOnly;         ///证券下单-仅选择使用免佣卡
FOUNDATION_EXPORT TBCouponCombinationDesc const _Nonnull kTBCouponCombinationDescVoucherOnly;          ///证券下单-仅使用代金券

FOUNDATION_EXPORT TBCouponCombinationDesc const _Nonnull kTBCouponCombinationDescBestOffer;            ///证券下单&基金&股票定投-选择最优优惠组合
FOUNDATION_EXPORT TBCouponCombinationDesc const _Nonnull kTBCouponCombinationDescOfferCombination;     ///证券下单&基金&股票定投-选择优惠组合

FOUNDATION_EXPORT TBCouponCombinationDesc const _Nonnull kTBCouponCombinationDescNoCouponSelected;     ///证券下单&基金&股票定投-未选中任何优惠
FOUNDATION_EXPORT TBCouponCombinationDesc const _Nonnull kTBCouponCombinationDescMoreThanOneSelected;  ///基金&股票定投-选择多张优惠券

FOUNDATION_EXPORT TBCouponCombinationDesc const _Nonnull kTBCouponCombinationDescVoucherAutoOnly;        ///股票定投-仅选择代金券
FOUNDATION_EXPORT TBCouponCombinationDesc const _Nonnull kTBCouponCombinationDescFreeCardAutoOnly;       ///股票定投-仅选择免佣卡
FOUNDATION_EXPORT TBCouponCombinationDesc const _Nonnull kTBCouponCombinationDescYieldVoucherAutoOnly;   ///基金定投-仅选择收益券
FOUNDATION_EXPORT TBCouponCombinationDesc const _Nonnull kTBCouponCombinationDescFundOneCouponSelected;  ///基金定投-仅选择一张

FOUNDATION_EXPORT NSString *const kTBCouponsInfoModelKey;

@protocol TBCouponDescriptionModel <NSObject>

@end

@interface TBCouponDescriptionModel : JSONModel

@property (nonatomic, copy) NSString *desc;
@property (nonatomic, copy) NSString *type;

@end

@protocol TBCouponDelegate <NSObject>

@required

@property (nonatomic, copy) TBCouponCategory category;
@property (nonatomic, copy) TBCouponStaus status;       /// 优惠券状态

@property (nonatomic, copy) NSString *statusDesc;

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *couponId;
@property (nonatomic, copy) NSString *awardId;
@property (nonatomic, copy) NSString *openTime;          /// 有效期开始时间
@property (nonatomic, copy) NSString *expiryTime;        /// 有效期结束时间

@property (nonatomic, assign) TBCouponEligible eligible; /// 卡券是否可用， 1: 可用，2:不可用 证券下单直接取接口eligible，股票&基金定投取接口canUse字段赋值
@property (nonatomic, assign) TBCouponCardType cardType; /// 0:次数卡 1:额度卡

@property (nonatomic, assign) BOOL defaultSelected;      /// 接口返回标识是否默认选中
@property (nonatomic, assign) BOOL bestCoupon;           /// 是否最优卡券 (改单传lastBind 为true 时候，最优卡券不一定是默认绑定卡券，需要通过该字段判断）

@property (nonatomic, strong) NSNumber *totalTimes;      /// 总次数，代金券默认是1
@property (nonatomic, strong) NSNumber *remainTimes;     /// 剩余次数，代金券默认是1
@property (nonatomic, strong) NSNumber *usedTimes;       /// 已使用次数

@optional

@property (nonatomic, strong) NSNumber *amount;        /// 优惠券金额

@property (nonatomic, strong) NSNumber *term;           /// 定投时存在-指定使用的期数, 0 表示不限制使用期数卡券,期数为0的代金券只要是可用的，可以选任意多张1~99 表示指定期数卡券，指定的期数相同的代金券，同一时间只能选一张

@property (nonatomic, copy) NSString *categoryName;     /// 免佣卡类型文案

@property (nonatomic, copy) NSString *currency;        /// 优惠券币种

@property (nonatomic, copy) NSString *cardId;          /// 免佣卡id

@property (nonatomic, copy) NSString *disableReason;   /// 不可用原因，股票&基金定投取接口message字段

@property (nonatomic, copy) NSString *moreDetailsTitle; /// 查看更多 or 卡券详情 文案

@property (nonatomic, copy) NSArray <TBCouponDescriptionModel>*freeScope;         /// 免佣卡免佣范围[佣金、平台费]


///是否是免佣卡
- (BOOL)isCommissionFreeCard;

///是否是代金券
- (BOOL)isStockVoucher;

///是否时收益券
- (BOOL)isFundYieldVoucher;

- (BOOL)canUseMaximumLimitTimes;

- (NSString *)orderRebateType;
- (NSString *)displayedName;
- (NSString *)couponTypeName;
- (NSString *)couponTypeIconName;


@end


@protocol TBCouponDataService <NSObject>

@required

/** 获取用户所有的卡券（免佣卡、代金券）
 * @param category ALL\FREE_CARD\VOUCHER 见TBCouponCategory定义
 * @param pageNumber 页码 从1开始
 * @param completion 数据回调 coupons:优惠券列表 userInfo:额外信息 {kTBCouponsInfoModelKey:TBCouponsInfoModel}
 *
 */
- (void)fetchCouponList:(TBCouponCategory)category
             pageNumber:(NSInteger)pageNumber
             parameters:(NSDictionary *)parameters
             completion:(void (^)(NSArray<TBCouponDelegate> *coupons, NSDictionary *userInfo))completion;

@optional

- (NSString *)tabTitleWithCategory:(TBCouponCategory)category;

/**
 * 数据是否允许分页
 */
- (BOOL)paginationEnabled;

- (void)fetchRecommendedCoupons:(TBCouponCategory)category
                     parameters:(NSDictionary *)parameters
                     completion:(void (^)(NSArray<TBCouponDelegate> *coupons, NSDictionary *userInfo))completion;

/**
 * @params parameters必须包含investmentId参数
 * @param completion 数据回调 planBindedCouponsInfoModel:定投计划绑定的优惠券信息 userInfo:额外信息
 */
- (void)fetchBinedCouponsOfPlan:(NSDictionary *)parameters
                     completion:(void (^)(TBPlanBindedCouponsInfoModel *planBindedCouponsInfoModel, NSDictionary *userInfo))completion;


@end

NS_ASSUME_NONNULL_END
