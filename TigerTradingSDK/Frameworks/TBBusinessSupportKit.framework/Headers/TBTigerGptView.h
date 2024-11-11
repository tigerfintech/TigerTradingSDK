//
//  TBTigerGptView.h
//  TBBusinessSupportKit
//
//  Created by dulijun on 2023/5/12.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBTigerGptView : UIView

@property (nonatomic, copy) void(^actionBlock)(void); // 点击view回调
@property (nonatomic, copy) void(^closeBlock)(void); // 点击关闭回调
@property (nonatomic, copy) void(^closeShowBlock)(void); // 关闭按钮展示回调


// 重置各ui状态（播放pag动画、移除shake动画、隐藏关闭按钮）
- (void)resetUIStatus;

@end

NS_ASSUME_NONNULL_END
