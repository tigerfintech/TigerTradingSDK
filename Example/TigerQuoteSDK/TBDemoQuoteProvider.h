//
//  TBDemoQuoteProvider.h
//  TigerQuoteSDK
//

#import <Foundation/Foundation.h>
#import <TigerTradingSDK/TigerTradingQuoteManager.h>

NS_ASSUME_NONNULL_BEGIN

typedef TigerTradingSDKQuoteType (^TBDemoQuoteTypeProvider)(void);
typedef void (^TBDemoQuoteCallback)(NSArray<TigerTradingContractQuoteModel *> *quotes);

@interface TBDemoQuoteProvider : NSObject

- (instancetype)initWithQuoteTypeProvider:(TBDemoQuoteTypeProvider)quoteTypeProvider NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

- (NSArray<TigerTradingContractQuoteModel *> *)quotesForContracts:(NSArray<TigerTradingContractInfoModel *> *)contracts;

- (void)subscribeContracts:(NSArray<TigerTradingContractInfoModel *> *)contracts
                 component:(TigerTradingSDKQuoteComponentType)component
                  callback:(TBDemoQuoteCallback)callback;

- (void)unsubscribeContracts:(NSArray<TigerTradingContractInfoModel *> *)contracts
                   component:(TigerTradingSDKQuoteComponentType)component;

@end

NS_ASSUME_NONNULL_END
