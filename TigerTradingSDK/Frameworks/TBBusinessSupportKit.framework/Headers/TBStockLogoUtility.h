//
//  TBStockLogoUtility.h
//  TBToolsKit
//
//  Created by mashanli on 17/8/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 根据标的信息获取logo
 */
@interface TBStockLogoUtility : NSObject

/**
 * 根据symbol获取图片，按照 缓存-兜底-SDWebImage(缓存-磁盘-网络)  的顺序获取
 * SDWebImage自带能力：网络获取到后，会放入缓存，并异步持久化到磁盘
 * 网络没获取到，使用兜底图，兜底图只放入缓存（后续网络接口可能更新图片）
 * @param symbol 通常是正股symbol
 * @param name 标的名称
 * @param secType secType 
 * @param completion 回调
 */
- (void)logoImageOfSymbol:(NSString *)symbol
                     name:(NSString *)name
                   market:(NSString *)market
                  secType:(NSString * _Nonnull)secType
               completion:(void (^)(UIImage * _Nonnull logoImage))completion;

/**
 * 根据originSymbol和secType，解析得到对应的正股symbol
 * @param originSymbol 包含symbol信息的原始数据
 */
//- (NSString *)stockUnderlyingSymbol:(NSString *)originSymbol secType:(NSString *)secType;

@end

NS_ASSUME_NONNULL_END
