//
//  Quote+TBQuote.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/8/31.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import "Quote.pbobjc.h"
#import "QuoteDepth.pbobjc.h"
#import "OptionDepth.pbobjc.h"
#import "FuturesDepth.pbobjc.h"
#import "HkOptionDepth.pbobjc.h"
#import "CryptoCurrencyDepth.pbobjc.h"
#import "HkGrey.pbobjc.h"
#import "HkQuoteDepth.pbobjc.h"
#import "FuturesBrief.pbobjc.h"
#import "MarketPage.pbobjc.h"
#import "HkQuoteBroker.pbobjc.h"
#import "QuoteTick.pbobjc.h"

// trade
#import "AssetSnapshot.pbobjc.h"
#import "PositionSnapshot.pbobjc.h"
#import "ComplexPositionSnapshot.pbobjc.h"

NS_ASSUME_NONNULL_BEGIN

@interface Quote (TBQuote)
- (NSDictionary *)quoteDictionary;
@end

@interface FuturesBrief (TBQuote)

- (NSDictionary *)quoteDictionary;

@end


@interface QuoteDepth (TBQuote)

- (NSDictionary *)usDepth;

@end

@interface HkQuoteDepth (TBQuote)
- (NSDictionary *)hkDepth;
@end

@interface Quote_OffsetDecimal (TBQuote)

- (NSNumber *)realValue;

@end

@interface MarketPage_OffsetDecimal (TBQuote)

- (NSNumber *)realValue;

@end

@interface OptionDepth (TBQuote)
- (NSDictionary *)optionDepth;
@end

@interface HkOptionDepth (TBQuote)
- (NSDictionary *)hkoptionDepth;
@end

@interface FuturesDepth (TBQuote)

- (NSDictionary *)futDepth;

@end

@interface CryptoCurrencyDepth (TBQuote)

- (NSDictionary *)cryptoCurrencyDepth;

@end

@interface HkGrey (TBQuote)

- (NSDictionary *)greyDepthAndQuote;

@end

@interface MarketPage (TBQuote)

- (NSDictionary *)quoteDict;

@end

@interface HkQuoteBroker (TBQuote)
- (NSDictionary *)quoteBrokerDict;

@end

@interface QuoteTick (TBQuote)
- (NSDictionary *)quoteDict;

@end


@interface AssetSnapshot (TBQuote)

/// 资产的proto类转为接口结构的字典
/// 因为推送和接口的部分结构不同, 需要特殊处理
- (NSDictionary *)toAssetDictionaryWithJSONObect:(NSDictionary *)jsonObject;

@end

@interface AssetSnapshot_ContraAssetInfo (TBQuote)

/// 资产的proto类转为接口结构的字典
/// 因为推送和接口的部分结构不同, 需要特殊处理
- (NSDictionary *)toAssetSnapshotDictionaryWithJSONObect:(NSDictionary *)jsonObject;

@end

@interface PositionSnapshot (TBQuote)

/// 单股持仓的proto类转为接口结构的字典
/// 因为推送和接口的部分结构不同, 需要特殊处理
- (NSDictionary *)toPositionDictionaryWithJSONObect:(NSDictionary *)jsonObject;

@end

@interface ComplexPositionSnapshot (TBPosition)

/// 单股持仓的proto类转为接口结构的字典
/// 因为推送和接口的部分结构不同, 需要特殊处理
- (NSDictionary *)toPositionDictionaryWithJSONObect:(NSDictionary *)jsonObject;

@end

@interface ComplexPositionSnapshot_ComboModePosition (TBPosition)

/// 单股持仓的proto类转为接口结构的字典
/// 因为推送和接口的部分结构不同, 需要特殊处理
- (NSDictionary *)toLegPositionDictionaryWithJSONObect:(NSDictionary *)jsonObject; 

@end


NS_ASSUME_NONNULL_END
