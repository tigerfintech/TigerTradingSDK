//
//  TBVideoPanelViewController.h
//  TBUIKit
//
//  Created by chenxin on 2023/3/30.
//

#import <UIKit/UIKit.h>
#import "TBVideoModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^TBVideoPanelDismissBlock)(BOOL isEnd);

@interface TBVideoPanelViewController : UIViewController

/*
 显示视频播放浮层
 videoModel 视频model
 needRecordProgress 是否需要记录播放进度， 默认为YES
 viewController 浮层所在vc
 dismissBlock 播放回调
 返回值为TBFloatingPanel类型
 */
+ (id)showVideoPanelWithModel:(TBVideoModel *)videoModel
             needRecordProgress:(BOOL)needRecordProgress
               inViewController:(UIViewController *)viewController
                   dismissBlock:(TBVideoPanelDismissBlock)dismissBlock;

@end

NS_ASSUME_NONNULL_END
