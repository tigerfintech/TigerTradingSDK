//
//  TBStockListTwoRowView.h
//  Stock
//
//  Created by zhenglanchun on 2021/5/20.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import "TBStockListBaseView.h"
@class YYLabel;
@class TBSingleLineView;

NS_ASSUME_NONNULL_BEGIN

/*
    上下布局的样式：
    ｜- leftTopLabel - (middleTopLabel, middleTwoLabel) - rightTopLabel - |
    ｜- (leftBottomOneIV - leftBottomTwoLabel - leftBottomThreeIV) - (xxx, xxx) - xxx - |
 */

@interface TBStockListTwoRowView : TBStockListBaseView

@property (nonatomic, strong) YYLabel *leftTopLabel;
@property (nonatomic, strong) UIImageView * leftBottomOneImageView;
@property (nonatomic, strong) YYLabel *leftBottomTwoLabel;
// 默认关注爱心icon
@property (nonatomic, strong) UIImageView *leftBottomThreeImageView;

@property (nonatomic, strong) UILabel *middleTopOneLabel;
@property (nonatomic, strong) UILabel *middleBottomOneLabel;

@property (nonatomic, strong) UILabel *middleTopTwoLabel;
@property (nonatomic, strong) UILabel *middleBottomTwoLabel;

@property (nonatomic, strong) UILabel *rightTopLabel;
@property (nonatomic, strong) UILabel *rightBottomLabel;

@property (nonatomic, strong) TBSingleLineView *singleLineView;

- (void)updateMiddleBottomOneLabelLeading: (CGFloat)leading;
- (void)updateRightBottomLabelLeading: (CGFloat)leading;
- (void)updateLeftBottomTwoLabelLeading: (CGFloat)leading;

@end

NS_ASSUME_NONNULL_END
