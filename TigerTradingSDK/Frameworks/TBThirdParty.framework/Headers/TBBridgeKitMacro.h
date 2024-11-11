//
//  TBBridgeKitMacro.h
//  YYKit <https://github.com/ibireme/YYKit>
//
//  Created by linbingjie on 2020/4/9.
//  Copyright © 2020 杜文. All rights reserved.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>
#import <sys/time.h>
#import <pthread.h>

#ifndef TBKitMacro_h
#define TBKitMacro_h

#ifdef __cplusplus
#define TB_EXTERN_C_BEGIN  extern "C" {
#define TB_EXTERN_C_END  }
#else
#define TB_EXTERN_C_BEGIN
#define TB_EXTERN_C_END
#endif


TB_EXTERN_C_BEGIN

#ifndef TB_CLAMP // return the clamped value
#define TB_CLAMP(_x_, _low_, _high_)  (((_x_) > (_high_)) ? (_high_) : (((_x_) < (_low_)) ? (_low_) : (_x_)))
#endif

#ifndef TB_SWAP // swap two value
#define TB_SWAP(_a_, _b_)  do { __typeof__(_a_) _tmp_ = (_a_); (_a_) = (_b_); (_b_) = _tmp_; } while (0)
#endif


#define TBAssertNil(condition, description, ...) NSAssert(!(condition), (description), ##__VA_ARGS__)
#define TBCAssertNil(condition, description, ...) NSCAssert(!(condition), (description), ##__VA_ARGS__)

#define TBAssertNotNil(condition, description, ...) NSAssert((condition), (description), ##__VA_ARGS__)
#define TBCAssertNotNil(condition, description, ...) NSCAssert((condition), (description), ##__VA_ARGS__)

#define TBAssertMainThread() NSAssert([NSThread isMainThread], @"This method must be called on the main thread")
#define TBCAssertMainThread() NSCAssert([NSThread isMainThread], @"This method must be called on the main thread")


/**
 Add this macro before each category implementation, so we don't have to use
 -all_load or -force_load to load object files from static libraries that only
 contain categories and no classes.
 More info: http://developer.apple.com/library/mac/#qa/qa2006/qa1490.html .
 *******************************************************************************
 Example:
     TBSYNTH_DUMMY_CLASS(NSString_TBAdd)
 */
#ifndef TBSYNTH_DUMMY_CLASS
#define TBSYNTH_DUMMY_CLASS(_name_) \
@interface TBSYNTH_DUMMY_CLASS_ ## _name_ : NSObject @end \
@implementation TBSYNTH_DUMMY_CLASS_ ## _name_ @end
#endif


/**
 Synthsize a dynamic object property in @implementation scope.
 It allows us to add custom properties to existing classes in categories.
 
 @param association  ASSIGN / RETAIN / COPY / RETAIN_NONATOMIC / COPY_NONATOMIC
 @warning #import <objc/runtime.h>
 *******************************************************************************
 Example:
     @interface NSObject (MyAdd)
     @property (nonatomic, retain) UIColor *myColor;
     @end
     
     #import <objc/runtime.h>
     @implementation NSObject (MyAdd)
     TBSYNTH_DYNAMIC_PROPERTY_OBJECT(myColor, setMyColor, RETAIN, UIColor *)
     @end
 */
