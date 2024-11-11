//
//  TBMQTTClientBaseManager+TBMultipleCallBack.h
//  tbmqtt
//
//  Created by 骆鹏飞 on 2022/6/19.
//

#import <tbmqtt/TBMQTTClientBaseManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBMQTTClientBaseManager (TBMultipleCallBack)

- (void)simpleTopic:(NSArray *)symbols addObserver:(id)observer callBack:(void(^)(NSData* message, NSString* topic))callBack;
- (void)simpleTopic:(NSArray *)symbols removeObserver:(id)observer;

- (void)simpleTopicMultipleCallBack:(NSString *)topic message:(NSData *)data;
@end

NS_ASSUME_NONNULL_END
