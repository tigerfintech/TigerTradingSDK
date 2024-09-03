//
//  TBRSPListModel.h
//  TBTradeBusiness
//
//  Created by swordzhou on 2022/11/2.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@class TBRSPInfoModel;
@class TBRSPFilterModel;

@protocol TBRSPInfoModel;
@protocol TBRSPFilterModel;
@protocol TBRSPListHeaderItemModel;

@interface TBRSPListHeaderItemModel : JSONModel

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *key;

@end

@interface TBRSPListModel : JSONModel

@property (nonatomic, strong) NSNumber *totalPage;
@property (nonatomic, strong) NSNumber *page;
@property (nonatomic, strong) NSNumber *total;

@property (nonatomic, copy) NSArray <TBRSPInfoModel> *items;
@property (nonatomic, copy) NSArray <TBRSPFilterModel> *filters;

@property (nonatomic, copy) NSArray <NSString*> *headers;
@property (nonatomic, copy) NSArray <NSString*> *keys;

@property (nonatomic, copy) NSArray <TBRSPListHeaderItemModel*> *listHeaders; ///< 解析headers keys放到这里

@property (nonatomic, copy) NSString *sortField;     /// riReturn1Yr riReturn2Yr riReturn3Yr riReturn5Yr
@property (nonatomic, copy) NSString *sort;          /// desc asc

@end

NS_ASSUME_NONNULL_END
