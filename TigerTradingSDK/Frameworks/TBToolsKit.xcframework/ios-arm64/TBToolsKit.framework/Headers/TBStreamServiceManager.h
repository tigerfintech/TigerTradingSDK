//
//  TBStreamServiceManager.h
//  Stock
//
//  Created by chenxin on 2020/5/25.
//  Copyright © 2020 com.tigerbrokers. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TBToolsKit/TBStreamPublicPopupModel.h>
#import <TBBaseKit/TBBaseUtility.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger,TBStreamServiceIpoTopBannerMarketType) {
    TBStreamServiceIpoTopBannerMarketTypeUS,//美国
    TBStreamServiceIpoTopBannerMarketTypeHK,//香港
    TBStreamServiceIpoTopBannerMarketTypeSG//新加坡
};

//homePage banner类型
typedef NS_ENUM(NSUInteger,TBStreamServiceHomePageBannerType) {
    TBStreamServiceHomePageBannerTypeLoginGuide,//引导登录
    TBStreamServiceHomePageBannerTypeOpenAccountGuide,//引导开户
    TBStreamServiceHomePageBannerTypeGuideDeposit,//引导入金
    TBStreamServiceHomePageBannerTypeBanner//banner位
};

// 物料类型
typedef NS_ENUM(NSUInteger, TBPublicPopupGroupType) {
    TBPublicPopupGroupTypeAppLoadingImage, // 开屏广告
    TBPublicPopupGroupTypeAppLoadedPopup, // 行情tab弹窗
    TBPublicPopupGroupTypeCommunityBanner, // 社区tab推荐banner
    TBPublicPopupGroupTypeDiscoverBanner, // 发现tab热门banner
    TBPublicPopupGroupTypeTraderPopup, // 交易tab弹窗
    TBPublicPopupGroupTypeMineBanner, // 我的tab活动banner
    TBPublicPopupGroupTypeQuoteDetailPopup, //个股详情页
    TBPublicPopupGroupTypeTradeTabBanner,  ///< 交易Tab banner
    TBPublicPopupGroupTypeDepositGuideBanner,  ///< 入金Tab banner
    TBPublicPopupGroupTypeIpoUSBanner,  //美股IPObanner
    TBPublicPopupGroupTypeIpoHongKongBanner,  //港股IPObanner
    TBPublicPopupGroupTypeIpoSGBanner,  //新加坡IPObanner
    TBPublicPopupGroupTypeIpoUSNotification,  //美股IPO prompt
    TBPublicPopupGroupTypeIpoHKNotification,  //港股IPO prompt
    TBPublicPopupGroupTypeIpoSGNotification,
    TBPublicPopupGroupTypeNoOpenAccountGuideMap, //开户引导页，未开户新人礼包
    TBPublicPopupGroupTypeNoDepositGuideMap, //开户引导页，未入金新人礼包
    TBPublicPopupGroupTypeQuotationTopBanner, //行情tab引导开户banner
    TBPublicPopupGroupTypeHomePageLoginGuide, //homepage页 引导登录
    TBPublicPopupGroupTypeHomePageOpenAccountGuide, //homepage页 引导开户
    TBPublicPopupGroupTypeHomePageDepositGuide, //homepage页 引导入金
    TBPublicPopupGroupTypeHomePageBanner, //homepage页 banner
    TBPublicPopupGroupTypeSearchBanner, //搜索页banner
    TBPublicPopupGroupTypePostDetailBanner, // 帖子详情页banner
    TBPublicPopupGroupTypeNewsDetailBanner, // 新闻详情页banner
    TBPublicPopupGroupTypeTigerVaultBanner, // 闲钱管家详情页banner
    TBPublicPopupGroupTypeSharePosterImage, // 分享海报位置
    TBPublicPopupGroupTypeRspBanner,        // 股票定投首页banner
    TBPublicPopupGroupTypeEnterpriseDetailBanner,   // 企业号首页banner
    TBPublicPopupGroupTypeFundHomeBanner,   // 基金超市页banner
    TBPublicPopupGroupTypeOptionDetailPopup, //期权详情页
    TBPublicPopupGroupTypeOptionOrderDetailPopup, // 期权订单详情页
    TBPublicPopupGroupTypeTigerCoins, // 虎币中心
    TBPublicPopupGroupTypeHomepagePlaceOrderGuidePopup, // 默认首页（首页tab或行情tab）新用户下单引导弹窗
    TBPublicPopupGroupTypeStockDetailPlaceOrderGuidePopup, // 个股页新用户下单引导弹窗
    TBPublicPopupGroupTypeHomepageTaskCompletePopup, // 默认首页（首页tab或行情tab）任务完成弹窗
    TBPublicPopupGroupTypeAppStoreRatingGuide, // 应用商店评分
    TBPublicPopupGroupTypeEtfGeneralToast, // 定投首页普通浮动条
    TBPublicPopupGroupTypeEtfcalcuGeneralToast, // 定投计算器普通浮动条
    TBPublicPopupGroupTypeQuoteGeneralToast, // 个股详情页普通浮动条
    TBPublicPopupGroupTypeHomeLiveToast, // 首页、行情、社区tab直播浮动条
    TBPublicPopupGroupTypeNoDepositReward, // 未入金奖励
    TBPublicPopupGroupTypeFundDetailBanner, // 基金详情页 banner
    TBPublicPopupGroupTypeHKETFMallBanner, // 港股ETF专区banner
    TBPublicPopupGroupTypeQuoteTabFCNBanner, // 行情tab页面FCN banner
    TBPublicPopupGroupTypeBondsBanner, // 债券banner
    TBPublicPopupGroupTypeTigerVaultPopup, // tigerVault 首页弹窗
    TBPublicPopupGroupTypeFundRSPBanner, // 基金定投页 banner
    TBPublicPopupGroupTypeFundPositionBanner, // 持仓基金 tab banner
    TBPublicPopupGroupTypeTradeShareAds, // 交易分享主页 banner
    TBPublicPopupGroupTypeContraCreditAds, // contra额度管理 banner
    TBPublicPopupGroupTypeStructureNotesAds, // 首页结构化票据 banner
    TBPublicPopupGroupTypeBondsCenterAds, // 国债专区 banner
};

