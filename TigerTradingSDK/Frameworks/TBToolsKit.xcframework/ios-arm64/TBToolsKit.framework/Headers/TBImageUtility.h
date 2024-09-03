//
//  TBImageUtility.h
//  TBBaseKit
//
//  Created by linbingjie on 2021/4/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define IMGVIEWO(obj)                                       [[UIImageView alloc] initWithImage:obj]
#define IMGO(obj)                                           [UIImage imageWithContentsOfFile:obj]
#define RESOURCEAT(name)                                    [NSString stringWithFormat:@"%@/%@.png", [[NSBundle mainBundle] resourcePath], name]

@interface TBImageUtility : NSObject

// 优化后压缩图片的方法
// 1 返回值为image
+ (UIImage *)compressedImageWithImage:(UIImage *)image toByte:(NSUInteger)maxLength;
// 2 返回值为data
+ (NSData *)compressedImageDataWithImage:(UIImage *)image toByte:(NSUInteger)maxLength;

//同步下载图片
+ (UIImage*)synchronousDownLoadImageFromUrl:(NSString *)url;

@end

NS_ASSUME_NONNULL_END
