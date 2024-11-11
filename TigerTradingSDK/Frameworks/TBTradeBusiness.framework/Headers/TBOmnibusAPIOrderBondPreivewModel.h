//
//  TBOmnibusAPIOrderBondPreivewModel.h
//  TBTradeBusiness
//
//  Created by 王昌阳 on 2024/1/2.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOmnibusAPIOrderBondPreivewModel : JSONModel

@property (nonatomic, strong) NSNumber *ytm;///< 到期收益率（yield to maturity）小于0时算不出具体的数，固定返回-0.00001
@property (nonatomic, strong) NSNumber *ptm;///< 到期总收益（profit to maturity）
@property (nonatomic, copy) NSString *currency;///< 币种

@end

NS_ASSUME_NONNULL_END
