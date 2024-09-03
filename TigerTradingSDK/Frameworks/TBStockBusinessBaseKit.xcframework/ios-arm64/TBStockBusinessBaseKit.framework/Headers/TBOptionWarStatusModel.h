//
//  TBOptionWarStatusModel.h
//  Stock
//
//  Created by WCP on 2018/8/15.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

@interface TBOptionWarStatusDataModel : JSONModel

@property (nonatomic, strong) NSNumber *status;   //!< 1 为未答题；2 为答题通过未签名 ； 3 为答题通过且已签名
@property (nonatomic, strong) NSNumber *opt_perm; //!<  0 为客户未开通期权交易 1为客户开通期权交易
@property (nonatomic, strong) NSNumber *error_code; 

@property (nonatomic, copy) NSString *error_message; 
@property (nonatomic, copy) NSString *error_description;
@property (nonatomic, copy) NSString *error; 
@end

@interface TBOptionWarStatusModel : JSONModel
@property (nonatomic, strong) NSNumber *is_succ;
@property (nonatomic, strong) TBOptionWarStatusDataModel *data;
@end
