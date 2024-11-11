#import <TBTradeBusinessBaseKit/TBOrderStatusConstants.h>
//
//  TBOrderStatusConstants.h
//  TBTradeBusiness
//
//  Created by swordzhou on 2021/8/4.
//

#ifndef TBOrderStatusConstants_h
#define TBOrderStatusConstants_h

typedef enum {
    TBOrderStatusInternalPendingSubmit  = -1,           // 服务器发给了ib 但是ib还没给返回状态.
    TBOrderStatusApiPending             = 0,            // 0 客户端应该收不到此类状态的订单
    TBOrderStatusAPiCancelled           = 1,            // 1 客户端应该收不到此类状态的订单
    TBOrderStatusPreSubmitted           = 2,            // 2 待提交
    TBOrderStatusPendingCancel          = 3,            // 3 待撤消
    TBOrderStatusCancelled              = 4,            // 4 已取消
    TBOrderStatusSubmitted              = 5,            // 5 已提交
    TBOrderStatusFilled                 = 6,            // 6 成交
    TBOrderStatusInactive               = 7,            // 7 已失效 (挂单过期没成交)
    TBOrderStatusPendingSubmit          = 8,            // 8 待提交
    TBOrderStatusUnknown                = 9,             // 9 未知 客户端应该收不到此类状态的订单
    TBOrderStatusPendingTrigger         = 100001,        //  综合账号，条件订单，条件待触发，手动赋值
} TBOrderStatus;

// 订单状态 order status
typedef NS_ENUM(NSInteger, TBTradeOrderStatus) {
    TBTradeOrderStatusInternalPendingSubmit  = -1,           // 服务器发给了ib 但是ib还没给返回状态.
    TBTradeOrderStatusApiPending             = 0,            // 0 客户端应该收不到此类状态的订单
    TBTradeOrderStatusAPiCancelled           = 1,            // 1 客户端应该收不到此类状态的订单
    TBTradeOrderStatusPreSubmitted           = 2,            // 2 待提交
    TBTradeOrderStatusPendingCancel          = 3,            // 3 待取消
    TBTradeOrderStatusCancelled              = 4,            // 4 已取消
    TBTradeOrderStatusSubmitted              = 5,            // 5 已提交
    TBTradeOrderStatusFilled                 = 6,            // 6 成交
    TBTradeOrderStatusInactive               = 7,            // 7 已失效 (挂单过期没成交)
    TBTradeOrderStatusPendingSubmit          = 8,            // 8 待提交
    TBTradeOrderStatusUnknown                = 9,            // 9 未知 客户端应该收不到此类状态的订单
    TBTradeOrderStatusPendingTrigger         = 100001,       // 综合账号，条件订单，条件待触发，手动赋值
};

typedef NS_ENUM(NSInteger, TBOrderTableCellButtonTag) {
    TBOrderTableCellButtonTagSymbol = 1,    // 个股
    TBOrderTableCellButtonTagDetail,        // 详情
    TBOrderTableCellButtonTagModify,        // 修改
    TBOrderTableCellButtonTagCancel,        // 撤销
    TBOrderTableCellButtonTagShare,         // 分享
    TBOrderTableCellButtonTagRelate,        // 关联订单
    TBOrderTableCellButtonTagPost,          // 交易观点
    TBOrderTableCellButtonTagOuterShare,    // 投资者分享订单到站外
    TBOrderTableCellButtonTagStarShare,     // 投资者分享订单
    TBOrderTableCellButtonTagCantStarShare, // 不可分享
};

#endif /* TBOrderStatusConstants_h */
