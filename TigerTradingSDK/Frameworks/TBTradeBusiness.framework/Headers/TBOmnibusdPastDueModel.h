//
//  TBOmnibusdPastDueModel.h
//  TBTradeBusiness
//
//  Created by zhenglanchun on 2022/2/28.
//

#import <TBTradeBusinessBaseKit/TBOmnibusAPIModel.h>

NS_ASSUME_NONNULL_BEGIN

//即将到期持仓
@interface TBOmnibusdPastDueItemModel : JSONModel
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *nameCn;
@property (nonatomic, copy) NSString *nameEn;
@property (nonatomic, copy) NSString *nameZh;
//@property (nonatomic, assign) NSTimeInterval date;
@property (nonatomic, strong) NSNumber *cashSettle;
@property (nonatomic, copy) NSString *date;  //直接用服务端返回的日子
@end

@protocol TBOmnibusdPastDueItemModel <NSObject>
@end

@interface TBOmnibusdPastDueModel : TBOmnibusAPIModel
@property (nonatomic, copy) NSArray <TBOmnibusdPastDueItemModel> *data;
@end

NS_ASSUME_NONNULL_END
