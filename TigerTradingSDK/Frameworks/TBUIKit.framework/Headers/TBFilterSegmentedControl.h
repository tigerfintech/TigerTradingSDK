//
//  TBFilterSegmentedControl.h
//  TBUIKit
//
//  Created by chenxin on 2023/11/2.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TBFilterSegmentedControlSegmentWidthStyle) {
    TBFilterSegmentedControlSegmentWidthStyleFixed, // 固定宽度
    TBFilterSegmentedControlSegmentWidthStyleSelectedDynamic, // 选中的Segment动态宽度，其他固定宽度
};

typedef NS_ENUM(NSUInteger, TBFilterSegmentedControlSegmentStyle) {
    TBFilterSegmentedControlSegmentStyleDefault, // 默认显示value（两行）
    TBFilterSegmentedControlSegmentStyleWithoutValue, // 不显示value (一行）
};

typedef void (^TBFilterSegmentedControlIndexChangeBlock)(NSInteger index);

@interface TBFilterSegmentModel : NSObject <NSCopying>

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *value;

@property (nonatomic, assign) NSInteger rowCount; // 当前行中，items的数量
@property (nonatomic, assign) BOOL isSelected; // 当前item是否被选中，默认NO
@property (nonatomic, assign) BOOL isArrowEnableOnOneRow; // 只有单个数据时，是否展示下三角箭头，默认YES

@property (nonatomic, copy) NSArray<NSDictionary *> *items;
@property (nonatomic, assign) NSUInteger selectedItemIndex;

@end

@interface TBFilterSegmentView : UIView

@property (nonatomic, assign) NSInteger numberOfLines; // 默认1
@property (nonatomic, strong) TBFilterSegmentModel *model;
@property (nonatomic, assign) TBFilterSegmentedControlSegmentStyle segmentStyle;

@end

@interface TBFilterSegmentedControl : UIView

@property (nonatomic, assign) TBFilterSegmentedControlSegmentWidthStyle segmentWidthStyle;

@property (nonatomic, assign) TBFilterSegmentedControlSegmentStyle segmentStyle;

@property (nonatomic, assign) BOOL showBottomLine;      /// Default NO

/// 当前选中的idx, 默认：-1 无选中idx
@property (nonatomic, assign, readonly) NSInteger selectedIndex;

@property (nonatomic, strong) TBFilterSegmentedControlIndexChangeBlock indexChangeBlock;

@property (nonatomic, copy) NSArray<TBFilterSegmentModel *> *filterSegments;

- (void)updateSelectedSegmentValue:(NSString *)value;

@end

NS_ASSUME_NONNULL_END

