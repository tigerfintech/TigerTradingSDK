//
//  TBStockListHeaderView.h
//  Stock
//
//  Created by zhenglanchun on 2021/5/20.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBStockBusinessBaseKit/TBStockListBaseView.h>

typedef NS_ENUM(NSInteger, TBStockListHeaderSortType){
    TBStockListHeaderSortTypeNormal   = 0,
    TBStockListHeaderSortTypeMiddleOneDes   = 1,
    TBStockListHeaderSortTypeMiddleOneInc   = 2,
    TBStockListHeaderSortTypeMiddleTwoDes   = 3,
    TBStockListHeaderSortTypeMiddleTwoInc   = 4,
    TBStockListHeaderSortTypeRightDes       = 5,
    TBStockListHeaderSortTypeRightInc       = 6
};

NS_ASSUME_NONNULL_BEGIN

@interface TBStockListHeaderView : TBStockListBaseView

/*
    | - left - (middleOne, middleTwo) - right - |
    对于3列的UI，middleTwo是被隐藏掉的；4列的UI，middleTwo被显示
 */

/// 控制是否显示所有的 sort icon，默认YES
@property (nonatomic, assign) BOOL showAllSortIcon;
//@property (nonatomic, assign) BOOL showLeftSort;
@property (nonatomic, assign) BOOL showMiddleOneSort;
@property (nonatomic, assign) BOOL showMiddleTwoSort;
@property (nonatomic, assign) BOOL showRightSort;

@property (nonatomic, strong) UIView *leftSortV;
@property (nonatomic, strong) UIView *middleOneSortV;
@property (nonatomic, strong) UIView *middleTwoSortV;
@property (nonatomic, strong) UIView *rightSortV;

@property (nonatomic, strong) UILabel *leftL;
@property (nonatomic, strong) UILabel *middleOneL;
@property (nonatomic, strong) UILabel *middleTwoL;
@property (nonatomic, strong) UILabel *rightL;

@property (nonatomic, strong) UIImageView *leftSortIV;
@property (nonatomic, strong) UIImageView *middleOneSortIV;
@property (nonatomic, strong) UIImageView *middleTwoSortIV;
@property (nonatomic, strong) UIImageView *rightSortIV;

@property (nonatomic, assign) TBStockListHeaderSortType sortType;

@property (nonatomic, copy) void (^tapMiddleOneSortCallback)(TBStockListHeaderSortType);
@property (nonatomic, copy) void (^tapMiddleTwoSortCallback)(TBStockListHeaderSortType);
@property (nonatomic, copy) void (^tapRightSortCallback)(TBStockListHeaderSortType);

@property (nonatomic, copy) NSString *leftText;
@property (nonatomic, copy) NSString *middleOneText;
@property (nonatomic, copy) NSString *middleTwoText;
@property (nonatomic, copy) NSString *rightText;


@end

NS_ASSUME_NONNULL_END
