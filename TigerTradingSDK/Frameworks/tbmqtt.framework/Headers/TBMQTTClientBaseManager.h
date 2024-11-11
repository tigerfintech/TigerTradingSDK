//
//  TBMQTTClientBaseManager.h
//  Stock
//
//  Created by 骆鹏飞 on 2020/9/28.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <tbmqtt/TBMQTTConstant.h>
#import <tbmqtt/TBMQTTHelper.h>
@import TBCocoaMQTT;

NS_ASSUME_NONNULL_BEGIN

@class TBMQTTClientManager;

@interface TBMQTTClientBaseManager : NSObject
//@property (nonatomic, strong, readonly) MQTTSessionManager *manager;
//
@property (nonatomic, assign, readonly) CocoaMQTTConnState state;



@property (nonatomic, copy) NSString *host;
@property (nonatomic, assign) UInt32 port;
@property (nonatomic, assign) BOOL usingSSL;
//@property (nonatomic, assign) BOOL hasAccessToken;
@property (nonatomic, copy) NSString *clientID;

@property (nonatomic, assign) BOOL connected;


// 连接成功
@property (nonatomic, copy) void (^connectedMQTTHandler)(void);

/// 连接长连接
/// @param usingSSL 是否usingSSL，兼容之前接口，该参数使用[TBUtils getMqttSSLEnabled]
- (void)connect:(BOOL)usingSSL;

/// 连接长连接
- (void)connect;

/// 参数发生改变，重连，比如host等
- (void)connectWithModifyParams;

/// 断开长连接，同时删除所有订阅信息
- (void)closeSession;

/// 断开长连接
- (void)disconnect;


/// 订阅主题
/// @param topicString 主题
- (void)subscribeTopic:(NSString *)topicString;

/// 取消订阅主题
/// @param topicString 主题
- (void)unsubscribeTopic:(NSString *)topicString;

/// 批量订阅
/// @param topicArray 主题数组
- (void)subscribeTopicList:(NSArray *)topicArray;

/// 批量取消订阅
/// @param topicArray 主题数组
- (void)unsubscribeTopicList:(NSArray *)topicArray;

/**
 是否允许长连接订阅，bulid mode == 0 下可以关闭长连接订阅，build==1不允许关闭
 */
@property (nonatomic, assign) BOOL enableSubscribe;

@property (nonatomic, assign) BOOL enableShortConnection;

/// 发布客户端配置
/// 客户端通过向长连接发送 publish 消息（使用QoS 1 - at least one），更新当前连接的全局配置。
- (void)publicClientConfig;


/**
 *  将长链接服务器传过来的压缩后的短key转换为未压缩的长key, 为了不修改原来的代码, 因为原来的长链接和短连接使用同一套key value的更新代码, 如果只有长链接修改为短key要修改各个地方的代码
 *
 *  @param dict 长链接推送的短key数组
 *
 *  @return 转换后的长key数据
 */
- (NSDictionary *)convertToUniKey:(NSDictionary *)dict;

@property (nonatomic, readonly) NSString *pbParam;

@property (nonatomic, strong) NSMutableDictionary *pbFormatKeyMap;

- (void)didReceiveMessage:(NSData *)data onTopic:(NSString *)topic retained:(BOOL)retained;

/// 个股详情消息订阅
/// @param symbol 个股symbol
/// @param usePB 是否使用PB
- (void)subscribeQuoteDetail:(NSString *)symbol usePB:(BOOL)usePB callBack:(void(^)(NSData *message, NSString *topic))callBack;
/// 取消个股详情消息订阅
/// @param symbol 个股symbol
/// @param usePB 是否使用PB
- (void)unsubscribeQuoteDetail:(NSString *)symbol usePB:(BOOL)usePB;

- (void)subscribeQuoteDetails:(NSArray *)symbols usePB:(BOOL)usePB callBack:(void(^)(NSData *message, NSString *topic))callBack;
- (void)unsubscribeQuoteDetails:(NSArray *)symbols usePB:(BOOL)usePB;


