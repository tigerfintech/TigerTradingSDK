//
//  UIColor+TBAddition.h
//  TBBaseUtils
//
//  Created by chenxin on 2020/9/27.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

// 宽度为screen width -30 的 gradient color
#define kGoldenSkinButtonGradientColor [UIColor tb_colorGradientChangeWithSize:CGSizeMake(SCREEN_WIDTH-30, 45) startColor:RGBCOLOR_HEX(0xFFEDBC) endColor:RGBCOLOR_HEX(0xCEA85E)]

// navbar中切换市场 的 gradient color
#define kGoldenSkinNavBarGradientColor [UIColor tb_colorGradientChangeWithSize:CGSizeMake(40, 40) startColor:RGBCOLOR_HEX(0xFFEDBC) endColor:RGBCOLOR_HEX(0xCEA85E)]

// 切换行情， 自选，新帖等等segment 的 gradient color
#define kGoldenSkinStockDetailSegmentGradientColor [UIColor tb_colorGradientChangeWithSize:CGSizeMake(60, 20) startColor:RGBCOLOR_HEX(0xFFEDBC) endColor:RGBCOLOR_HEX(0xCEA85E)]

// 切换交易，订单segment 的 gradient color
#define kGoldenSkinOrderSegmentGradientColor [UIColor tb_colorGradientChangeWithSize:CGSizeMake(100, 20) startColor:RGBCOLOR_HEX(0xFFEDBC) endColor:RGBCOLOR_HEX(0xCEA85E)]

// 切换交易，分析segment 的 gradient color
#define kGoldenSkinAnalysisSegmentGradientColor [UIColor tb_colorGradientChangeWithSize:CGSizeMake(150, 20) startColor:RGBCOLOR_HEX(0xFFEDBC) endColor:RGBCOLOR_HEX(0xCEA85E)]

// 切换分时segment 的 gradient color
#define kGoldenSkinCellSegmentGradientColor [UIColor tb_colorGradientChangeWithSize:CGSizeMake(30, 20) startColor:RGBCOLOR_HEX(0xFFEDBC) endColor:RGBCOLOR_HEX(0xCEA85E)]

// 根据size创建黑金皮肤文字渐变色
#define TBGoldenSkinTextGradientColor(size) [UIColor tb_colorGradientChangeWithSize:size startColor:RGBCOLOR_HEX(0xFFEDBC) endColor:RGBCOLOR_HEX(0xCEA85E)]

@interface UIColor (TBAddition)

// 渐变颜色，默认从左到右
+ (instancetype)tb_colorGradientChangeWithSize:(CGSize)size
                                    startColor:(UIColor*)startcolor
                                      endColor:(UIColor*)endColor;

+ (instancetype)tb_colorGradientChangeWithSize:(CGSize)size
                                    startColor:(UIColor*)startcolor
                                      endColor:(UIColor*)endColor
                                    startPoint:(CGPoint)startPoint
                                      endPoint:(CGPoint)endPoint;

/**
 Creates and returns a color object using the hex RGB color values.
 
 @param rgbValue  The rgb value such as 0x66ccff.
 
 @return          The color object. The color information represented by this
                  object is in the device RGB colorspace.
 */
+ (UIColor *)colorWithRGB:(uint32_t)rgbValue;

/**
 Creates and returns a color object using the hex RGBA color values.
 
 @param rgbaValue  The rgb value such as 0x66ccffff.
 
 @return           The color object. The color information represented by this
                   object is in the device RGB colorspace.
 */
+ (UIColor *)colorWithRGBA:(uint32_t)rgbaValue;

/**
 Creates and returns a color object using the specified opacity and RGB hex value.
 
 @param rgbValue  The rgb value such as 0x66CCFF.
 
 @param alpha     The opacity value of the color object,
                  specified as a value from 0.0 to 1.0.
 
 @return          The color object. The color information represented by this
                  object is in the device RGB colorspace.
 */
+ (UIColor *)colorWithRGB:(uint32_t)rgbValue alpha:(CGFloat)alpha;

@end

NS_ASSUME_NONNULL_END
