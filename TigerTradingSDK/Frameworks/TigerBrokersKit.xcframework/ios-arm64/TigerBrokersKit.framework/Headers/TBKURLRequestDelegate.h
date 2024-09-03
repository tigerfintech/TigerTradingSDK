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

#import "TBKNetworkGlobal.h"

NS_ASSUME_NONNULL_BEGIN

@class TBKURLRequest;
@class TBKURLResponse;

@protocol TBKURLRequestCompletionDelegate <NSObject>

- (void)requestSuccess:(id)responseObject;
- (void)requestFailure:(id)responseObject;

@end

// Interceptor
@protocol TBKURLRequestDelegate <NSObject>
@optional

- (BOOL)requestShouldStartLoad:(TBKURLRequest *)request;
- (void)requestWillStartLoad:(TBKURLRequest *)request;

/**
 * The request has begun loading.
 *
 * This method will not be called if the data is loaded immediately from the cache.
 * @see requestDidFinishLoad:
 */
- (void)requestDidStartLoad:(TBKURLRequest *)request;

/**
 * The request has loaded some more data.
 *
 * Check the totalBytesLoaded and totalBytesExpected properties for details.
 */
- (void)requestDidUploadData:(TBKURLRequest *)request;

- (void)request:(TBKURLRequest *)request willFinishLoadWithResponse:(TBKURLResponse *)response;

/**
 * The request has loaded data and been processed into a response.
 *
 * If the request is served from the cache, this is the only delegate method that will be called.
 */
- (void)request:(TBKURLRequest *)request didFinishLoadWithResponse:(TBKURLResponse *)response;

/**
 * Allows delegate to handle any authentication challenges.
 */
- (void)request:(TBKURLRequest *)request
didReceiveAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge;

// ???: request will/didFailLoad delegate 要不要加 response 参数
- (void)request:(TBKURLRequest *)request willFailLoadWithResponse:(TBKURLResponse *)response error:(NSError *)error;

/**
 * The request failed to load.
 */
- (void)request:(TBKURLRequest *)request didFailLoadWithResponse:(TBKURLResponse *)response error:(NSError *)error;

- (void)requestWillCancelLoad:(TBKURLRequest *)request;

/**
 * The request was canceled.
 */
- (void)requestDidCancelLoad:(TBKURLRequest *)request;

// 可以添加的:
// didReceiveReponse

@end

// TODO: 处理翻页
@protocol TBKNetworkPagableManager <NSObject>

@property (nonatomic, assign) NSInteger pageSize;
@property (nonatomic, assign, readonly) NSUInteger currentPageNumber;
@property (nonatomic, assign, readonly) BOOL isFirstPage;
@property (nonatomic, assign, readonly) BOOL isLastPage;

- (void)loadNextPage;

@end


@protocol TBKNetworkValidator <NSObject>
@required
- (BOOL)request:(TBKURLRequest *_Nonnull)request validateParameters:(NSDictionary *_Nonnull)parameters;
- (BOOL)request:(TBKURLRequest *_Nonnull)manager validateResponseObject:(id)responseObject;
@end


NS_ASSUME_NONNULL_END
