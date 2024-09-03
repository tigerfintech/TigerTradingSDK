//
//  TBTableEmptyView.h
//  Stock
//
//  Created by liwt on 14/12/18.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBUIKit/TBEmptyView.h>

/*
 为了兼容，TBTableEmptyView继承TBEmptyView
 旧代码仍使用以下方法设置标题和图片，新代码使用TBEmptyView中的方法设置
 */

@interface TBTableEmptyView : TBEmptyView

@property (nonatomic, strong, readonly) UILabel *msgLabel;
@property (nonatomic, strong, readonly) UIImageView *imageView;

@property (nonatomic, copy) NSString *msg;
@property (nonatomic, strong) UIImage *image;

- (void)setImageViewSize:(CGSize)size;

@end
