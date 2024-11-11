//
//  TBStockSheetView.h
//  Stock
//
//  Created by luopengfei on 2018/8/15.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TBStockSheetView : UIView
@property (nonatomic, copy) NSArray *titles;
@property (nonatomic, copy) NSArray <NSArray <NSString *> *> *values;

@property (nonatomic, assign) CGFloat verticalTitleWidth;   // 左侧纵向标题宽度
@property (nonatomic, assign) CGFloat itemHeight;       // 每行的高度
@property (nonatomic, assign) CGFloat contentWidth;     // 内容区每个item的宽度

@property (nonatomic, strong) UIColor *titleColor;  // 横竖标题的颜色
@property (nonatomic, strong) UIColor *contentColor;    // 内容颜色，collectionView里的item
@end
