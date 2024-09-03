//
//  TBTigerTradeHostFactory.h
//  TBHostManager
//
//  Created by chenxin on 2021/2/8.
//

#import "TBBaseHost.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBTigerTradeHost : TBBaseHost <TBHostManagerProtocol>

@end

@interface TBTigerTradeBaseConfig : NSObject <TBHostConfig>

@end

#pragma mark - Tiger Trade 使用的 host 类

// !!!: TigerTrade新增host类时，也要在TBTradeUPHost中同步添加，以防TradeUP获取host出错

/// 原cg域名, 负责i18n等接口
@interface TBTigerTradeHostCG : TBTigerTradeBaseConfig
@end

/// dnha域名
@interface TBTigerTradeHostDNHA : TBTigerTradeBaseConfig
@end

/// dnha备用域名
@interface TBTigerTradeHostDNHA2 : TBTigerTradeBaseConfig
@end

@interface TBTigerTradeHostIBTrade : TBTigerTradeBaseConfig
@end

@interface TBTigerTradeHostHq : TBTigerTradeBaseConfig
@end

@interface TBTigerTradeHostOAuth : TBTigerTradeBaseConfig
@end

@interface TBTigerTradeHostCustomer : TBTigerTradeBaseConfig
@end

@interface TBTigerTradeHostCustomerSupport : TBTigerTradeBaseConfig
@end

@interface TBTigerTradeHostCustomerInfobase : TBTigerTradeBaseConfig
@end

@interface TBTigerTradeGCSChatHost : TBTigerTradeBaseConfig <TBHostConfig>
@end

@interface TBTigerTradeTicketHost : TBTigerTradeBaseConfig <TBHostConfig>
@end

@interface TBTigerTradeFundHost : TBTigerTradeBaseConfig <TBHostConfig>
@end

@interface TBTigerTradeTrackHost : TBTigerTradeBaseConfig <TBHostConfig>
@end

@interface TBTigerTradePortalHost : TBTigerTradeBaseConfig <TBHostConfig>
@end

@interface TBTigerTradePortalActivityHost : TBTigerTradeBaseConfig <TBHostConfig>
@end

@interface TBTigerTradeCollegeHost : TBTigerTradeBaseConfig <TBHostConfig>
@end

@interface TBTigerTradeCampaignHost : TBTigerTradeBaseConfig <TBHostConfig>
@end

@interface TBTigerBffMobileHost : TBTigerTradeBaseConfig <TBHostConfig>
@end

@interface TBTigerTradeBffApiHubHost : TBTigerTradeBaseConfig <TBHostConfig>
@end

@interface TBFAHost : TBTigerTradeBaseConfig <TBHostConfig>
@end

NS_ASSUME_NONNULL_END
