//
//  TBOptionChainBottomView.h
//  TBStockBusiness
//
//  Created by mashanli on 2023/4/19.
//
#import "TBStockDetailBottomTabBarView.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TBOptionChainBottomWatchType) {
    TBOptionChainBottomWatchTypeOutWatch, //没添加自选
    TBOptionChainBottomWatchTypeDisable,  //不可点击
    TBOptionChainBottomWatchTypeInWatch,  //添加自选
};

@interface TBOptionChainBottomView : UIView

@property (nonatomic, strong) UIButton *tradeView;
@property (nonatomic, strong) UILabel *strategyLabel;
@property (nonatomic, strong) UIImageView *arrowImageView;
@property (nonatomic, strong) UILabel *widthLabel;

@property (nonatomic, copy) NSString *strategy;//策略key

@property (nonatomic, assign) TBOptionChainBottomWatchType watchType;

@property (nonatomic, copy) void(^clickBlock)(TBStockBottomBarEventType barEventType);

- (void)updateLayout;

@end


NS_ASSUME_NONNULL_END
