//
//  TBWebViewProgressView.h
//  Stock
//
//  Created by chenxin on 2019/6/4.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TBWebViewProgressView : UIProgressView

- (void)start;
- (void)finish;
- (void)fail;
- (void)stop;

@end
