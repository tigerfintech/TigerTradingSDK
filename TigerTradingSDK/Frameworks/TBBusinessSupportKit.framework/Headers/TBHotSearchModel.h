//
//  TBHotSearchModel.h
//  Stock
//
//  Created by yangfan on 2019/6/28.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TBHotSearchKeyword;
@protocol TBHotSearchStock;

@interface TBHotSearchKeyword : JSONModel

@property (nonatomic, copy) NSString * name;
@property (nonatomic, copy) NSString * link;
@property (nonatomic, assign) int64_t objectId;
@property (nonatomic, assign) NSInteger objectType;
@property (nonatomic, strong) NSNumber *secondaryType;
@property (nonatomic, assign) BOOL isHot;
@property (nonatomic, assign) BOOL isNew;
@property (nonatomic, assign) BOOL isAuto;

@end

@interface TBHotSearchStock : JSONModel

@property (nonatomic, copy) NSString * name;
@property (nonatomic, copy) NSString * symbol;
@property (nonatomic, copy) NSString * link;

@end

@interface TBHotSearchStar : JSONModel

@property (nonatomic, copy) NSString *link;
@property (nonatomic, copy) NSArray *userList;

@end

@interface TBHotSearchFund : JSONModel

@property (nonatomic, copy) NSString *period;

/*
 changeRate = 0.1559;
 fundName = "First Sentier Global Balanced A Acc USD";
 symbol = "SG9999000178.USD";
 */
@property (nonatomic, copy) NSArray *fundsList;

@end

@interface TBHotSearchModel : JSONModel

@property (nonatomic, copy) NSArray *sorted;
@property (nonatomic, copy) NSArray<TBHotSearchStock> *hotSymbolList;
@property (nonatomic, copy) NSArray<TBHotSearchKeyword> *hotSearchList;
@property (nonatomic, copy) TBHotSearchStar *starContributors;
@property (nonatomic, copy) TBHotSearchFund *topFunds;

@end

NS_ASSUME_NONNULL_END
