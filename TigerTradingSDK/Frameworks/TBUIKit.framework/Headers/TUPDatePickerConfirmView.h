//
//  TUPDatePickerConfirmView.h
//  Stock
//
//  Created by WCP on 2018/1/24.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import "TBDatePickerConfirmView.h"
#import "TBCommonConfirmView.h"

@interface TUPDatePickerConfirmView : TBCommonConfirmView

@property (nonatomic, strong) UITextField           *startTextField;
@property (nonatomic, strong) UITextField           *endTextField;

@property (nonatomic, strong) NSDate *startDate;
@property (nonatomic, strong) NSDate *endDate;

@property (nonatomic, weak) id <TBDatePickerConfirmViewDelegate>datePickerDelegate;

- (void)backViewCenter;
@end
