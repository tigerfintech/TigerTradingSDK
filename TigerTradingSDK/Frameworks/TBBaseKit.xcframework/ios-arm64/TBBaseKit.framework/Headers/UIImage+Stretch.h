//
//  UIImage+Stretch.h
//  Stock
//
//  Created by liwt on 14/12/18.
//  Copyright (c) 2014年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Stretch)

- (UIImage *)stretchableImageByCenter;
- (UIImage *)stretchableImageByHeightCenter;
- (UIImage *)stretchableImageByWidthCenter;
- (UIImage *)rotationToUp;
- (UIImage *)imageScale:(CGSize)newSize;
- (UIImage *)imageRotate:(UIImageOrientation)orientation;
+ (UIImage *)imageWithColor:(UIColor *)color;
+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size;
+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size radius:(CGFloat)radius;
- (UIImage *)imageWithText:(NSString *)text;

///自定义绘图的iocn方法
+ (UIImage *)circelBorderImageWithBackGroundColor:(UIColor *)backGroundColor imageColor:(UIColor *)imageColor borderColor:(UIColor *)borderColor contentSize:(CGSize)contentSize imageSize:(CGSize)imageSize contentRadius:(CGFloat)contentRadius imageRadius:(CGFloat)imageRadius;

+ (UIImage *)lineWidthIconWithBackGroundColor:(UIColor *)backGroundColor itemColor:(UIColor *)itemColor borderColor:(UIColor *)borderColor contentSize:(CGSize)contentSize itemHeight:(CGFloat)itemHeight radius:(CGFloat)radius;

+ (UIImage *)lineStyleIconWithBakcGroundColor:(UIColor *)backGroundColor borderColor:(UIColor *)borderColor lineColor:(UIColor *)lineColor lineWidth:(CGFloat)lineWidth contentSize:(CGSize)contentSize radius:(CGFloat)radius dashEnable:(BOOL)dashEnable leftArrowEnable:(BOOL)leftArrowEnable rightArrowEnable:(BOOL)rightArrowEnable;

+ (void)generatePathWithContext:(CGContextRef)context rect:(CGRect)rect radius:(CGFloat)radius;


+ (UIImage *)borderIconWithBackGroundColor:(UIColor *)backGroundColor borderColor:(UIColor *)borderColor contentSize:(CGSize)contentSize radius:(CGFloat)radius;

// 渐变色图片
+ (UIImage *)gradientColorImageFromColors:(NSArray*)colors imgSize:(CGSize)imgSize;
- (UIImage *)imageWithMaxSide:(CGFloat)maxSide;     //等比压缩图片，并且最大边距为maxSide
- (UIImage *)imageWithCornerRadius:(float)cornerRadius;   //设置图片圆角
- (UIImage *)imageByApplyingAlpha:(CGFloat)alpha;         //设置图片透明度
- (UIImage *)compressQualityWithMaxLength:(NSInteger)maxLength; //压缩图片到指定大小
+ (UIImage *)qrCodeImageWithString:(NSString *)text size:(CGSize)size;      //将文本生成相应的二维码图片

// 裁剪图片
- (UIImage*)subImageWithRect:(CGRect)rect;

/**
 拼接图片
 imageArray 图片数组
 width 拼接后的图片宽度
 要求传入的图片宽度最好和width一致，不一致的会等比缩放再拼接
 */
+ (UIImage *)combinedImagefromArray:(NSArray *)imageArray width:(CGFloat)width;

/**
 The right horizontal end-cap size. (read-only)
 
 End caps specify the portion of an image that should not be resized when an image is stretched. This technique is used
 to implement buttons and other resizable image-based interface elements. When a button with end caps is resized, the
 resizing occurs only in the middle of the button, in the region between the end caps. The end caps themselves keep
 their original size and appearance.
 
 This property specifies the size of the left end cap. The middle (stretchable) portion is assumed to be `1` pixel wide.
 
 By default, this property is set to `0`, which indicates that the image does not use end caps and the entire image is
 subject to stretching. To create a new image with a nonzero value for this property, use the
 `stretchableImageWithLeftCapWidth:topCapHeight:` method.
 */
@property (nonatomic, readonly) NSInteger rightCapWidth;

/**
 The bottom vertical end-cap size. (read-only)
 
 End caps specify the portion of an image that should not be resized when an image is stretched. This technique is used
 to implement buttons and other resizable image-based interface elements. When a button with end caps is resized, the
 resizing occurs only in the middle of the button, in the region between the end caps. The end caps themselves keep
 their original size and appearance.
 
 This property specifies the size of the top end cap. The middle (stretchable) portion is assumed to be `1` pixel wide.
 
 By default, this property is set to `0`, which indicates that the image does not use end caps and the entire image is
 subject to stretching. To create a new image with a nonzero value for this property, use the
 `stretchableImageWithLeftCapWidth:topCapHeight:` method.
 */
@property (nonatomic, readonly) NSInteger bottomCapHeight;

//如果图片通过网络下载，那么将可以记录其源地址
@property (nonatomic, copy) NSURL    * sorceURL;


/**
 Rounds a new image with a given corner size.
 
 @param radius  The radius of each corner oval. Values larger than half the
 rectangle's width or height are clamped appropriately to half
 the width or height.
 */
- (nullable UIImage *)imageByRoundCornerRadius:(CGFloat)radius;

/**
 Rounds a new image with a given corner size.
 
 @param radius       The radius of each corner oval. Values larger than half the
                     rectangle's width or height are clamped appropriately to
                     half the width or height.
 
 @param borderWidth  The inset border line width. Values larger than half the rectangle's
                     width or height are clamped appropriately to half the width
                     or height.
 
 @param borderColor  The border stroke color. nil means clear color.
 */
- (nullable UIImage *)imageByRoundCornerRadius:(CGFloat)radius
                                   borderWidth:(CGFloat)borderWidth
                                   borderColor:(nullable UIColor *)borderColor;

/**
 Rounds a new image with a given corner size.
 
 @param radius       The radius of each corner oval. Values larger than half the
                     rectangle's width or height are clamped appropriately to
                     half the width or height.
 
 @param corners      A bitmask value that identifies the corners that you want
                     rounded. You can use this parameter to round only a subset
                     of the corners of the rectangle.
 
 @param borderWidth  The inset border line width. Values larger than half the rectangle's
                     width or height are clamped appropriately to half the width
                     or height.
 
 @param borderColor  The border stroke color. nil means clear color.
 
 @param borderLineJoin The border line join.
 */
- (nullable UIImage *)imageByRoundCornerRadius:(CGFloat)radius
                                       corners:(UIRectCorner)corners
                                   borderWidth:(CGFloat)borderWidth
                                   borderColor:(nullable UIColor *)borderColor
                                borderLineJoin:(CGLineJoin)borderLineJoin;
 
@end
