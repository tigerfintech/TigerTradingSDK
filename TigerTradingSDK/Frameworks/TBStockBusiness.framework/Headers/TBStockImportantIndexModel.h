//
//  TBStockImportantIndexModel.h
//  Stock
//
//  Created by 王灵博 on 2020/7/16.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>

NS_ASSUME_NONNULL_BEGIN
@interface TBStockImportantIndexDetailModel : TBBaseModel
@property(nonatomic, copy)NSArray <NSArray <NSString *> *>*data;
@property(nonatomic, copy)NSArray <NSString *> * headers;
@property(nonatomic, copy)NSString *packageId;
@property(nonatomic, copy)NSString *name;
@property(nonatomic, assign)NSInteger page;
@property(nonatomic, assign)NSInteger totalCount;
@property(nonatomic, assign)NSInteger totalPage;
@end
@protocol TBStockImportantIndexDetailModel;
@interface TBStockImportantIndexModel : TBBaseModel
@property(nonatomic, copy)NSArray <TBStockImportantIndexDetailModel>*topics;
@property(nonatomic, strong)NSNumber *serverTime;
@end

NS_ASSUME_NONNULL_END
