//
//  TBOpenAccountPickerView.h
//  StockGlobal
//
//  Created by CharmingQin on 2018/11/12.
//  Copyright © 2018 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>


// MARK : 由于mmpicker 的barbuttonItem无法修改title，存在循环引用， UI可能不符合设计等，仿制了一个picker类，后续可能会继续修改。

NS_ASSUME_NONNULL_BEGIN

extern NSString * const TBbackgroundColor;
extern NSString * const TBtextColor;
extern NSString * const TBtoolbarColor;
extern NSString * const TBbuttonColor;
extern NSString * const TBfont;
extern NSString * const TBvalueY;
extern NSString * const TBselectedObject;
extern NSString * const TBtoolbarBackgroundImage;
extern NSString * const TBtextAlignment;
extern NSString * const TBshowsSelectionIndicator;
extern NSString * const TBPickerLeftTitle;
extern NSString * const TBPickerRightTitle;
extern NSString * const TBPickerBorderColor;

@interface TBOpenAccountPickerView: UIView

+ (void)showPickerViewInView: (UIView *)view
                withStrings: (NSArray *)strings
                withOptions: (NSDictionary *)options
                 completion: (void(^__nullable)(NSArray *selectedString))completion
             doneCompletion: (void(^)(NSArray *selectedObject))doneCompletion;


+ (void)dismissWithCompletion: (void(^__nullable)(NSArray *))completion;

+ (void)doneWithCompletion: (void(^)(NSArray *))completion;

@end

NS_ASSUME_NONNULL_END
