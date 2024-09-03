//
//  TBBaseUtility.h
//  TBBaseKit
//
//  Created by linbingjie on 2021/1/28.
//
//
#import "TBBaseKitUtil.h"
#import "TBNetWorkUtility.h"

#ifndef TBBaseUtility_h
#define TBBaseUtility_h

#define TextValid(text) ((text == nil || ![text isKindOfClass:[NSString class]] || [text isEqualToString:@""]) ? NO : YES)

//将bool转化为form需要的true,false字符串
#define BoolForForm(bool) (bool ? @"true" : @"false")
#define VENDOR                                              @"AppStore"

#define DEFAULT_PRICE_VALUE                                 @"--"

#define COLOR_INCREASE_GREEN                                0
#define COLOR_INCREASE_RED                                  1

#define TBIsArrayObject(obj) (obj && [obj isKindOfClass:[NSArray class]])
#define TBIsDictionaryObject(obj) (obj && [obj isKindOfClass:[NSDictionary class]])

#define TBConvertToString(obj) [TBNetWorkUtility tbutilscovert_toString:obj]
#define TBConvertToDictionaryOrNil(obj) [TBNetWorkUtility tbutilscovert_toDictionaryOrNil:obj]
#define TBConvertToArrayOrNil(obj) [TBNetWorkUtility tbutilscovert_toArrayOrNil:obj]


#define DECLARE_SHARED_INSTANCE(className)  \
+ (className *)sharedInstance;

#define IMPLEMENT_SHARED_INSTANCE(className)  \
+ (className *)sharedInstance { \
    static className *sharedInstance = nil; \
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
        sharedInstance = [[self alloc] init]; \
    }); \
    return sharedInstance; \
}

#ifndef weakify
   #if DEBUG
       #if __has_feature(objc_arc)
       #define weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
       #else
       #define weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
       #endif
   #else
       #if __has_feature(objc_arc)
       #define weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
       #else
       #define weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
       #endif
   #endif
#endif

#ifndef strongify
   #if DEBUG
       #if __has_feature(objc_arc)
       #define strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
       #else
       #define strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
       #endif
   #else
       #if __has_feature(objc_arc)
       #define strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
       #else
       #define strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
       #endif
   #endif
#endif

#define weakSelf()                                          __weak __typeof(self) weakSelf = self
#define strongSelf()                                        __strong __typeof(weakSelf) strongSelf = weakSelf

// HAS_TEST_ENV: 是否有测试环境, 包括开发包和测试包两种情况
// 只能在主工程里使用，在Pod里用无效
#if defined (DEBUG) || defined (TEST)
    #define HAS_TEST_ENV                                    1
#else
    #define HAS_TEST_ENV                                    0
#endif

// IS_TEST_ENV: 当前是否为测试环境
#define IS_TEST_ENV                                 [TBBaseKitUtil isTestEnvironment]

//
#define blockSelf()                                         __block __typeof(self) blockSelf = self
//

//本地化图片名称
#define TBLocalizedImageName(name) [TBBaseKitUtil localizedImageName:name]

//

#endif /* TBBaseUtility_h */
