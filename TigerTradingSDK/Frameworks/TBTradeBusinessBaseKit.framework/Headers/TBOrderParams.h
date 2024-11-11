//
//  TBOrderParams.h
//  TBTradeBusiness
//
//  Created by swordzhou on 2022/10/17.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBOrderParams;

@interface TBOrderParams : JSONModel

@property (nonatomic, copy, nullable) NSString *type;

@property (nonatomic, strong, nullable) NSNumber <Optional> *startTime;         //(TWAP和VWAP专用)生效开始时间(时间戳) 单位:毫秒
@property (nonatomic, strong, nullable) NSNumber <Optional> *endTime;           //(TWAP和VWAP专用)生效结束时间(时间戳) 单位:毫秒
@property (nonatomic, strong, nullable) NSNumber <Optional> *participationRate; //(VWAP专用)参与率(0.01-0.5)

@property (nonatomic, copy, nullable) NSString *settlementPeriod; // 换汇记录标签，T+0/T+2

- (NSDictionary *)toParams;

@end

NS_ASSUME_NONNULL_END
