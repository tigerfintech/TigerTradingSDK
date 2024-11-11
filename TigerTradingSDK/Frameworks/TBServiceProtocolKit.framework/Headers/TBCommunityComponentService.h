//
//  TBCommunityComponentService.h
//  TBServiceProtocolKit
//
//  Created by linbingjie on 2022/1/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef enum : NSUInteger {
    TBCommunityPersonInviteTypeInviteCode,
    TBCommunityPersonInviteTypeInvitationLink,
    TBCommunityPersonInviteTypeInvitationText,
} TBCommunityPersonInviteType;

// 获取personalmanager Bool参数类型的值
typedef enum : NSUInteger {
    TBPersonalManagerBoolPropertyType_hasUnreadCommunityMessage,
    TBPersonalManagerBoolPropertyType_hasUnreadPesonalMessage,
    TBPersonalManagerBoolPropertyType_isBirthday,
    TBPersonalManagerBoolPropertyType_showNewbieGuide,
    TBPersonalManagerBoolPropertyType_showNewbieGiftGuide,
    TBPersonalManagerBoolPropertyType_changeMembershipShareBgView,
    TBPersonalManagerBoolPropertyType_showMyselfMembershipLogo,    
} TBPersonalManagerBoolPropertyType;


@protocol TBCommunityComponentService <NSObject>


/// 获取person的userid
- (int64_t)tbCommunity_fetchPersonUserID;

/// 获取person的邀请相关信息
/// @param inviteType 邀请信息类型
- (NSString *)tbCommunity_fetchPersonInviteType:(TBCommunityPersonInviteType)inviteType;

/// 关联了企业号的标的列表
- (NSArray *)tbCommunity_fetchRelatedCompanyList;

/// 查看用户主页
/// @param userId userid
- (void)tbCommunity_gotoUserHomePage:(int64_t)userId;
- (void)tbCommunity_gotoUserHomePage:(int64_t)userId arriveFrom:(NSString *)arriveFrom recommendSymbols:(NSString *)recommendSymbols isStarInvestorHome:(BOOL)isStarInvestorHome;
- (void)tbCommunity_gotoUserHomePage:(int64_t)userId arriveFrom:(NSString *)arriveFrom recommendSymbols:(NSString *)recommendSymbols isStarInvestorHome:(BOOL)isStarInvestorHome otherQuery:(NSDictionary *)otherQuery;

/// 判断交易分享abtest
- (BOOL)tbCommunity_abForNewStarInvestor;

/// 获取TBCommunityUtils的userinfo信息
/// {其中status对应的value：1.表示初始状态，2，表示非初始状态}
- (NSDictionary *)tbCommunity_fetchUserInfo;
- (void)tbCommunity_setUserInfo:(NSDictionary *)userInfo;

// 获取社区缓存的信息, 比如点赞, 转发, 评论的数目等
- (void)tbCommunity_getCacheData;
// 清空本地缓存的数据
- (void)tbCommunity_cleanCacheData;

- (void)tbCommunity_getPersonalRelationsData;

- (void)tbCommunity_initUserInfo;

- (void)tbCommunity_autoRefreshUserStatus;

- (void)tbCommunity_refreshUserStatus:(void(^)(BOOL isFinished))completed
                              failure:(void(^)(NSString * message))failure;

- (void)tbCommunity_notifyRewardRead:(void(^)(id result))success
                             failure:(void(^)(NSString * message))failure;

- (void)tbCommunity_statisticsShareWithObjectId:(NSString *)objectId
                                       itemType:(NSInteger)type
                               destPlatformType:(NSInteger)platformType
                                 withCompletion:(void(^)(NSError *error))block;

- (void)tbCommunity_cleanAuthStatus;
// 通过urlstring打开发帖编辑器页面
- (void)tbCommunity_gotoCreatePostWithString:(NSString *)urlStr;

// 通过发帖类型和参数字典进入发帖页面
- (void)tbCommunity_gotoCreatePostWithType:(NSInteger)type param:(NSDictionary *)dict;

- (UIViewController *)tbCommunity_openCreateVCWithDict:(NSDictionary *)dict;

- (void)tbCommunity_gotoPostDetail:(NSString *)postId;

- (BOOL)tbCommunity_showMembershipEntry;

- (BOOL)tbCommunity_showMembershipPositionShareEntry;

- (BOOL)tbCommunity_enableWaterMark;

- (NSNumber *)tbCommunity_getMembershipLevel;

- (BOOL)tbCommunity_changeMembershipShareBgView;

- (void)tbCommunity_SetChangeMembershipShareBgView:(BOOL)flag;

