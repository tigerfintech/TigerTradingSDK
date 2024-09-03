//
//  TBFundamentalDesModel.h
//  Stock
//
//  Created by 骆朋飞 on 2017/6/8.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>
#import <TBUIKit/TTHeader.h>
#import <TBStockBusinessBaseKit/TBStockDetailDesTableViewCell.h>

@protocol TBFundamentalItemModel <NSObject>
@end
@interface TBFundamentalItemModel : JSONModel <TBStockDetailDesTableViewCell>
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *des;
@end

@protocol TBFundamentalDesItemModel <NSObject>
@end
@interface TBFundamentalDesItemModel : JSONModel
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *desTitle;

@property (nonatomic, copy) NSArray<TBFundamentalItemModel> *sectionFlow;
@property (nonatomic, copy) NSArray<TBFundamentalItemModel> *section1;
@property (nonatomic, copy) NSArray<TBFundamentalItemModel> *section0;
@property (nonatomic, copy) NSDictionary *linkDict;

@property (nonatomic, readonly) TTURLAction *desItemAction;

@end

@interface TBFundamentalDesModel : JSONModel

@property (nonatomic, strong) TBFundamentalDesItemModel *capital;

@property (nonatomic, copy) NSArray<TBFundamentalDesItemModel> *fundamental;


@property (nonatomic, copy) NSArray<TBFundamentalDesItemModel> *keyStatistics;

@property (nonatomic, copy) NSArray<TBFundamentalDesItemModel> *interest;

@property (nonatomic, copy) NSArray<TBFundamentalDesItemModel> *dataVane;

@end
