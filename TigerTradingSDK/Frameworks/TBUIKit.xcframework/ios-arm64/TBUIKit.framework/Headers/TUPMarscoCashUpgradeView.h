//
//  TUPMarscoCashUpgradeView.h
//  StockGlobal
//
//  Created by wind on 2021/4/22.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TUPMarscoCashUpgradeView : UIView

- (void)showInView:(UIView *)view confirm:(void(^)(void))confirm cancel:(void(^)(void))cancel;

@end

NS_ASSUME_NONNULL_END
