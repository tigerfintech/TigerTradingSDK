//
//  TBPlaceOrderConditionItem.h
//  TBTradeBusiness
//
//  Created by 王昌阳 on 2022/3/30.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBPlaceOrderConditionItem;

@interface TBPlaceOrderConditionItem : JSONModel

@property (nonatomic, assign) NSInteger ID;///< 条件序号
@property (nonatomic, copy) NSString *type;///< 条件类型
@property (nonatomic, copy) NSString *value;///< 条件值
@property (nonatomic, copy) NSString *Operator;///< 条件运算符[EQ, NE, GT, LT, GE, LE]
@property (nonatomic, copy) NSString *conjunction;///< 条件连接符[AND, OR]

- (NSString *)conditionDesString;

- (NSString *)conditionTriggerTypeDes;

@end


NS_ASSUME_NONNULL_END
