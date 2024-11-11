//
//  TBStockRightLikeModel.h
//  Stock
//
//  Created by 王灵博 on 2020/4/30.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>
#import <TBBaseKit/TBBaseModel.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBStockRightLikeModel : TBBaseModel
@property (nonatomic, strong)   NSNumber          * itemId;
@property (nonatomic, copy)   NSString          * logoLink;
@property (nonatomic, copy)   NSString          * market;
@property (nonatomic, copy)   NSString          * name;
@property (nonatomic, copy)   NSString          * symbol;
@property (nonatomic, copy)   NSString          * secType;
@property (nonatomic, copy)   NSString          * watchRation;
@property (nonatomic, copy)   NSArray           * lineItem;
@property (nonatomic, copy)   NSArray           * yValues;
@property (nonatomic, copy)   NSArray           * xValues;
@property (nonatomic, copy)   NSString          * onYearGain;
@property (nonatomic, copy)   NSString          * fiveYearGain;
@property (nonatomic, assign)  double          onYearFloat;
@property (nonatomic, strong)   UIColor          * onYearColor;
@property (nonatomic, strong)   UIColor          * fiveYearColor;
-(void)fetchLineDataSuccess:(void(^)(id responseObject))success
                    failure:(void(^)(NSError *error))failure;
@end

@protocol TBStockRightLikeModel;
@interface TBStockItemRightLikeModel : TBBaseModel
@property (nonatomic, copy) NSArray <TBStockRightLikeModel>*items;
@property (nonatomic, assign) NSInteger          page;
@property (nonatomic, assign) NSInteger          totalPage;
@end

@interface TBStockMainRightLikeModel : TBBaseModel
@property (nonatomic, copy)   NSString          * error_msg;
@property (nonatomic, strong) NSNumber          * is_succ;
@property (nonatomic, strong) TBStockItemRightLikeModel          * data;
@end

NS_ASSUME_NONNULL_END
