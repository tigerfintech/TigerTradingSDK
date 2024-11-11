//
//  TBStockObliqueLineProgressView.h
//  press
//
//  Created by 王灵博 on 2020/7/10.
//  Copyright © 2020 Tiger. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockObliqueLineProgressView : UIView
@property(nonatomic, assign)CGFloat obliqueOffset;//倾斜几像素
@property(nonatomic, assign)CGFloat distance;//间距
@property(nonatomic, strong)UIColor *redColor;//红
@property(nonatomic, strong)UIColor *equalColor;//平色
@property(nonatomic, strong)UIColor *greenColor;//绿
@property(nonatomic, assign)BOOL hasCornerRadius;//是否有圆角
@property(nonatomic, assign)BOOL isFollowSetting;//是否跟随用户设置红涨绿跌或红跌绿涨改变颜色，默认跟随用户设置
- (void)setUpPersent:(float)upPersent
         downPersent:(float)downPersent
        equalPersent:(float)equalPersent;
@end

NS_ASSUME_NONNULL_END
