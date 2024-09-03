//
//  TBOmnibusContraAssetInfoModel.h
//  TBTradeBusinessBaseKit
//
//  Created by zlc on 2024/1/17.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOmnibusContraAssetInfoModel : JSONModel

@property (nonatomic, strong) NSNumber *outstandingAmount;          //!< contra-未抵消额度
@property (nonatomic, strong) NSNumber *offsetAmount;               //!< contra-可抵消额度
@property (nonatomic, strong) NSNumber *availableCreditAmount;      //!< contra-可用借贷额度
@property (nonatomic, strong) NSNumber *usedCreditAmount;            //!< contra-已使用借贷额度


@end

NS_ASSUME_NONNULL_END
