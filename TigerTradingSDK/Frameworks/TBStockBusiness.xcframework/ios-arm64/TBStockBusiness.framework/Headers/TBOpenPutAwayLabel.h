//
//  TBOpenPutAwayLabel.h
//  YYLabelDemo
//
//  Created by 王灵博 on 2021/12/23.
//  Copyright © 2021 100uu. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
/*
 展开收起label
 */
@interface TBOpenPutAwayLabel : UIView
@property(nonatomic, strong)UIFont *textFont;//内容
@property(nonatomic, strong)UIFont *OpenPutAwayFont;//展开收起文字Font
@property(nonatomic, strong)UIColor *textColor;
@property(nonatomic, strong)UIColor *OpenPutAwayColor;
@property(nonatomic, strong)NSString *openText;//默认为展开
@property(nonatomic, strong)NSString *putAwayText;//默认为收起
@property(nonatomic, strong)NSString *content;
@property(nonatomic, assign)NSInteger numberOfLines;
@end

NS_ASSUME_NONNULL_END
