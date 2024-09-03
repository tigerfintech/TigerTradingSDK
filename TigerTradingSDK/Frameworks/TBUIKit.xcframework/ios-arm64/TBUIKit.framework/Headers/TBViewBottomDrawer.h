//
//  TBViewBottomDrawer.h
//  Stock
//
//  Created by xw.long on 15/10/16.
//  Copyright © 2015年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "TBViewitemChooseAlert.h"

typedef NS_ENUM(NSUInteger, VDrawerEvent) {
    VDrawerEventNone,
    VDrawerEventDelete,
    VDrawerEventCopy,
    VDrawerEventCommentDelete,
    VDrawerEventToReport,
    VDrawerEventToShare,
    VDrawerEventToReply,
    
    VDrawerEventWatchlistDelete,//自选删除
    VDrawerEventWatchlistSticky,//自选置顶
    VDrawerEventWatchlistToEnd, //自选置底
    VDrawerEventWatchlistAddGroup,//自选添加到分组
    VDrawerEventWatchlistBulk,  //自选批量编辑
    
    VDrawerEventMessagePostOriginal,  ///< 社区助手to查看
    VDrawerEventMessagePostBlock,//社区助手拉黑
    VDrawerEventMessagePostCancelBlock,//社区助手取消拉黑
    
    // 版主相关操作
    VDrawerEventModeratorPick,        // 加精
    VDrawerEventModeratorCancelPick,  // 取消精选
    VDrawerEventModeratorCancel,      // 删除
    VDrawerEventModeratorUnverified,  // 屏蔽
};

typedef void(^VBottomDrawerBlock)(VDrawerEvent event);

@interface TBViewBottomDrawer : UIView

@property (nonatomic, strong) TBViewitemChooseAlert *itemAlert;
@property (nonatomic, strong) UIImageView *imgvBack;
@property (nonatomic, assign) CGPoint touchP;

@property (nonatomic, copy) void(^singleTypeClicked)(ItemAlertSingleType type);

- (TBViewitemChooseAlert *)createItemAlert;
/*
 抽屉蒙层弹框中的按钮操作的回调block函数调用接口。
 */
-(void)vbottomEvent:(VBottomDrawerBlock)thisBlock;



/*
 初始化弹框蒙层
 帖子详情页面，长按弹出操作弹框。{[复制,删除][复制,举报]}
 弹框控件是：ItemAlertType。
 */
-(instancetype)initItemChooseTypeWithFrame:(CGRect)frame;
@property (nonatomic, assign) ItemAlertType alertType;//只用于上面这个copy delete report的弹框
@property (nonatomic, copy) NSArray *singleTypes;


-(void)setHidden:(BOOL)hidden;

@end
