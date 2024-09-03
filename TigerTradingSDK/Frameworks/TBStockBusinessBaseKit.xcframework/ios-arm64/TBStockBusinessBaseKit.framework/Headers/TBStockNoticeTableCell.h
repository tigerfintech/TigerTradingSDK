//
//  TBStockNoticeTableCell.h
//  StockBusiness
//
//  Created by liuhuan on 2024/4/1.
//  Copyright © 2024 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
#import "TBStockNoticeGroupTableCell.h"
#import "TBStockNoticeCellBaseConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBStockNoticeTableCell : TBTableViewCell <TBStockNoticeGroupTableCellProtocol>

// 标题标签
@property (nonatomic, strong, readonly) UILabel *titleLabel;
// 日历按钮
@property (nonatomic, strong, readonly) UIButton *dateButton;
// 操作按钮
@property (nonatomic, strong, readonly) UIButton *actionButton;
// 用于配置关闭按钮
@property (nonatomic, assign) BOOL closeButtonShow;
@property (nonatomic, copy, nullable) void(^closeButtonClick)(void);
// 标签点击弹窗标题
@property (nonatomic, copy, nullable) NSString *titleLabelClickTitle;
// 没别的用，只是用于方便埋点
@property (nonatomic, copy, nullable) void(^titleLabelBlock)(void);
@property (nonatomic, copy, nullable) void(^foldButtonBlock)(void);

- (void)setIconImage:(NSString *)image;
// 外部调用关闭
- (void)closeButtonClick:(nullable UIButton *)sender;
// 配置日历按钮状态并对应状态
- (BOOL)configDateButtonWithSymbol:(NSString *)symbol startDate:(NSDate *)startDate;
// 删除日历对应事件
- (void)removeDateEventWithSymbol:(NSString *)symbol startDate:(NSDate *)startDate;

@end

@interface TBStockNoticeTableCellItem : TBTableViewCellItem

@property (nonatomic, strong) id<TBStockNoticeCellConfig> config;

@end

NS_ASSUME_NONNULL_END
