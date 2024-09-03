//
//  TBMultipleColumnTableView.h
//  TBTradeBusiness
//
//  Created by chenxin on 2024/5/29.
//

#import <UIKit/UIKit.h>
#import <TBUIKit/TBMultipleColumnViewCell.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TBMultipleColumnViewLeftCircleStyle) {
    TBMultipleColumnViewLeftCircleStyleNone,
    TBMultipleColumnViewLeftCircleStyleSolid,
    TBMultipleColumnViewLeftCircleStyleHollow,
};

@class TBMultipleColumnView;

@protocol TBMultipleColumnViewDelegate <NSObject>

- (nullable NSString *)multipleColumnView:(TBMultipleColumnView *)columnView titleForHeaderAtColumn:(NSInteger)column;

- (CGFloat)multipleColumnView:(TBMultipleColumnView *)columnView cellWidthAtColumn:(NSInteger)column;

- (TBMultipleColumnViewCell *)multipleColumnView:(TBMultipleColumnView *)columnView cellAtRow:(NSInteger)row column:(NSInteger)column;

@optional

- (TBMultipleColumnViewLeftCircleStyle)multipleColumnView:(TBMultipleColumnView *)columnView leftCircleStyleAtRow:(NSInteger)row;

- (void)multipleColumnView:(TBMultipleColumnView *)columnView didSelectCellAtRow:(NSInteger)row column:(NSInteger)column;

@end

/*
 多列视图，左侧固定，右侧可滑动
 暂未实现cell复用逻辑
 */

#define kTBMultipleColumnViewDefaultHorizontalPadding 8

@interface TBMultipleColumnView : UIView

@property (nonatomic, assign) BOOL hasHeaderView; // 是否有标题，默认为YES
@property (nonatomic, assign) CGFloat headerTitleVerticalPadding; // 标题上下边距, 默认为8
@property (nonatomic, copy) NSDictionary *headerTitleAttributes; // 标题样式，默认为字体FONTO(10)，颜色B3

@property (nonatomic, assign) CGFloat horizontalPadding; // 列间左右边距, 默认为8

@property (nonatomic, assign) CGFloat cotentLeftPadding; // 整体内容左边距

@property (nonatomic, assign) CGFloat cotentRightPadding; // 整体内容右边距

@property (nonatomic, assign) NSUInteger topLabelLines; // 上方label展示行数，默认为一行

@property (nonatomic, assign) NSUInteger rowCount; // 行数

@property (nonatomic, assign) NSUInteger leftColumnCount; // 左侧列数

@property (nonatomic, assign) NSUInteger rightColumnCount; // 右侧列数

@property (nonatomic, weak) id <TBMultipleColumnViewDelegate> delegate;

@property (nonatomic, assign) BOOL hasLeftCircle; // 左侧是否有圆圈

- (void)reloadData;

@end

NS_ASSUME_NONNULL_END
