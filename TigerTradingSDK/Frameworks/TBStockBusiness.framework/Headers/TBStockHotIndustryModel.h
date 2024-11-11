//
//  TBStockHotIndustryModel.h
//  Stock
//
//  Created by 王灵博 on 2020/7/27.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockHotIndustryModel : TBBaseModel
@property(nonatomic, copy)NSArray <NSString *>*headers;
@property(nonatomic, copy)NSString *itemId;
@property(nonatomic, copy)NSArray *items;
@property(nonatomic, copy)NSString *name;
@property(nonatomic, strong)NSNumber *serverTime;
@property(nonatomic, copy)NSString *titleName;
@end

NS_ASSUME_NONNULL_END
