//
//  TBBaseHostFactory.h
//  TBHostManager
//
//  Created by chenxin on 2021/2/8.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseKit.h>
#import <TBHostManager/TBHostIdentifiers.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBHostManagerProtocol <NSObject>

@required
- (BOOL)useTestHost;

@optional
- (BOOL)useQAHost;

@end

typedef NS_ENUM(NSInteger, TBHostConfigRule) {
    TBHostConfigRuleCommon = 0,
    TBHostConfigRuleUseLicense = 1,
    TBHostConfigRuleUseRegion,
    TBHostConfigRuleUseLocation,
    TBHostConfigRuleUseEdition,
    TBHostConfigRuleUseLicenseHint,
    // ... 添加新字段
    TBHostConfigRuleCustom = 31 // 子类自定义规则
};

@protocol TBHostConfig <NSObject>

@property (nonatomic, readonly) NSString *hostId;
@property (nonatomic, readonly) NSString *defaultTestHost;
@property (nonatomic, readonly) NSString *defaultOnlineHost;

@optional
@property (nonatomic, readonly) id defaultQAHost; // 默认QA环境域名，可能为String或Dict
@property (nonatomic, readonly) NSString *cgKey; // 在cg接口对应的key
@property (nonatomic, readonly) NSString *businessName; // 在cg接口对应的key
@property (nonatomic, readonly) TBHostConfigRule rule; // 规则枚举类型, 域名配置内容为字典的需要提供
@property (nonatomic, readonly) NSString *ruleKey; // rule=TBHostConfigRuleCustom时使用的key
@property (nonatomic, readonly) BOOL appendSlash;
- (NSString *)customHost:(NSString *)host; // 自定义要返回的域名, 如添加接口版本号

@end

// 放一些仅在组件内部使用的func
@protocol TBInnerProtocol <NSObject, TBHostService>

// 子类需要提供的信息
- (NSArray *)hostClasses; // 初始化时注册子类使用的域名
- (NSString *)hostKeyWithConfig:(id<TBHostConfig>)config; // cg value是dict时用哪个key

@optional
- (NSString *)hostWithConfig:(id<TBHostConfig>)config; // 怎么使用config里的信息, 如tigertrade加后缀

@end

@interface TBBaseHost : NSObject <TBInnerProtocol> {
    NSMutableArray *_cgAllHosts; // 用新的TBBaseHost解析方法解析的从cg下发的域名列表, 用于判断tigerHosts
}

@property (nonatomic, weak) id<TBHostManagerProtocol> delegate;

// 用于 cg接口解析数据 和 "选择服务器"页查看app使用的各域名
@property (nonatomic, readonly) NSArray<id<TBHostConfig>> *configs;

@property (nonatomic, strong) NSNumber *serverIndex; // 线路选择

/// 请求失败次数, 因为app启动会请求两次cg接口, 所以暂时%3来决定使用主备域名
/// 应该解决启动两次请求cg的问题, 需要网络层做什么? 取消之前的请求? 重新走启动流程?
@property (nonatomic, assign) NSInteger failCount;

// 供TBHost内部代码直接调用
- (NSString *)hostWithIdentifier:(NSString *)hostId;
- (NSString *)hostWithIdentifier:(NSString *)hostId options:(nullable NSDictionary *)options;

/// 解析和保存cg接口指定key的域名数据
/// @param host 域名的数据结构, 可以是字典, 可以是以";"分隔一组域名, 可以是单个域名
/// @param key cg接口中域名对应的key
- (void)setHost:(id)host forCGKey:(NSString *)key;

/// 更新customHosts数据, 并根据当前环境(test/qa/online)保存到NSUserDefaults
- (void)updateCustomHosts:(NSDictionary *)hosts;

/// 重置customHosts数据, 清空内存和NSUserDefaults
- (void)resetCustomHosts;

// 缓存
// 因为通知在app, 所以增加一个方法, 切环境(包括qa)后要主动调用
// 改线路 只需要重置内存
- (void)resetAfterEnvironmentChanged; // 环境变了, 清空缓存, 重新load相关变量如custom host

- (NSArray *)hostListWithIdentifier:(NSString *)hostId; // 返回一组域名, 用于测速


















//- (NSString *)hostWithIdentifier:(NSString *)hostId specificKey:(NSString *)key; // 特定key下的值, 如中国官网

@end

#pragma mark -

NS_ASSUME_NONNULL_END
