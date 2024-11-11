//
//  TBLoginApiModel.h
//  Stock
//
//  Created by WCP on 2018/7/26.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

@interface TBLoginApiDataModel : JSONModel

@property (nonatomic, copy) NSString *message;               //!< 请求成功带回的消息

/**
 请求失败带回的消息
 */
@property (nonatomic, copy) NSString *error_description;
@property (nonatomic, copy) NSString *error_message;
@property (nonatomic, copy) NSString *error_code;
@property (nonatomic, copy) NSString *error;

@end

@interface TBLoginApiModel : JSONModel

@property (nonatomic, strong) NSNumber *is_succ;              //!< 请求成功失败的标志

@property (nonatomic, strong) TBLoginApiDataModel *data;      //!< 带回的数据

@end