#ifndef TBSYNTH_DYNAMIC_PROPERTY_OBJECT
#define TBSYNTH_DYNAMIC_PROPERTY_OBJECT(_getter_, _setter_, _association_, _type_) \
- (void)_setter_ : (_type_)object { \
    [self willChangeValueForKey:@#_getter_]; \
    objc_setAssociatedObject(self, _cmd, object, OBJC_ASSOCIATION_ ## _association_); \
    [self didChangeValueForKey:@#_getter_]; \
} \
- (_type_)_getter_ { \
    return objc_getAssociatedObject(self, @selector(_setter_:)); \
}
#endif


/**
 Synthsize a dynamic c type property in @implementation scope.
 It allows us to add custom properties to existing classes in categories.
 
 @warning #import <objc/runtime.h>
 *******************************************************************************
 Example:
     @interface NSObject (MyAdd)
     @property (nonatomic, retain) CGPoint myPoint;
     @end
     
     #import <objc/runtime.h>
     @implementation NSObject (MyAdd)
     TBSYNTH_DYNAMIC_PROPERTY_CTYPE(myPoint, setMyPoint, CGPoint)
     @end
 */
#ifndef TBSYNTH_DYNAMIC_PROPERTY_CTYPE
#define TBSYNTH_DYNAMIC_PROPERTY_CTYPE(_getter_, _setter_, _type_) \
- (void)_setter_ : (_type_)object { \
    [self willChangeValueForKey:@#_getter_]; \
    NSValue *value = [NSValue value:&object withObjCType:@encode(_type_)]; \
    objc_setAssociatedObject(self, _cmd, value, OBJC_ASSOCIATION_RETAIN); \
    [self didChangeValueForKey:@#_getter_]; \
} \
- (_type_)_getter_ { \
    _type_ cValue = { 0 }; \
    NSValue *value = objc_getAssociatedObject(self, @selector(_setter_:)); \
    [value getValue:&cValue]; \
    return cValue; \
}
#endif

/**
 Convert CFRange to NSRange
 @param range CFRange @return NSRange
 */
static inline NSRange TBNSRangeFromCFRange(CFRange range) {
    return NSMakeRange(range.location, range.length);
}

/**
 Convert NSRange to CFRange
 @param range NSRange @return CFRange
 */
static inline CFRange TBCFRangeFromNSRange(NSRange range) {
    return CFRangeMake(range.location, range.length);
}

/**
 Same as CFAutorelease(), compatible for iOS6
 @param arg CFObject @return same as input
 */
static inline CFTypeRef TBCFAutorelease(CFTypeRef CF_RELEASES_ARGUMENT arg) {
    if (((long)CFAutorelease + 1) != 1) {
        return CFAutorelease(arg);
    } else {
        id __autoreleasing obj = CFBridgingRelease(arg);
        return (__bridge CFTypeRef)obj;
    }
}

/**
 Profile time cost.
 @param block    code to benchmark
 @param complete code time cost (millisecond)
 
 Usage:
    TBBenchmark(^{
        // code
    }, ^(double ms) {
        NSLog("time cost: %.2f ms",ms);
    });
 
 */
static inline void TBBenchmark(void (^block)(void), void (^complete)(double ms)) {
    // <QuartzCore/QuartzCore.h> version
    /*
    extern double CACurrentMediaTime (void);
    double begin, end, ms;
    begin = CACurrentMediaTime();
    block();
    end = CACurrentMediaTime();
    ms = (end - begin) * 1000.0;
    complete(ms);
    */
    
    // <sys/time.h> version
    struct timeval t0, t1;
    gettimeofday(&t0, NULL);
    block();
    gettimeofday(&t1, NULL);
    double ms = (double)(t1.tv_sec - t0.tv_sec) * 1e3 + (double)(t1.tv_usec - t0.tv_usec) * 1e-3;
    complete(ms);
}

static inline NSDate *_TBCompileTime(const char *data, const char *time) {
    NSString *timeStr = [NSString stringWithFormat:@"%s %s",data,time];
    NSLocale *locale = [[NSLocale alloc] initWithLocaleIdentifier:@"en_US"];
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"MMM dd yyyy HH:mm:ss"];
    [formatter setLocale:locale];
    return [formatter dateFromString:timeStr];
}

/**
 Get compile timestamp.
 @return A new date object set to the compile date and time.
 */
#ifndef TBCompileTime
// use macro to avoid compile warning when use pch file
#define TBCompileTime() _TBCompileTime(__DATE__, __TIME__)
#endif

/**
 Returns a dispatch_time delay from now.
 */
static inline dispatch_time_t dispatch_time_delay(NSTimeInterval second) {
    return dispatch_time(DISPATCH_TIME_NOW, (int64_t)(second * NSEC_PER_SEC));
}

/**
 Returns a dispatch_wall_time delay from now.
 */
static inline dispatch_time_t dispatch_walltime_delay(NSTimeInterval second) {
    return dispatch_walltime(DISPATCH_TIME_NOW, (int64_t)(second * NSEC_PER_SEC));
}

/**
 Returns a dispatch_wall_time from NSDate.
 */
static inline dispatch_time_t dispatch_walltime_date(NSDate *date) {
    NSTimeInterval interval;
    double second, subsecond;
    struct timespec time;
    dispatch_time_t milestone;
    
    interval = [date timeIntervalSince1970];
    subsecond = modf(interval, &second);
    time.tv_sec = second;
    time.tv_nsec = subsecond * NSEC_PER_SEC;
    milestone = dispatch_walltime(&time, 0);
    return milestone;
}

///**
// Whether in main queue/thread.
// */
//static inline bool dispatch_is_main_queue() {
//    return pthread_main_np() != 0;
//}

///**
// Submits a block for asynchronous execution on a main queue and returns immediately.
// */
//static inline void dispatch_async_on_main_queue(void (^block)()) {
//    if (pthread_main_np()) {
//        block();
//    } else {
//        dispatch_async(dispatch_get_main_queue(), block);
//    }
//}
//
///**
// Submits a block for execution on a main queue and waits until the block completes.
// */
//static inline void dispatch_sync_on_main_queue(void (^block)()) {
//    if (pthread_main_np()) {
//        block();
//    } else {
//        dispatch_sync(dispatch_get_main_queue(), block);
//    }
//}

///**
// Initialize a pthread mutex.
// */
//static inline void pthread_mutex_init_recursive(pthread_mutex_t *mutex, bool recursive) {
//#define TBMUTEX_ASSERT_ON_ERROR(x_) do { \
//__unused volatile int res = (x_); \
//assert(res == 0); \
//} while (0)
//    assert(mutex != NULL);
//    if (!recursive) {
//        TBMUTEX_ASSERT_ON_ERROR(pthread_mutex_init(mutex, NULL));
//    } else {
//        pthread_mutexattr_t attr;
//        TBMUTEX_ASSERT_ON_ERROR(pthread_mutexattr_init (&attr));
//        TBMUTEX_ASSERT_ON_ERROR(pthread_mutexattr_settype (&attr, PTHREAD_MUTEX_RECURSIVE));
//        TBMUTEX_ASSERT_ON_ERROR(pthread_mutex_init (mutex, &attr));
//        TBMUTEX_ASSERT_ON_ERROR(pthread_mutexattr_destroy (&attr));
//    }
//#undef TBMUTEX_ASSERT_ON_ERROR
//}


TB_EXTERN_C_END
#endif
