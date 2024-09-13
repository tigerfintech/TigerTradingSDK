//
//  TBOptionPickPositionCell.h
//  TBStockBusiness
//
//  Created by 王灵博 on 2021/11/22.
//

#import <TBUIKit/TBTableViewCell.h>
typedef NS_ENUM(NSInteger, TBOptionPickType) {
    TBOptionPickTypePosition,
    TBOptionPickTypeTimeAndPrice,
    TBOptionPickTypeStrategy, ///< 策略
    TBOptionPickTypeAnnualizedRate, ///< 年化回报率
    TBOptionPickTypeDeltaRange, ///< delta 范围
};


NS_ASSUME_NONNULL_BEGIN

@interface TBOptionPickPositionCell : TBTableViewCell

@end

@interface TBOptionPickPositionCellItem : TBTableViewCellItem
@property(nonatomic, assign)TBOptionPickType pickType;
@property(nonatomic, assign)NSInteger selectIndex;
@property(nonatomic, copy) NSString *hold;
@property(nonatomic, copy) NSString *symbol;
@property(nonatomic, copy) NSString *priceTitle;
@property(nonatomic, copy) NSString *timeTitle;
@property(nonatomic, copy) NSString *trendTitle;
@property(nonatomic, copy) NSString *strategyTitle;
@property(nonatomic, strong) NSAttributedString *strategyAttributedString;

// TBOptionPickTypeAnnualizedRate 和 TBOptionPickTypeDeltaRange 使用
@property(nonatomic, copy) NSArray <NSString *>  *btnTitles;
@property(nonatomic, copy, readonly) NSString *selectedBtnTitle;

@end

NS_ASSUME_NONNULL_END
