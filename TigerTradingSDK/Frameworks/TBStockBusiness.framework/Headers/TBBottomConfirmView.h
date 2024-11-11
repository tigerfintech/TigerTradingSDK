//
//  TBConfirmView.h
//  Stock
//
//  Created by WCP on 2018/8/13.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM (NSInteger, TBBottomConfirmAction) {
    TBConfirmBottomLeftAction,             //!< 左边按钮的Action
    TBConfirmBottomRightAction,            //!< 右边按钮的Action
};

typedef void(^TBBottomConfirmCallBackBlock)(TBBottomConfirmAction action);

@interface TBBottomConfirmView : UIView

- (void)updateLeftTitle:(NSString *)leftTitle rightTitle:(NSString *)rightTitle callBack:(TBBottomConfirmCallBackBlock)callBack;

@end
