//
//  TBShareSDK.h
//  Stock
//
//  Created by ChenXin on 2017/6/28.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>
#import "TBShareInfoModel.h"
#import "TBShareDefines.h"

@interface TBShareSDK : NSObject

@property (nonatomic, assign, readonly) TBSharePlatformType currentSharePlatformType;
@property (nonatomic, copy) NSArray *crmOrderedChannels; // 来自crm配置的各分享渠道的顺序
@property (nonatomic, copy) NSArray *orderedSharePlatformTypes; // 按crm排序的枚举类型

DECLARE_SHARED_INSTANCE(TBShareSDK)

// 默认展示的分享平台类型
+ (NSArray *)defaultSharePlatformTypes;

// 分享渠道名称，用于显示
+ (NSString *)channelTitleWithType:(TBSharePlatformType)type;

// completion会导致循环引用，使用时需在外部声明weakSelf
+ (void)shareWithInfo:(TBShareInfoModel *)infoModel platformType:(TBSharePlatformType)type inViewController:(UIViewController *)viewController completion:(TBShareCompletion)completion;

@end