- (BOOL)tbCommunity_hasUnreadPesonalMessage;

- (void)tbCommunity_setHasUnreadPersonalMessage:(BOOL)flag;

- (BOOL)tbCommunity_hasUnreadCommunityMessage;

- (void)tbCommunity_setHasUnreadCommunityMessage:(BOOL)flag;
- (void)tbCommunity_setShowCommunityTopBarRed:(BOOL)flag;
- (void)tbCommunity_setShowCommunityFocusRed:(BOOL)flag;
- (void)tbCommunity_setBottomNavigationSourceList:(NSArray *)list;

- (BOOL)tbCommunity_showCommunityGuide;

- (void)tbCommunity_setShowCommunityGuide:(BOOL)flag;

- (BOOL)tbCommunity_personalManagerIsBirthday;

- (void)tbCommunity_setPersonalManagerIsBirthday:(BOOL)flag;

- (void)tbCommunity_fetchMembershipInfo:(void(^)(BOOL isFinished))completed
                                failure:(void(^)(NSString * message))failure;

- (void)tbCommunity_fetchMembershipLevelNoticeInfoIsHomePage:(BOOL)flag
                                         
                                                     success:(void(^)(BOOL showRedPoint, BOOL showAlert, NSInteger level))success
                                        
                                                     failure:(void(^)(NSString * message))failure;

//获取消息中心未读消息数量
- (void)tbCommunity_fetchCommunityUnreadMessageCount:(void(^)(id result))success
                                             failure:(void(^)(NSString * message))failure;

//获取新版社区小红点 以及消息中心未读数接口
- (void)tbCommunity_fetchCommunityNewVersionUnreadMessageCount:(void(^)(id result))success
                                                       failure:(void(^)(NSString * message))failure;

// 检查用户状态并对LV2发生改变加提示
- (void)tbCommunity_refreshUserStatusWithLV2Prompt:(void(^)(BOOL isFinished))completed failure:(void(^)(NSString * message))failure;

// 跳转到学院视频
- (void)tbCommunity_gotoCollegeVideoWithGID:(id)gid videoId:videoId fromAD:(BOOL)fromAD;

// 跳转到学院视频 or 栏目视频详情页面
- (void)tbCommunity_gotoCollegeVideoWithGID:(id)gid
                                    videoId:videoId
                                 isPrograma:(BOOL)flag
                                     fromAD:(BOOL)fromAD;
/// 跳转换头像界面
- (void)tbCommunity_goTochangeUserAvator;

/// 跳转新闻社区
/// @param newsId 新闻id
/// @param isHighlight 高亮
/// @param fromAD
/// @param arriveFrom 来源
- (void)tbCommunity_gotoNewsById:(NSString *)newsId isHighlight:(BOOL)isHighlight fromAD:(BOOL)fromAD arriveFrom:arriveFrom;

/// 跳转学院
/// @param fromAD 来自AD
- (void)tbCommunity_gotoStockCourse:(BOOL)fromAD;

- (void)tbCommunity_openIPODetailWithLiveId:(NSString *)liveId type:(NSNumber *)type fromAD:(BOOL)fromAD;

// 获取直播状态
- (void)tbCommunity_fetchLiveStatusWithLiveId:(NSString *)liveId completion:(void(^)(BOOL isLive))completion;

// 打开视频详情页
- (void)tbCommunity_openVideoDetailWithId:(NSString *)Id;
- (void)tbCommunity_openVideoDetailWithId:(NSString *)Id videoId:(NSString *)videoId;

/// 跳转搜索
/// @param keyword 关键字
- (void)tbCommunity_gotoSearchWithKeyword:(NSString *)keyword;

- (void)tbCommunity_gotoCollegePage:(nullable NSDictionary *)userInfo;

- (NSString *)tbCommunity_getNotificationKey_REFRESH_VIEW_PRESSED_INCONSULTINGVC;
- (NSString *)tbCommunity_getNotificationKey_NOTIFICATION_KEY_THEME_DID_SELECT;
- (NSString *)tbCommunity_getNotificationKey_USER_DEFAULT_KEY_LIVE_PLAY_BACKGROUND;
- (NSString *)tbCommunity_getNotificationKey_USER_DEFAULT_KEY_LIVE_PLAY_ON_WINDOW;
- (NSString *)tbCommunity_getNotificationKey_NOTIFICATION_KEY_EXIT_CREAT_POST;
- (NSString *)tbCommunity_getNotificationKey_NOTIFICATION_KEY_THEME_DID_SELECT_AND_PUBLISH;
- (NSString *)tbCommunity_getNotificationKey_USER_DEFAULT_KEY_HAS_MEMBERSHIP_SKIN;

