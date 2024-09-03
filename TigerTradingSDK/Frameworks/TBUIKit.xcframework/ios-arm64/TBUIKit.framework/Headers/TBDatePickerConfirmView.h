//
//  TBDatePickerConfirmView.h
//  Stock
//
//  Created by WCP on 2018/1/24.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

typedef NS_ENUM(NSInteger, TBDatePickerSelectedRow) {
    TBDatePickerSelectedOne,
    TBDatePickerSelectedTwo,
};

@protocol TBDatePickerConfirmViewDelegate<NSObject>

- (void)datePickerConfirmViewSelected:(TBDatePickerSelectedRow)selectedRow;
@end 

#import "TBCommonConfirmView.h"

@interface TBDatePickerConfirmView : TBCommonConfirmView

@property (nonatomic, strong) UITextField           *startTextField;
@property (nonatomic, strong) UITextField           *endTextField;

@property (nonatomic, weak) id <TBDatePickerConfirmViewDelegate>datePickerDelegate;

- (void)backViewCenter;
@end
