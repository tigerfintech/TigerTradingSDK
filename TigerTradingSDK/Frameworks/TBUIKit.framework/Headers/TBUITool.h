//
//  TBUITool.h
//  TBUIKit
//
//  Created by zhengzhiwen on 2021/5/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBUITool : NSObject

/*
 自定义bundle中对应主题的图片名称，不同主题图片通过结尾区分：
 如果是白皮肤，名称结尾拼上"_skin2"；
 一般情况下，蓝黑共用一套图片，结尾不需要拼字符串；
 部分图片有黑皮肤专属图片，结尾需拼上"_skin0"；
 通过hasBlack区分是否有黑皮肤图片，默认为NO
 */
+ (NSString *)bundleThemeImageName:(NSString *)imageName hasBlackTheme:(BOOL)hasBlackTheme;

//这两个方法只有TBUIKit里用到了，先放到这里吧，如果放到TBStockKit不太合适，会导致TBUIKit依赖TBStockKit
/// 神奇九转 9 的icon
+ (NSString *)getIncreaseMagicPoint9;
+ (NSString *)getDecreaseMagicPoint9;

@end

NS_ASSUME_NONNULL_END
