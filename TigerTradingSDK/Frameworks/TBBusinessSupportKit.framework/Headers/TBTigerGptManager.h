//
//  TBTigerGptManager.h
//  TBCommunityBusiness
//
//  Created by dulijun on 2023/5/11.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>

//NS_ASSUME_NONNULL_BEGIN

@interface TBTigerGptManager : NSObject
DECLARE_SHARED_INSTANCE(TBTigerGptManager);

#pragma mark - 公用
/// TigerGpt 网页地址（TigerGpt页为web页）
+ (NSString *)tigerGptWebLink;

/// 打开TigerGpt页
+ (void)openTigerGptPage;

/// 打开TigerGpt页，可携带参数，拼在url上
/// - Parameter query: 在url上拼接的参数
+ (void)openTigerGptPageWithQuery:(NSDictionary *)query;

/// 打开TigerGpt设置页
+ (void)openTigerGptSettingPage;

#pragma mark - 首页TigerGpt相关
/// 首页是否可以展示TigerGpt按钮（注意：是否可以展示，但不一定会展示，因为可以通过设置中开关控制）
+ (BOOL)homepageCouldShowGpt;

/// 首页是否要展示TigerGpt入口
+ (BOOL)homepageShouldShowGpt;

/// 更新设置中，首页是否展示tigerGpt开关状态
/// - Parameter isVisible: 是否展示
+ (void)updateHomepageTigerGptIsVisible:(BOOL)isVisible;

/// 首页中saerch按钮引导气泡是否展示过
+ (BOOL)isHomepageSearchTipDidShow;
/// 更新状态：首页中saerch按钮引导气泡已经展示过
+ (void)homepageSearchTipDidShow;
/// 首页中gpt入口按钮引导气泡是否展示过
+ (BOOL)isHomepageGptEntranceTipDidShow;
/// 更新状态：首页中gpt入口按钮引导气泡是否展示过
+ (void)homepageGptEntranceTipDidShow;

// 美股公告页面是否显示gpt入口
+ (BOOL)usNoticePageShouldShowGpt;

#pragma mark - 搜索页TigerGpt
/// 搜索页是否要展示TigerGpt入口
+ (BOOL)searchPageShouldShowGpt;

#pragma mark - 个股详情页

/// 个股页是否可以展示TigerGpt按钮
+ (BOOL)stockDetailPageCouldShowGpt;

/// 个股详情页是否要展示TigerGpt 气泡tip
+ (BOOL)stockDetailPageShouldShowGptTip ;

/// 获取个股详情页TigerGpt的引导气泡数据
/// - Parameters:
///   - symbol: 个股symbol
///   - success: 返回的数据格式为：{@"showAccess":true, @"presetQuestionId": @"xxx", @"presetQuestion": @"xxx"}。showAccess：是否展示gpt入口，presetQuestion：tip气泡信息
///   - failure: 失败回调
+ (void)fetchStockDetailTigerGptInfoWithSymbol:(NSString *)symbol success:(void(^)(NSDictionary *responseObject))success
                                       failure:(void(^)(NSError *error))failure;
/// 更新设置中开关状态：个股详情页是否展示tigerGpt tip
/// - Parameter isVisible: 是否展示
+ (void)updateStockDetialTigerGptTipIsVisible:(BOOL)isVisible;

@end

//NS_ASSUME_NONNULL_END
