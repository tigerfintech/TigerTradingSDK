//
//  TBCheckBoxConfirmView.h
//  Stock
//
//  Created by yangfan on 2019/7/25.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import "TBCommonConfirmView.h"

NS_ASSUME_NONNULL_BEGIN

@class TBCheckBoxConfirmView;

@protocol TBCheckBoxConfirmViewDelegate <TBCommonConfirmViewDelegate>

@optional
- (void)checkBoxConfirmView:(TBCheckBoxConfirmView *)checkBoxConfirmView didSelectedAtIndex:(NSInteger)index checkBoxSelected:(BOOL)selected;

@end

@interface TBCheckBoxConfirmView : TBCommonConfirmView

@property (nonatomic, assign, readonly) BOOL    isCheckBoxSelected;
@property (nonatomic, copy) NSString          * checkboxMessage;
@property (nonatomic, strong) UIColor *checkboxMessageColor;
@property (nonatomic, strong) UIButton        * checkboxButton;
@property (nonatomic, copy) void(^checkboxButtonBlock)(BOOL isSelected);
@property (nonatomic, copy) void(^checkboxMessageBlock)(void);

@property (nonatomic, assign) BOOL disableDismiss;

@property (nonatomic, weak) id<TBCheckBoxConfirmViewDelegate> checkBoxDelegate;

@property (nonatomic, copy) void(^checkBoxSelectedBlock)(TBCheckBoxConfirmView *confirmView, NSInteger index, BOOL selected);
-(void)setcheckboxMessage:(NSString *)checkboxMessage left:(CGFloat)left;
@end

NS_ASSUME_NONNULL_END
