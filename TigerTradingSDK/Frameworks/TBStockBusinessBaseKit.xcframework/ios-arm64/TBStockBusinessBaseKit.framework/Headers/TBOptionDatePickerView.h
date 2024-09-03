//
//  TBOptionDatePickerView.h
//  Stock
//
//  Created by luopengfei on 2018/4/20.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol TBOptionDatePickerViewDelegate;

//这个类仅限期权链里使用
@interface TBOptionDatePickerView : UIView

@property (nonatomic, weak) id<TBOptionDatePickerViewDelegate> delegate;

/*
 * 在期权链中，dateItems是二维数组[[TBOptionExpiryItemModel]]
 */
@property (nonatomic, copy) NSArray *dateItems;//[[TBOptionExpiryItemModel]]
@property (nonatomic, assign) NSInteger selectedIndex;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, assign) CGFloat itemWith;
@property (nonatomic, assign) BOOL disableAdjustOffset;

- (void)reloadData;

@end


@protocol TBOptionDatePickerViewDelegate

- (void)pickView:(TBOptionDatePickerView *)pickerView didSelectedIndex:(NSInteger)selectedIndex;

@end
