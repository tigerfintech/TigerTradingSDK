//
//  TBOptionPriceTableViewCell.h
//  Stock
//
//  Created by 骆朋飞 on 2017/8/10.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

@protocol TBOptionPriceTableViewCellDelegate <NSObject>

- (NSString *)latestPriceString;
- (NSString *)changeString;
- (UIColor *)latestPriceColor;

- (NSNumber *)latestPrice;
- (NSNumber *)preClose;

@end

@interface TBOptionPriceTableViewCell : TBTableViewCell

@end


@interface TBOptionPriceTableViewCellItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *market;
@property (nonatomic, weak) id<TBOptionPriceTableViewCellDelegate> dataSource;
@property (nonatomic, strong) NSMutableArray *optionPermissions;

@end
