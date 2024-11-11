//
//  TBOptionScreenerRecommendCell.h
//  Pods
//
//  Created by zlc on 2022/5/18.
//  
//

#import <TBUIKit/TBTableViewCell.h>
#import "TBOptionScreenerRecommendModel.h"

@class TBOptionScreenerRecommendOption;

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionScreenerRecommendCellItem : TBTableViewCellItem

@property (nonatomic, assign) BOOL isIncomeType; // rate or delta

@property (nonatomic, copy) NSString *market;
@property (nonatomic, strong) TBOptionScreenerRecommendOption *option;

@property (nonatomic, copy) NSString *rate;
@property (nonatomic, copy) NSString *rateTips;

@property (nonatomic, copy) NSAttributedString *optionAttributedString;
@property (nonatomic, copy) NSString *latestPrice;
@property (nonatomic, copy) NSString *change;
@property (nonatomic, copy) NSString *changeRate;
@property (nonatomic, copy) UIColor *changeColor;

@property (nonatomic, strong, readonly) NSNumber *changeNumber;

@property (nonatomic, copy, readonly) NSString *optionSymbol;

- (void)updateChangeRateAndLatestPrice;

@end

@interface TBOptionScreenerRecommendCell : TBTableViewCell

@end

NS_ASSUME_NONNULL_END
