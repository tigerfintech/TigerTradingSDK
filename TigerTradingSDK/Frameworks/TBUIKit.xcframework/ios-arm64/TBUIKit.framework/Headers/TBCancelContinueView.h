//
//  TBCancelContinueView.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/5/26.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBCancelContinueView : UIView


@property (nonatomic, copy) void (^cancelButtonAction)(void);
@property (nonatomic, copy) void (^continueButtonAction)(void);

@property (nonatomic, copy) NSString *continueBtnTitle;
@property (nonatomic, copy) NSString *cancelBtnTitle;

@property (nonatomic, strong) UIFont *continueBtnTitleFont;
@property (nonatomic, strong) UIFont *cancelBtnTitleFont;

- (void)hideCancelBtn;

@end

NS_ASSUME_NONNULL_END
