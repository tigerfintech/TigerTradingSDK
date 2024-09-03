//
//  TBConfigureServerModel.h
//  Stock
//
//  Created by 董恭甫 on 2017/8/4.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <TBBaseKit/JSONModel.h>

@protocol TBConfigureServerItemModel;
@protocol TBConfigureServerItemDomainConfigModel;

@class TBConfigureServerItemPushModel;
@class TBConfigureServerItemEsopModel;

@interface TBConfigureServerModel : JSONModel

@property (nonatomic, assign) NSInteger ret;
@property (nonatomic, copy) NSString *msg;
@property (nonatomic, copy) NSArray<TBConfigureServerItemModel> *items;

//@property (nonatomic, assign) NSTimeInterval serverTime;

@end


@interface TBConfigureServerItemModel : JSONModel

@property (nonatomic, copy) NSString *businessName;
@property (nonatomic, copy) NSArray<TBConfigureServerItemDomainConfigModel> *domainConfigList;



//@property (nonatomic, copy) NSString *apilist;          // 环球交易
//@property (nonatomic, copy) NSString *hqlist;           // 行情
@property (nonatomic, copy) NSDictionary *customer;     // 开户 key=license
@property (nonatomic, copy) NSString *customerSupport;  // 非证券业务的支持项目

// 社区
//@property (nonatomic, copy) NSDictionary *newsList; // 社区新闻 key=region

//@property (nonatomic, copy) NSDictionary *gcsChat; // 在线chat地址，key=license
//@property (nonatomic, copy) NSDictionary *ticket; // 新版用户反馈API

// 社区
@property (nonatomic, copy) NSDictionary *liveList; // 社区直播域名, key为region.
//@property (nonatomic, copy) NSDictionary *tigerCommunityList; // 社区service.laohu8域名, key为region.
@property (nonatomic, copy) NSDictionary *webCommunityList; // 社区laohu8域名, key为region.
@property (nonatomic, copy) NSDictionary *communityList; // 社区fronted域名, key为region. 常见于推荐等feed请求
//@property (nonatomic, copy) NSDictionary *communityPushList; // 社区push相关域名
@property (nonatomic, copy) NSString *theme; // 社区主题
//@property (nonatomic, copy) NSString *spacePay; // 空间站提现
@property (nonatomic, copy) NSString *communityVideoUpload;

// 官网
//@property (nonatomic, copy) NSDictionary *portalServer;//NPS域名，key为location
//@property (nonatomic, copy) NSDictionary *portal; // 官网域名, key为location.

//@property (nonatomic, copy) NSDictionary *webIPO; // IPO, 质押融资业务
@property (nonatomic, copy) NSString *campaign;   // 优惠券信息
@property (nonatomic, copy) NSString *bffMobile;  // 8.0首页模块配置

// auth
//@property (nonatomic, copy) NSString *tesseract; // 香港
//@property (nonatomic, copy) NSString *tesseractPoll; // 北京

// 期权
//@property (nonatomic, copy) NSString *optionGeek;
//@property (nonatomic, copy) NSString *optionDepth;
@property (nonatomic, copy) NSString *option;

#pragma mark - 行情
//@property (nonatomic, copy) NSString *econdataHost; // 宏观经济日历
//@property (nonatomic, copy) NSString *futureContract; // 期货合约
//@property (nonatomic, copy) NSString *hqPerm; // 行情权限
//@property (nonatomic, copy) NSString *futureQuote; // 期货行情
@property (nonatomic, copy) NSString *cryptoWeb; // 数字货币行情
//@property (nonatomic, copy) NSString *greyQuote; // 暗盘行情
//@property (nonatomic, copy) NSString *depth; // 美股深度数据
//@property (nonatomic, copy) NSString *optionlist;

// 交易
@property (nonatomic, copy) NSString *omnibus;
@property (nonatomic, copy) NSString *virtualTrade; // 模拟账户
//@property (nonatomic, copy) NSString *omnibuslist;
@property (nonatomic, copy) NSDictionary *trade; // omnibus交易域名, key为license.

// esop
@property (nonatomic, copy) NSString *esopAPI; // TODO: 改成dict?
@property (nonatomic, copy) NSString *esopWeb; // TODO: 改成dict?

// 基础
//@property (nonatomic, copy) NSString *sensors; // 神策


