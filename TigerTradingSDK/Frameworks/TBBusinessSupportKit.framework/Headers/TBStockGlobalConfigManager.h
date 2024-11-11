//
//  TBStockGlobalConfigManager.h
//  Stock
//
//  Created by 骆鹏飞 on 2019/8/13.
//  Copyright © 2019 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBStockGlobalConfigConstant.h"
#import <TBBaseKit/TBBaseUtility.h>

NS_ASSUME_NONNULL_BEGIN

static NSString *NOTIFICATION_KEY_MARKET_SORT = @"marketSort";

// 国际化行情配置持久化
UIKIT_EXTERN NSString * _Nullable const StockGlobalQuoteUserDefaultKey;

UIKIT_EXTERN NSString * _Nullable const StockGlobalConfigChangeNotifationKey;




@interface TBStockGlobalConfigManager : NSObject
DECLARE_SHARED_INSTANCE(TBStockGlobalConfigManager);

#pragma mark --- 行情tab
/**
 将代码比如CN/US/UK/FUT...
 转为：沪深/美股/伦敦/期货
 */
@property (nonatomic, copy, readonly) NSDictionary *codeToZhDictionary;

@property (nonatomic, copy, readonly) NSDictionary *zhToCodeDictionary;


@property (nonatomic, copy) NSString *region;
@property (nonatomic, copy) NSString *location;
@property (nonatomic, copy) NSString *edition;

/// 行情轮询时间
/// /api/v1/device/init
@property (nonatomic, strong, getter=optionQuotePolling) NSNumber *quotePolling;

- (void)resetLocalGlobalInfo;

/**
 请求国际化行情
 */
- (void)fetchGlobalConfig;

/**
 是否隐藏对应key的模块
 */
- (BOOL)isHiddenModuleForKey:(NSString *)key;


/**
 行情展示标题
 */
@property (nonatomic, strong, readonly) NSMutableArray *quoteTitlesMArray;

/**
 只有市场，不包含自选 和 全球
 */
@property (nonatomic, strong, readonly) NSMutableArray *marketQuoteTitles;
- (NSString *)marketLocalizable:(NSString *)market;

/**
 后端允许展示市场
 */
@property (nonatomic, strong, readonly) NSMutableArray *supportDisplayTitleMArray;

- (NSArray *)defaultMarketSortArray;

- (NSArray *)userDefaultPriorityStock;

/**
 是否隐藏环球tab
 */
@property (nonatomic, assign, readonly) BOOL isHiddenGlobalTab;

/**
数字货币是否被隐藏
*/
@property (nonatomic, assign, readonly) BOOL isHiddenDigitalCurrency;

- (NSArray *)visibleMarkets;

#pragma mark --- 个股详情页tab展示

/**
 个股详情页需要移除底部tab

 @param market 市场
 @param secType secType description
 @return 需要移除底部tab类名字符串，会通过NSClassFromString获取对应的类
 */
- (NSArray *)stockDetailRemoveBottomTabWithMarket:(NSString *)market  secType:(NSString *)secType isIndex:(BOOL)isIndex isETF:(BOOL)isEtf;

/**
 个股详情页底部tab是否显示发帖tab

 @param market 市场
 @param secType secType
 @return BOOL value
 */
- (BOOL)stockDetailBottomTabDisplayPost:(NSString *)market secType:(NSString *)secType;

/// 是否隐藏行情权限，region=SGP隐藏
@property (nonatomic, assign, readonly) BOOL isHiddenQuoteMarketDataPrice;


#pragma mark --- 发现页面控制展示隐藏

/**
 主题组合
 */
@property (nonatomic, assign, readonly) BOOL isHiddenTheme;

/**
 新股申购
 */
@property (nonatomic, assign, readonly) BOOL isHiddenHotIPO;

/**
 新股日历
 */
@property (nonatomic, assign, readonly) BOOL isHiddenNewCalendar;

/**
 新股申购 - 是否有新加坡ipo权限
 */
@property (nonatomic, assign, readonly) BOOL isHiddenSgpIpo;

/**
 新股申购 - 是否有美股ipo权限
 */
@property (nonatomic, assign, readonly) BOOL isHiddenUSIpo;

/**
 新股申购 - //港股打新是否有协议页面
 */
@property (nonatomic, assign, readonly) BOOL isHiddenHKAgreement;

/**
 新股申购 - //美股打新是否有协议页面
 */
@property (nonatomic, assign, readonly) BOOL isHiddenUSAgreement;

/**
 热门交易榜
 */
@property (nonatomic, assign, readonly) BOOL isHiddenHotTrendPost;

/**
 热议股票
 */
