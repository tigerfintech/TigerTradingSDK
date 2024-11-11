//
//  TBUser.h
//  Stock
//
//  Created by yangfan on 2017/7/12.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

@interface TBLevel : JSONModel

@property (nonatomic, assign) NSInteger       Id;
@property (nonatomic, copy) NSString        * name;         //等级简体名称
@property (nonatomic, copy) NSString        * nameTw;       //等级繁体名称
@property (nonatomic, copy) NSString        * represent;    //等级描述
@property (nonatomic, copy) NSString        * factor;       //等级条件
@property (nonatomic, copy) NSString        * iconColor;    //等级的主题色
@property (nonatomic, copy) NSString        * bgColor;      //等级的H5背景色

//获取所在等级的主题色
- (UIColor *)themeColor;

//获取所在等级的h5背景色
- (UIColor *)h5Color;

@end

@interface TBUser : JSONModel

@property (nonatomic, copy) NSString        * avatar;
@property (nonatomic, copy) NSString        * name;
@property (nonatomic, assign) int64_t         userId;

@property (nonatomic, assign) NSInteger       fanSize;
@property (nonatomic, assign) NSInteger       headSize;
@property (nonatomic, assign) NSInteger       status;
@property (nonatomic, assign) NSInteger       tweetSize;
@property (nonatomic, assign) NSInteger       vip;
@property (nonatomic, assign) NSTimeInterval  gmtCreate;
@property (nonatomic, assign) NSTimeInterval  gmtModify;
@property (nonatomic, strong) NSArray       * medals;
@property (nonatomic, strong) NSDictionary *badgeLevel;
@property (nonatomic, strong) NSDictionary *currentWearingBadge;
@property (nonatomic, strong) NSArray *individualDisplayBadges;
@property (nonatomic, copy) NSString *hat;

@property (nonatomic, strong) TBLevel       * level;

@property (nonatomic, assign) BOOL boolIsFan; ///< 你是否关注了这用户
@property (nonatomic, assign) BOOL boolIsHead; ///< 这个用户是否关注了你

@property (nonatomic, strong) NSNumber *crmLevel; // 会员等级
@property (nonatomic, strong) NSNumber *crmLevelSwitch; // 是否展示会员铭牌的开关

@property (nonatomic, assign) BOOL userFollowAuthorFlag; // 当前用户是否已关注作者, 不是所有列表都对该字段赋值！
@property (nonatomic, assign) BOOL authorFollowUserFlag; // 当前作者是否已关注用户, 不是所有列表都对该字段赋值！
@property (nonatomic, assign) BOOL userFollowInvestorFlag;
@property (nonatomic, strong) NSNumber *starInvestorFlag;
@property (nonatomic, strong) NSNumber *starInvestorFollowerNum;
@property (nonatomic, strong) NSNumber *starInvestorOrderShareNum;
@property (nonatomic, assign) BOOL showRor;
@property (nonatomic, copy) NSString *investmentPhilosophy;
@property (nonatomic, strong) NSNumber *winRationPercentage;
@property (nonatomic, strong) NSNumber *ror;
@property (nonatomic, copy) NSString *introduction;
@property (nonatomic, strong) NSNumber *navOrReporedYield;

@end
