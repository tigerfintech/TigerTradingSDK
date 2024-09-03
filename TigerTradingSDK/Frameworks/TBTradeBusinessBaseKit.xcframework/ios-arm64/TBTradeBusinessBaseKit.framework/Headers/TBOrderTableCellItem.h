//
//  TBOrderTableCellItem.h
//  Stock
//
//  Created by liwt on 15/1/6.
//  Copyright (c) 2015年 com.tigerbrokers. All rights reserved.
//

#import "TBOrderBaseTableViewCellItem.h"

@class TBMarketBriefPriceItemModel;

@interface TBOrderTableCellItem : TBOrderBaseTableViewCellItem

@property (nonatomic, assign) BOOL disableModify;
@property (nonatomic, assign) BOOL disableCancel;

// 废弃属性
@property (nonatomic, strong) NSNumber *clientId;
@property (nonatomic, strong) NSNumber *orderId;

@property (nonatomic, copy) NSString *account;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *nameCN;

@property (nonatomic, copy) NSString *strike;   //期权底层价格
@property (nonatomic, copy) NSString *right;    //期权PUT/CALL
@property (nonatomic, copy) NSString *expiry;   //期权过期日  按照EST yyyyMMdd format 的string.
@property (nonatomic, copy) NSString *secType;
@property (nonatomic, strong) NSNumber *multiplier;

@property (nonatomic, strong) NSNumber *liquidation; //1代表是系统强制平仓

@property (nonatomic, copy) NSString *operation; // action
@property (nonatomic, copy) NSString *orderType;
@property (nonatomic, strong) NSNumber *limitPrice;
@property (nonatomic, strong) NSNumber *latestPrice;

@property (nonatomic, strong) NSNumber *openTime;
@property (nonatomic, strong) NSNumber *totalQuantity;
@property (nonatomic, strong) NSNumber *filledQuantity;
@property (nonatomic, strong) NSNumber *avgFillPrice;
@property (nonatomic, copy) NSString *timeInForce;
@property (nonatomic, assign) BOOL outsideRth;

@property (nonatomic, strong) NSNumber *auxPrice; // stop price;
@property (nonatomic, copy) NSString *goodTillDate;
@property (nonatomic, strong) NSNumber *latestTime;
@property (nonatomic, strong) NSNumber *trailStopPrice;
@property (nonatomic, strong) NSNumber *trailingPercent;
@property (nonatomic, strong) NSNumber *status;

@property (nonatomic, copy) NSString *remark;

// 期货价格展示、行情展示
@property (nonatomic, strong) TBMarketBriefPriceItemModel *contractPriceModel;

@property (nonatomic, assign) BOOL hideReasonText;///< 是否隐藏 “原因：” 字符串，在 订单-待成交 订单列表 不显示，在 订单-已撤销 订单列表显示；默认不隐藏

@property (nonatomic, assign) BOOL showSelectOption;///< 是否展示 选中 icon (待成交订单列表在用，默认 NO)
@property (nonatomic, assign) BOOL selectState;///< 是否被选中 默认 NO

@property (nonatomic, assign) BOOL needShowTradeTimeTips;///< 是否需要显示交易提醒，只有综合账号显示
@property (nonatomic, copy) NSString *tradeTimeTips;///< 盘前盘后交易时间提醒文案，在 cellHeight 方法里面进行赋值，便于刷新同步

@property (nonatomic, copy) NSString *attachOrderMainOrderStatusDesc;///<  附加订单 对应的主订单的状态，只有成交的时候才显示

- (CGFloat)tradeTimeAlertHeight;

@end


@interface TBOrderTableCell : TBTableViewCell
@property (nonatomic, strong) UILabel *nameLabel;
@property (nonatomic, strong) UILabel *latestPriceLabel; // 被子类隐藏, 所以放在头文件

@property (nonatomic, strong) UIButton *symbolButton;
@property (nonatomic, strong) UIButton *detailButton;
@property (nonatomic, strong) UIButton *modifyButton;
@property (nonatomic, strong) UIButton *cancelButton;
@property (nonatomic, strong) UIButton *shareButton;

@property (nonatomic, strong) UIView *buttonContainerView;
@property (nonatomic, strong, readonly) UIView *tradeTimeAlertView;///< 交易提醒
@end
