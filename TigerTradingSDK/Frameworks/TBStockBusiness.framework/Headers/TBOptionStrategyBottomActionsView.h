//
//  TBOptionStrategyBottomActionsView.h
//  TBStockBusiness
//
//  Created by 王昌阳 on 2023/4/17.
//

#import <TBUIKit/TBView.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionStrategyBottomActionsView : TBView

@property (nonatomic, assign) BOOL tradeable;
@property (nonatomic, assign) BOOL inWatchList;

@property (nonatomic, assign) BOOL inPlaceOrder;

@property (nonatomic, copy) dispatch_block_t placeOrderBlock;
@property (nonatomic, copy) dispatch_block_t addWatchListBlock;

@property (nonatomic, strong) UIButton *placeOrderBtn;

- (instancetype)initWithTradeable:(BOOL)tradeable;

- (void)changeInWatchList:(BOOL)inWatchList animate:(BOOL)animate;

@end

NS_ASSUME_NONNULL_END
