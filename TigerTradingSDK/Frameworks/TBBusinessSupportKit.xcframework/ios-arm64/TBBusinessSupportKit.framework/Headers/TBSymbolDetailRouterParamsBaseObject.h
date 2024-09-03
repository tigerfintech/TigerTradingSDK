//
//  TBSymbolDetailRouterParamsBaseObject.h
//  TBTradeBusiness
//
//  Created by 王昌阳 on 2023/9/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBSymbolDetailRouterParamsBaseObjectDelegate <NSObject>

@required
- (NSDictionary *)requiredParams;

@end


@interface TBSymbolDetailRouterParamsBaseObject : NSObject<TBSymbolDetailRouterParamsBaseObjectDelegate>

@property (nonatomic, strong) id symbolItem;

@end

NS_ASSUME_NONNULL_END
