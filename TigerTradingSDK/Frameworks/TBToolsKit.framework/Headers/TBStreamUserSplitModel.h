//
//  TBStreamUserSplitModel.h
//  Stock
//
//  Created by chenxin on 2020/6/5.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStreamUserSplitModel : JSONModel

@property (nonatomic, copy) NSString *splitId; // 实验id
@property (nonatomic, copy) NSString *key; // 实验key
@property (nonatomic, copy) NSString *valueType; //value类型, 目前只会出现 string
@property (nonatomic, copy) NSString *value; // value
@property (nonatomic, copy) NSString *license; // 实验涉及的牌照条件（可选）

@end

NS_ASSUME_NONNULL_END
