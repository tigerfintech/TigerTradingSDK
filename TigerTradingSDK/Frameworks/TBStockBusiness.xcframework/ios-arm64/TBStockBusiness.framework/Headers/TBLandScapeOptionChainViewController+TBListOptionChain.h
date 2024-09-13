//
//  TBLandScapeOptionChainViewController+TBListOptionChain.h
//  Stock
//
//  Created by 王灵博 on 2021/1/19.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import "TBLandScapeOptionChainViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBLandScapeOptionChainViewController (TBListOptionChain)
- (void)handleAllOption:(NSArray *)items scrollToStrike:(BOOL)scrollToStrike;
- (NSInteger)getListIndexOfFirstCallLatestPriceType;
- (void)scrollToCellCloseToStrike;

- (void)handleMQTTOptionChainData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
