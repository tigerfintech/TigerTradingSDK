//
//  TBSymbolDetailRouterParamsFUNDObject.h
//  TBTradeBusiness
//
//  Created by 王昌阳 on 2023/9/20.
//

#import "TBSymbolDetailRouterParamsBaseObject.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TBSymbolDetailFundParamsProtocol <NSObject>

@required
- (NSString *)fundSymbol;
@optional
- (NSString *)fundName;

@end

@interface TBSymbolDetailRouterParamsFUNDObject : TBSymbolDetailRouterParamsBaseObject

@property (nonatomic, strong) id<TBSymbolDetailFundParamsProtocol> symbolItem;

@end

NS_ASSUME_NONNULL_END
