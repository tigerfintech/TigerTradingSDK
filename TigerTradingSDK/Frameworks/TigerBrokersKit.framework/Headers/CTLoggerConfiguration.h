//
//  CTLogConfig.h
//  CTLogTrackCenter
//
//  Created by Softwind.Tang on 14-5-15.
//  Copyright (c) 2014年 casatwy Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CTLoggerConfiguration : NSObject

/** 渠道ID */
@property (nonatomic, copy) NSString *channelID;

/** app标志 */
@property (nonatomic, copy) NSString *appKey;

/** app名字 */
@property (nonatomic, copy) NSString *logAppName;

/** 服务名 */
@property (nonatomic, copy) NSString *serviceType;

/** 记录log用到的webapi方法名 */
@property (nonatomic, copy) NSString *sendLogMethod;

/** 记录action用到的webapi方法名 */
@property (nonatomic, copy) NSString *sendActionMethod;

/** 发送log时使用的key */
@property (nonatomic, copy) NSString *sendLogKey;

/** 发送Action记录时使用的key */
@property (nonatomic, copy) NSString *sendActionKey;

//- (void)configWithAppType:(CTAppType)appType;

@end
