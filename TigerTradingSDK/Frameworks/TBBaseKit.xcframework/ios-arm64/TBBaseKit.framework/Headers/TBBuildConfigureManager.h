//
//  TBBuildConfigureManager.h
//  TBBaseKit
//
//  Created by linbingjie on 2021/1/28.
//

#import <Foundation/Foundation.h>

#import "TBBaseUtility.h"
#import "TBAppManager.h"

#define TBONLYDebug [[TBBuildConfigureManager sharedInstance] isDebugStyle]  // 只是debug
#define TBDebug [[TBBuildConfigureManager sharedInstance] isDebugOrTestStyle] // debug || test
#define TBRelease [[TBBuildConfigureManager sharedInstance] isReleaseStyle]

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    TBBuildConfigStyleRelease = 0, // 默认为release
    TBBuildConfigStyleDebug,
    TBBuildConfigStyleTest,
    TBBuildConfigStyleRC
} TBBuildConfigStyle;

typedef enum : NSUInteger {
    TBProjectTypeUnknown,
    TBProjectTypeTigerTrade,
    TBProjectTypeTradeUP
} TBProjectType;

@interface TBBuildConfigureManager : NSObject
DECLARE_SHARED_INSTANCE(TBBuildConfigureManager)

@property (nonatomic, assign, readonly) TBBuildConfigStyle buildType;
@property (nonatomic, assign, readonly) TBProjectType projectType;
@property (nonatomic, copy, readonly) NSString *keyChainService; // 用在tbkeychainmanager内

- (void)setupBuildConfiguration:(TBBuildConfigStyle)buildType;
- (void)setupProjectConfiguration:(TBProjectType)projectType;

/// 设置keychain的service名
/// @param service service一般用bundleid即可
- (void)setupKeyChainStoreWithService:(NSString *)service;

- (BOOL)isDebugStyle;
- (BOOL)isDebugOrTestStyle;
- (BOOL)isReleaseStyle;

@end

NS_ASSUME_NONNULL_END

