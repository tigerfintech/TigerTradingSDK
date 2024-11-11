//
//  TBHKOptionListModel.h
//  Stock
//
//  Created by 王灵博 on 2020/8/13.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBBaseModel.h>

typedef NS_ENUM(NSUInteger,TBHKOptionNameType){
    TBHKOptionTotalOpenIntType,//总未平仓数
    TBHKOptionTotalOpenIntChangeType,//总未平仓涨跌
};

typedef NS_ENUM(NSUInteger,TBHKOptionSortType){
    TBHKOptionSortNoneType,
    TBHKOptionSortAseType,
    TBHKOptionSortDescType,
};

NS_ASSUME_NONNULL_BEGIN
@interface TBHKOptionItemModel : TBBaseModel
@property(nonatomic, copy)NSString *name;
@property(nonatomic, copy)NSString *market;
@property(nonatomic, copy)NSString *symbol;
@property(nonatomic, strong)NSNumber *openIntChange;
@property(nonatomic, strong)NSNumber *totalOpenInt;
@property(nonatomic, copy)NSString *underlyingSymbol;
@end
@protocol TBHKOptionItemModel;
@interface TBHKOptionListModel : TBBaseModel
@property(nonatomic, strong)NSNumber *serverTime;
@property(nonatomic, copy)NSArray <TBHKOptionItemModel> *items;
@end


@interface TBHKOptionSortModel : TBBaseModel
@property(nonatomic, assign)TBHKOptionNameType nameType;
@property(nonatomic, assign)TBHKOptionSortType sortType;
@property(nonatomic, copy)NSString *nameString;
@property(nonatomic, copy)NSString *sortString;
@property(nonatomic, copy)NSString *imgString;
@property(nonatomic, strong)NSMutableDictionary *sortMDic;
@end

NS_ASSUME_NONNULL_END