//@property (nonatomic, copy) NSString *stockgame; // 炒股大赛
//@property (nonatomic, copy) NSString *webAMS; // 个人中心业务
//@property (nonatomic, copy) NSString *biStream; // 营销增长相关
//@property (nonatomic, copy) NSDictionary *fundBusiness; //基金业务
//@property (nonatomic, copy) NSString *tipRanks;
//@property (nonatomic, copy) NSString *backendActivity; // 活动, 使用默认官网域名
@property (nonatomic, copy) NSString *live;

// mqtt
//@property (nonatomic, strong) TBConfigureServerItemPushModel *push; // 长连接
//@property (nonatomic, strong) TBConfigureServerItemPushModel *cryptoPush; // 数字货币长连接
//@property (nonatomic, copy) NSString *push2; // APNs
//@property (nonatomic, copy) NSString *iap; // iOS内购

#pragma mark - unused
@property (nonatomic, copy) NSString *securities;
@property (nonatomic, copy) NSString <Ignore>  *portal_default;
@property (nonatomic, copy) NSString *upgrade; // "https://up.play-analytics.com",
@property (nonatomic, copy) NSString *instAccountCenter_default;
@property (nonatomic, copy) NSDictionary *instAccountCenter;
@property (nonatomic, copy) NSString *weibo;
@property (nonatomic, copy) NSString *facebook;
@property (nonatomic, copy) NSString *wechat;
@property (nonatomic, copy) NSString *guardian;

@property (nonatomic, copy) NSString *exceptionLog;


#pragma mark - Ignore
@property (nonatomic, copy) NSString <Ignore> *api; // apilist
@property (nonatomic, copy) NSString <Ignore> *apihk; // apilist

@property (nonatomic, copy) NSString <Ignore> *quote; // hqlist
@property (nonatomic, copy) NSString <Ignore> *watchlist; // hqlist

@property (nonatomic, copy) NSString <Ignore> *oauth; // oauth-global
@property (nonatomic, copy) NSString <Ignore> *oauthlist; // oauth-global

@property (nonatomic, copy) NSString <Ignore> *news; // newslist
@property (nonatomic, copy) NSString <Ignore> *news2; // newslist

// app未使用

// 下线
@property (nonatomic, copy) NSString <Ignore> *ffa; // 财富管理
@property (nonatomic, copy) NSString <Ignore> *hostAppAnalyticsTigerBBS; // 社区统计

//@property (nonatomic, copy) NSString <Ignore> *tcti; // 下线

//@property (nonatomic, copy) NSString <Ignore> *www; // 使用portal
//@property (nonatomic, copy) NSString <Ignore> *stock; // 使用portal
//@property (nonatomic, copy) NSString <Ignore> *sspWeb; // 广告系统(deprecated)

#pragma mark -
// 社区
//@property (nonatomic, copy) NSString <Ignore> *webCommunity; // 使用web-community-list
//@property (nonatomic, copy) NSString <Ignore> *tigerbrokersCommunity; // 使用tiger-community-list
//@property (nonatomic, copy) NSString <Ignore> *community; // 使用community-list
//@property (nonatomic, copy) NSString <Ignore> *communityBroadcast; // 未使用
//@property (nonatomic, copy) NSString <Ignore> *communityHost; // 使用community-list
//@property (nonatomic, copy) NSString <Ignore> *scoreMall; // 悬赏贴规则
//@property (nonatomic, copy) NSString <Ignore> *PDFReader; // 社区研选周报 未使用

//@property (nonatomic, copy) NSString *marketing; // 活动营销

// 是否使用omnibusTrade长连接推送. 临时放在这里, 以后会放在用户设置
@property (nonatomic, copy) NSString *omnibusTradePush;

@end


@interface TBConfigureServerItemPushModel : JSONModel

@property (nonatomic, copy) NSString *host;
@property (nonatomic, strong) NSNumber *port;
@property (nonatomic, copy) NSString *protocol;

@end


@interface TBConfigureServerItemEsopModel : JSONModel

@property (nonatomic, copy) NSString *commonHost;
@property (nonatomic, copy) NSString *sgHost;

@end

@interface TBConfigureServerItemDomainConfigModel : JSONModel

@property (nonatomic, copy) NSString *domainName;
@property (nonatomic, copy) NSString *region;
@property (nonatomic, copy) NSString *location;
@property (nonatomic, copy) NSString *license;
@property (nonatomic, copy) NSString *addition;

@end
