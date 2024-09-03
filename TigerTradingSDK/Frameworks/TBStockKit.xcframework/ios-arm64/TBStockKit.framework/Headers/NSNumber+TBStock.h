//
//  NSNumber+TBStock.h
//  TBStockKit
//
//  Created by 董恭甫 on 2023/4/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSNumber (TBStock)

/// 从数字转为用户设置的涨跌颜色
@property (nonatomic, readonly) UIColor *tb_upDownColor;

@end

NS_ASSUME_NONNULL_END
