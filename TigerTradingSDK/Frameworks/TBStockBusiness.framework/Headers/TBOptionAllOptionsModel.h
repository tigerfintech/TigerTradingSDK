//
//  TBOptionAllOptionsModel.h
//  TBStockBusiness
//
//  Created by zlc on 2022/8/9.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBOptionAllOptionsItemModel;

@interface TBOptionAllOptionsModel : JSONModel

@property (nonatomic, assign) NSInteger ret;
@property (nonatomic, copy) NSArray <TBOptionAllOptionsItemModel> *items;

@end


@interface TBOptionAllOptionsItemModel : JSONModel

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, strong) NSNumber *isMonth;
@property (nonatomic, strong) NSNumber *expiry;
@property (nonatomic, copy) NSArray <NSString *> *strikes;

@end


NS_ASSUME_NONNULL_END