@property (nonatomic, assign, readonly) BOOL isHiddenHotStock;

/**
 老虎研报
 */
@property (nonatomic, assign, readonly) BOOL isHiddenTigerResearch;

/**
 炒股大赛
 */
@property (nonatomic, assign, readonly) BOOL isHiddenHotCompetition;


/**
 交易-更多-全部功能-基金
 */
@property (nonatomic, assign, readonly) BOOL isHiddenFunctionsFund;


/**
 已经开户-未入金-其他券商转入账户
 */

@property (nonatomic, assign, readonly) BOOL isHiddenTransferStock;
/**
 交易-更多-全部功能-质押融资
 */
@property (nonatomic, assign, readonly) BOOL isHiddenPledgeFinancing;

/**
 基金超市-资讯
 */
@property (nonatomic, assign, readonly) BOOL isHiddenFundMallNews;

/**
 基金超市-课堂
 */
@property (nonatomic, assign, readonly) BOOL isHiddenFundMallClass;

/**
 基金超市-介绍
 */
@property (nonatomic, assign, readonly) BOOL isHiddenFundMallIntroduce;

/**
 基金超市-五星基金
 */
@property (nonatomic, assign, readonly) BOOL isHiddenFundMallFiveStar;

#pragma mark -- 社区
/**
 关注tab    社区头部
 */
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityTabFollow;

/**
 推荐tab    社区头部
 */
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityTabRecommend;

/**
  社区助手    社区-资讯右上角
 */
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityNewsAssistant;

/**
 热点事件    社区-资讯
 */
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityNewsHotEvent;

/**
  相关推荐    社区-资讯-新闻详情
 */
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityNewsRelatedRecommend;

/**
 相关个股    社区-资讯-新闻详情
 */
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityNewsRelatedStock;

/**
 评论框    社区-资讯-新闻详情
 */
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityNewsCommentBox;

/**
 下方评论区    社区-资讯-新闻详情
 */
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityNewsBelowCommentSection;

/**
 快讯tab    社区-资讯
 */
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityNewsTabFlash;

/**
  翻译按钮    社区-资讯-新闻详情
 */
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityNewsTranslateButton;

/**
 分享组件    社区-资讯-新闻详情
 */
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityNewsSharesButton;

/**
 
  新帖（连带发帖和分享）  （所有标的）个股详情页-新帖
 */
@property (nonatomic, assign, readonly) BOOL isHiddenNewsPost;

@property (nonatomic, assign, readonly) BOOL isHiddenCommunityNewsPush;


/**
 持仓交易分享    持仓分享
 */
@property (nonatomic, assign, readonly) BOOL isHiddenTradeSharesHold;

/**
 分享至"老虎社区"    所有分享组件
 */
@property (nonatomic, assign, readonly) BOOL isHiddenSharesToTiger;

/**
 热搜页面    APP内所有搜索
 */
@property (nonatomic, assign, readonly) BOOL isHiddenHotSearchPage;


/// 控制社区搜索热点隐藏
@property (nonatomic, assign, readonly) BOOL isHiddenHotCommunityContent;

/**
 模拟账户交易模块    是否隐藏实盘
 */
@property (nonatomic, assign, readonly) BOOL isHiddenSimulateTradeActual;

/**
 模拟账户交易模块    是否隐藏学院
 */
@property (nonatomic, assign, readonly) BOOL isHiddenSimulateTradeCollege;

/**
 模拟账户交易模块    是否隐藏奖励
 */
@property (nonatomic, assign, readonly) BOOL isHiddenSimulateTradeReward;

/**
 交易分享    是否隐藏持仓交易分享
 */
@property (nonatomic, assign, readonly) BOOL isHiddenAdvisorPostShare;

/**
 新闻收藏    是否隐藏持仓交易分享
 */
@property (nonatomic, assign, readonly) BOOL isHiddenNewsFavorite;

/**
 积分任务    是否隐藏新闻详情页积分任务
 */
@property (nonatomic, assign, readonly) BOOL isHiddenNewsIntegralTask;

