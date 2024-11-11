//
//  TBCouponCellItem.h
//  TBTradeBusiness
//
//  Created by swordzhou on 2022/3/17.
//

#import <TBUIKit/TBTableViewCellItem.h>
#import <TBBusinessSupportKit/TBCouponDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBCouponDelegate;

@interface TBCouponCellItem : TBTableViewCellItem

@property (nonatomic, strong) id<TBCouponDelegate> couponInfo;

@property (nonatomic, assign) BOOL selected;
@property (nonatomic, assign) BOOL showStatusBadge;     /// Default:NO

@end

NS_ASSUME_NONNULL_END
