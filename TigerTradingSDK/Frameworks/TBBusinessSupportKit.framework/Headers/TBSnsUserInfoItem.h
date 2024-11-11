//
//  TBSnsUserInfoItem.h
//  Stock
//
//  Created by liwt on 10/14/15.
//  Copyright © 2015 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/TBObject.h>
@class TBLevel;

@interface TBSnsUserInfoItem : TBObject

@property (nonatomic, copy) NSString *ID; // id
@property (nonatomic, copy) NSString *id;
@property (nonatomic, strong) NSNumber *gmtCreate;
@property (nonatomic, copy) NSString *gmtCreateText;

@property (nonatomic, strong) NSNumber *gmtModify;
@property (nonatomic, copy) NSString *gmtModifyText;
@property (nonatomic, copy) NSString *phone;
@property (nonatomic, copy) NSString *name;

@property (nonatomic, copy) NSString *introduction; // 认证信息. vip == 2 时一定有
@property (nonatomic, copy) NSString *signature; // 个人简介
@property (nonatomic, copy) NSString *avatar;
@property (nonatomic, strong) NSNumber *vip;
@property (nonatomic, strong) NSNumber *crmLevel;
@property (nonatomic, strong) NSNumber *crmLevelSwitch;

@property (nonatomic, copy) NSString *token;
@property (nonatomic, copy) NSString *fanSize;
@property (nonatomic, copy) NSString *headSize;
@property (nonatomic, copy) NSString *favoriteSize;
@property (nonatomic, assign) BOOL boolIsFan;
@property (nonatomic, assign) BOOL boolIsHead;
@property (nonatomic, assign) BOOL starInvestorFlag;
@property (nonatomic, assign) BOOL starInvestorSubscribeFlag;

@property (nonatomic, strong) NSNumber *status; // 用户状态. 1 非社区用户, 2 社区普通用户,10 机器人, 99 黑名单, 100 管理员
@property (nonatomic, copy) NSString *pinyin;
@property (nonatomic, strong) TBLevel  *level;    //用户等级

@property (nonatomic, copy) NSString *tweetSize;
@property (nonatomic, strong) NSNumber *questionSize;
@property (nonatomic, copy) NSArray *medals;
@property (nonatomic, copy) NSArray<NSDictionary *> *badges;
@property (nonatomic, copy) NSString *themeCounts;//主题数量
@property (nonatomic, copy) NSString *badgeCounts;//主题数量
@property (nonatomic, copy) NSDictionary *badgeLevel; // 显示在头像右下角的徽章
@property (nonatomic, copy) NSString *hat; // 显示在头像上的头饰
@property (nonatomic, copy) NSString *hatId; // 显示在头像上的头饰ID
@property (nonatomic, copy) NSString *hatName; // 显示在头像上的头饰名字
@property (nonatomic, strong) NSURL *avatarImageURL; // 自己的头像

// 企业号相关
@property (nonatomic, copy) NSString *coverImage; ///< 企业封面
@property (nonatomic, copy) NSArray *symbols; ///< 企业关联的百科标的
@property (nonatomic, copy) NSDictionary *baikeDict; ///< 企业关联的百科信息 为community/detail接口请求所得

// 新加坡认证交易员
@property (nonatomic, strong) NSNumber *tradeLevel; ///< 认证等级
@property (nonatomic, assign) BOOL isShowTradeButton; ///< 是否显示新加坡交易员入口

// 新版徽章字段
@property (nonatomic, strong) NSNumber *userBadgeCount; ///< 用户徽章数量
@property (nonatomic, strong) NSArray *userBadges; ///< 用户拥有的徽章
@property (nonatomic, strong) NSDictionary *currentWearingBadge; ///< 用户当前佩戴的徽章
@property (nonatomic, strong) NSArray *individualDisplayBadges; // 812新加字段

- (TBSnsUserInfoItem *)setValueByOtherItem:(TBSnsUserInfoItem *)other;

// 返回个人信息页的简介, 大v返回认证信息, 普通用户返回个性签名
- (NSString *)userInfoIntro;

// 有用户名
- (BOOL)hasNickname;

@end

