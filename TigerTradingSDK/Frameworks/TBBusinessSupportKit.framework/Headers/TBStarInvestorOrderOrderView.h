//
//  TBStarInvestorOrderOrderView.h
//  TBBusinessSupportKit
//
//  Created by F.S. on 2023/12/13.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStarInvestorOrderOrderView : UIView

@property (nonatomic, copy) NSString *sideStr;
@property (nonatomic, strong) UIColor *sideColor;
@property (nonatomic, assign) BOOL openFlag;

@property (nonatomic, copy) NSDictionary *orderPnl;

@property (nonatomic, copy) NSString *avgFillPrice;
@property (nonatomic, copy) NSString *position;

@property (nonatomic, assign) BOOL isHolding;
@property (nonatomic, assign) CGFloat theViewWidth;

@property (nonatomic, assign) BOOL showSmallHoldTag;

@property (nonatomic, assign) BOOL isVirtual; // 是否是虚拟号订单
@property (nonatomic, strong) NSNumber *changeType;
@property (nonatomic, strong) NSNumber *portfolioPercentChange;

- (void)updateStarInvestorOrderView;

@end

NS_ASSUME_NONNULL_END
