//
//  TBSymbolDetailRouterParamsOPTObject.h
//  TBTradeBusiness
//
//  Created by 王昌阳 on 2023/9/20.
//

#import "TBSymbolDetailRouterParamsBaseObject.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TBSymbolDetailOptionParamsProtocol <NSObject>
@required
- (NSString *)optionSymbol;
- (NSNumber *)optionExpiry;
- (NSString *)optionStrike;
- (NSString *)optionRight;
- (NSString *)optionMarket;
@optional
- (NSString *)optionSymbolCN;
@end

@interface TBSymbolDetailRouterParamsOPTObject : TBSymbolDetailRouterParamsBaseObject

@property (nonatomic, strong) id<TBSymbolDetailOptionParamsProtocol> symbolItem;

@end

NS_ASSUME_NONNULL_END
