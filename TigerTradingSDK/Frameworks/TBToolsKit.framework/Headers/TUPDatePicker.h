//
//  TUPDatePicker.h
//  StockGlobal
//
//  Created by linbingjie on 2021/1/19.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#define TBASDK_DATEPICKER_MIN_HIEGHT 140

@class TUPDatePicker;

typedef void(^TBPickerActionDateDoneBlock)(TUPDatePicker *picker, NSDate *selectedDate);
typedef void(^TBPickerActionDateCancelBlock)(TUPDatePicker *picker);

@protocol TBDatePickerDelegate <NSObject>

- (void)datePickerDone:(TUPDatePicker *)picker date:(NSDate *)date;
- (void)datePickerCancel;

@end

@interface TUPDatePicker : UIView

@property (nonatomic, weak) id<TBDatePickerDelegate> delegate;
@property (nonatomic, assign) BOOL showMask;
@property (nonatomic, weak) UIDatePicker *datePicker;
@property (nonatomic, copy) TBPickerActionDateDoneBlock onActionSheetDone;
@property (nonatomic, copy) TBPickerActionDateCancelBlock onActionSheetCancel;

@end


NS_ASSUME_NONNULL_END
