//
//  TBShareToolbar.h
//  Stock
//
//  Created by ChenXin on 2017/11/27.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TBShareDefines.h"

#define kTBShareToolbarHeight (24 + 65 * 2 + 24 + 16 + 3 + 16)

@class TBShareViewController;

@protocol TBShareToolbarDelegate;

@interface TBShareToolbar : UIView

@property (nonatomic, weak) id <TBShareToolbarDelegate> delegate;

@property (nonatomic, copy) NSString *score; // 显示在按钮底部的积分信息（目前只有微信好友和朋友圈显示）

@property (nonatomic, assign) BOOL communityRec; // 社区按钮右上角是否显示推荐

/*
 默认设置全部可用第三方分享平台
 tigerPostEnable 是否允许分享到老虎社区，默认不允许
*/
- (instancetype)initWithTigerPostEnable:(BOOL)tigerPostEnable;

// 自定义设置分享平台
- (void)setupItemViewsWithTypes:(NSArray *)itemTypes;

// 自定义分享平台最多显示4个分享渠道，并水平居中,平均分配toolbar宽度
- (void)setupItemViewsWithAvgTypes:(NSArray *)itemTypes;

/// 展示动画（TradeUP添加的逻辑，TigerTrade是否使用待产品确认）
- (void)showAnimation;

@end

@protocol TBShareToolbarDelegate <NSObject>

@optional
- (void)shareToolbar:(TBShareToolbar *)shareToolbar didSelectWithPlatformType:(TBSharePlatformType)platformType;

// 新的分享delegate, 用于选择某一个平台的分享时, 给各业务代码一个机会执行自己的操作, 如统计
// 添加该方法是为了保持分享功能的纯净, 让业务代码和分享代码分离
// 和上面的旧delegate方法的区别是, 旧方法的思想是重写, 让一些特殊业务重写分享; 新方法是AOP
- (void)shareToolbar:(TBShareToolbar *)shareToolbar willSelectWithPlatformType:(TBSharePlatformType)platformType;

@end