// 实时物料长连接推送通知，通知的userInfo包含groupType参数
extern NSString * const kTBMarketMaterialDidReceivedNotification;

/*
 个性化物料管理类
 1.物料点击跳转使用handleJumpWithModel方法
 2.物料展示时应调用trackShowEventWithMaterialModel方法，否则无法正确记录展示次数和埋点
 3.物料点击时应调用trackClickEventWithMaterialModel方法记录点击事件埋点
 */

@interface TBStreamServiceManager : NSObject

DECLARE_SHARED_INSTANCE(TBStreamServiceManager);

//// 获取用户分流数据，用于A/B测试
//- (void)fetchUserSplitDataWithSuccess:(void(^)(NSArray<TBStreamUserSplitModel *> *userSplitModels))success
//                              failure:(void(^)(NSError *error))failure;

// 是否有行情tab弹窗，用于判断行情tab各种弹窗优先级
- (BOOL)hasQuoteTabPopup;

// 启动时获取所有个性化物料
- (void)fetchAllPublicPopupData;

// 获取对应分组当前需要展示的物料
- (void)fetchMaterialWithGroupType:(TBPublicPopupGroupType)groupType
                externalParameters:(nullable NSDictionary *)externalParameters
                           success:(void(^)(TBStreamPublicPopupMaterialModel *materialModel))success
                           failure:(void(^)(NSError *error))failure;

// 通过string类型groupName获取物料
- (void)fetchMaterialWithGroupName:(NSString *)groupName
                externalParameters:(nullable NSDictionary *)externalParameters
                           success:(void(^)(NSArray<TBStreamPublicPopupMaterialModel *> *materialList))success
                           failure:(void(^)(NSError *error))failure;

