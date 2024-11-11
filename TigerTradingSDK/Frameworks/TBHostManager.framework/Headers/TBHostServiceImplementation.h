//
//  TBHostServiceImplementation.h
//  StockGlobal
//
//  Created by wind on 2021/3/11.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseKit.h>
#import <TBHostManager/TBHostManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBHostServiceImplementation : NSObject<TBHostService, TBServiceBaseProtocol>
DECLARE_SHARED_INSTANCE(TBHostServiceImplementation);

@end

NS_ASSUME_NONNULL_END
