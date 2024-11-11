//
//  TBWealthCheckDataSource.h
//  AFNetworking
//
//  Created by wind on 2023/11/1.
//

#import <Foundation/Foundation.h>

@class TBWealthCheckBaseItem;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TBWealthCheckType) {
    TBWealthCheckTypeNone = 0,
    TBWealthCheckTypeLogin,  //登录
    TBWealthCheckTypeAccountOpened,  //开户
    TBWealthCheckTypeAccountFunded,  //入金
    TBWealthCheckTypePersonalInformation,  //个人信息填写
    TBWealthCheckTypeFundTrade,  //基金交易权限
    TBWealthCheckTypeCKA,  //TBSG 交易基金，需要先做 CKA
    TBWealthCheckTypeFundRiskRating,  //基金风险测评是否通过
    TBWealthCheckTypeFCNAbility,  //FCN 行情展示，不检查 FCN 交易能力
    TBWealthCheckTypeFCNConfigEnable, //FCN 用户配置展示
    TBWealthCheckTypeAICashMGMT,  //高净值理财，TBSG AI合格投资者，TBNZ PI合格投资者
    TBWealthCheckTypePI,
    TBWealthCheckTypeTradePermission,
    TBWealthCheckTypeRiskAssessment,
    TBWealthCheckTypeKnowledgeAssessment,
    TBWealthCheckTypeAI,            // precondition 接口AI检查
    TBWealthCheckTypeRegion,        // 居住国检查
    TBWealthCheckTypeWI,        // TFNZ wholesale 权限检查
    TBWealthCheckTypeOptShortPermission, // 检查期权做空权限 （AU）
    TBWealthCheckTypeOptSellQuestionnaire, // 检查期权做空权限问卷（AU）
    TBWealthCheckTypeOptBuyQuestionnaire, // 检查期权做多权限问卷（AU）
};

@interface TBWealthCheckDataSource : NSObject

+ (NSArray *)showFCNQuoteCheckTypes;

+ (NSArray *)showAICashMGMTCheckTypes;

+ (NSArray *)fundTradePreCheck;

+ (NSArray *)tigerVaultTradePreCheck;

- (NSArray<TBWealthCheckBaseItem *> *)checkItemsFromCheckTypes:(NSArray *)checkingTypes;

- (TBWealthCheckBaseItem *)checkItemFromCheckType:(TBWealthCheckType)checkingType;

/// 构建检查项
/// - Parameters:
///   - checkingTypes: 检查项对应的 type
///   - params: 检查项对应的参数，params 的 key 需要是对应的 @(TBWealthCheckType)
- (NSArray<TBWealthCheckBaseItem *> *)checkItemsFromCheckTypes:(NSArray *)checkingTypes params:(nullable NSDictionary<NSNumber *, NSDictionary *> *)params;


@end

NS_ASSUME_NONNULL_END