// 获取对应分组所有物料
- (void)fetchAllMaterialWithGroupType:(TBPublicPopupGroupType)groupType
                   externalParameters:(nullable NSDictionary *)externalParameters
                              success:(void(^)(NSArray<TBStreamPublicPopupMaterialModel *> *materialModels))success
                              failure:(void(^)(NSError *error))failure;

/*
 获取多个分组当前需要展示的物料，业务根据实际需要决定使用顺序
 groupTypes元素为NSNumber类型，对应TBPublicPopupGroupType枚举值
 */
- (void)fetchMaterialsWithGroupTypes:(NSArray *)groupTypes
                  externalParameters:(nullable NSDictionary *)externalParameters
                             success:(void(^)(NSArray<TBStreamPublicPopupModel *> *groupTypeList))success
                             failure:(void(^)(NSError *error))failure;

// 获取开屏广告
- (void)fetchAppLoadingImageWithSuccess:(void(^)(TBStreamPublicPopupMaterialModel *materialModel, TBStreamPublicPopupModel *popupModel))success
                                failure:(void(^)(NSError *error))failure;

/// 获取tabbar下tab弹窗物料
/// - Parameters:
///   - tabKey: tab标识
///   - isRealTime: 是否是实时物料
///   - success: 成功回调
///   - failure: 失败回调
- (void)fetchTabBarPopUpWithTabKey:(NSString *)tabKey
                        isRealTime:(BOOL)isRealTime
                           success:(void(^)(TBStreamPublicPopupMaterialModel *materialModel, TBStreamPublicPopupModel *popupModel))success
                           failure:(void(^)(NSError *error))failure;

// 获取默认首页下单引导弹窗
- (void)fetchHomepagePlaceOrderGuidePopupWithSuccess:(void(^)(TBStreamPublicPopupMaterialModel *materialModel, TBStreamPublicPopupModel *popupModel))success
                                             failure:(void(^)(NSError *error))failure;
// 获取个股页下单引导浮窗
- (void)fetchStockDetailPlaceOrderGuidePopupWithSuccess:(void(^)(TBStreamPublicPopupMaterialModel *materialModel, TBStreamPublicPopupModel *popupModel))success
                                                failure:(void(^)(NSError *error))failure;
// 获取默认首页任务完成弹窗
- (void)fetchHomepageTaskCompletePopupWithSuccess:(void(^)(TBStreamPublicPopupMaterialModel *materialModel, TBStreamPublicPopupModel *popupModel))success
                                             failure:(void(^)(NSError *error))failure;
// 获取交易tab弹窗
- (void)fetchTradeTabPopupWithSuccess:(void(^)(TBStreamPublicPopupMaterialModel *materialModel, TBStreamPublicPopupModel *popupModel))success
                              failure:(void(^)(NSError *error))failure;

// 发现tab-热门banner，支持多个
- (void)fetchDiscoverTopBannerWithSuccess:(void(^)(NSArray<TBStreamPublicPopupMaterialModel *> *materialList))success
                                  failure:(void(^)(NSError *error))failure;

// tigerVault 首页弹框
- (void)fetchTigerVaultDetailPopupWithSuccess:(void(^)(TBStreamPublicPopupMaterialModel *materialModel, TBStreamPublicPopupModel *popupModel))success
                                          failure:(void(^)(NSError *error))failure;

// 闲钱管家详情Top-banner
- (void)fetchTigerVaultDetailTopBannerWithSuccess:(void(^)(NSArray<TBStreamPublicPopupMaterialModel *> *materialList))success
                                          failure:(void(^)(NSError *error))failure;

// 基金详情-banner
- (void)fetchFundDetailBannerWithSymbol:(NSString *)symbol success:(void(^)(NSArray<TBStreamPublicPopupMaterialModel *> *materialList))success failure:(void(^)(NSError *error))failure;

// 基金定投-banner
- (void)fetchFundRSPBannerSuccess:(void(^)(NSArray<TBStreamPublicPopupMaterialModel *> *materialList))success failure:(void(^)(NSError *error))failure;

