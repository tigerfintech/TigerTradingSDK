//
//  TBOrderBaseTableViewCellItem.h
//  TBTradeBusinessBaseKit
//
//  Created by swordzhou on 2/22/24.
//

#import <TBUIKit/TBTableViewCellItem.h>
#import <TBUIKit/TBTableViewCell.h>
#import <TBUIKit/TBFont.h>
#import <TBUIKit/TBAppColor.h>

NS_ASSUME_NONNULL_BEGIN

// 改单的价格标签 颜色
#define kOrderReplacePriceColor [TBAppColor colorFromDark:0x7E829C white:0xA6A9B6]
// 改单的数量标签 颜色
#define kOrderReplaceCountColor [TBAppColor colorFromDark:0x7E829C white:0xA6A9B6]
// 改单的价格标签 字号
#define kOrderReplacePriceFont NUMFONTO(12)
// 改单的数量标签 字号
#define kOrderReplaceCountFont NUMFONTO(12)

@class TBTradeAPIOrderItemModel;
@class TBFuturesContractModel;

@interface TBOrderBaseTableViewCellItem : TBTableViewCellItem
{
}

@property (nonatomic, strong) TBTradeAPIOrderItemModel *orderModel;
@property (nonatomic, strong) TBFuturesContractModel *contractModel;

@property (nonatomic, assign) BOOL isOpen;
@property (nonatomic, assign) BOOL enableOpen;

// 交易分享 相关字段
@property (nonatomic, assign) BOOL shared; ///< 订单是否已经被认证的投资者分享过
@property (nonatomic, copy) NSString *tweetId; ///<  如果投资者分享了该订单 会返回该帖子id
@property (nonatomic, assign) BOOL canStarShare; ///< 是否可以作为订单帖分享观点
@property (nonatomic, assign) BOOL gt24h; ///< 是否已经超过了24小时 超过24小时则不可再分享
@property (nonatomic, copy) NSString *explanationOfGt24h; ///<  不可分享的原因
@property (nonatomic, assign) BOOL symbolInWhitelist; ///< 订单关联的标的 是否在白名单内
@property (nonatomic, assign) BOOL showQuantityCheckbox; ///< 改订单是否展示 显示股数按钮
@property (nonatomic, assign) BOOL hiddenShare; //默认隐藏分享按钮，现实需要去实现分享功能

@property (nonatomic, assign, readonly) BOOL hasShowBadge;

@property (nonatomic, assign) BOOL displayInOrderList;              ///< 是否在订单列表中展示，用于控制是否显示 综合账号 附加订单 主副标识
@property (nonatomic, assign) BOOL useCustomActions;                ///< 展开操作选项框是否为自定义事件
@property (nonatomic, copy) NSArray<NSNumber *> *customActions;     ///< 自定义事件

@property (nonatomic, assign) BOOL isAuthExchange;              ///Default:NO

- (NSArray *)getTagImages;

@end

NS_ASSUME_NONNULL_END
