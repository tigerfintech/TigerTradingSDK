//
//  TBViewExposureDataSource.h
//  Stock
//
//  Created by 王昌阳 on 2020/6/27.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#ifndef TBViewExposureDataSource_h
#define TBViewExposureDataSource_h

typedef NS_ENUM(NSUInteger, TBViewExposureStrategy) {
    TBViewExposureStrategyAll  = 0,        ///< 统计策略 - 全部露出，100% 露出
    TBViewExposureStrategyPart = 1,        ///< 统计策略 - 部分露出，(默认露出 100 高度) 露出；1、内容高度 小于 显示区域高度 部分露出，2、内容高度 大于 显示区域高度 部分露出
};

typedef NS_ENUM(NSUInteger, TBViewScrollDirection) {
    TBViewScrollDirectionVertical = 0,      ///< 竖直方向滚动
    TBViewScrollDirectionHorizental = 1,    ///< 水平方向滚动
};

@protocol TBViewExposureDataSource <NSObject>

@required
@property (nonatomic, assign) CGFloat viewHeight;///< 曝光 view 的高度，默认 cell 的高度
@property (nonatomic, assign) BOOL shouldStatisViewExposure;///< 是否应该统计曝光，默认不曝光
@property (nonatomic, weak, readonly) UIScrollView *exposureScrollView;///< 所在滚动视图
@property (nonatomic, strong, readonly) NSIndexPath *exposureItemIndexPath;///< 曝光 item 所在位置

#pragma mark - 判断是否统计曝光所需条件
@optional

@property (nonatomic, copy, readonly) NSString *model;///< 业务
@property (nonatomic, copy, readonly) NSString *type;///< 维度
@property (nonatomic, copy, readonly) NSString *sector;///< 模块

@property (nonatomic, copy, readonly) NSString *page;
@property (nonatomic, copy, readonly) NSString *component;

@property (nonatomic, assign, readonly) BOOL useNewStatisticMethod; /// Default:NO

@property (nonatomic, assign) CGFloat exposureFixedHeight;///< 曝光 view 露出的高度，曝光策略 = 0时，exposureFixedHeight 为view height，否则默认露出 100
@property (nonatomic, assign) TBViewExposureStrategy exposureStrategy;///< 曝光策略
@property (nonatomic, assign) TBViewScrollDirection scrollDirection;///< 滚动方向

@property (nonatomic, assign) BOOL debugMode;///< 输出 log

@property (nonatomic, copy, readonly) NSString *event;

@property (nonatomic, copy, readonly) NSDictionary *eventInfo;

@end


#endif /* TBViewExposureDataSource_h */
