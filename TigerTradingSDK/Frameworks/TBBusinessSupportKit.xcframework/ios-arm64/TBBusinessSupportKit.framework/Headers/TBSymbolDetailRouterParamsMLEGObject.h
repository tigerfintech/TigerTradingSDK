//
//  TBSymbolDetailRouterParamsMLEGObject.h
//  TBTradeBusiness
//
//  Created by 王昌阳 on 2023/9/20.
//

#import "TBSymbolDetailRouterParamsBaseObject.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TBSymbolDetailMLegParamsProtocol <NSObject>

- (NSArray *)mlegOptionItems;

@end


@interface TBSymbolDetailRouterParamsMLEGObject : TBSymbolDetailRouterParamsBaseObject

@property (nonatomic, strong) id<TBSymbolDetailMLegParamsProtocol> symbolItem;

@end

NS_ASSUME_NONNULL_END