// 持仓页面，基金 tab - banner
- (void)fetchFundPositionBannerSuccess:(void(^)(NSArray<TBStreamPublicPopupMaterialModel *> *materialList))success failure:(void(^)(NSError *error))failure;

- (void)fetchDepositGuideBannerWithSuccess:(void(^)(NSArray<TBStreamPublicPopupMaterialModel *> *materialList))success
                                   failure:(void(^)(NSError *error))failure;

// 社区tab-推荐banner
- (void)fetchCommunityBannerWithSuccess:(void(^)(NSArray<TBStreamPublicPopupMaterialModel *> *materialList))success
                           failure:(void(^)(NSError *error))failure;

/// 获取行情引导开户banner数据
/// @param success 成功回调
/// @param failure 失败回调
- (void)fetchQuotesOpenAccountGuideBannerWithSuccess:(void(^)(TBStreamPublicPopupMaterialModel *materialModel))success
                                            failure:(void(^)(NSError *error))failure;

/// 获取搜索banner数据
/// @param success 成功回调
/// @param failure 失败回调
- (void)fetchSearchBannerWithSuccess:(void(^)(TBStreamPublicPopupMaterialModel *materialModel))success
                             failure:(void(^)(NSError *error))failure;

// 我的tab-活动banner
- (void)fetchMineBannerWithSuccess:(void(^)(NSArray<TBStreamPublicPopupMaterialModel *> *materialList))success
                           failure:(void(^)(NSError *error))failure;

// 交易分享banner
- (void)fetchStarInvestorBannerWithSuccess:(void(^)(NSArray<TBStreamPublicPopupMaterialModel *> *materialList))success
                                   failure:(void(^)(NSError *error))failure;

// 股票定投-活动banner
- (void)fetchRspBannerWithSuccess:(void(^)(NSArray<TBStreamPublicPopupMaterialModel *> *materialList))success
                          failure:(void(^)(NSError *error))failure;

// 交易tab-banner，每次只展示一个
- (void)fetchTradeBannerWithSuccess:(void(^)(TBStreamPublicPopupMaterialModel *materialModel))success
                            failure:(void(^)(NSError *error))failure;

/// 个股详情页开户入金引导
- (void)fetchStockDetailBannerWithSymbol:(NSString *)symbol
                                  market:(NSString *)market
                                 success:(void(^)(TBStreamPublicPopupMaterialModel *materialModel))success
                                 failure:(void(^)(NSError *error))failure;

// ipo banner与其他banner不同，传参除了通用参数uuid、groupTypeList之外,需要额外传参数account_type
-(void)fetchIpoTopBannerWithMarketType:(TBStreamServiceIpoTopBannerMarketType)marketType externalParameters:(NSDictionary *)externalParameters Success:(void (^)(NSArray<TBStreamPublicPopupMaterialModel *> *materialList))success failure:(void (^)(NSError *error))failure;
// ipo 顶部prompt
- (void)fetchIpoPromptWithMarketType:(TBStreamServiceIpoTopBannerMarketType)marketType externalParameters:(NSDictionary *)externalParameters Success:(void (^)(NSArray<TBStreamPublicPopupMaterialModel *> *materialList))success failure:(void (^)(NSError *error))failure;

/// 获取HomePage页 banner
/// @param success 成功回调
/// @param failure 失败回调
- (void)fetchHomePageBannerType:(TBStreamServiceHomePageBannerType)bannerType
                        success:(void(^)(TBStreamPublicPopupMaterialModel *materialModel))success
                        failure:(void(^)(NSError *error))failure;

// 社区 帖子新闻详情页关联的banner
- (void)fetchCommunityDetailWithId:(NSString *)Id isPost:(BOOL)isPost Success:(void (^)(NSArray<TBStreamPublicPopupMaterialModel *> *materialList))success failure:(void (^)(NSError *error))failure;

