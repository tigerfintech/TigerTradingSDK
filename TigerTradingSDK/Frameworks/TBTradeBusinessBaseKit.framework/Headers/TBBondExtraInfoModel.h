//
//  TBBondExtraInfoModel.h
//  TBTradeBusinessBaseKit
//
//  Created by swordzhou on 11/1/23.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

//国债额外信息
@interface TBBondExtraInfoModel : JSONModel

@property (nonatomic, strong) NSNumber *leavesInterest;     /// 剩余应计利息
@property (nonatomic, strong) NSNumber *filledInterest;     /// 成交应计利息

@end

NS_ASSUME_NONNULL_END
