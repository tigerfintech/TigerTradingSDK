//
//  TBRecommendTableViewCell.h
//  Stock
//
//  Created by 骆朋飞 on 2017/4/25.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

@protocol TBRecommendTableViewCell <NSObject>

- (NSString *)dateString;
- (NSString *)actionString;
- (NSString *)quantityString;
- (NSString *)priceString;

@end

@interface TBRecommendTableViewCell : TBTableViewCell
@property (nonatomic, strong) UILabel *dateLabel;
@property (nonatomic, strong) UILabel *instutionLabel;
@property (nonatomic, strong) UILabel *gradeLabel;
@property (nonatomic, strong) UILabel *priceLabel;
@end

@interface TBRecommendTableViewCellItem : TBTableViewCellItem
@property (nonatomic, strong) id<TBRecommendTableViewCell> dataSource;

@property (nonatomic, assign, getter=isHeader) BOOL header;
@end