/// 获取邀请信息（用于分享图片底部信息，包括logo 链接、文字、二维码链接）
/// @param success 成功回调
/// @param failure 失败回调
- (void)fetchInvitationInfoWithSuccess:(void(^)(TBStreamPublicPopupMaterialModel *materialModel))success
                               failure:(void(^)(NSError *error))failure;
/// 获取企业号主页banner
/// @param OfficialId 企业号id
/// @param success 成功回调
/// @param failure 失败回调
- (void)fetchEnterpriseDetailBannerWithId:(NSString *)EnterpriseId success:(void (^)(NSArray<TBStreamPublicPopupMaterialModel *> *materialList))success failure:(void (^)(NSError * _Nonnull))failure;

/// 获取基金超市页banner
/// @param success 成功回调
/// @param failure 失败回调
- (void)fetchFundHomeBannerWithSuccess:(void (^)(NSArray<TBStreamPublicPopupMaterialModel *> *materialList))success failure:(void (^)(NSError *error))failure;

/// 获取期权详情页banner
/// - 811 期权费用套餐banner
/// @param success 成功回调
/// @param failure 失败回调
- (void)fetchOptionDetailBannerWithSymbol:(NSString *)symbol
                                   market:(NSString *)market
                                  success:(void(^)(TBStreamPublicPopupMaterialModel *materialModel))success
                                   failure:(void(^)(NSError *error))failure;

/// 获取期权订单详情页banner
/// - 811 期权费用套餐banner
/// @param success 成功回调
/// @param failure 失败回调
- (void)fetchOptionOrderDetailBannerWithSuccess:(void(^)(TBStreamPublicPopupMaterialModel *materialModel))success
                                        failure:(void(^)(NSError *error))failure;

/// 获取虎币中心物料
/// @param success 成功回调
/// @param failure 失败回调
- (void)fetchTigerCoinsWithSuccess:(void(^)(NSArray<TBStreamPublicPopupMaterialModel *> *materialList))success
                           failure:(void(^)(NSError *error))failure;


/// 是否引导用户跳转应用市场评分
/// @param success 成功回调
/// @param failure 失败回调 
- (void)fetchAppStoreRatingGuideWithSuccess:(void(^)(NSArray<TBStreamPublicPopupMaterialModel *> *materialList))success
                                    failure:(void(^)(NSError *error))failure;

// 通知服务端不再返回部分物料
- (void)forbiddenPublicPopupWithMaterialIDs:(NSArray *)materialIDs;

// 处理点击跳转
+ (void)handleJumpWithModel:(TBStreamPublicPopupMaterialModel *)model;

// 统计展示事件
- (void)trackShowEventWithMaterialModel:(TBStreamPublicPopupMaterialModel *)materialModel;

// 统计点击事件
- (void)trackClickEventWithMaterialModel:(TBStreamPublicPopupMaterialModel *)materialModel;

// 统计关闭事件
- (void)trackCloseEventWithMaterialModel:(TBStreamPublicPopupMaterialModel *)materialModel;

/// 本地记录物料展示时间和次数
- (void)recordMaterialDisplayInfoWithMaterial:(TBStreamPublicPopupMaterialModel *)materialModel;

/*
 判断物料是否应该展示
 顺序展示只判断物料本身的展示设置
 随机展示要判断所属分组的展示设置
 */
- (BOOL)shouldShowPopupMaterialModel:(TBStreamPublicPopupMaterialModel *)model popupModel:(TBStreamPublicPopupModel *)popupModel;

// 生成相应的model，放到接口文件中
- (TBStreamPublicPopupMaterialModel *)getMaterialModelWithPopupModel:(TBStreamPublicPopupModel *)popupModel;

// 分享渠道顺序接口
// https://tigertech.feishu.cn/wiki/wikcnoqYa8KFHGRPm0YLr3pMDke
- (void)getShareChannelOrderForApp:(NSString *)appName success:(void (^)(NSArray<NSString *> * _Nullable order))success;

@end

NS_ASSUME_NONNULL_END
