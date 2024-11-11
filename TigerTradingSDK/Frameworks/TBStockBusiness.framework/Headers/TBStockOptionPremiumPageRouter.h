//
//  TBStockOptionPremiumPageRouter.h
//  TBStockBusiness
//
//  Created by zlc on 2024/4/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TBStockDetailOptionPremiumOptionItemModel;

@interface TBStockOptionPremiumPageRouter : NSObject

/// 去抄底神器详情页面
+ (void)gotoStrikeAndSaveDetailPage;

/// 去权利金详情页面
+ (void)gotoOptionPremiumDetailPageWithModel:(TBStockDetailOptionPremiumOptionItemModel *)optionItemModel;

@end

NS_ASSUME_NONNULL_END
