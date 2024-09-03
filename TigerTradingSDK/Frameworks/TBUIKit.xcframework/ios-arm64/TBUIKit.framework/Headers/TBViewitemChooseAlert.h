//
//  TBViewitemChooseAlert.h
//  Stock
//
//  Created by xw.long on 15/12/7.
//  Copyright © 2015年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, ItemAlertSingleType) {
    ItemAlertSingleTypeTop,
    ItemAlertSingleTypeDelete,
    ItemAlertSingleTypeEnd,
    ItemAlertSingleTypeGroup,
    ItemAlertSingleTypeEdit,
    ItemAlertSingleTypeRemark
};

typedef NS_ENUM(NSUInteger, ItemAlertType) {
    //社区
    ItemAlertTypeCopyOnly,
    ItemAlertTypeCopyDelete,
    ItemAlertTypeCopyReport,
    ItemAlertTypeReplyCopyDelete,
    ItemAlertTypeReplyCopyReport,
    ItemAlertTypeShareCopyDelete,
    ItemAlertTypeShareCopyReport,
    ItemAlertTypeReplyShareCopyReportDelete,
    ItemAlertTypeShareCopyReportDelete,
    ItemAlertTypeCopyReportDelete,
    ItemAlertTypeReplyCopyReportDelete,

    //股票自选
    ItemAlertTypeDelete_Top_End,
    ItemAlertTypeDelete,
    ItemAlertTypeDelete_Top_End_Group_Edit,
    ItemAlertTypeDelete_Group_Edit,
    
    //社区助手 回复 | 查看(原文) | 举报 | 拉黑
    ItemAlertTypeReplyOriginalReportBlock,
    //社区助手 回复 | 查看(原文) | 举报 | 取消拉黑
    ItemAlertTypeReplyOriginalReportCancelBlock,
    
    // 版主相关
    ItemAlertTypeModerator,                    // 版主一级评论样式 加精 屏蔽 删除 分享 复制 举报
    ItemAlertTypeModeratorCancel,              // 版主一级评论样式 取消精选 屏蔽 删除 分享 复制 举报
    ItemAlertTypeModeratorSecondary,           // 版主二级评论样式 屏蔽 删除 复制 举报
};

typedef void(^ItemChooseBlock)(NSInteger selectedIndex);

/*
 本控件只用于帖子详情页面，回复列表部分，长按点击的弹出小黑框。
 */
@interface TBViewitemChooseAlert : UIView

+(TBViewitemChooseAlert *)shareDrawerInItemChoose;

-(void)itemChooseBlock:(ItemChooseBlock )thisBlock;

@property (nonatomic, assign) ItemAlertType alertType;

@property (nonatomic, copy) NSArray *singleTypes;

- (NSUInteger)singleTypesMaxRawValue;

@end
