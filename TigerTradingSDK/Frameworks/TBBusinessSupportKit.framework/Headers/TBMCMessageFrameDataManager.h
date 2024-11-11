//
//  TBMCMessageFrameDataManager.h
//  Stock
//
//  Created by F.S. on 2020/4/7.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#define topImageViewWidth ((SCREEN_WIDTH) - (k_LeftOffset) - (40) - (10) - (30))

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBPhoneUtility.h>
#import <TBBaseKit/TBConstantUI.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBMCMessageFrameDataManager : NSObject

/// 计算消息中心title高度
+ (CGFloat)heightForCommunityTitle:(NSString *)title;

/// 格式化社区消息中心title
+ (NSAttributedString *)attributedStringForCommunityTitle:(NSString *)title userBehavior:(NSString *)userBehavior;

/// 计算消息中心subTitle高度
+ (CGFloat)heightForCommunitySubTitle:(NSString *)subTitleString;

/// 计算消息中心被回复的主体高度
+ (CGFloat)heightForCommunityInfoTitle:(NSString *)infoTitleString;

/// 格式化社区消息中心subTitle
+ (NSAttributedString *)attributedStringForCommunitySubTitle:(NSString *)subTitleString;

/// 返回社区消息助手触发的事件名称
+ (NSString *)behaviorWithPreviewType:(NSInteger)previewType;

@end

NS_ASSUME_NONNULL_END
