//
//  TBOptionStrategyBuilderOptionsSelectViewController.h
//  TBStockBusiness
//
//  Created by zlc on 2022/8/10.
//

#import <TBUIKit/TBListTableViewController.h>

NS_ASSUME_NONNULL_BEGIN

@class TBOptionAllOptionsItemModel;
@class TBOptionStrategyBuilderStrategyOptionModel;

@interface TBOptionStrategyBuilderOptionsSelectViewController : TBListTableViewController

@property (nonatomic, copy) NSString *market;
@property (nonatomic, strong) TBOptionStrategyBuilderStrategyOptionModel *defaultOptionModel; // 默认的期权信息
@property (nonatomic, strong, nullable) TBOptionStrategyBuilderStrategyOptionModel *selectedOptionModel; // 选中的期权信息
@property (nonatomic, copy) NSArray <TBOptionAllOptionsItemModel *> *allOptionsArray;
@property (nonatomic, copy) void(^cancelBlock)(void);
@property (nonatomic, copy) void(^confirmBlock)(NSNumber *expiry, NSString *strike, NSString *right);

- (instancetype)initWithMarket:(NSString *)market
            defaultOptionModel:(TBOptionStrategyBuilderStrategyOptionModel *)defaultOptionModel
           selectedOptionModel:(TBOptionStrategyBuilderStrategyOptionModel *)selectedOptionModel
               allOptionsArray:(NSArray <TBOptionAllOptionsItemModel *> *)allOptionsArray
                   cancelBlock:(void(^)(void))cancelBlock
                  confirmBlock:(void(^)(NSNumber *expiry, NSString *strike, NSString *right))confirmBlock;

+ (CGFloat)contentHeight;

@end

NS_ASSUME_NONNULL_END
