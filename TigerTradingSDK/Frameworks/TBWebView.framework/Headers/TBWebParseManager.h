//
//  TBWebParseManager.h
//  ACETelPrompt
//
//  Created by linbingjie on 2021/8/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBWebParseManager : NSObject

+ (BOOL)shouldJumptoNative:(NSString *)linkUrl;
+ (BOOL)shouldJumptoNative:(NSString *)linkUrl fromAD:(BOOL)fromAD;
+ (BOOL)shouldJumptoNative:(NSString *)urlStr fromAD:(BOOL)fromAD arriveFrom:(NSString *)arriveFrom;
+ (BOOL)shouldJumptoNative:(NSString *)urlStr fromAD:(BOOL)fromAD symbol:(nullable NSString *)stockSymbol;
+ (BOOL)shouldJumptoNative:(NSString *)urlStr fromAD:(BOOL)fromAD RNThemeId:(nullable NSString *)RNThemeId;
+ (BOOL)shouldJumptoNative:(NSString *)urlStr fromAD:(BOOL)fromAD symbol:(nullable NSString *)stockSymbol RNThemeId:(nullable NSString *)RNThemeId arriveFrom:(NSString *)arriveFrom;
+ (BOOL)shouldJumptoNative:(NSString *)urlStr fromAD:(BOOL)fromAD symbol:(nullable NSString *)stockSymbol RNThemeId:(nullable NSString *)RNThemeId arriveFrom:(NSString *)arriveFrom outerParams:(nullable NSDictionary *)outerParams;

+ (NSString *)parseStockSymbol:(NSString *)linkUrl;
//判断是否是跳转到搜索
+ (NSString *)parseSearchKeyword:(NSString *)linkUrl;

+ (BOOL)jumpToURLPath:(NSString *)jPath;

/// 从URL跳转到页面
/// - Parameters:
///   - jPath: laohu8.com/J/前缀的url, 去掉query, 映射成urlAction跳转
///   - urlQuery: 将url.query转成字典, 对应urlAction.query
///   - originPath: 保留query的原始url, 用于传给webview打开
+ (BOOL)jumpToURLPath:(NSString *)jPath urlQuery:(NSDictionary *)urlQuery originPath:(NSString *)originPath;

@end

NS_ASSUME_NONNULL_END
