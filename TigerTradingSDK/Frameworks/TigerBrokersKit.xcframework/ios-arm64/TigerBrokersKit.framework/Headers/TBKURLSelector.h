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

// UINavigator (private)
//#import "TigerBrokersKit/private/TBKURLArgumentType.h"
#import "TigerBrokersKit/TBKURLArgumentType.h"

@interface TBKURLSelector : NSObject {
    NSString*       _name;
    SEL             _selector;
    TBKURLSelector*  _next;
}

@property (nonatomic, readonly) NSString*       name;
@property (nonatomic, strong)   TBKURLSelector*  next;

- (id)initWithName:(NSString*)name;

- (NSString*)perform:(id)object returnType:(TBKURLArgumentType)returnType;

@end
