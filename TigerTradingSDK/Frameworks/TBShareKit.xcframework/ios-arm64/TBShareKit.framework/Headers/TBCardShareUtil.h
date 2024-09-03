//
//  TBCardShareUtil.h
//  TBShareKit
//
//  Created by dulijun on 2023/4/13.
//

#import <Foundation/Foundation.h>
#import "TBCardShareDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBCardShareUtil : NSObject


/// 根据索引获取分享卡片上的文案
/// - Parameter index: index取值范围0~25
+ (NSString *)shareDescriptionWithStickerIndex:(NSInteger)index;

/// 根据索引获取分享卡片上的表情图片名字（避免名字有改动，都收到这里处理）
/// - Parameter index: index取值范围0~25
+ (NSString *)shareStickerImageNameWithIndex:(NSInteger)index;

/// 根据索引获取对应的图片code，网络接口使用（避免后期改动，都收到这里处理）
/// - Parameter index: index取值范围0~25
+ (NSString *)shareStickerImageNetCodeWithIndex:(NSInteger)index;

/// 根据盈亏值获取分享中表情使用的index值
/// - Parameters:
///   - shareType: 分享值的类型（比例、金额、数量）
///   - number: 盈亏的金额或比例
+ (NSInteger)stickerIndedxWithType:(TBCardShareValueType)shareType number:(double)number;

/// 获取分享图片上二维码链接
/// - Parameters:
///   - source: 来源
///   - shareTo: 分享到
///   - campaign: id
///   - shareID: 分享id
+ (NSString *)qrLinkUrlWithSource:(nullable NSString *)source
                              shareTo:(nullable NSString *)shareTo
                             campaign:(nullable NSString *)campaign
                          shareID:(nullable NSString *)shareID;

// （分享图片上 二维码前面的）文案
+ (NSString *)shareInvitationText;

// 获取表情和文字列表
+ (void)fetchShareEmojiListWithSuccess:(void(^)(NSDictionary *dataDict))success
                               failure:(void(^)(NSString *errorMessage))failure;


/// 解锁分享卡片上的表情
/// - Parameters:
///   - index: 待解锁的表情索引（1~26）
///   - success: 成功回调
///   - failure: 失败回调
+ (void)unlockShareEmojiWithStickerIndex:(NSInteger)index success:(void(^)(NSDictionary *_Nullable dataDict))success
                          failure:(void(^)(NSString *errorMessage))failure;

/// 在字符串中加入空格，以保证在字符串中所有的“%”符号前都有一个空格。
/// - Parameter string: 要加空格的字符串，必须是NSString类型的对象，否则返回nil
+ (NSString *)addSpaceBeforePercentInString:(NSString *)string;

// 解锁一个表情（ 按照未解锁的表情包编号从小到大找到第一个未解锁的）
+ (void)unlockFirstlockedEmoji;

@end

NS_ASSUME_NONNULL_END
