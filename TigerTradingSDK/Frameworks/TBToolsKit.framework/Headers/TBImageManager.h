//
//  TBImageManager.h
//  TBToolsKit
//
//  Created by linbingjie on 2021/8/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBImageManager : NSObject

+ (void) animationShakeView:(UIView *)view;

+ (UIImage *)addlogoImage:(UIImage *)imgLogo toImg:(UIImage *)baseImg withFrame:(CGRect) frame;

+ (UIImage *)combinImagefromArr:(NSArray *)imageArr withSize:(CGSize )sizeCon;

// 用于分享的合并图片
+(UIImage *)combinShareImagefromArr:(NSArray *)imageArr withSize:(CGSize )sizeCon;

+ (NSData *)imageWithImage:(UIImage*)image scaledToSize:(CGSize)newSize;

//获取分享二维码图片
+ (UIImage *)getQRImage;

//获取分享二维码文字
+ (NSMutableAttributedString *)getInvitationText;

/**
生成分享底部图片
@param text 二维码图片旁边的文字
*/
+ (UIImage *)generateShareBottomImageWithText:(NSString *)text;

/*
@param type 分享类型
@param campaign 活动id
@param shareID 分享唯一 id
@param shareText 二维码图片旁边的文字
@param qrLink 二维码链接
 */
+ (UIImage *)stockDetailShareBottomImageWithType:(NSString *)type campaign:(NSString *)campaign shareID:(NSString *)shareID shareText:(NSString *)shareText qrLink:(NSString *)qrLink;

/// 生成分享底部图片
/// @param qrLink 二维码链接
+ (UIImage *)generateShareBottomImageWithQrlink:(NSString *)qrLink;

/**
 生成分享底部图片
 @param size 图片尺寸
 @param type 分享类型
 @param shareTo 分享渠道
 @param campaign 活动id
 @param shareID 分享唯一 id
 @param shareText 二维码图片旁边的文字
 @return 生成分享底部图片
 */
+ (UIImage *)generateShareBottomImageWithSize:(CGSize)size
                                         type:(nullable NSString *)type
                                      shareTo:(nullable NSString *)shareTo
                                     campaign:(nullable NSString *)campaign
                                      shareID:(nullable NSString *)shareID
                                      shareText:(nullable NSString *)shareText;

+ (UIImage *)generateShareBottomImageWithSize:(CGSize)size
                                         type:(nullable NSString *)type
                                      shareTo:(nullable NSString *)shareTo
                                      shareText:(nullable NSString *)shareText;

// 生成分享底部图片
+ (UIImage *)generateShareBottomImage;

// 生成顶部安全区域占位图片
+ (UIImage *)shareSafeTopImageWithSize:(CGSize)size;
@end

NS_ASSUME_NONNULL_END
