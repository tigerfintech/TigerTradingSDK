//
//  TBOptionVolatilityChartCell.h
//  Stock
//
//  Created by 王灵博 on 2021/1/4.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionVolatilityChartCell : TBTableViewCell

@end


@interface TBOptionVolatilityChartCellItem : TBTableViewCellItem

@property(nonatomic, copy)NSString *market;
@property(nonatomic, copy)NSString *skewness;

@property (nonatomic, copy) NSArray *dateItems;

@property (nonatomic, assign) NSInteger selectedIndex;

@property (nonatomic, copy) NSDictionary *chartInfo;

@end

NS_ASSUME_NONNULL_END
