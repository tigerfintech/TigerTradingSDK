//
//  TBSNShareModel.h
//  TBTradeBusinessBaseKit
//
//  Created by dulijun on 2023/11/20.
//

#import <TBBaseKit/TBBaseModel.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *TBSNShareType;

FOUNDATION_EXPORT TBSNShareType const _Nonnull kTBSNShareTypeFCN;  // 分享的结构化票据类型为FCN


@interface TBSNShareModel : TBBaseModel

@property (nonatomic, copy) TBSNShareType snShareType; ///< 分享的结构化票据类型（比如：FCN：kTBSNShareTypeFCN）
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *currency; ///< 币种
@property (nonatomic, strong) NSNumber *tenor; ///< 期限
@property (nonatomic, strong) NSNumber *couponPercentage; ///< 年化票息

// 埋点所需
@property (nonatomic, copy) NSString *utm_campaign; ///< 标的代码
@property (nonatomic, copy) NSString *utm_source; ///< 来源

@end

NS_ASSUME_NONNULL_END
