//
//  TBStockAgreementManager.h
//  ACETelPrompt
//
//  Created by 骆鹏飞 on 2021/12/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockAgreementManager : NSObject

/// - 老虎社区服务协议
+ (NSString *)laohu8ServiceAgreement;

/// - 老虎社区守则（新）
+ (NSString *)laohu8RulesAgreement;

/// 老虎社区守则 海外（旧）
+ (NSString *)laohu8RulesOverSeaAgreement;

/// - 老虎社区账号管理规范
+ (NSString *)laohu8AccountManagerAgreement;

/// 隐私政策
+ (NSString *)privacyPolicyAgreement15;


/// 隐私政策摘要 8.0
+ (NSString *)privacyPolicyAgreementSummary;

/// 个人信息共享清单
+ (NSString *)privateInfoShareAgreement;

/// 第三方共享个人信息清单
+ (NSString *)thirdPartyShareAgreement;

/// 产品使用许可协议/用户协议
+ (NSString *)userAgreement12;

/// 根据协议获取 code
+ (NSString *)linkCodeWithLink:(NSString *)link;

@end

NS_ASSUME_NONNULL_END
