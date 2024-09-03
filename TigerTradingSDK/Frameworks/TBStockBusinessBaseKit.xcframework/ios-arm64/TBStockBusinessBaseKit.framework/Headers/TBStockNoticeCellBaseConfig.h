//
//  TBStockNoticeCellBaseConfig.h
//  StockBusiness
//
//  Created by liuhuan on 2024/4/1.
//  Copyright © 2024 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBUIKit/TBStockPrompView.h>

@class TBStockNoticeTableCell;

NS_ASSUME_NONNULL_BEGIN

@protocol TBStockNoticeCellConfig <NSObject>

@property (nonatomic, assign, readonly) TBStockPrompViewType type;

- (void)setData:(id)data;
- (void)setupConfigForCell:(TBStockNoticeTableCell *)cell;

@end

/// 基本通知配置
/// https://tigertech.feishu.cn/docx/EPrRdgg3JotnlGxWtEuceHTfnNh
@interface TBStockNoticeCellBaseConfig : NSObject <TBStockNoticeCellConfig>

- (instancetype)initWithType:(TBStockPrompViewType)type;

@end

NS_ASSUME_NONNULL_END
