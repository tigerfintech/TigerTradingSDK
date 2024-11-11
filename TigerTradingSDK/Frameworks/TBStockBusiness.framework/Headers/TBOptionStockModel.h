//
//  TBOptionStockModel.h
//  TBOptionChain
//
//  Created by 王灵博 on 2021/5/26.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionStockModel : JSONModel
@property (nonatomic, copy) NSString *nameCN;
@property (nonatomic, copy) NSString *volume;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, strong) NSNumber *latestPrice;
@property (nonatomic, strong) NSNumber *preClose;
@property (nonatomic, strong) NSNumber *change;
@property (nonatomic, strong) NSNumber *halted;
@property (nonatomic, strong) NSNumber *changeRate;
- (TBOptionStockModel *)applyTitle:(NSString *)nameCN symbol:(NSString *)symbol latestPrice:(NSNumber *)latestPrice changeRate:(NSNumber *)changeRate marketType:(NSString *)marketType;

@end

@protocol TBOptionStockModel;
@interface TBOptionStockDataModel : JSONModel
@property(nonatomic,copy)NSArray <TBOptionStockModel> *items;
@end

NS_ASSUME_NONNULL_END
