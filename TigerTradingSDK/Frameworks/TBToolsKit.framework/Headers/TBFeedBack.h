//
//  TBFeedBack.h
//  ACETelPrompt
//
//  Created by linbingjie on 2021/7/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM (NSInteger, TBFeedbackCategory) {
    TBFeedbackCategoryLoginOrOpenAccount = 1, // 登录/开户
    TBFeedbackCategoryDeposit = 2, // 入金
    TBFeedbackCategoryQuotes = 3, // 行情/自选
    TBFeedbackCategoryTradeOrAccount = 4, // 交易/账户
    TBFeedbackCategoryCommunityOrNews = 5, // 社区/新闻
    TBFeedbackCategoryComplants = 6, // 欺诈投诉
    TBFeedbackCategoryActivities = 7, // 活动
    TBFeedbackCategoryForbiddenAppeal = 8, // 封禁申诉
    TBFeedbackCategoryOther = 9 // 其他
};

@interface TBFeedBack : NSObject

@end

NS_ASSUME_NONNULL_END
