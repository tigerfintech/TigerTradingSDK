//
//  TBBaseModelBuryingPointModel.h
//  Stock
//
//  Created by 王灵博 on 2020/8/11.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>

NS_ASSUME_NONNULL_BEGIN
/*
 用于曝光事件的model
 */
@interface TBBaseModelBuryingPointModel : TBBaseModel

@property(nonatomic, assign) BOOL useNewStatisticMethod;        /// 是否使用新的埋点数据统计方式，默认NO

@property(nonatomic, copy) NSString *market;
@property(nonatomic, copy) NSString *model;
@property(nonatomic, copy) NSString *type;
@property(nonatomic, copy) NSString *sector;

@property(nonatomic, copy) NSString *page;
@property(nonatomic, copy) NSString *component;

@end

NS_ASSUME_NONNULL_END
