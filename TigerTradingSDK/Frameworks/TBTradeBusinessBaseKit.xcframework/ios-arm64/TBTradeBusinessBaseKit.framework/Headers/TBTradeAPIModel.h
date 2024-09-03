//
//  TBTradeAPIModel.h
//  Stock
//
//  Created by donggongfu on 16/10/20.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBTradeAPIModel : JSONModel

@property (nonatomic, assign) NSInteger ret;
@property (nonatomic, assign) NSTimeInterval serverTime;
@property (nonatomic, copy, nullable) NSString <Optional> *message;

@end

NS_ASSUME_NONNULL_END

