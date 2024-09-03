//
//  TBComboPositionStragegyModel.h
//  TBTradeBusiness
//
//  Created by swordzhou on 4/23/23.
//

#import <TBBaseKit/JSONModel.h>
#import "TBPositionLabelTypes.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TBComboPositionModel;

@interface TBComboPositionStragegyModel : JSONModel

@property (nonatomic, copy) NSString *comboType;
@property (nonatomic, copy) NSString *comboTypeDesc;
@property (nonatomic, copy) NSArray<TBPositionLabelType> *labels;

@property (nonatomic, copy) NSArray<TBComboPositionModel> *comboPositions;

@property (nonatomic, strong) NSNumber *quantity; // 组合合约的数量，可能为负数，传入时处理

- (BOOL)isMarginReducation;                          /// 是否保证金减免

@end

@interface TBComboPositionModel : JSONModel

@property (nonatomic, strong) NSNumber *contractId;       // 腿合约ID

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *expiry;
@property (nonatomic, copy) NSString *right;
@property (nonatomic, copy) NSString *strike;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, copy) NSString *action;

@property (nonatomic, strong) NSNumber *quantity;
@property (nonatomic, strong) NSNumber *multiplier;
@property (nonatomic, strong) NSNumber *ratio;

@property (nonatomic, copy) NSArray<TBPositionLabelType> *labels;

- (BOOL)isMarginReducation;                         /// 是否保证金减免

- (NSString *)originSymbol;

- (NSDictionary *)contractInfoDicForQuote:(NSString *)market;

@end

NS_ASSUME_NONNULL_END
