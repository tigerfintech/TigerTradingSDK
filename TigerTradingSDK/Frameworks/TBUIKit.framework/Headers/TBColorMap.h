//
//  TBColorMap.h
//  TBColorKit
//
//  Created by zhengzhiwen on 2021/5/19.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

NS_ASSUME_NONNULL_BEGIN

/*
 改枚举类，定义了 TigerTrade 和 TradeUP 所有的色号
 部分色号是 TigerTrade 独有的，例如：B23
 部分色号是 TradeUP 独有的，例如：A17
 如果取不到对应的色号，相关 Color 会返回 nil
 **/

/**
 色号对应的色值，可以通过 TigerTradeColor.plist 和 TradeUP.plist 查看
 色值色号映射表:https://tigertech.feishu.cn/sheets/shtcnYXKAYhlck5pw9EsOMH2Jtd
 */
typedef NS_ENUM(NSInteger, TBColorType) {
    TBColorTypeA0,
    TBColorTypeA1,
    TBColorTypeA2,
    TBColorTypeA3,
    TBColorTypeA4,
    TBColorTypeA5,
    TBColorTypeA6,
    TBColorTypeA7,
    TBColorTypeA9,
    TBColorTypeA10,
    TBColorTypeA11,
    TBColorTypeA12,
    TBColorTypeA13,
    TBColorTypeA14,
    TBColorTypeA16,
    TBColorTypeA17,
    TBColorTypeA18,
    TBColorTypeA21,
    TBColorTypeA22,
    TBColorTypeA25,
    TBColorTypeB1,
    TBColorTypeB2,
    TBColorTypeB3,
    TBColorTypeB4,
    TBColorTypeB5,
    TBColorTypeB6,
    TBColorTypeB7,
    TBColorTypeB8,
    TBColorTypeB9,
    TBColorTypeB10,
    TBColorTypeB11,
    TBColorTypeB12,
    TBColorTypeB13,
    TBColorTypeB15,
    TBColorTypeB16,
    TBColorTypeB17,
    TBColorTypeB18,
    TBColorTypeB19,
    TBColorTypeB20,
    TBColorTypeB21,
    TBColorTypeB22,
    TBColorTypeB23,
    TBColorTypeB24,
    TBColorTypeB25,
    TBColorTypeB26,
    TBColorTypeB27,
    TBColorTypeB28,
    TBColorTypeB29,
    TBColorTypeB30,
    TBColorTypeB31,
    TBColorTypeB32,
    TBColorTypeB34,
    TBColorTypeC5,
    TBColorTypeC6,
    TBColorTypeC7,
    TBColorTypeC8,
    TBColorTypeC9,
    TBColorTypeC10,
    TBColorTypeC11,
    TBColorTypeC12,
    TBColorTypeC13,
    TBColorTypeC14,
    TBColorTypeC15,
    TBColorTypeC16,
    TBColorTypeC17,
    TBColorTypeE7,
    TBColorTypeE8,
    TBColorTypeE9,
    TBColorTypeS1,
    TBColorTypeS2,
    TBColorTypeS3,
    TBColorTypeS4,
};


#define TBColorMapWithType(type) [[TBColorMap sharedInstance] colorWithType:type]

@interface TBColorMap : NSObject

DECLARE_SHARED_INSTANCE(TBColorMap)

//TigerTrade 黑蓝白
//TradeUp 白/黑 解析的时候需要分开处理
- (UIColor *)colorWithType:(TBColorType)type;

//现在只有TigerTrade使用，带渐变颜色
- (UIColor *)colorWithType:(TBColorType)type size:(CGSize)size;

//获取 type 对应的所有颜色
- (NSArray<UIColor *> *)colorsWithType:(TBColorType)type;

- (UIColor *)colorWithType:(TBColorType)type skinType:(NSInteger)skinType;

@end

NS_ASSUME_NONNULL_END
