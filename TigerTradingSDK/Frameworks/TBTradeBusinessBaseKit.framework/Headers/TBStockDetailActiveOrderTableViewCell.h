//
//  TBStockDetailActiveOrderTableViewCell.h
//  Stock
//
//  Created by 骆鹏飞 on 2021/3/10.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBBusinessSupportKit/TBStockDetailOrderBaseTableViewCell.h>
#import <TBTradeBusinessBaseKit/TBPlaceOrderContactInfoDataSource.h>
@class TBStockDetailOrderEditPriceView;
@class TBTradeAPIPlaceOrderModel;
@class TBTradeAPIOrderItemModel;
@class TBStockDetailActiveOrderLegsInfoView;

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN NSString *const kStockDetailOrderFoldKey;

/*
 文件描述：个股详情页待成交订单类
 需求文档：https://wiki.tigerbrokers.net/pages/viewpage.action?pageId=77663550
 UI稿：https://app.mockplus.cn/app/NCghar47Li/specs/design/9MrlPBgdXW
 需求版本：699
 */
@interface TBStockDetailActiveOrderTableViewCell : TBStockDetailOrderBaseTableViewCell


/// 详情btn
@property (nonatomic, strong) UIButton *detailBtn;

/// 修改
@property (nonatomic, strong) UIButton *modifyBtn;

/// 撤单
@property (nonatomic, strong) UIButton *cancelBtn;

/// 订单描述
@property (nonatomic, strong) UILabel *desLabel;

/// 可编辑价格
@property (nonatomic, strong) TBStockDetailOrderEditPriceView *editPriceView;

/// 价格格式化formatter
@property (nonatomic, strong) NSNumberFormatter *price;

/// 改单
@property (nonatomic, strong) UIView *modifyBottomView;

/// 改单确认按钮
@property (nonatomic, strong) UIButton *modifyViewContinueBtn;

/// 该当取消按钮
@property (nonatomic, strong) UIButton *modifyViewCancelBtn;

/// 改单对象
@property (nonatomic, strong) TBTradeAPIPlaceOrderModel *placeOrderModel;

/// 是否在编辑
@property (nonatomic, assign) BOOL isEditingPrice;

@property (nonatomic, strong) UIView *attachReleationView;///< 附加订单主订单 标识


/// 附加订单线
@property (nonatomic, strong) UIView *subLineView;

@property (nonatomic, strong)  CAGradientLayer *leftGradientLayer;

@property (nonatomic, strong) TBStockDetailActiveOrderLegsInfoView *legsInfoView;

/// cdp tags
@property (nonatomic, strong) UIStackView *tagContainer;



- (void)updateEdtingStatus:(BOOL)isEditing;

- (void)updateTypeAndPrice:(TBTradeAPIOrderItemModel *)model;

- (void)updateOrderOperateBtnStatus:(TBTradeAPIOrderItemModel *)model;

@end

@interface TBStockDetailActiveOrderTableViewCellItem : TBStockDetailOrderBaseTableViewCellItem

@property (nonatomic, strong) id /*<TBStockDetailInfoDataSource>*/ secInfo;

@property (nonatomic, strong) TBTradeAPIOrderItemModel *orderModel;

/// 存储订单支持类型/有效期/保证金等信息
@property (nonatomic, weak) id<TBPlaceOrderContactInfoDataSource> contractInfo;

/// 改单对象
@property (nonatomic, strong) TBTradeAPIPlaceOrderModel *placeOrderModel;

/**
 * 是否支持contractInfo中获取tickSize
 * - 在期权详情页，不支持（默认状态，tickSize==0.01）
 * - 在组合期权详情页，支持
 */
@property (nonatomic, assign) BOOL isMlegMinTickEnable;

/// 是否在编辑
@property (nonatomic, assign) BOOL isEditingPrice;

/// 是否有父订单
@property (nonatomic, assign) BOOL hasParentOrder;

/// 是否有父OCA订单
@property (nonatomic, assign) BOOL hasParentOCAOrder;

/// 是否可以展示关联订单线
@property (nonatomic, assign) BOOL canShowAttchView;

@end

NS_ASSUME_NONNULL_END
