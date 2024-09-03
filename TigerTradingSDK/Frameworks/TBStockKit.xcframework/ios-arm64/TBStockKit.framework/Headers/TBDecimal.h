//
//  TBDecimal.h
//  Stock
//
//  Created by 胡金友 on 2018/7/4.
//  Copyright © 2018 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBDecimal : TBBaseModel

- (instancetype)initWithValue:(NSInteger)value offset:(NSInteger)offset;

@property (assign, nonatomic) NSInteger value;

@property (assign, nonatomic) NSInteger offset;

@property (assign, nonatomic, readonly) CGFloat decimalsValue;
@property (retain, nonatomic, readonly) NSNumber *originalNumber;

@property (copy, nonatomic, readonly) NSString *(^displayDecimalWithScale)(short scale);
@property (copy, nonatomic, readonly) NSString *(^displayNumberWithScale)(short scale);

@property (copy, nonatomic, readonly) NSString *displayNumberString;
@property (copy, nonatomic, readonly) NSString *displayDecimalString;

@end

NS_ASSUME_NONNULL_END
