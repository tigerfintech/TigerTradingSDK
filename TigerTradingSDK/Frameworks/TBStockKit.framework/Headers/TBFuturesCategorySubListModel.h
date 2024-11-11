//
//  TBFuturesCategorySubListModel.h
//  Stock
//
//  Created by 胡金友 on 2018/7/10.
//  Copyright © 2018 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>

NS_ASSUME_NONNULL_BEGIN

@class TBFuturesSymbolModel;
@class TBFuturesContractModel;

@interface TBFuturesCategorySubListModel : TBBaseModel

@property (copy, nonatomic) NSArray <TBFuturesContractModel *> *contracts; // 合约分类下热门列表

@property (strong, nonatomic) TBFuturesSymbolModel *symbol;

@end

NS_ASSUME_NONNULL_END
