//
//  TBOmnibuAPIOrderLegInfoModel.h
//  TBTradeBusiness
//
//  Created by 王昌阳 on 2023/4/17.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOmnibuAPIOrderLegInfoModel : JSONModel

@property (nonatomic, copy) NSString *action; // 买卖方向，默认BUY
@property (nonatomic, copy) NSString *market; // 市场：默认US
@property (nonatomic, copy) NSString *secType; // secType 默认OPT
@property (nonatomic, strong) NSNumber *ratio; // 默认为1
@property (nonatomic, copy, readonly) NSString *optionCombinedSymbol;

// 期权四要素
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *right;
@property (nonatomic, copy) NSString *expiry;
@property (nonatomic, copy) NSString *strike;

@property (nonatomic, copy) NSString *currency;
@property (nonatomic, strong) NSNumber *multiplier;
@property (nonatomic, strong) NSNumber *totalQuantity;
@property (nonatomic, strong) NSNumber *filledQuantity;
@property (nonatomic, strong) NSNumber *avgFilledPrice;
@property (nonatomic, strong) NSNumber *createdAt;
@property (nonatomic, strong) NSNumber *updatedAt;

- (NSDictionary *)legContractInfoDictionary;

- (NSString *)combinedOptionSymbol;

- (NSString *)mlegsSingleSymbol;

@end

NS_ASSUME_NONNULL_END