/// 自选简要行情
/// @param symbols <#symbols description#>
/// @param usePB <#usePB description#>
/// @param callBack <#callBack description#>
- (void)subscribeQuoteSimples:(NSArray *)symbols usePB:(BOOL)usePB callBack:(nonnull void (^)(NSData * _Nonnull, NSString * _Nonnull))callBack;
//cancelCallBack 是否删除回调
- (void)unsubscribeQuoteSimples:(NSArray *)symbols usePB:(BOOL)usePB cancelCallBack:(BOOL)cancelCallBack;
- (void)unsubscribeQuoteSimples:(NSArray *)symbols usePB:(BOOL)usePB;


- (void)subscribeQuoteSimples:(NSArray *)symbols usePB:(BOOL)usePB dictionaryCallback:(nonnull void(^)(NSDictionary *, NSString * _Nonnull))callback;


/// 消息发布
/// - Parameters:
///   - topic: 服务网关，对应接口文档中的topic，行情网关根据这个参数来寻找对应的后端服务
///   - responseTopic: 对应接口文档中的responseTopic，要传递类似/austock/stock_info/brief的字符串，表示与后端约定好的资源。
///   - dict: 参数部分，网关不会解析这部分内容只是会透传給应用后端服务器
///   - callBack: response 回调包括：data,code,msg
///   - backup: 降级回调
- (void)publish:(NSString *)topic responseTopic:(NSString *)responseTopic topicPayload:(NSDictionary *)dict callBack:(void (^ _Nullable)(NSData * _Nullable, NSString * _Nullable, NSString * _Nullable))callBack backup:(void (^ _Nullable)(void))backup;

/// 消息发布
/// - Parameters:
///   - topic: 服务网关，对应接口文档中的topic，行情网关根据这个参数来寻找对应的后端服务
///   - responseTopic: 对应接口文档中的responseTopic，要传递类似/austock/stock_info/brief的字符串，表示与后端约定好的资源。
///   - dict: 参数部分，网关不会解析这部分内容只是会透传給应用后端服务器
///   - userProperty:  格式是一个个的key-value对。目前主要包括三个参数：accept(客户端期望响应包体payload格式)、lang(国际化多语言 en_US, zh_CN zh_TW)、timestamp(客户端发起网络请求时间戳，单位（ms），零时区)
///   - callBack: response 回调包括：
///   - backup: 降级回调
- (void)publish:(NSString *)topic responseTopic:(NSString *)responseTopic topicPayload:(NSDictionary *)dict userProperty:(NSDictionary<NSString*, NSString*> *)userProperty callBack:(void (^ _Nullable)(NSData * _Nullable, NSString * _Nullable, NSString * _Nullable))callBack backup:(void (^ _Nullable)(void))backup;

/// 简要行情消息回调
@property (atomic, copy, nullable) void (^quoteSimpleMessageHandler)(NSData* message, NSString* topic);
@property (atomic, copy, nullable) void (^quoteDetailMessageHandler)(NSData *message, NSString *topic);


@property (atomic, copy, nullable) void (^quoteSimpleDictionaryHandler)(NSDictionary *dict, NSString *topic);

// 用于长连接调试页面, 可以接收多个topic
@property (atomic, copy, nullable) void (^commonMessageHandler)(NSData *message, NSString *topic);

- (void)handleMarketOpenNotifation:(NSNumber *)timestamp;

/// 发送通知
/// @param aName <#aName description#>
/// @param anObject <#anObject description#>
/// @param userinfo <#userinfo description#>
+ (void)postNotificationName:(NSString *)aName object:(nullable id)anObject userinfo:(nullable NSDictionary *)userinfo;

/// 统计项
/// @param type <#type description#>
/// @param name <#name description#>
/// @param param1 <#param1 description#>
- (void)traceMQTTBehavior:(NSString *)type name:(NSString *)name param1:(NSString *)param1;



/// 用来处理多callback
/// NSMapTable 来缓存Block。因为这种缓存方式可以设置KEY和Value的缓存策略，并且可以把KEY设置成Object。设置Value的缓存策略，可以让我们把绑定的Block的Target也就是我们Value设置成 NSPointerFunctionsWeakMemory 这样就可以在Target释放的时候，自动移除我们的此条数据。
@property (nonatomic, strong) NSMapTable *valueTable;
@property (nonatomic, strong) NSMapTable *keyTable;

- (NSArray *)simpleQuoteTopics:(NSArray *)symbols usePB:(BOOL)usePB;



@property (nonatomic, strong, readonly) TBMQTTClientManager *clientManager;

@end

NS_ASSUME_NONNULL_END
