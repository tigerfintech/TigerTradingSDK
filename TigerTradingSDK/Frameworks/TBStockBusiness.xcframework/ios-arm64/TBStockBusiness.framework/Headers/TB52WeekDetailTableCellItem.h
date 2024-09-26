//
//  TB52WeekDetailTableCellItem.h
//  Stock
//
//  Created by 马超 on 2017/5/2.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCellItem.h>
#import <TBUIKit/TBTableViewCell.h>

@interface TB52WeekDetailTableCellItem : TBTableViewCellItem
@property (nonatomic, copy) NSString *nameCN;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, strong) NSNumber *latestPrice;
@property (nonatomic, strong) NSNumber *preClose;
@property (nonatomic, strong) NSNumber *changeRate;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *secType;

@property (nonatomic, copy) NSString *lowestPrice;//52周最低价格
@property (nonatomic, copy) NSString *heightPrice;//52周最高价格

- (TB52WeekDetailTableCellItem *)applyTitle:(NSString *)nameCN symbol:(NSString *)symbol price:(NSNumber *)latestPrice changeRate:(NSNumber *)changeRate lowestPrice:(NSString *)lowestPrice heightPrice:(NSString *)heightPrice marketType:(NSString *)marketType;

@property (nonatomic, copy) NSString * displayLastestPrice;
@property (nonatomic, copy) NSString * displayChangeRate;
@property (nonatomic, copy) NSString * displayChangeAmount;  //期货涨跌额
@property (nonatomic, copy) NSString *arriveFrom;

@end

@interface TB52WeekDetailTableCell : TBTableViewCell

@property (nonatomic, strong) UILabel *lowestPriceLabel;
@property (nonatomic, strong) UILabel *heightPriceLabel;
@property (nonatomic, strong) UIImageView * watchedImageView;

@end
