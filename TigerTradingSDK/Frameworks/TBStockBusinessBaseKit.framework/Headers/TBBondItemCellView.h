//
//  TBBondItemCellView.h
//  StockBusiness
//
//  Created by liuhuan on 2024/3/11.
//  Copyright © 2024 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBBondItemCellView : UIView

@property (nonatomic, strong) UILabel *tenorValueLabel;
@property (nonatomic, strong) UILabel *tenorTitleLabel;
@property (nonatomic, strong) UILabel *ytmValueLabel;
@property (nonatomic, strong) UILabel *ytmTitleLabel;
@property (nonatomic, strong) UILabel *nameLabel;
@property (nonatomic, strong) UIView *lineView;

- (void)setTenor:(NSString *)tenor;
- (void)setYTM:(NSNumber *)ytm;
- (void)setName:(NSString *)name date:(NSString *)date currency:(NSString *)currency;

@end

NS_ASSUME_NONNULL_END
