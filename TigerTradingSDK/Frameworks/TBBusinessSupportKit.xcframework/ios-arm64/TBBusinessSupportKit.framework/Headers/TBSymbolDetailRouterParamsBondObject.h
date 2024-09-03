//
//  TBSymbolDetailRouterParamsBondObject.h
//  TBTradeBusiness
//
//  Created by swordzhou on 11/15/23.
//

#import "TBSymbolDetailRouterParamsBaseObject.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TBSymbolDetailBondParamsProtocol <NSObject>

@required
- (NSString *)bondSymbol;
- (NSString *)bondSecType;
@optional
- (NSString *)bondSymbolCN;

@end


@interface TBSymbolDetailRouterParamsBondObject : TBSymbolDetailRouterParamsBaseObject

@property (nonatomic, strong) id<TBSymbolDetailBondParamsProtocol> symbolItem;

@end

NS_ASSUME_NONNULL_END
