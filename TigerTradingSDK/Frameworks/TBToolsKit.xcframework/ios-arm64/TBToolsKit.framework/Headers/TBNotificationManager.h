//
//  TBNotificationManager.h
//  ACETelPrompt
//
//  Created by linbingjie on 2021/4/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBNotificationManager : NSObject

// post notification in main thread
+ (void) postNotificationName:(NSString *)aName object:(nullable id)anObject;
// post notification in main thread(notificationName, object, userinfo)
+ (void) postNotificationName:(NSString *)aName object:(nullable id)anObject userinfo:(nullable NSDictionary *)userinfo;

// 封装addObserverForName:object:queue:usingBlock:方法
+ (void)observeNotificationForName:(NSString *)name
                      shouldRemove:(BOOL)shouldRemove
                        usingBlock:(void(^)(NSNotification *note))block;

@end

NS_ASSUME_NONNULL_END

