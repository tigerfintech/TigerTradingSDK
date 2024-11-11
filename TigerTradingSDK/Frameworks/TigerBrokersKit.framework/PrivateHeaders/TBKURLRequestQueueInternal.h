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

#import "TigerBrokersKit/TBKURLRequestQueue.h"

@class TBKRequestLoader;
@class TBKURLResponse;

/**
 * The internal interface for the TBKRequestLoaders to interact with the TBKURLRequestQueue.
 */
@interface TBKURLRequestQueue (TBKRequestLoader)

- (void)loader:(TBKRequestLoader *)loader didReceiveAuthenticationChallenge: (NSURLAuthenticationChallenge *)challenge;

- (void)loader:(TBKRequestLoader *)loader didLoadResponse:(NSHTTPURLResponse *)response;
- (void)loader:(TBKRequestLoader *)loader didLoadResponse:(NSHTTPURLResponse *)response data:(id)data error:(NSError *)error;

- (void)loader:(TBKRequestLoader *)loader didLoadUnmodifiedResponse:(NSHTTPURLResponse *)response;
- (void)loader:(TBKRequestLoader *)loader didLoadUnmodifiedResponse:(NSHTTPURLResponse *)response data:(id)data error:(NSError *)error;

- (void)loader:(TBKRequestLoader *)loader didFailLoadWithError:(NSError *)error;
- (void)loader:(TBKRequestLoader *)loader didFailLoadResponse:(NSHTTPURLResponse *)response data:(id)data error:(NSError *)error;

- (void)loaderDidCancel:(TBKRequestLoader *)loader wasLoading:(BOOL)wasLoading;

@end