//判断是否关注某人
- (BOOL)tbCommunity_hasFocusUserById:(NSString *)userID;
//判断是否被某人关注
- (BOOL)tbCommunity_hasFansUserById:(NSString *)userID;

- (void)tbCommunity_focusUserByID:(NSString *)userID
                        completed:(void(^)(void))completed;

- (void)tbCommunity_cancelFocusUserByID:(NSString *)userID
                              completed:(void(^)(void))completed;

//从推送跳转到新闻详情页
- (void)tbCommunity_gotoNewsDetailPageFromAPNs:(int64_t)newsId
                                          type:(NSInteger)type;

//从推送跳转帖子详情， fromInAppPush区分是远程推送还是应用内推送
- (void)tbCommunity_gotoPostDetailPageFromAPNs:(int64_t)postId
                                 fromInAppPush:(BOOL)fromInAppPush;

// 会员是否为贵宾会员
- (BOOL)tbCommunity_isMemberSvip;

// 是否为社区超级管理员身份
- (BOOL)tbCommunity_isSuperModerator;

- (UIViewController *)tbCommunity_getDiscoverStarInvestorProVC;

- (UIViewController *)tbCommunity_getStarInvestorStockRankVC;

- (UIView *)tbCommunity_getDiscoverStarInvestorTipsView;

- (UIView *)tbCommunity_getStockStarInvestorTipsView;

- (void)tbCommunity_checkSharePermissionWithOrders:(NSArray *)orders completion:(void (^)(NSArray *orderPermissionInfos))completion;

- (void)tbCommunity_fetchTigerGptData:(void(^)(BOOL show))completion;

/// 获取晒单（持仓分享、订单分享）需要关联的主题信息
/// - Parameter completion: 成功回调，themeDictionary字典结构为：@{@"themeId": , @"themeName": , @"themeImage": }
- (void)tbCommunity_fetchOrderShareThemeData:(void(^)(NSDictionary *themeDictionary))completion;

/// 跳转到公告详情
- (void)tbCommunity_gotoAnnouncementWithId:(NSInteger)Id
                                      type:(NSString *)type
                                   symbols:(NSString *)symbols;

/// 是否设置过新闻内容语言偏好设置
- (BOOL)tbCommunity_newsContentLanguageHasSetted;
/// 是否设置过公告内容语言偏好设置
- (BOOL)tbCommunity_noticeContentLanguageHasSetted;

- (BOOL)tbCommunity_contentTranslateControlHasSetted;

- (BOOL)tbCommunity_ENContentTranslateControlHasSetted;

- (BOOL)tbCommunity_showContentTranslateSetting;

- (BOOL)tbCommunity_getContentTranslateSetting;

- (BOOL)tbCommunity_getENContentTranslateSetting;

- (void)tbCommunity_changeContentTranslateSetting:(BOOL)showTranslate;

- (void)tbCommunity_changeENContentTranslateSetting:(BOOL)showTranslate;

- (void)tbCommunity_changeNewsContentLanguageSettingType:(NSInteger)settingType;

- (void)tbCommunity_changeNoticeContentLanguageSettingType:(NSInteger)settingType;

- (void)tbCommunity_resetNewsContentLanguageSettingType;
- (void)tbCommunity_resetNoticeContentLanguageSettingType;

- (NSInteger)tbCommunity_getCurrentNewsContentLanguageSettingType;

- (NSInteger)tbCommunity_getCurrentNoticeContentLanguageSettingType;

- (NSInteger)tbCommunity_getContentLanguageSettingTypeWithArray:(NSArray *)arr
                                                    selectIndex:(NSInteger)index;

- (NSInteger)tbCommunity_newsContentSettingTypeForSettingKey:(NSString *)newsSettingKey;

- (NSInteger)tbCommunity_noticeContentSettingTypeForSettingKey:(NSString *)noticeSettingKey;

- (NSString *)tbCommunity_getCurrentNewsContentLanguageSettingKey;
- (NSString *)tbCommunity_getCurrentNoticeContentLanguageSettingKey;

- (BOOL)tbCommunity_hasCommunityActionWithType:(NSInteger)actionType ID:(NSString *)ID;
- (void)tbCommunity_userCommunitytActionType:(NSInteger)actionType ID:(NSString *)ID;
- (void)tbCommunity_cancelUserCommunityActionType:(NSInteger)actionType ID:(NSString *)ID;
- (void)tbCommunity_goToPredictionListWithSymbol:(NSString *)symbol;
- (void)tbCommunity_pushWarmUpTips;
- (void)tbCommunity_setCommunityTabWithPageIndex:(NSInteger)index vc:(UIViewController *)vc;
- (void)tbCommunity_openBaikeDetailWithBaikeId:(id)baikeId type:(id)type;

