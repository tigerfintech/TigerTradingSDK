//
//  TBFontManaer.h
//  TBUIKit
//
//  Created by linbingjie on 2021/4/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TBFontSizeType) {
    TBFontSizeNormal,
    TBFontSizeBigger,
    TBFontSizeBiggest,
};


// BFF对应的key
static NSString *kTBFontSizeTypeKey  = @"FontSizeSettings";
// bff对应的value
static NSString *kTBBFF_Font_Default = @"Default";
static NSString *kTBBFF_Font_Normal  = @"Normal";
static NSString *kTBBFF_Font_Larger  = @"Larger";
static NSString *kTBBFF_Font_Maximum = @"Maximum";

@interface TBFontManager : NSObject

@property (nonatomic, assign, class) TBFontSizeType fontSizeType;

/// 不同字体大小对应的字号算法
/// - Parameter fontSize: 传入的算法
+ (NSInteger)adjustedFontSize:(NSInteger)fontSize;
+ (NSInteger)adjustedFontSize:(NSInteger)fontSize fontSizeType:(TBFontSizeType)type; // 传入指定type获取矫正后的font
    
    
// FONTO(value)
+ (UIFont *)fonto:(NSInteger)font;

/// FITSIZEFONTO
+ (UIFont *)fitSizeFonto:(NSInteger)font;

/// FITSMALLSIZEFONTO
+ (UIFont *)fitSmallSizeFonto:(NSInteger)font;

/// FITSMALLSIZEBoldFONTO
+ (UIFont *)fitSmallSizeBoldFonto:(NSInteger)font;

/// BOLDFONTO
+ (UIFont *)boldFonto:(NSInteger)font;

/// MEDFONTO
+ (UIFont *)medFonto:(NSInteger)font;

/// NUMFONTO
+ (UIFont *)numFonto:(NSInteger)font;

/// NUMBOLDFONTO
+ (UIFont *)numBoldFonto:(NSInteger)font;

// ================= 以下方法添加了 adjustFont 的方法 ===================

// FONTO(value)
+ (UIFont *)fonto:(NSInteger)font
       adjustFont:(BOOL)needAdjust;

/// FITSIZEFONTO
+ (UIFont *)fitSizeFonto:(NSInteger)font
              adjustFont:(BOOL)needAdjust;

/// FITSMALLSIZEFONTO
+ (UIFont *)fitSmallSizeFonto:(NSInteger)font
                   adjustFont:(BOOL)needAdjust;

/// FITSMALLSIZEBoldFONTO
+ (UIFont *)fitSmallSizeBoldFonto:(NSInteger)font
                       adjustFont:(BOOL)needAdjust;

/// BOLDFONTO
+ (UIFont *)boldFonto:(NSInteger)font
           adjustFont:(BOOL)needAdjust;

/// MEDFONTO
+ (UIFont *)medFonto:(NSInteger)font
          adjustFont:(BOOL)needAdjust;

/// NUMFONTO
+ (UIFont *)numFonto:(NSInteger)font
          adjustFont:(BOOL)needAdjust;

/// NUMBOLDFONTO
+ (UIFont *)numBoldFonto:(NSInteger)font
              adjustFont:(BOOL)needAdjust;

@end

NS_ASSUME_NONNULL_END