@property (nonatomic, assign, readonly) BOOL isHiddenCommunityTrend; ///< 是否隐藏多空表态
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityPredi; ///< 是否隐藏涨跌激励
#pragma mark - 我的模块
//黑名单
@property (nonatomic, assign, readonly) BOOL isHiddenMeBlacklist;
@property (nonatomic, assign, readonly) BOOL isHiddenMeWelcomPage;
@property (nonatomic, assign, readonly) BOOL isHiddenMeCommunityRule;
@property (nonatomic, assign, readonly) BOOL isHiddenMeUserHome;
@property (nonatomic, assign, readonly) BOOL isHiddenMeJoinUs;
@property (nonatomic, assign, readonly) BOOL isHiddenMeMessageAssistant;
@property (nonatomic, assign, readonly) BOOL isHiddenMeClert;
@property (nonatomic, assign, readonly) BOOL isHiddenMeIncomeAlert;
@property (nonatomic, assign, readonly) BOOL isHiddenMeAdjustAlert;
@property (nonatomic, assign, readonly) BOOL isHiddenMeCommunityToolbar;
@property (nonatomic, assign, readonly) BOOL isHiddenMeBanner;
@property (nonatomic, assign, readonly) BOOL isHiddenMeBadge;
@property (nonatomic, assign, readonly) BOOL isHiddenMeAvatarHat;
@property (nonatomic, assign, readonly) BOOL isHiddenMePushSetting;
@property (nonatomic, assign, readonly) BOOL hideTigerCoin;

@property (nonatomic, assign, readonly) BOOL isHiddenCashPlusAccount;
@property (nonatomic, assign, readonly) BOOL isHiddenFundMallAccount;

@property (nonatomic, assign, readonly) BOOL isLocationCNH;

@property (nonatomic, assign, readonly) BOOL isHiddenBiometricRules;

// 是否隐藏分享微信小程序功能
@property (nonatomic, assign, readonly) BOOL isHiddenShareMiniProgram;

@property (nonatomic, assign, readonly) BOOL isHiddenSocialAccount; // 是否隐藏微博和微信绑定

@property (nonatomic, assign, readonly) BOOL isHiddenCustomIM; // 是否使用自研客服系统

#pragma mark - 社区国际化相关

@property (nonatomic, assign, readonly) BOOL isHiddenCommunityQA;  ///< 企业问答tab

@property (nonatomic, assign, readonly) BOOL isHiddenCommunityFollowRecommend;  ///< 关注 推荐关注
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityFollowMyTopic;    ///< 关注 我的主题
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityFollowRelation;   ///< 关注 我关注的人关注了谁
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityTabCollege;       ///< 社区顶部tab 学院tab

@property (nonatomic, assign, readonly) BOOL isHiddenCommunityTabRecommendHot;       ///< 社区推荐顶部tab热榜
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityTabRecommendSpaceStation;       ///< 社区推荐 空间站
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityTabRecommendTopic;       ///< 社区推荐 讨论
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityTabFollowTheme;       ///< 社区关注 话题
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityIpoTopicEntry; /// 社区ipo主题入口
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityCollegeHeader; /// 学院header

@property (nonatomic, assign, readonly) BOOL isHiddenHomePageTigerSpaceCreat;   ///< 个人主页 创建空间站入口
@property (nonatomic, assign, readonly) BOOL isHiddenHomePageTigerSpaceEntry;   ///< 个人主页 空间站入口
@property (nonatomic, assign, readonly) BOOL isHiddenHomePageTigerSpaceList;    ///< 个人主页 空间站列表tab

@property (nonatomic, assign, readonly) BOOL isHiddenUsPostTabRecommend;        ///< 个股新帖 推荐tab
@property (nonatomic, assign, readonly) BOOL isHiddenUsPostTabTopic;            ///< 个股新帖 主题tab
@property (nonatomic, assign, readonly) BOOL isHiddenUsPostTabVote;             ///< 个股新帖 投票tab
@property (nonatomic, assign, readonly) BOOL isHiddenUsPostTabSelector;         ///< 个股新帖 全部tab的评论筛选器
@property (nonatomic, assign, readonly) BOOL isHiddenUsPostTabToplist;          ///< 个股新帖 股票推广位

@property (nonatomic, assign, readonly) BOOL isHiddenNewsPostMore;              ///< 编辑器 提问 写笔记 电脑写
@property (nonatomic, assign, readonly) BOOL isHiddenNewsPostAddTopic;          ///< 编辑器 关联主题
@property (nonatomic, assign, readonly) BOOL isHiddenNewsPostVideoLink;         ///< 编辑器 插入视频连接
@property (nonatomic, assign, readonly) BOOL isHiddenNewsPostVote;              ///< 编辑器 投票

@property (nonatomic, assign, readonly) BOOL isHiddenCommunityPostHotTag;           ///< 帖子详情页 热榜标签
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityPostHubiTag;          ///< 帖子详情页 虎币标签
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityPostHubiGive;         ///< 帖子详情页 虎币打赏
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityPostTopic;            ///< 帖子详情页 关联主题
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityPostRelatedRecommend; ///< 帖子详情页 相关推荐
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityPostRelatedCourse;    ///< 帖子详情页 相关学院

