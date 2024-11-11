//
//  TBMaterialBannerCellItem.h
//  Stock
//
//  Created by chenxin on 2018/12/5.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCellItem.h>
#import <TBUIKit/TBTableViewCell.h>

@interface TBMaterialBannerCellItem : TBTableViewCellItem

@property (nonatomic, assign) BOOL timerLoop;//是否启用自动轮播，默认不启用
@property (nonatomic, copy) NSArray<NSString *> *bannerArray; // 图片url数组
@property (nonatomic, copy) NSArray<NSNumber *> *couldCloseArray; // 对应图片是否可关闭
@property (nonatomic, strong) void(^bannerActionBlock)(NSInteger bannerIndex);
@property (nonatomic, strong) void(^bannerShowBlock)(NSInteger bannerIndex);
@property (nonatomic, strong) void(^bannerCloseBlock)(NSInteger bannerIndex);
@property (nonatomic, strong) UIColor *cellBackgroundColor;
@property (nonatomic, strong) NSNumber *imageAspect; ///< 图片高宽比

@end

@interface TBMaterialBannerCell : TBTableViewCell

@end
