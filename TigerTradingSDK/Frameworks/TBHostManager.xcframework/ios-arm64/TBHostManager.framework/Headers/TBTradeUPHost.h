//
//  TBTradeUPHostFactory.h
//  TBHostManager
//
//  Created by wind on 2021/2/19.
//

#import "TBBaseHost.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBTradeUPHost : TBBaseHost <TBHostManagerProtocol>

@end

@interface TBTradeUPHostCG : NSObject <TBHostConfig>

@end

@interface TBTradeUPHostDNHA : NSObject <TBHostConfig>

@end

@interface TBTradeUPHostDNHA2 : NSObject <TBHostConfig>

@end

@interface TBTradeUPHostPortal : NSObject <TBHostConfig>

@end

@interface TBTradeUPHostPortalActivity : NSObject <TBHostConfig>

@end

@interface TBTradeUPHostIBTrade : NSObject <TBHostConfig>
@end

@interface TBTradeUPHostHq : NSObject <TBHostConfig>
@end

@interface TBTradeUPHostOAuth : NSObject <TBHostConfig>
@end

@interface TBTradeUPHostCustomer : NSObject <TBHostConfig>
@end

@interface TBTradeUPHostCustomerSupport : NSObject <TBHostConfig>
@end

@interface TBTradeUPHostCustomerInfobase : NSObject <TBHostConfig>
@end

@interface TBTradeUPCollegeHost : NSObject <TBHostConfig>

@end

@interface TBTradeUPBffMobileHost : NSObject <TBHostConfig>
@end

@interface TBTradeUPBffApiHubHost : NSObject <TBHostConfig>
@end

@interface TBTradeUPTicketHost : NSObject <TBHostConfig>
@end

@interface TBTradeUPTrack : NSObject <TBHostConfig>
@end

NS_ASSUME_NONNULL_END
