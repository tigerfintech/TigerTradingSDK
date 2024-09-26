//
//  TBHKStockL0PromptView.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/10/12.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//
/*
 港股L0列表footerView提示
 
 */
#import <UIKit/UIKit.h>

static CGFloat const PROMPTVIEWHEIGHT = 70;

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger, HKStockL0PromptViewType) {
    HKStockL0PromptViewTypeOtherList,
    HKStockL0PromptViewTypeWatchList,
    HKStockL0PromptViewTypeWatchListHKGroup,
};

@interface TBHKStockL0PromptView : UIView

@property (nonatomic, assign) HKStockL0PromptViewType promptType;

@end

NS_ASSUME_NONNULL_END
