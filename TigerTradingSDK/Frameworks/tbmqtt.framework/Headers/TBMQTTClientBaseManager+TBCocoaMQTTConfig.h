//
//  TBMQTTClientBaseManager+TBCocoaMQTTConfig.h
//  tbmqtt
//
//  Created by 骆鹏飞 on 2023/11/22.
//

#import <tbmqtt/TBMQTTClientBaseManager.h>

// .h 文件不推荐这种写法，会报错。
//#if __has_include(<tbmqtt/tbmqtt-Swift.h>)
//    #import <tbmqtt/tbmqtt-Swift.h>
//#else
//    #import "tbmqtt-Swift.h"
//#endif


NS_ASSUME_NONNULL_BEGIN

@interface TBMQTTClientBaseManager (TBCocoaMQTTConfig) 

@end

NS_ASSUME_NONNULL_END
