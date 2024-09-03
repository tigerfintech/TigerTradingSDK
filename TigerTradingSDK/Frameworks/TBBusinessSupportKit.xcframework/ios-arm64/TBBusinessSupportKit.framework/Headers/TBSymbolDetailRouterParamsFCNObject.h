//
//  TBSymbolDetailRouterParamsFCNObject.h
//  TBBusinessSupportKit
//
//  Created by swordzhou on 12/18/23.
//

#import "TBSymbolDetailRouterParamsBaseObject.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TBSymbolDetailFCNParamsProtocol <NSObject>

@required
- (NSNumber *)stockContractId;

@end

@interface TBSymbolDetailRouterParamsFCNObject : TBSymbolDetailRouterParamsBaseObject

@end

NS_ASSUME_NONNULL_END
