//
//  TBDatePickerSuspendView.h
//  TBTradeBusinessBaseKit
//
//  Created by wind on 2024/2/7.
//

#import <UIKit/UIKit.h>

@class TBSNInquiryHistoryDatePicker;

NS_ASSUME_NONNULL_BEGIN

@interface TBDatePickerSuspendView : UIView

- (instancetype)initWithDatePicker:(TBSNInquiryHistoryDatePicker *)datePicker;

@property (nonatomic, copy) void (^maskViewTapBlock)(void);

@end

NS_ASSUME_NONNULL_END
