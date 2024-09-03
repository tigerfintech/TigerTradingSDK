//
//  TBStockWarningDisplayModel.h
//  Stock
//
//  Created by yangfan on 2020/2/12.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockWarningDisplayStockInfo : JSONModel

@property (nonatomic, copy) NSString * market;
@property (nonatomic, copy) NSString * symbol;
@property (nonatomic, copy) NSString * name;
@property (nonatomic, copy) NSString * secType;
@property (nonatomic, assign) BOOL globalSwith;

@end

@interface TBStockWarningDisplayCondition : JSONModel

@property (nonatomic, assign) CGFloat threshold;

@end

@interface TBStockWarningDisplayModel : JSONModel

@property (nonatomic, copy) NSString * Id;
@property (nonatomic, assign) NSTimeInterval timestamp;
@property (nonatomic, assign) NSInteger category;
@property (nonatomic, assign) NSInteger alertType;
@property (nonatomic, assign) NSInteger frequency;
@property (nonatomic, assign) BOOL enable;
@property (nonatomic, copy) NSString * message;
@property (nonatomic, strong) TBStockWarningDisplayCondition * condition;

@end

NS_ASSUME_NONNULL_END
