//
//  UIImage+TYSnapshot.h
//  UITableViewSnapshotTest
//
//  Created by Tony on 2016/7/11.
//  Copyright © 2016年 TonyReet. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (TYSnapshot)

/**
*  拼接快照
*
*  @param imagesArr 快照的数组
*
*  @return 最终拼接的图片
*/
+ (UIImage *)getImageFromImagesArray:(NSArray *)imagesArr;


/**
 绘制图片
 
 @param color 背景色
 @param size 大小
 @param text 文字
 @param textAttributes 字体设置
 @param isCircular 是否圆形
 @return 图片
 */
+ (UIImage *)td_imageWithColor:(UIColor *)color
                          size:(CGSize)size
                          text:(NSString *)text
                textAttributes:(NSDictionary *)textAttributes
                      circular:(BOOL)isCircular;

@end
