//
//  TBCatchExceptionManager.h
//  Stock
//
//  Created by yangfan on 2018/1/17.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBObject.h>
#import "NSObject+Zombie.h"
#import "TBKeepLiveObject.h"
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, TBCatchErrorCode) {
    TBCatchErrorCodeNone = 0,
    TBCatchErrorCodeData = 1000,
    TBCatchErrorCodeLogic = 1001,
};

@protocol TBCatchExceptionDelegate <NSObject>

@required
+ (void)catchException;
+ (void)setEnableZombie;

@end

@interface TBCatchExceptionManager : TBObject

+ (instancetype)manager;

+ (void)exchangeClassMethod:(Class)objcClass originalSelector:(SEL)originalSelector swizzledSelector:(SEL)swizzledSelector;

//是否捕获所有异常,这是一个总开关
@property (nonatomic, assign) BOOL               catchAllException;
//是否允许捕获异常
@property (nonatomic, assign) BOOL               enableCatchException;
//是否允许生成Zombie以防止EXC_BAD_ACCESS
@property (nonatomic, assign) BOOL               enableZombie;
//不需要捕获异常的类名
@property (nonatomic, strong) NSMutableArray   * excludeClassArray;
//不需要捕获异常的控制器类名
@property (nonatomic, strong) NSMutableArray   * excludeVCArray;
//用于同步zombie操作
@property (nonatomic, strong) dispatch_queue_t   zombieOperationQueue;
//最大zombie对象个数
@property (nonatomic, assign) NSInteger          maxZombieCount;
//允许zombie的类
@property (nonatomic, strong) NSMutableArray   * zombieClassArray;

@property (nonatomic, strong) NSMutableArray *zombieCacheArray;

/**
 慎用此方法，确保在数据异常引起程序crash、功能异常的地方使用此方法上报记录，记录关键错误以便辅助问题跟踪。
 因为记录 NSError 的开销可能会相当大。当您进行调用时，Crashlytics 会通过一个名为 Stack Unwinding（堆栈展开）
 的过程来捕获当前线程的调用堆栈，开销较大。
 @param cls 取cls做为NSError的domain 记录的错误是根据 domain 和 code 来分组的
 @param code 记录的错误是根据 domain 和 code 来分组的
 @param message 错误描述信息
 */
- (void)reportError:(Class)cls code:(TBCatchErrorCode)code message:(NSString *)message;

- (TBKeepLiveObject *)existZombieAlready:(NSString *)p;

@end

@interface NSArray (TBCatchExceptionArray) <TBCatchExceptionDelegate>

@end

@interface NSData (TBCatchExceptionData) <TBCatchExceptionDelegate>

@end

@interface NSMutableData (TBCatchExceptionMutableData) <TBCatchExceptionDelegate>

@end

@interface NSMutableArray (TBCatchExceptionMutableArray) <TBCatchExceptionDelegate>

@end

@interface NSMutableDictionary (TBCatchExceptionMutableDictionary) <TBCatchExceptionDelegate>

@end

@interface UIPageViewController (TBCatchExceptionPageViewController) <TBCatchExceptionDelegate>

@end

@interface UIView (TBCatchExceptionUIView) <TBCatchExceptionDelegate>

@end

@interface UIScrollView (TBCatchExceptionScrollView) <TBCatchExceptionDelegate>

@end

@interface UITableView (TBCatchExceptionUITableView) <TBCatchExceptionDelegate>

@end

@interface UICollectionView (TBCatchExceptionUITableView) <TBCatchExceptionDelegate>

@end

@interface NSUserDefaults (TBCatchExceptionNSUserDefaults) <TBCatchExceptionDelegate>

@end

@interface NSMutableAttributedString (TBCatchExceptionAttributedString) <TBCatchExceptionDelegate>

@end

@interface NSAttributedString (TBCatchExceptionAttributedString) <TBCatchExceptionDelegate>

@end

@interface NSObject (TBCatchExceptionObject) <TBCatchExceptionDelegate>

@end

@interface NSJSONSerialization () <TBCatchExceptionDelegate>

@end

@interface TBZombie : NSObject

+ (instancetype)sharedZombie;

@end

#define TBCatchExceptionKit [TBCatchExceptionManager manager]

