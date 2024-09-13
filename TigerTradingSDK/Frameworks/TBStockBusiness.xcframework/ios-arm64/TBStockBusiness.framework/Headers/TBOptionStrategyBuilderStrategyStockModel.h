//
//  TBOptionStrategyBuilderStrategyStockModel.h
//  TBStockBusiness
//
//  Created by zlc on 2022/8/9.
//

#import <TBBaseKit/TBObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionStrategyBuilderStrategyStockModel : TBObject

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, assign) NSInteger shares; // 默认1手
@property (nonatomic, copy) NSString *trade; // 买卖方向，同optionModel字段保持一致，默认买入

@property (nonatomic, copy, readonly) NSString *combinedStockInfo; //eg: AAPL 100 shares

- (instancetype)initWithSymbol:(NSString *)symbol;

- (BOOL)isBuyAction;

@end

NS_ASSUME_NONNULL_END
