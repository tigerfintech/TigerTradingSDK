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

// UI
#import "TigerBrokersKit/TBKURLPattern.h"
#import "TigerBrokersKit/TBKNavigationMode.h"

@interface TBKURLNavigatorPattern : TBKURLPattern {
//    Class             __weak _targetClass;
//    id                __weak _targetObject;
    TBKNavigationMode  _navigationMode;
//    NSString*         _parentURL;
//    NSInteger         _transition;
//    NSInteger         _argumentCount;
}

@property (nonatomic, assign)   Class             targetClass;
@property (nonatomic, weak)     id                targetObject;
@property (nonatomic, readonly) TBKNavigationMode  navigationMode;
@property (nonatomic, copy)     NSString*         parentURL;
@property (nonatomic, assign)   NSInteger         transition;
@property (nonatomic, assign)   NSInteger         argumentCount;
@property (nonatomic, readonly) BOOL              isUniversal;
@property (nonatomic, readonly) BOOL              isFragment;

- (id)initWithTarget:(id)target;
- (id)initWithTarget:(id)target mode:(TBKNavigationMode)navigationMode;

- (void)compile;

- (BOOL)matchURL:(NSURL*)URL;

- (id)invoke:(id)target withURL:(NSURL*)URL query:(NSDictionary*)query;

/**
 * either instantiates an object or delegates object creation
 * depending on current configuration
 * @return the newly created object or nil if something went wrong
 */
- (id)createObjectFromURL:(NSURL*)URL query:(NSDictionary*)query;

@end