@property (nonatomic, assign, readonly) BOOL isHiddenAppHomePageLVTag;          ///< 个人主页 等级标签
@property (nonatomic, assign, readonly) BOOL isHiddenAppHomePageBadgeTag;       ///< 个人主页 徽章
@property (nonatomic, assign, readonly) BOOL isHiddenAppHomePageTopicEntry;     ///< 个人主页 主题入口
@property (nonatomic, assign, readonly) BOOL isHiddenAppHomePageBadgeEntry;     ///< 个人主页 徽章入口

@property (nonatomic, assign, readonly) BOOL isHiddenCommunityEnterprise;     ///< 个人主页 企业号

@property (nonatomic, assign, readonly) BOOL isHiddenSingporeAceTrader;     ///< 个人主页 avatar cell, 新加坡认交易认证标识是否展示
@property (nonatomic, assign, readonly) BOOL isHiddenMinePersonalizedRecommendSetting;     ///< 我的-通用-个性化推荐管理
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityAceonly;      ///< 新加坡路透视频tab
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityExtraTab;     ///< 社区额外tab
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityFunction;     ///< 社区推荐头部

@property (nonatomic, assign, readonly) BOOL isHiddenCommunityShareCards;   ///< 分享卡片

@property (nonatomic, assign, readonly) BOOL isHiddenUpgradeToMarginAccount;   ///< 是否支持升级为保证金账户


@property (nonatomic, assign, readonly) BOOL isHiddenAccountDescription;

@property (nonatomic, assign, readonly) BOOL isHiddenCommunityQuoteMessageCenter; ///< 消息中心首页入口以及对底导红点的影响
@property (nonatomic, assign, readonly) BOOL isHiddenCommunityDailyReference; ///< 早晚报模块

@property (nonatomic, assign, readonly) BOOL isHiddenCommunityLiveTab; ///< 直播模块

@property (nonatomic, assign, readonly) BOOL isHiddenTBNZPI; ///< 专业投资者认证
@property (nonatomic, assign, readonly) BOOL isHiddenTBSGAI; ///< 合格投资者认证
@property (nonatomic, assign, readonly) BOOL isHiddenAFSLWI; ///< 合格投资者认证

@property (nonatomic, assign, readonly) BOOL isHiddenGPT;    ///< GPT

///< 是否隐藏 IPO 申购规则
@property (nonatomic, assign, readonly) BOOL isHiddenHKIPORules;
@property (nonatomic, assign, readonly) BOOL isHiddenUSIPORules;
@property (nonatomic, assign, readonly) BOOL isHiddenSGIPORules;

///是否隐藏 IPO 情报
@property (nonatomic, assign, readonly) BOOL isHiddenHKIPONews;
@property (nonatomic, assign, readonly) BOOL isHiddenUSIPONews;
@property (nonatomic, assign, readonly) BOOL isHiddenSGIPONews;

/// 是否需要隐藏新股盘点，only for hk market
@property (nonatomic, assign, readonly) BOOL isHiddenHKIPOSummary;

@property (nonatomic, assign, readonly) BOOL isTradeUPHiddenComponentMarket; /// 是否隐藏组件-市场，使用TradeUP市场
@property (nonatomic, assign, readonly) BOOL isTradeUPHiddenComponentMessage; /// 是否隐藏组件-消息中心，使用TradeUP消息中心
@property (nonatomic, assign, readonly) BOOL isTradeUPHiddenComponentOptionchain; /// 是否隐藏组件-期权链，使用TradeUP期权链
@property (nonatomic, assign, readonly) BOOL isTradeUPHiddenComponentAnalysis; /// 是否隐藏组件-分析，使用TradeUP分析
@property (nonatomic, assign, readonly) BOOL isTradeUPHiddenComponentMessageCenterStockNews; /// 是否隐藏组件-消息中心个股资讯
@property (nonatomic, assign, readonly) BOOL isTradeUPHiddenComponentTrade; /// 是否隐藏组件-交易

@property (nonatomic, assign, readonly) BOOL isHiddenExchangeAutoConversion; /// 是否隐藏自动换汇入口
@property (nonatomic, assign, readonly) BOOL isHiddenOptionPricePlan;        /// 是否隐藏期权阶梯收费入口

@property (nonatomic, assign, readonly) BOOL isHiddenExchangeAutoRepay; /// 是否隐藏自动还款入口

@property (nonatomic, assign, readonly) BOOL isHiddenCDPSell; /// 是否隐藏CDPSell相关功能

@end

#define TBGlobalConfigKit [TBStockGlobalConfigManager sharedInstance]

NS_ASSUME_NONNULL_END
