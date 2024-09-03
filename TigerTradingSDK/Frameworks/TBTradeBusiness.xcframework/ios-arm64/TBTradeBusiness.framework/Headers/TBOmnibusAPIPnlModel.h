//
//  TBOmnibusAPIPnlModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 个股已实现盈亏
@interface TBOmnibusAPIPnlDataModel : JSONModel

@property (nonatomic, copy) NSString *symbol;   // 股票代码
@property (nonatomic, copy) NSString *nameCn;   // 股票名称
@property (nonatomic, assign) CGFloat pnl;      // 已实现盈亏

@end

@protocol TBOmnibusAPIPnlDataModel;
@interface TBOmnibusAPIPnlModel : TBOmnibusAPIModel

@property (nonatomic, copy) NSArray<TBOmnibusAPIPnlDataModel> *data;

@end

NS_ASSUME_NONNULL_END
