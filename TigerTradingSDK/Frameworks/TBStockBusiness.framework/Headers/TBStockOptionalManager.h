//
//  TBStockOptionalManager.h
//  Stock
//
//  Created by 王灵博 on 2020/7/2.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseModel.h>
#import <TBStockBusiness/TBStockOptionalManager.h>
#import <TBBaseKit/TBBaseUtility.h>
typedef NS_ENUM(NSUInteger,TBStockOptionalType) {
    TBStockOptionalAllGroup,//可以加入系统分分组和自定义分组
    TBStockOptionalOnlySystemGroup//只加入系统分组
};
NS_ASSUME_NONNULL_BEGIN
@interface TBStockOptionalModel : TBBaseModel
@property(nonatomic,copy) NSString *symbol;
@property(nonatomic,copy) NSString *market;
@property(nonatomic,copy) NSString *nameCN;
@property(nonatomic,copy) NSString *secType;
@property(nonatomic,copy) NSString *addstr;
@property(nonatomic,copy) NSString *deleteStr;
@property(nonatomic,assign) TBStockOptionalType optionType;
@property(nonatomic,copy) NSString *sid;

@end
@interface TBStockOptionalManager : NSObject
DECLARE_SHARED_INSTANCE(TBStockOptionalManager);
@property(nonatomic ,copy)NSArray *ignoreGroups;
-(void)stockOptinonSelect:(BOOL)select optionalModel:(TBStockOptionalModel *)optionalModel select:(void (^)( BOOL select))block;
-(void)addWatchListWithOptionModels:(nonnull NSArray <TBStockOptionalModel *> *)optionalModels select:(nonnull void (^)(BOOL))block;

-(void)addOrRemoveWatchListWithOptionModels:(nonnull NSArray <TBStockOptionalModel *> *)optionalModels isAdd:(BOOL)isAdd completion:(nonnull void (^)(BOOL))block;

@end



NS_ASSUME_NONNULL_END