- (NSError *)tbCommunity_serverResponseWithMessage:(NSString *)message;
- (NSError *)tbCommunity_serverResponseDataFormatError;


// 社区用户信息，昵称，头像等
- (NSDictionary *)tbCommunity_getUserInfoDict;

// 获取config/list接口返回数据中key对应的value
- (id)tbCommunity_getConfigListValueForKey:(NSString *)key;

// 获取用户昵称
- (NSString *)tbCommunity_getNickname;

/// 获取实名
- (void)tbCommunity_checkRealNameInfo:(BOOL)needPop withSuccess:(void (^)(void))success;

/// 是否实名认证
- (BOOL)tbCommunity_isRealNameVerification;

/// 跳转主题详情页
- (void)tbCommunity_gotoThemeWithThemeId:(id)themeId type:(NSInteger)type tab:(nullable NSString *)tab arriveFrom:(nullable NSString *)arriveFrom;
- (void)tbCommunity_gotoThemeWithThemeId:(id)themeId type:(NSInteger)type tab:(nullable NSString *)tab arriveFrom:(nullable NSString *)arriveFrom topicSource:(nullable NSString *)topicSource;

// 基金详情页 获取新帖tab的vc方法
- (id)tbCommunity_fundMallPostViewController:(NSString *)symbol fundName:(NSString *)fundName;
// 更新基金详情页帖子vc的属性
- (void)tbCommunity_updateFundMallPostViewController:(id)vc symbol:(NSString *)symbol fundName:(NSString *)fundName;

// 个人邀请码
- (NSString *)tbCommunity_personalInviteCode;

// 邀请链接
- (NSString *)tbCommunity_invitationLink;

// 邀请文案
- (NSString *)tbCommunity_invitationText;

- (void)tbCommunity_fetchCollegeInfo:(void(^)(id result))success
                             failure:(void(^)(NSString * message))failure;

- (void)tbCommunity_fetchHomePageLessonInfoWithType:(NSString *)type
                                            success:(void(^)(NSArray *array))success
                                            failure:(void(^)(NSString *message))failure;

- (void)tbCommunity_fetchFcnDetailInvestLessonVideoSuccess:(void(^)(NSArray *array))success failure:(void(^)(NSString *message))failure;

- (void)tbCommunity_requestFCNDetailNewsWithItemCount:(NSInteger)count
                                  success:(void(^)(NSArray *list))success
                                              failure:(void(^)(NSString *error))failure;

- (void)tbCommunity_reloadCollegeView:(UIView *)collegeView dataArray:(NSArray *)dataArray;

- (UIView *)tbCommunity_commonCollegeView;

- (NSArray *)tbCommunity_getNewsContentAllLanguageSetting;

- (NSArray *)tbCommunity_getNoticeContentAllLanguageSetting;

- (NSString *)tbCommunity_getCurrentNewsContentLanguageSettingValue;

- (NSString *)tbCommunity_getCurrentNoticeContentLanguageSettingValue;

- (NSString *)tbCommunity_getContentLanguageSettingValueWithModel:(id)model;

- (NSInteger)tbCommunity_getContentLanguageSettingTypeWithModel:(id)model;

//ipo分享
- (void)tbCommunity_showIPOShareCard:(id)positionItem;

// 分享到老虎社区，infoModel为TBShareInfoModel类型
- (void)tbCommunity_tigerPostShareWithInfo:(id)infoModel;

- (UIViewController *)tbCommunity_initTBNewsViewController;

// 跳转到我的徽章墙
- (void)tbCommunity_gotoMyBadgeWall;


/// 获取personalmanager中的参数类型
/// @param propertyType 参数类型
- (BOOL)tbCommunity_fetchPersonalManagerProperty:(TBPersonalManagerBoolPropertyType)propertyType;

- (void)tbCommunity_setPersonalManagerShowNewbieGiftGuide:(BOOL)showNewbieGiftGuide;
- (void)tbCommunity_setPersonalManagerShowNewbieGuide:(BOOL)showNewbieGuide;

- (BOOL)tbCommunity_getPersonalManagerShowNewbieGiftGuide;

- (BOOL)tbCommunity_isPersonalizedPopupSwitchOff;

- (UIImage *)tbCommunity_getNewspaperMessageImage:(NSTimeInterval)time;

- (UIImage *)tbCommunity_getNewspaperMessageImage:(NSTimeInterval)time isHomepage:(BOOL)flag;

- (void)tbCommunity_requestNewspaperStatus;

