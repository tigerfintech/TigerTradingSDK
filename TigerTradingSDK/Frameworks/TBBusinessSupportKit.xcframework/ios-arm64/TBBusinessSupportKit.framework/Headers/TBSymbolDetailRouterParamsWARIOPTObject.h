//
//  TBSymbolDetailRouterParamsWARIOPTObject.h
//  TBTradeBusiness
//
//  Created by 王昌阳 on 2023/9/20.
//

#import "TBSymbolDetailRouterParamsBaseObject.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TBSymbolDetailWARIOPTParamsProtocol <NSObject>
@required
- (NSString *)warIOPTSymbol;
- (NSString *)warIOPTMarket;
@optional
- (NSString *)warIOPTSymbolCN;
@end


@interface TBSymbolDetailRouterParamsWARIOPTObject : TBSymbolDetailRouterParamsBaseObject

@property (nonatomic, strong) id<TBSymbolDetailWARIOPTParamsProtocol> symbolItem;

@end

NS_ASSUME_NONNULL_END
