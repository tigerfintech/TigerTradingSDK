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

@protocol TBKURLObject <NSObject>
@optional

/**
 * Converts the object to a URL using TBKURLMap.
 */
@property (nonatomic, readonly) NSString* URLValue;

/**
 * Converts the object to a specially-named URL using TBKURLMap.
 */
- (NSString*)URLValueWithName:(NSString*)name;


@end
