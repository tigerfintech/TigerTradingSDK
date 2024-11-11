//
//  TBStockDetailDesTableViewCell.h
//  Stock
//
//  Created by 骆朋飞 on 2017/6/7.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

@protocol TBStockDetailDesTableViewCell <NSObject>

- (NSString *)titleString;

- (NSString *)desString;

@optional
- (UIColor *)desTextColor;
@end

@interface TBStockDetailDesTableViewCell : TBTableViewCell

@end

@interface TBStockDetailDesTableViewCellItem : TBTableViewCellItem

@property (nonatomic, strong) id<TBStockDetailDesTableViewCell> dataSource;

@property (nonatomic, assign) BOOL isExtension;

@property (nonatomic, assign) BOOL adjustActionTrigger;

@property (nonatomic, assign) BOOL showHiglight;///< 是否展示高亮文案

@property (nonatomic, assign) BOOL isFundAccountDes;///< 是否为基金数据指标说明

@end
