//
//  TBHomeTradeGuideCongratulationPopupViewController.h
//  TBBusinessSupportKit
//
//  Created by dulijun on 2023/3/20.
//

#import <TBUIKit/TBBaseViewController.h>
#import <TBToolsKIT/TBStreamPublicPopupModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBHomeTradeGuideCongratulationPopupViewController : TBBaseViewController

+ (void)showHomePagePopupForContratulateNewUserPlaceOrderWithData:(TBStreamPublicPopupMaterialModel *)data;

@end

NS_ASSUME_NONNULL_END
