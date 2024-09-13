//
//  TBOptionDetailIVIndexModel.h
//  Stock
//
//  Created by JustLee on 2020/11/30.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionDetailIVIndexModel : TBBaseModel

@property (nonatomic, strong) NSNumber *impliedVol;
@property (nonatomic, strong) NSNumber *time;//时间戳
@property (nonatomic, strong) NSNumber *volatility;
@property (nonatomic, strong) NSNumber *volatilityPremium;//波动率溢价
@property (nonatomic, copy) NSString *timeStr;//年月日
@property (nonatomic, copy) NSString *market;//时间戳

@end

NS_ASSUME_NONNULL_END
