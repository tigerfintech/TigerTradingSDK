//
//  TBScreenShotShareView.h
//  Stock
//
//  Created by yangfan on 16/12/20.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol TBScreenShotShareViewDelegate <NSObject>

@optional

- (void)didTappedShareButton;
- (void)screenShotShareViewDidDisappear;

@end

@interface TBScreenShotShareView : UIView

@property (nonatomic, weak) id<TBScreenShotShareViewDelegate>       delegate;

- (void)addToWindow;

- (void)dismiss;

@end
