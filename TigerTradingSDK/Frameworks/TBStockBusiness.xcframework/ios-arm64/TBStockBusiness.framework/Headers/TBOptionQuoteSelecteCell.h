//
//  TBOptionQuoteSelecteCell.h
//  Stock
//
//  Created by JustLee on 2020/12/17.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
#import <TBUIKit/TBComponentCollectionViewHeader.h>

typedef NS_ENUM(NSUInteger, TBOptionQuoteTrendType) {
    TBOptionQuoteTrendTypeSurge, //股票大涨
    TBOptionQuoteTrendTypeSlump, //股票暴跌
    TBOptionQuoteTrendTypeClimb, //股票攀升
    TBOptionQuoteTrendTypeDrop   //股票下跌
};

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionQuoteSelecteCell : TBTableViewCell

@end


@interface TBOptionQuoteSelecteCellItem : TBTableViewCellItem

/// 当前行情趋势类型
@property (nonatomic, assign) TBOptionQuoteTrendType quoteTrendType;

/// 标的symbol
@property (nonatomic, copy) NSString *symbol;

/// 标的名称，可能没有 nameCN ?: symbol
@property (nonatomic, copy) NSString *nameCN;

@end


@interface TBOptionQuoteTrendItemCell : TBComponentCollectionCell

@end

@interface TBOptionQuoteTrendItemCellItem : TBComponentCollectionCellItem

/// 趋势类型
@property (nonatomic, assign) TBOptionQuoteTrendType quoteTrendType;

@property (nonatomic, assign, getter=isSelected) BOOL selected;

- (NSString *)displayText;

- (UIImage *)selectedDisplayImage;

- (UIImage *)normalDisplayImage;

@end

NS_ASSUME_NONNULL_END
