//
//  TBTradeBusinessComponentServiceImplementation.h
//  ACETelPrompt
//
//  Created by yangln on 2021/12/2.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>
#import <TBServiceProtocolKit/TBTradeBusinessComponentService.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBTradeBusinessComponentServiceImplementation : NSObject<TBTradeBusinessComponentService>

DECLARE_SHARED_INSTANCE(TBTradeBusinessComponentServiceImplementation);

@end

NS_ASSUME_NONNULL_END
