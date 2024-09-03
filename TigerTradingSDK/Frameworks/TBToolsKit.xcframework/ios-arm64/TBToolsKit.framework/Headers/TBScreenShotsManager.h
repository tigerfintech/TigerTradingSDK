//
//  TBScreenShotsManager.h
//  ACETelPrompt
//
//  Created by linbingjie on 2021/7/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBScreenShotsManager : NSObject

+ (UIImage *)screenCutFrom:(UIView *)viewDest withFrame:(CGRect)frameCut;

/// MARK- 局部照片截取：
/// viewDest：截取View
/// originFrame:截取view frame
/// frameCut:截取的局部
+ (UIImage *)screenCutFrom:(UIView *)viewDest originFrame:(CGRect)originFrame cutFrame:(CGRect)frameCut;
//没有缩放的截图
+ (UIImage *)screenCutFrom:(UIView *)viewDest originFrame:(CGRect)originFrame;


/*
 根据分享内容生成小程序封面图
 @param avatar 作者头像
 @param name 作者名称
 @param content 内容
 @param image 图片（视频帖），image与content只能有一个
 @param bottomText 底部文本（xx点赞 xx评论 xx转发）
 */
+ (NSData *)miniProgramImageDataWithAvatar:(UIImage * _Nullable)avatar name:(NSString * _Nullable)name content:(NSString * _Nullable)content image:(UIImage * _Nullable)image bottomText:(NSString * _Nullable)bottomText;

@end

NS_ASSUME_NONNULL_END
