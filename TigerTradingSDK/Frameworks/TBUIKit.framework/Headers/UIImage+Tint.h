//
//  UIImage+Tint.h
//  Stock
//
//  Created by luopengfei on 2018/4/26.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

/// 获取图片资源，不会根据主题颜色获取图片
#define TBResourcesImage(imageName) [UIImage tb_imageNamed: imageName]

/// 获取图片资源，会根据主题颜色获取图片，与colorImageNamed 逻辑相同
#define TBResourcesThemeImage(imageName) [UIImage tb_themeImageNamed: imageName]

/// 获取多语言图片资源，不会根据主题颜色获取图片
#define TBResourcesLocalizableImage(imageName) [UIImage tb_localizedImageNamed: imageName]

/// 获取多语言图片资源，会根据主题颜色获取图片
#define TBResourcesLocalizableThemeImage(imageName) [UIImage tb_localizedThemeImageNamed: imageName]


@interface UIImage (Tint)
//调用此方法会根据当前皮肤样式给图片染色，必须配合视图的tintColor一起使用
//改变皮肤样式后只需设置视图的tintColor即可改变图片颜色
- (UIImage *)tintedImage;

//调用此方法会根据当前皮肤样式给图片染色，不需要设置视图的tintColor
//改变皮肤样式后，必须重新调用此方法传入新的image
- (UIImage *)blendedImage;

- (UIImage *)blendedImageWithColor:(UIColor *)color;

//调用此方法会根据当前皮肤样式获取对应样式的图片，不能染色的情况下使用
+ (UIImage *)colorImageNamed:(NSString *)name;

//调用此方法会根据当前皮肤样式获取对应样式的图片名称，注意只是名称
+ (NSString *)themeImageNameWithDefaultName:(NSString *)name;

/// 从TBResources 获取图片资源，不会根据主题颜色获取图片
/// @param name 图片名称
+ (UIImage *)tb_imageNamed:(NSString *)name;

/// 从TBResources 获取图片资源，蓝白共用一套，黑金用一套
/// @param name 图片名称
/// @param hasGoldenImage 是否有金色皮肤
+ (UIImage *)tb_imageNamed:(NSString *)name hasGoldenImage:(BOOL)hasGoldenImage;

/// 从TBResources 获取图片资源，会根据主题颜色获取图片，与colorImageNamed 逻辑相同
/// @param name 图片名称
+ (UIImage *)tb_themeImageNamed:(NSString *)name;

/// 从TBResources 获取图片资源，根据需求是否需要根据主题颜色获取图片
/// @param name 图片名称
/// @param needThemeImage 是否需要根据主题颜色获取图片资源
+ (UIImage *)tb_imageNamed:(NSString *)name needThemeImage:(BOOL)needThemeImage;


///  从TBResources 获取多语言图片资源，不会根据主题颜色获取图片
/// @param name 图片名称
+ (UIImage *)tb_localizedImageNamed:(NSString *)name;

/// 从TBResources 获取多语言图片资源，会根据主题颜色获取图片
/// @param name 图片名称
+ (UIImage *)tb_localizedThemeImageNamed:(NSString *)name;



@end
