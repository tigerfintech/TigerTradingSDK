//
//  TBStarInvestorOrderSymbolView.h
//  TBBusinessSupportKit
//
//  Created by F.S. on 2023/12/13.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStarInvestorOrderSymbolView : UIView

@property (nonatomic, copy) NSString *imgStr;
@property (nonatomic, copy) NSString *topStr;
@property (nonatomic, copy) NSString *botStr;
@property (nonatomic, strong) UIImage *marketImage;
@property (nonatomic, strong) NSNumber *createTime;

@property (nonatomic, assign) BOOL isHolding;
@property (nonatomic, assign) BOOL isNarrowMode;
@property (nonatomic, assign) BOOL openFlag;
@property (nonatomic, assign) CGFloat theViewWidth;
@property (nonatomic, assign) BOOL symbolLogoHidden;
@property (nonatomic, assign) BOOL holdingLabelHidden;
@property (nonatomic, assign) BOOL isHomeMode;

@property (nonatomic, assign) BOOL isVirtual; // 是否是虚拟号订单
@property (nonatomic, copy) NSString *periodExplanation;

- (void)updateStarInvestorSymbolView;

@end

NS_ASSUME_NONNULL_END
