//
//  TBSNInquiryHistoryDatePicker.h
//  TBTradeBusiness
//
//  Created by 秦晓强 on 2023/10/12.
//

#import <TBUIKit/TBView.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TBDatePickPeriod) {
    TBDatePickPeriodNone = 0,
    TBDatePickPeriodFundAll,
    TBDatePickPeriodOneWeek,
    TBDatePickPeriodOneMonth,
    TBDatePickPeriodThreeMonths,
    TBDatePickPeriodSixMonths,
    TBDatePickPeriodOneYear,
};

typedef void (^DatePickDoneCallBack) (NSDate *startDate,NSDate *endDate, NSString *startDateString, NSString *endDateString);
typedef void (^DatePickSelectedCallBack) (NSDate *date);
typedef void (^DatePickDoneCloseBack) (void);

@interface TBSNInquiryHistoryDatePicker : TBView
#pragma mark -  common

@property (nonatomic, strong) NSDate *minimumDate;

@property (nonatomic, strong) NSDate *maximumDate;

@property (nonatomic, copy) DatePickDoneCloseBack closeBlock;

/// datePicker 所需高度
- (CGFloat)contentHeight;

#pragma mark - 时间段选择器
/// 时间段择器初始化方法
/// - Parameters:
///   - title: 标题
///   - periods: 快捷选择的周期
///   - closeButtonTitle: 取消按钮 title
///   - needBottomCorner: 是否需要底部圆角
- (instancetype)initWithTitle:(nullable NSString *)title
                      periods:(nullable NSArray <NSNumber *> *)periods
             closeButtonTitle:(nullable NSString *)closeButtonTitle
             needBottomCorner:(BOOL)needBottomCorner;

- (instancetype)initWithTitle:(nullable NSString *)title 
                      periods:(nullable NSArray <NSNumber *> *)periods
             closeButtonTitle:(nullable NSString *)closeButtonTitle
             needBottomCorner:(BOOL)needBottomCorner
                  minimumDate:(NSDate *)minimumDate
                  maximumDate:(NSDate *)maximumDate;

/// 设置选中周期
/// - Parameter period: 周期
- (void)updateSelectedPeriod:(TBDatePickPeriod)period;

/// 设置其实日期
/// - Parameters:
///   - startDate: 开始日期
///   - endDate: 结束日期
- (void)updateWithStartDate:(nullable NSDate *)startDate endDate:(nullable NSDate *)endDate;

/// 激活开始日期选择
- (void)activeStartDatePicker;

/// 激活结束日期选择
- (void)activeEndDatePicker;

@property (nonatomic, copy) DatePickDoneCallBack doneBlock;

#pragma mark - 日期选择器

- (instancetype)initWithTitle:(nullable NSString *)title closeButtonTitle:(nullable NSString *)closeButtonTitle needBottomCorner:(BOOL)needBottomCorner;

@property (nonatomic, copy) DatePickSelectedCallBack selectedBlock;

- (void)activeSelectedDate:(NSDate *)date;

- (void)updateBackViewColor:(UIColor *)color;

@end

NS_ASSUME_NONNULL_END
