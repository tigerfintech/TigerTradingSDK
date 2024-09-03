//
//  TBFuturesCategoryHotsModel.h
//  Stock
//
//  Created by 胡金友 on 2018/7/10.
//  Copyright © 2018 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>

NS_ASSUME_NONNULL_BEGIN

@class TBFuturesContractModel;
@class TBFuturesCategoryModel;


/*
 
 
 合约分类热门列表
 
 
 */


@interface TBFuturesCategoryHotsModel : TBBaseModel

@property (strong, nonatomic) TBFuturesCategoryModel *category;

@property (copy, nonatomic) NSArray <TBFuturesContractModel *> *hots; // 合约分类下热门列表

@property (copy, nonatomic) NSString *categoryId;       // 类别id

@end

NS_ASSUME_NONNULL_END
