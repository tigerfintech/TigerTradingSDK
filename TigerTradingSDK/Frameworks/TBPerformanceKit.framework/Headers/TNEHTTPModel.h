//
//  TNEHTTPModel.h
//  TigerNetworkEye
//
//  Created by 骆朋飞 on 2017/6/4.
//  Refactored by donggongfu on 2021/12/29
//  Copyright © 2021 Tiger Brokers. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TNEHTTPModel : NSObject

@property (nonatomic, strong) NSURLRequest *tne_request;
@property (nonatomic, strong) NSHTTPURLResponse *tne_response;
@property (nonatomic, strong) NSDate *startDate;
@property (nonatomic, strong) NSDate *endDate;
@property (nonatomic, copy) NSString *startDateString;
@property (nonatomic, copy) NSString *endDateString;

// request
@property (nonatomic, copy) NSString *requestURLString;
@property (nonatomic, copy) NSString *requestCachePolicy;
@property (nonatomic, assign) double requestTimeoutInterval;
@property (nonatomic, nullable, copy) NSString *requestHTTPMethod;
@property (nonatomic, nullable, copy) NSString *requestAllHTTPHeaderFields;
@property (nonatomic, nullable, copy) NSString *requestHTTPBody;

// response
@property (nonatomic, nullable, copy) NSString *responseMIMEType;
@property (nonatomic, copy) NSString * responseExpectedContentLength;
@property (nonatomic, nullable, copy) NSString *responseTextEncodingName;
@property (nonatomic, nullable, copy) NSString *responseSuggestedFilename;
@property (nonatomic, assign) NSInteger responseStatusCode;
@property (nonatomic, nullable, copy) NSString *responseAllHeaderFields;

// JSONData
@property (nonatomic, copy) NSString *receiveJSONData;

// error
@property (nonatomic, strong) NSError *error;
// 时间指标
@property (nonatomic, strong) NSURLSessionTaskMetrics *metrics  API_AVAILABLE(ios(10.0));

- (void)tb_setTne_request:(NSURLRequest *)tne_request_new;

@end

NS_ASSUME_NONNULL_END

