//
//  TBFundOrderTAGLabel.h
//  TBTradeBusiness
//
//  Created by zlc on 2022/7/20.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    TBFundOrderTagNone = 0,
    TBFundOrderTagAutoSweep,
    TBFundOrderTagRSP,
    TBFundOrderTagStockAutoInvest, ///< 股票定投标签
    TBOrderCouponTag,              ///< 优惠券
    TBFundOrderFAAccountMgmtFeeTag, ///< FA 账户管理费
    TBFundOrderFAPerformanceFeeTag, ///< FA 绩效费
    TBOrderCouponOvernight,         ///< 夜盘
    TBOrderCouponCDPSell,         ///< CDP sell
    TBOrderCouponBuyIn            ///< Buy in
} TBFundOrderTag;

@interface TBFundOrderTAGLabel : UIView

+ (instancetype)tagLabel:(TBFundOrderTag)tag;

- (instancetype)initWithFrame:(CGRect)frame text:(NSString *)text;

- (instancetype)initWithFrame:(CGRect)frame text:(NSString *)text textFont:(UIFont *)textFont textColor:(UIColor *)textColor;

@end

@interface TBFundOrderAutoSweepLabel : TBFundOrderTAGLabel

@end

@interface TBFundOrderRSPLabel : TBFundOrderTAGLabel

@end

@interface TBSotckOrderAutoInvestLabel : TBFundOrderTAGLabel

@end

@interface TBAIPCouponLabel : TBFundOrderTAGLabel

@end

NS_ASSUME_NONNULL_END
