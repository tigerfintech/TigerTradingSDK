//
//  TBStockDetailTradeGuidePopupView.h
//  TBBusinessSupportKit
//
//  Created by dulijun on 2023/3/20.
//

#import <UIKit/UIKit.h>
#import <TBToolsKIT/TBStreamPublicPopupModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockDetailTradeGuidePopupView : UIView

@property (nonatomic, strong) TBStreamPublicPopupMaterialModel *data;
@property (nonatomic, strong) void(^actionBlock)(void);
@property (nonatomic, strong) void(^closeBlock)(void);

@end

NS_ASSUME_NONNULL_END
