//
//  TBStockRightAlertManager.h
//  Stock
//
//  Created by 王灵博 on 2020/5/6.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockRightAlertManager : NSObject
DECLARE_SHARED_INSTANCE(TBStockRightAlertManager);
- (void)showAlert;

- (void)showRightLikeWithMarket:(NSString *)market;
@end

NS_ASSUME_NONNULL_END
