//
//  TBMessageView.h
//  Stock
//
//  Created by liwt on 11/16/15.
//  Copyright © 2015 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TBMessageView : UIView

@property (nonatomic, strong) UIImageView *backgroundImageView;
@property (nonatomic, strong) UIButton *messageCountButton;
@property (nonatomic, assign, readonly) NSInteger unreadCount;///< 未读消息数

- (instancetype)initWithFrame:(CGRect)frame;

- (void)updateMessageCount:(NSInteger)count;
- (void)clearUnreadMessage;
- (void)showRedPoint;
- (BOOL)isShowRedPoint;

/// 早晚报相关
- (void)updateNewspaperBackgroundImageView:(NSTimeInterval)time; ///< 早晚报更新图片方法

- (void)updateNewspaperBackgroundImageView:(NSTimeInterval)time isHomePage:(BOOL)flag/*是否在8.0首页显示*/;

@end
