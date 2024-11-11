//
//  TBStockDetailOrderBaseTableViewCell.h
//  Stock
//
//  Created by 骆鹏飞 on 2021/3/9.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import "TBStockDetailBaseTradeTableViewCell.h"


NS_ASSUME_NONNULL_BEGIN

@interface TBStockDetailOrderBaseTableViewCell : TBStockDetailBaseTradeTableViewCell

/// 买卖方向
@property (nonatomic, strong) UILabel *diretionLabel;

/// 订单类型
@property (nonatomic, strong) UILabel *typeLabel;

/// 条件单 or 止损限价单
@property (nonatomic, strong) UILabel *type2Label;

/// 订单数量
@property (nonatomic, strong) UILabel *countLabel;

/// icon 订单属性
@property (nonatomic, strong) UIImageView *orderIcon;
@property (nonatomic, strong) UIImageView *orderIcon2;

/// 订单状态:已提交/部分成交（部分成交数量@部分成交均价）
@property (nonatomic, strong) UILabel *statusLabel;



@end

@interface TBStockDetailOrderBaseTableViewCellItem : TBStockDetailBaseTradeTableViewCellItem


@property (nonatomic, assign) BOOL canShowOrderMessage;///< 是否展示订单信息：标的详情页中的订单列表展示 message; 点击交易按钮后的也展示 message；默认不展示

@end

NS_ASSUME_NONNULL_END