- (void)tbCommunity_setIsPersonalizedPopupSwitchOff:(BOOL)flag;

- (BOOL)tbCommunity_shouldFetchNewBadge;

- (void)tbCommunity_fetchNewspaperUpdateStatus:(void(^)(id result))success
                           failure:(void(^)(NSString * message))failure;

/// 查询新点亮的徽章
- (void)tbCommunity_fetchCommunityNewBadge:(void(^)(id result))success
                                   failure:(void(^)(NSString * message))failure;

- (UIViewController *)tbCommunity_getNewBadgeVC:(NSDictionary *)badgeDic;

- (id)tbCommunity_getBadgeUserInfoCellItemWithSnsInfoItem:(id)item;

- (BOOL)tbCommunity_isMorningNewspaper:(NSTimeInterval)time;

/// 判断早晚报 & 早晚报轮询时间
- (BOOL)tbCommunity_isMorning;
- (BOOL)tbCommunity_isNight;
- (BOOL)tbCommunity_inCurrentNewspaperRequest:(NSTimeInterval)time; /// 当前时间是否在轮询早晚报接口

- (void)tbCommunity_uploadImage:(UIImage *)image
                      imageData:(nullable NSData *)imageData
                          isGif:(BOOL)isGif
                            use:(NSString *)use
                       progress:(void(^)(CGFloat progress))progress
                        success:(void(^)(id result))success
                        failure:(void(^)(NSString * message))failure;


- (BOOL)tbCommunity_shouldShowNewFeature;

- (void)tbCommunity_fetchUserInfo:(void(^)(id result))success
                          failure:(void(^)(NSString * message))failure;

- (UIViewController *)tbCommunity_getMyPostViewController;

- (UIViewController *)tbCommunity_getMyQAListViewController;

- (UIViewController *)tbCommunity_getUserCollectionVC; // 我的收藏

- (UIViewController *)tbCommunity_getUserHistoryVC; // 我的浏览历史

- (void)tbCommunity_PersonalManagerFetchReward:(void (^)(id result))success failure:(void (^)(NSString * message))failure;

- (void)tbCommunity_netGetCommunityAppConfiguration;

/// tabbar触发notification后communitytab跳转事件
/// @param selectedViewController communityVC
/// @param userInfo notification userinfo
- (void)tbCommunity_tabbarAction:(UIViewController *)selectedViewController
            notificationUserInfo:(NSDictionary *)userInfo;

- (void)tbCommunity_gotoSubPageVC:(UIViewController *)selectedVC index:(NSInteger)index;


//通过用户id判断是不是用户自身
- (BOOL)tbCommunity_isMyself:(int64_t)userId;

/// 发帖的检测方法
- (void)tbCommunity_checkRealNameInfoForPost:(void(^)(void))success;

- (id)tbCommunity_buildCommunityItemWithType:(NSInteger)type
                            content:(NSString *)content
                          thumbnail:(NSString *)thumbnail
                           supObjId:(NSString *)supObjId
                            supType:(NSInteger)supType;

- (NSDictionary *)tbCommunity_getRNForwardParamsWithConfig:(NSDictionary *)configDict
                                           action:(NSDictionary *)actionDict;

- (BOOL)tbCommunity_isENNewsListTranslate;

- (void)tbCommunity_setNewsListTranslate:(BOOL)isTranslate;

- (void)tbCommunity_setENNewsListTranslate:(BOOL)isTranslate;

- (UIImage *)tbCommunity_getShareImageWithContent:(NSString *)content
                                 pubTime:(NSTimeInterval)pubTime
                                  newsID:(NSString *)newsID;

- (id)tbCommunity_convertToNewsCombineCellWithDict:(NSDictionary *)dict;

//转发帖子
- (void)tbCommunity_forwardCommunity:(NSDictionary *)params;

- (void)tbCommunity_favoriteObject:(id)objectId
                     type:(NSInteger)type
              supObjectId:(id)supObjectId
                  supType:(NSInteger)supType
               isFavorite:(BOOL)isFavorite
                  success:(void(^)(id result))success
                  failure:(void(^)(NSString * message))failure;

- (void)tbCommunity_favoriteStatusWithObject:(id)objectId
                               type:(NSInteger)type
                        supObjectId:(id)supObjectId
                            supType:(NSInteger)supType
                            success:(void(^)(id result))success
                            failure:(void(^)(NSString * message))failure;

- (void)tbCommunity_tabbarDidSelectFeedVC:(UIViewController *)viewController;

- (void)tbCommunity_netGetCommunityUserInfo;

- (NSString *)tbCommunity_getCurrentPage:(NSInteger)pageId;

