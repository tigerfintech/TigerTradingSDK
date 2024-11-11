//
//  TBHKTenLevelDataDetailTicksHelper.h
//  TBStockBusiness
//
//  Created by zhenglanchun on 2021/10/22.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBHKTenLevelDataDetailTicksHelper : UIView

@property (nonatomic, strong) UIView *tickTipsHeaderView;
@property (nonatomic, copy) void(^tapHeaderViewAction)(void);

- (void)scrollViewWillBeginDraggingWithSuperView: (UIView *)view withLayoutView:(UIView *)layoutView;
- (void)scrollViewDidEndDragging;
- (void)hideTickTipsHeaderView;
- (void)hideTickTipsHeaderViewWithCancelPreviousAction;

- (NSString *)tips;
- (UIColor *)tipsTextColor;

+ (BOOL)isTipsHeaderEnabledWithMarket:(NSString *)market secType:(NSString*) secType;

@end

NS_ASSUME_NONNULL_END
