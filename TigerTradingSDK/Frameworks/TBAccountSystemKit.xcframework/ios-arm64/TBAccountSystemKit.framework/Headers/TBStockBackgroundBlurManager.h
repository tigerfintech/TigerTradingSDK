//
//  TBStockBackgroundBlurManager.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/5/11.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockBackgroundBlurManager : NSObject

DECLARE_SHARED_INSTANCE(TBStockBackgroundBlurManager);

- (void)blurScreenShot;

- (void)showBlurView;
- (void)hiddenBlurView;

@end

NS_ASSUME_NONNULL_END
