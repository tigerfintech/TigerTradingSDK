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

/**
 * A helper class for storing user info to help identify a request.
 *
 * This class lets you store both a strong reference and a weak reference for the duration of
 * the request.  The weak reference is special because TBKURLRequestQueue will examine it when
 * you call cancelRequestsWithDelegate to see if the weak object is the delegate in question.
 * For this reason, this object is a safe way to store an object that may be destroyed before
 * the request completes if you call cancelRequestsWithDelegate in the object's destructor.
 */
@interface TTUserInfo : NSObject {
    NSString* _topic;
    id        _strongRef;
    id        __weak _weakRef;
}

@property (nonatomic, copy)   NSString* topic;
@property (nonatomic, strong) id        strongRef;
@property (nonatomic, weak) id        weakRef;

+ (id)topic:(NSString*)topic strongRef:(id)strongRef weakRef:(id)weakRef;
+ (id)topic:(NSString*)topic;
+ (id)weakRef:(id)weakRef;

- (instancetype)initWithTopic:(NSString*)topic strongRef:(id)strongRef weakRef:(id)weakRef NS_DESIGNATED_INITIALIZER;


@end