- (void)tbCommunity_fetchLatestEarningArticleWithSymbol:(NSString *)symbol
                                          type:(NSString *)type
                                       success:(void (^)(NSArray *articles))success
                                       failure:(void(^)(NSString * message))failure;

// 向服务器注册idfa，用于ASO广告区分用户
- (void)tbCommunity_registerIDFA;

// Apple Search Ads 归因
- (void)tbCommunity_recordAppleSearchAds;

- (NSArray *)tbCommunity_convertStockDetailNewsItemsWithDictionary:(NSDictionary *)dict;

- (NSArray *)tbCommunity_getStockDetailCellItemWithArray:(NSArray *)arr
                                                  symbol:(NSString *)symbol;

/// 查找投放的行情购买权限的 数据模型
/// @param extraInfo 额外信息
- (void)tbCommunity_fetchQuotePrivilegePurchaseUrl:(NSString *)extraInfo;

/// 中文环境下 控制新闻是否翻译 如果 不显示翻译按钮 或翻译按钮为关闭状态 则不翻译
- (BOOL)tbCommunity_isNewsListTranslate;

- (void)tbCommunity_personalManagerFetchMyPlatesWithSuccess:(void (^)(NSArray *myPlates))success
                                        failure:(void(^)(NSString * message))failure;

//搜索股票
- (NSURLSessionTask *)tbCommunity_searchStock:(NSString *)keyword success:(void(^)(id result))success failure:(void(^)(NSString * message))failure;
//搜索股票-带可传入参数
- (NSURLSessionTask *)tbCommunity_searchStock:(NSString *)keyword
                            param:(NSDictionary *)param
                          success:(void(^)(id result))success
                          failure:(void(^)(NSString * message))failure;

- (void)tbCommunity_requestRspGuideWithSuccess:(void(^)(NSArray *feeds, NSDictionary *extraInfo))success
                                       failure:(void(^)(NSError *error))failure;

- (void)tbCommunity_requestPortfolioLiteTradingTipsWithSuccess:(void(^)(NSArray *list))success
                                                       failure:(void(^)(NSError *error))failure;

- (UIViewController *)tbCommunity_getRspSearchVCWithArray:(NSArray *)array
                                                 selected:(void(^)(NSDictionary *dict))selected;

- (UIViewController *)tbCommunity_getMoreContractVCWithSymbol:(NSString *)symbol
                                                        array:(NSArray *)array
                                                     selected:(void(^)(NSDictionary *dict))selected;

- (UIViewController *)tbCommunity_getSearchMoreContractVCWithSymbol:(NSString *)symbol
                                                            secType:(NSString *)secType
                                                      autoLandScape:(BOOL)flag
                                                         searchType:(NSInteger)type
                                                              array:(NSArray *)array
                                                           selected:(void(^)(id model))selected;

- (void)tbCommunity_SetRspSearchVCWithArray:(NSArray *)array
                                         vc:(UIViewController *)vc;

- (id)tbCommunity_getLandScapeSearchCellItemWithDict:(NSDictionary *)dict;

- (void)tbCommunity_requestThemeInfoWithSuccess:(void(^)(id item))success
                                        failure:(void(^)(NSString *error))failure;

- (NSString *)tbCommunity_getCommunityTigerLinkByRegion;

- (void)tbCommunity_communityLanguageSettingAlert;

- (NSString *)tbCommunity_getInternationalLangShow;

- (BOOL)tbCommunity_isTrendSymbol:(NSString *)symbol;

- (void)tbCommunity_addSearchHistory:(NSString *)text;


- (UIViewController *)tbCommunity_getNoticeVCWithTitle:(NSString *)title
                                                symbol:(NSString *)symbol
                                               secType:(NSString *)secType
                                                market:(NSString *)market
                                                nameCN:(NSString *)nameCN;

- (UIViewController *)tbCommunity_getStarInvestorVCWithTitle:(NSString *)title
                                                      symbol:(NSString *)symbol
                                                     secType:(NSString *)secType
                                                      market:(NSString *)market
                                                      nameCN:(NSString *)nameCN;

- (UIViewController *)tbCommunity_getNewsVCWithTitle:(NSString *)title
                                              symbol:(NSString *)symbol
                                             secType:(NSString *)secType
                                              market:(NSString *)market
                                              nameCN:(NSString *)nameCN;

- (UIViewController *)tbCommunity_getPostVCWithStockInTradingTime:(BOOL)flag
                                                        isIpoStep:(BOOL)isIpo
                                                           symbol:(NSString *)symbol
                                                          secType:(NSString *)secType
                                                           market:(NSString *)market
                                                           nameCN:(NSString *)nameCN
                                                         preClose:(nullable NSNumber *)preClose
                                                      latestPrice:( nullable NSNumber *)price
                                                            title:(NSString *)title;

