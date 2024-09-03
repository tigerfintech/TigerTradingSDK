//
//  TBSymbolDetailRouterParamsSTKObject.h
//  TBTradeBusiness
//
//  Created by 王昌阳 on 2023/9/20.
//  注意：期货、国债、债券收益率、汇率 market 对应的取值为 secType，market 字段可不传，标的详情页会覆盖重写
//  from: 标的详情页 代码
//  if ([_secType tb_isFutures] || [_secType tb_isBonds] || [_secType tb_isForex] || [_secType tb_isBond]) {
//    有些接口依赖market，server将market 与 secType 保持同一个值
//      _market = _secType;

#import "TBSymbolDetailRouterParamsBaseObject.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TBSymbolDetailStockParamsProtocol <NSObject>
@required
- (NSString *)stockSymbol;
- (NSString *)stockSecType;
- (NSString *)stockMarket;
@optional
- (NSString *)stockSymbolCN;
@end


@interface TBSymbolDetailRouterParamsSTKObject : TBSymbolDetailRouterParamsBaseObject

@property (nonatomic, strong) id<TBSymbolDetailStockParamsProtocol> symbolItem;

@end

NS_ASSUME_NONNULL_END
