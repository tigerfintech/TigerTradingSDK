//
//  TBConstantUI.h
//  TBBaseKit
//
//  Created by linbingjie on 2021/1/28.
//

#ifndef TBConstantUI_h
#define TBConstantUI_h

// color
#define RGBCOLOR(r,g,b)                                     [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define RGBACOLOR(r,g,b,a)                                  [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
#define RGBCOLOR_HEX(h)                                     RGBCOLOR((((h)>>16)&0xFF), (((h)>>8)&0xFF), ((h)&0xFF))
#define RGBACOLOR_HEX(h,a)                                  RGBACOLOR((((h)>>16)&0xFF), (((h)>>8)&0xFF), ((h)&0xFF), (a))
#define RGBPureColor(h)                                     RGBCOLOR(h, h, h)
#define HSVCOLOR(h,s,v)                                     [UIColor colorWithHue:(h) saturation:(s) value:(v) alpha:1]
#define HSVACOLOR(h,s,v,a)                                  [UIColor colorWithHue:(h) saturation:(s) value:(v) alpha:(a)]
#define RGBA(r,g,b,a)                                       (r)/255.0f, (g)/255.0f, (b)/255.0f, (a)
#define RGBColor_HexString(hex)                             [TBCommonAppColor colorWithHexString:hex]
#define COLOR_FromRGB(rgbValue)                             [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]


#define K_1PX                                               (1.f / [UIScreen mainScreen].scale)

#define k_LeftOffset                                        (IS_IPHONE_5_OR_LESS ? 10 : 15.0f)
#define K_LinkWidth                                         1

// 列表分割条高度
#define kTableViewSectionSpace                              (6.0f)

#define kLeftToRightSpace (15.f)

#define kWarIoptChainItemWidth (90.f)


#endif /* TBConstantUI_h */
