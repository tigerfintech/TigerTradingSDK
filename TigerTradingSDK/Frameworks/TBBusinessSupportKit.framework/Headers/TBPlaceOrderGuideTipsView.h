//
//  TBPlaceOrderGuideTipsView.h
//  TBBusinessSupportKit
//
//  Created by dulijun on 2023/3/10.
//

#import <UIKit/UIKit.h>
#import "TBMultiStepGuideTipsModel.h"
#import <TBBaseKit/TBBaseUtility.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBPlaceOrderGuideTipsView : UIView
//DECLARE_SHARED_INSTANCE(TBPlaceOrderGuideTipsView);

- (void)addTip:(TBMultiStepGuideTipsModel *)tip;
- (void)showTips;

@end

NS_ASSUME_NONNULL_END
