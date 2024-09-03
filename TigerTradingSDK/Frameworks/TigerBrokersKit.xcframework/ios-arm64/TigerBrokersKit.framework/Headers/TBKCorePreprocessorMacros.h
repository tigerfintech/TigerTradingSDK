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

// Code Management

/**
 * Borrowed from Apple's AvailabiltyInternal.h header. There's no reason why we shouldn't be
 * able to use this macro, as it's a gcc-supported flag.
 * Here's what we based it off of.
 * __AVAILABILITY_INTERNAL_DEPRECATED         __attribute__((deprecated))
 */
#define __TBKDEPRECATED_METHOD __attribute__((deprecated))
#define __TBKDEPRECATED_MSG_METHOD(s) __attribute((deprecated((s))))

#define __TBKDEPRECATED_ATTRIBUTE __attribute__((deprecated))
#define __TBKDEPRECATED_MSG_ATTRIBUTE(s) __attribute((deprecated((s))))

// For singleton
// - (id)init __attribute__((unavailable("cannot use init for this class, use +(MYClass*)sharedInstance instead")));
#define __TBKUNAVAILABLE_METHOD __attribute__((unavailable))
#define __TBKUNAVAILABLE_MSG_METHOD(s) __attribute__((unavailable((s))))

// suppress warning -Warc-performSelector-leaks
// see https://stackoverflow.com/q/7017281/913522
#define TBK_SUPPRESS_WARNING_PERFORM_SELECTOR_LEAKS(Stuff) \
    do { \
        _Pragma("clang diagnostic push") \
        _Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
        Stuff \
        _Pragma("clang diagnostic pop") \
    } while (0)

/**
 * Add this macro before each category implementation, so we don't have to use
 * -all_load or -force_load to load object files from static libraries that only contain
 * categories and no classes.
 * See https://developer.apple.com/library/content/qa/qa1490/_index.html for more info.
 */
#define TBK_FIX_CATEGORY_BUG(name) @interface TBK_FIX_CATEGORY_BUG_##name @end \
@implementation TBK_FIX_CATEGORY_BUG_##name @end


// Flags

/**
 * For when the flag might be a set of bits, this will ensure that the exact set of bits in
 * the flag have been set in the value.
 */
#define IS_MASK_SET(value, flag)  (((value) & (flag)) == (flag))


// Time

#define TBK_MINUTE 60
#define TBK_HOUR   (60 * TBK_MINUTE)
#define TBK_DAY    (24 * TBK_HOUR)
#define TBK_5_DAYS (5 * TBK_DAY)
#define TBK_WEEK   (7 * TBK_DAY)
#define TBK_MONTH  (30.5 * TBK_DAY)
#define TBK_YEAR   (365 * TBK_DAY)

// Safe releases

#define TBK_RELEASE_SAFELY(__POINTER) { [__POINTER release]; __POINTER = nil; }
#define TBK_INVALIDATE_TIMER(__TIMER) { [__TIMER invalidate]; __TIMER = nil; }

// Release a CoreFoundation object safely.
#define TBK_RELEASE_CF_SAFELY(__REF) { if (nil != (__REF)) { CFRelease(__REF); __REF = nil; } }

// Singleton

#define TBK_DECLARE_SINGLETON_FOR_CLASS(classname) \
\
+ (instancetype)sharedInstance; \
\
- (instancetype)init __TBKUNAVAILABLE_MSG_METHOD("cannot use `init` for this class, use `+ (instancetype *)sharedInstance` instead");

#define TBK_IMPLEMENT_SINGLETON_FOR_CLASS(classname) \
\
static classname *sharedInstance = nil; \
\
+ (instancetype)sharedInstance { \
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
        sharedInstance = [[self alloc] init]; \
    }); \
    return sharedInstance; \
} \
\
+ (instancetype)allocWithZone:(struct _NSZone *)zone { \
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
        sharedInstance = [super allocWithZone:zone]; \
    }); \
    return sharedInstance; \
} \
\
+ (id)copyWithZone:(struct _NSZone *)zone { \
    return self; \
}