- (void)tbCommunity_fetchNewsListWithStockDetailNewsVC:(UIViewController *)VC;

- (void)tbCommunity_fetchPostListWithStockDetailPostVC:(UIViewController *)VC;

- (UITableView *)tbCommunity_getTrackScrollViewWithStockDetailPostVC:(UIViewController *)VC;

- (void)tbCommunity_fetchNoticeListWithStockDetailNoticeVC:(UIViewController *)VC;


- (UIViewController *)tbCommunity_getSimilarCandleHotViewControllerWithSymbolList:(NSArray *)list searchStockType:(NSInteger)type selectedBlock:(void (^)(NSString *text))block;

- (void)tbCommunity_requestIpoThemePostListWithSuccess:(void(^)(NSArray *list))success
                                               failure:(void(^)(NSString *error))failure;

- (void)tbCommunity_gotoPostDetailPage:(int64_t)postId
                         jumpToComment:(BOOL)jumpToComment;

- (id)tbCommunity_getStockLandSearchModelWithSymbol:(NSString *)symbol
                                       originSymbol:(NSString *)originSymbol
                                             nameCN:(NSString *)nameCN
                                            secType:(NSString *)secType
                                              maket:(NSString *)market;

- (UIViewController *)tbCommunity_getNewStockSearchViewControllerWithVC:(UIViewController *)vc delegate:(id)delegate top:(CGFloat)top groupArray:(NSArray *)array;

- (void)tbCommunity_searchKeyWord:(NSString *)word vc:(UIViewController *)vc;

/// 个股多空表态
- (void)tbCommunity_fetchStockTrend:(NSString *)symbol
                          itemWidth:(CGFloat)width
                            success:(void(^)(id result))success
                            failure:(void(^)(NSString *message, NSError *error))failure;

/// 多空表态详情页
- (void)tbCommunity_fetchStockTrendList:(NSString *)symbol
                                success:(void(^)(id result))success
                                failure:(void(^)(NSString * message))failure;

- (NSInteger)tbCommunity_getStockDetailTrendStockItemRankListCountWithCellItem:(id)item;

// 检查是否需要返回活动功能
- (void)tbCommunity_showFloatIfNeededWithUrlPath:(NSString *)path;

// 获取基金资讯tab的推广位cellItem
- (id)tbCommunity_fundMallCommunityRecommendTableViewCellItem:(NSString *)symbol dic:(NSDictionary *)dic;

// 老虎早晚报image
- (UIImage *)tbCommunity_newspaperMessageImage:(NSTimeInterval)time isHomePage:(BOOL)flag;

- (BOOL)tbCommunity_isDuringNewspaper;

/**
 * 获取早晚报更新时间
 * @param completion hasReadNewNewspaper:是否已读更新的早晚报 newNewspaperTime:早晚报更新时间
 */
- (void)tbCommunity_fetchNewspaperStatus:(void(^)(BOOL success, BOOL hasReadNewNewspaper, NSTimeInterval newNewspaperTime))completion;

// 分享logo图片链接
- (NSString *)tbCommunity_tigerShareLogoLink;

// 是否在跳转GCS客服前先显示VIP微信客服
- (BOOL)tbCommunity_shouldShowVipWechatBeforeGCS;
- (void)tbCommunity_fetchVipWechat;

// 是否是明星投资者
- (BOOL)tbCommunity_isStarInvestor;

/*
 判断订单是否可以分享发帖
 orderId 订单id
 completion 回调
 */
- (void)tbCommunity_checkSharePermissionWithOrderId:(id)orderId
                                         completion:(void (^)(NSDictionary *orderPermissionInfo))completion;

/*
 展示明星投资者订单分享弹窗
 orderId 订单id
 symbolName 订单标的名称
 amountString 订单数量（股/手）
 actionString 订单方向（买入/卖出）
 arriveFrom 来源
 */
- (void)tbCommunity_starInvestorShareWithOrderId:(id)orderId
                                      symbolName:(NSString *)symbolName
                                    amountString:(NSString *)amountString
                                    actionString:(NSString *)actionString
                            showQuantityCheckbox:(BOOL)showQuantityCheckbox
                                      arriveFrom:(NSString *)arriveFrom;

// 明星投资者 关注提示
- (UIView *)tbCommunity_starInvestorTipsView;

// 订单分享成功Key
- (NSString *)tbCommunity_getNotificationKey_NOTIFICATION_STAR_INVESTOR_SHARE_ORDER;


