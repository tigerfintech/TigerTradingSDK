//
//  TBStockListOneRowView.h
//  Stock
//
//  Created by zhenglanchun on 2021/5/20.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBStockBusinessBaseKit/TBStockListBaseView.h>

NS_ASSUME_NONNULL_BEGIN

/*
    一行布局的样式：
    ｜- (leftImageView,leftLabel) - (middleTopLabel, middleTwoLabel) - rightTopLabel - |
 */

@interface TBStockListOneRowView : TBStockListBaseView

@property (nonatomic, strong) UIImageView * leftOneImageView;
@property (nonatomic, strong) UILabel *leftTwoLabel;

@property (nonatomic, strong) UILabel *middleTopOneLabel;

@property (nonatomic, strong) UILabel *middleTopTwoLabel;

@property (nonatomic, strong) UILabel *rightTopLabel;

@property (nonatomic, assign) BOOL leftOneImageViewHidden;

@property (nonatomic, assign) CGSize leftOneImageSize;

@end

NS_ASSUME_NONNULL_END
