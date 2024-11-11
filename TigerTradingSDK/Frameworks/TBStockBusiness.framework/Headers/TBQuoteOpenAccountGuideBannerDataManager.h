//
//  TBQuoteOpenAccountGuideBannerDataManager.h
//  TBStockBusiness
//
//  Created by dulijun on 2021/10/12.
//
// 这个manager用于请求行情顶部的引导开户入金数据，做成单例提供给各个market行情vc直接获取。

#import <Foundation/Foundation.h>
@class TBStreamPublicPopupMaterialModel;
#import <TBToolsKit/TBStreamServiceManager.h>
#import <TBBaseKit/TBBaseUtility.h>

@interface TBQuoteOpenAccountGuideBannerDataManager : NSObject
DECLARE_SHARED_INSTANCE(TBQuoteOpenAccountGuideBannerDataManager);

@property (nonatomic, strong) TBStreamPublicPopupMaterialModel *bannerData;

/// 获取开户引导页，新人开户/入金礼包
- (void)fetchQuotesOpenAccountGuideBanner;

@end

