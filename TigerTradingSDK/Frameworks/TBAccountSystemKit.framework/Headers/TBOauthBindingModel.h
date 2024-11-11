//
//  TBOauthBindingModel.h
//  Stock
//
//  Created by 马超 on 2017/7/31.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

@class TBOAuthStatusSnsStatusModel;

@interface TBOauthDataModel : JSONModel

@property (nonatomic, strong) TBOAuthStatusSnsStatusModel *sns_status;
@property (nonatomic, assign) BOOL phone;
@property (nonatomic, assign) BOOL email;
@property (nonatomic, copy) NSString *error_description;
@property (nonatomic, copy) NSString *error_message;
@property (nonatomic, strong) NSNumber *error_code;
@property (nonatomic, copy) NSString *error;
@end

@interface TBOauthBindingModel : JSONModel

@property (nonatomic, strong) TBOauthDataModel *data;
@property (nonatomic, assign) BOOL is_succ;

@end
