//
// Copyright 2009-2011 Facebook
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <Foundation/Foundation.h>

#define TBK_DEFAULT_CACHE_INVALIDATION_AGE (60*60*24)    // 1 day
#define TBK_DEFAULT_CACHE_EXPIRATION_AGE   (60*60*24*7)  // 1 week
#define TBK_CACHE_EXPIRATION_AGE_NEVER     (1.0 / 0.0)   // inf

// TODO: 测试环境和线上环境
typedef NS_ENUM (NSInteger, TBKNetworkEnvironmentType) {
    TBKNetworkEnvironmentTest = 1,
    TBKNetworkEnvironmentOnline,
    TBKNetworkEnvironmentDevelopment,
    TBKNetworkEnvironmentTemp
};

extern NSString * _Nonnull const TBKNetworkHttpMethodGET;
extern NSString * _Nonnull const TBKNetworkHttpMethodHEAD;
extern NSString * _Nonnull const TBKNetworkHttpMethodPOST;
extern NSString * _Nonnull const TBKNetworkHttpMethodPUT;
extern NSString * _Nonnull const TBKNetworkHttpMethodPATCH;
extern NSString * _Nonnull const TBKNetworkHttpMethodDELETE;


// FIXME: 未使用
extern NSString * _Nonnull const kCTAPIBaseManagerRequestID; // 请求id，不需要单独存放一个key

// notification name
extern NSString * _Nonnull const kTBKNetworkUserTokenInvalidNotification;
extern NSString * _Nonnull const kTBKNetworkUserTokenIllegalNotification;
extern NSString * _Nonnull const kTBKNetworkUserTokenNotificationUserInfoKeyRequestToContinue; // 刷新 token 后要继续执行的请求，暂时只支持网络请求


/**
 * Increment the number of active network requests.
 *
 * The status bar activity indicator will be spinning while there are active requests.
 *
 * @threadsafe
 */
void TTNetworkRequestStarted(void);

/**
 * Decrement the number of active network requests.
 *
 * The status bar activity indicator will be spinning while there are active requests.
 *
 * @threadsafe
 */
void TTNetworkRequestStopped(void);

///////////////////////////////////////////////////////////////////////////////////////////////////
// Images

#define TTIMAGE(_URL) [[TTURLCache sharedCache] imageForURL:_URL]
