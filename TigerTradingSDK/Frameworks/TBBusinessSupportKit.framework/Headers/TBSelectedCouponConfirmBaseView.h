//
//  TBSelectedCouponConfirmBaseView.h
//  TBBusinessSupportKit
//
//  Created by swordzhou on 8/24/23.
//

#import <TBUIKit/TBUIKit.h>
#import <TBUIKit/TBView.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBCouponDelegate;

@interface TBSelectedCouponConfirmBaseView : TBView

@property (nonatomic, assign) BOOL unfolded;            /// 是否展开 YES:展开的 NO:收起的 默认:NO

@property (nonatomic, assign) NSInteger availableCount;

@property (nonatomic, copy) NSArray<TBCouponDelegate> *coupons;

@property (nonatomic, strong) void(^confirmBlock)(void);

@property (nonatomic, strong) void(^selectedCouponDidChangedBlock)(NSArray<TBCouponDelegate> *);

@property (nonatomic, strong) void(^onFoldedBlock)(BOOL unfolded);

- (CGFloat)contentHeight:(NSArray<TBCouponDelegate> *)coupons;

@end

NS_ASSUME_NONNULL_END