// 投资者 订阅&取消订阅
- (void)tbCommunity_hasfoucedAndToSubscribeUnknowStarInvestor:(NSString *)sendUserId showToast:(BOOL)showToast;
- (void)tbCommunity_subscribeStarInvestor:(NSString *)sendUserId;
- (void)tbCommunity_unSubscribeStarInvestor:(NSString *)sendUserId;
- (void)tbCommunity_subscribeAllStarInvestor:(NSArray *)starInvestorIDs success:(void (^)(void))success;

// 投资者 订阅状态更改Key
- (NSString *)tbCommunity_getNotificationKey_NOTIFICATION_STAR_INVESTOR_FOLLOW_STATUS_CHANGE;

// 社区 用户关注状态更改
- (void)tbCommunity_changeUserRelationship:(NSString *)userId isStarInvestor:(BOOL)isStarInvestor isFollowStarInvestor:(BOOL)isFollowStarInvestor boolIsFan:(BOOL)boolIsFan;
- (void)tbCommunity_changeUserRelationship:(NSString *)userId isStarInvestor:(BOOL)isStarInvestor isVirtual:(BOOL)isVirtual isFollowStarInvestor:(BOOL)isFollowStarInvestor boolIsFan:(BOOL)boolIsFan;

// 社区 用户关注状态更改Key
- (NSString *)tbCommunity_getNotificationKey_NOTIFICATION_COMMUNITY_FOCUS_STATUS_CHANGED;

// 是否展示投资者模块
- (BOOL)tbCommunity_showStarInvestorForLicense;

// 社区跳转到详情页的方法
- (void)tbCommunity_gotoStockPage:(NSString *)symbol market:(NSString *)market secType:(NSString *)secType nameCn:(NSString *)nameCn arriveFrom:(NSString *)arriveFrom;
- (void)tbCommunity_gotoStockPage:(NSString *)symbol market:(NSString *)market secType:(NSString *)secType nameCn:(NSString *)nameCn arriveFrom:(NSString *)arriveFrom uuid:(NSString *)uuid;

// 获取社区时间格式
- (NSString *)tbCommunity_communityListFormattedTime:(long long)time;

/// 获取ETF专区-课程列表
/// - Parameters:
///   - success: 成功回调
///   - failure: 失败回调
- (void)tbCommunity_fetchEtfMallLessonInfo:(void(^)(id cellItem))success failure:(void(^)(NSString * message))failure;

/// 获取ETF专区-直播列表
/// - Parameters:
///   - success: 成功回调
///   - failure: 失败回调
- (void)tbCommunity_fetchEtfMallLiveInfo:(void(^)(id cellItem))success failure:(void(^)(NSString * message))failure;

/// 获取股票定投-直播列表
/// - Parameters:
///   - success: 成功回调
///   - failure: 失败回调
- (void)tbCommunity_fetchRspLiveInfo:(void(^)(id cellItem))success failure:(void(^)(NSString * message))failure;

/// 获取股票定投-学院教程
/// - Parameters:
///   - success: 成功回调
///   - failure: 失败回调
- (void)tbCommunity_fetchRspCollegeLessonInfo:(void(^)(id cellItem))success failure:(void(^)(NSString * message))failure;
    

/// 获取ETF专区-etf news
/// - Parameters:
///   - success: 成功回调
///   - failure: 失败回调
- (void)tbCommunity_fetchEtfMallNews:(void(^)(id cellItem))success failure:(void(^)(NSString * message))failure;

/**
 * 查询指定标的的交易分享feed
 * @param opt 期权代码(四要素),例如"QQQ 20240314 438.0 CALL"; symbol和opt应只传参一个,同时存在将使用symbol参数
 * @param symbol 标的代码,目前是指正股代码
 * @param pageSize 不传时，默认10; 有效范围[1,20]
 */
- (void)tbCommunity_starInvestorStockDetailList:(NSNumber *)startFromTime symbol:(nullable NSString *)symbol opt:(nullable NSString *)opt pageSize:(nullable NSNumber *)pageSize success:(void(^)(id result))success failure:(void(^)(NSString * message))failure;

// 公告新内容接口（用来判断是否有小红点提示）
- (void)tbCommunity_checkFilingsIsNeedShowRedPointWithSymbol:(NSString *)symbol finished:(void(^)(BOOL shouldShow))finished;

// 获取通知key：个股详情页清除公告小红点
- (NSString *)tbCommunity_getNotificationKey_TB_NOTIFICATION_COMMUNITY_CLEAR_STOCK_DETAIL_FILINGS_RED_POINT;

@end

NS_ASSUME_NONNULL_END

