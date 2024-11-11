//
//  TBMinTickModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/25.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBMinTickModel <NSObject>

@end
@interface TBMinTickModel : JSONModel

@property (nonatomic, copy, nullable) NSString <Optional> *begin;
@property (nonatomic, copy, nullable) NSString <Optional> *end;
@property (nonatomic, strong, nullable) NSNumber <Optional> *minTick;

/// 最小价格单位
@property (nonatomic, strong, nullable) NSNumber <Optional> *tickSize;

/// 区间类型，开区间，闭区间，左开右闭，左闭右开
/// 区间类型 OPEN_INTERVAL/LEFT_CLOSE_RIGHT_OPEN/LEFT_OPEN_RIGHT_CLOSE/CLOSE_INTERVAL
@property (nonatomic, copy, nullable) NSString<Optional> *type;


@end

NS_ASSUME_NONNULL_END
