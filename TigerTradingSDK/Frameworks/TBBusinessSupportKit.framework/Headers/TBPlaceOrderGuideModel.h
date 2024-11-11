//
//  TBPlaceOrderGuideModel.h
//  TBBusinessSupportKit
//
//  Created by dulijun on 2023/3/20.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBPlaceOrderGuideSymbolModel : JSONModel

// 任务规则文案
@property (nonatomic, copy) NSString *name;
// 奖励描述文案
@property (nonatomic, copy) NSString *pic;
// 合规文案
@property (nonatomic, copy) NSString *symbol;

@end

@protocol TBPlaceOrderGuideSymbolModel <NSObject>
@end

@interface TBPlaceOrderGuideModel : JSONModel

// 任务规则文案
@property (nonatomic, copy) NSString *taskRules;
// 奖励描述文案
@property (nonatomic, copy) NSString *rewardDes;
// 合规文案
@property (nonatomic, copy) NSString *complianceText;
// 活动标题
@property (nonatomic, copy) NSString *campaignDesTitle;
// 活动说明
@property (nonatomic, copy) NSString *campaignDes;
// symbol 列表
@property (nonatomic, copy) NSArray <TBPlaceOrderGuideSymbolModel>*symbols;

@end

NS_ASSUME_NONNULL_END
