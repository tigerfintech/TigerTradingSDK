//
//  TBNSENumConstant.h
//  Pods
//
//  Created by yangln on 2022/2/22.
//

#ifndef TBNSENumConstant_h
#define TBNSENumConstant_h

/// 触发开户入金引导页的来源
typedef NS_ENUM(NSInteger, TBOpenAccountGuideSourceType) {
    TBOpenAccountGuideSourceTypeAPPTradeTab = 1,      //!< app开户tab
    TBOpenAccountGuideSourceTypePersonCenterAccount,      //!< 我的-老虎账户
    TBOpenAccountGuideSourceTypeOfficialWebsite,      //!< 官网（目前没有用到）
    TBOpenAccountGuideSourceTypeSetting,      //!< 设置-账户管理
    TBOpenAccountGuideSourceTypeQuoteWatchBanner,      //!< APP行情页- 自选banner
    TBOpenAccountGuideSourceTypeQuoteUSBanner,      //!< APP行情页- 美股banner
    TBOpenAccountGuideSourceTypeQuoteHKBanner,      //!< APP行情页- 港股banner
    TBOpenAccountGuideSourceTypeQuoteCNBanner,      //!< APP行情页- 沪深banner
    TBOpenAccountGuideSourceTypeQuoteUKBanner,      //!< APP行情页- 伦敦banner
    TBOpenAccountGuideSourceTypeQuoteSIBanner,      //!< APP行情页- 新加坡banner
    TBOpenAccountGuideSourceTypeQuoteAUBanner,      //!< APP行情页- 澳洲banner
    TBOpenAccountGuideSourceTypeQuoteFuturesBanner,      //!< APP行情页- 期货banner
    TBOpenAccountGuideSourceTypeQuoteGlobalBanner,      //!< APP行情页- 全球banner
};

#endif /* TBNSENumConstant_h */
