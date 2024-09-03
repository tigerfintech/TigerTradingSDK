//
//  TBFuturesCategoryModel.h
//  Stock
//
//  Created by 胡金友 on 2018/7/4.
//  Copyright © 2018 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>

/*
 
 合约分类model
 
 */

NS_ASSUME_NONNULL_BEGIN

@interface TBFuturesCategoryModel : TBBaseModel

@property (copy, nonatomic) NSString *categoryId;       // 类别id
@property (copy, nonatomic) NSString *name;             // 类别英文名，股票端用这个作为展示名称
//@property (copy, nonatomic) NSString *nameCN;           // 类别中文名
@property (copy, nonatomic) NSString *securityType;     // 类别所属类型

@end

NS_ASSUME_NONNULL_END
