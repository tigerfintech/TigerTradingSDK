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

@interface NSObject (TBKAdditions)

/**
 * Additional performSelector signatures that support up to 7 arguments.
 */
- (id)performSelector:(SEL)selector withObject:(id)p1 withObject:(id)p2 withObject:(id)p3;
- (id)performSelector:(SEL)selector withObject:(id)p1 withObject:(id)p2 withObject:(id)p3
           withObject:(id)p4;
- (id)performSelector:(SEL)selector withObject:(id)p1 withObject:(id)p2 withObject:(id)p3
           withObject:(id)p4 withObject:(id)p5;
- (id)performSelector:(SEL)selector withObject:(id)p1 withObject:(id)p2 withObject:(id)p3
           withObject:(id)p4 withObject:(id)p5 withObject:(id)p6;
- (id)performSelector:(SEL)selector withObject:(id)p1 withObject:(id)p2 withObject:(id)p3
           withObject:(id)p4 withObject:(id)p5 withObject:(id)p6 withObject:(id)p7;

// ARC 下按推荐不使用 NSInvocation 的版本
// fix warning: PerformSelector may cause a leak because its selector is unknown
- (id)tbk_performSelector:(SEL)aSelector;
- (id)tbk_performSelector:(SEL)aSelector withObject:(id)object;
- (id)tbk_performSelector:(SEL)aSelector withObject:(id)object1 withObject:(id)object2;
- (id)tbk_performSelector:(SEL)aSelector withObject:(id)object1 withObject:(id)object2 withObject:(id)object3;
- (id)tbk_performSelector:(SEL)aSelector withObject:(id)object1 withObject:(id)object2 withObject:(id)object3 withObject:(id)object4;
- (id)tbk_performSelector:(SEL)aSelector withObject:(id)object1 withObject:(id)object2 withObject:(id)object3 withObject:(id)object4 withObject:(id)object5;
- (id)tbk_performSelector:(SEL)aSelector withObject:(id)object1 withObject:(id)object2 withObject:(id)object3 withObject:(id)object4 withObject:(id)object5 withObject:(id)object6;
- (id)tbk_performSelector:(SEL)aSelector withObject:(id)object1 withObject:(id)object2 withObject:(id)object3 withObject:(id)object4 withObject:(id)object5 withObject:(id)object6 withObject:(id)object7;

@end


@interface NSObject (TBKNetwork)

- (id)tbk_defaultValue:(id)defaultData;
- (BOOL)tbk_isEmptyObject;

@end
