//
//  TBCombineOptionFundamentalModel.h
//  Stock
//
//  Created by mashanli on 2023/6/15.
//  Copyright (c) 2023 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

@interface TBCombineOptionFundamentalModel : JSONModel

@property (nonatomic, copy) NSString *intrinsicValue;
@property (nonatomic, copy) NSString *timeValue;
@property (nonatomic, copy) NSString *delta;
@property (nonatomic, copy) NSString *theta;
@property (nonatomic, copy) NSString *vega;
@property (nonatomic, copy) NSString *gamma;
@property (nonatomic, copy) NSString *rho;

@property (nonatomic, copy) NSString *breakEvens;
@property (nonatomic, copy) NSString *profitProbabilityString;

@end

