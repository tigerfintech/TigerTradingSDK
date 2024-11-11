//
//  TBUserBehaviorMarcro.h
//  Pods
//
//  Created by linbingjie on 2021/5/20.
//

#ifndef TBUserBehaviorMarcro_h
#define TBUserBehaviorMarcro_h
#import <TBToolsKit/TBUserBehaviorManager.h>

#define TB_SA_TRACK_APP_BEHAVIOR(_TYPE, _NAME) TB_SA_TRACK_APP_BEHAVIOR_PARAM(_TYPE, _NAME, @"", @"")
#define TB_SA_TRACK_APP_BEHAVIOR_PARAM(_TYPE, _NAME, _PARAM1, _PARAM2)  [TBUserBehaviorManager track:@"appBehavior" withProperties:@{@"type": _TYPE, @"name": _NAME, @"param1": _PARAM1, @"param2": _PARAM2} extraMessage:nil]

#define TB_SA_TRACK_APP_BEHAVIOR_APP(_TYPE, _NAME)  TB_SA_TRACK_APP_BEHAVIOR_APP_PARAM(_TYPE, _NAME, @"", @"")
#define TB_SA_TRACK_APP_BEHAVIOR_APP_PARAM(_TYPE, _NAME, _PARAM1, _PARAM2)  [TBUserBehaviorManager track:@"appBehavior" withProperties:@{@"model": @"App公共部分", @"type": _TYPE, @"name": _NAME, @"param1": _PARAM1, @"param2": _PARAM2} extraMessage:nil]

#define TB_SA_TRACK_APP_BEHAVIOR_QUOTE(_TYPE, _NAME)  TB_SA_TRACK_APP_BEHAVIOR_QUOTE_PARAM(_TYPE, _NAME, @"", @"")
#define TB_SA_TRACK_APP_BEHAVIOR_QUOTE_PARAM(_TYPE, _NAME, _PARAM1, _PARAM2)  [TBUserBehaviorManager track:@"appBehavior" withProperties:@{@"model": @"行情", @"type": _TYPE, @"name": _NAME, @"param1": _PARAM1, @"param2": _PARAM2} extraMessage:nil]

#define TB_SA_TRACK_APP_BEHAVIOR_COMMUNITY(_TYPE, _NAME)  TB_SA_TRACK_APP_BEHAVIOR_COMMUNITY_PARAM(_TYPE, _NAME, @"", @"")
#define TB_SA_TRACK_APP_BEHAVIOR_COMMUNITY_PARAM(_TYPE, _NAME, _PARAM1, _PARAM2)  [TBUserBehaviorManager track:@"appBehavior" withProperties:@{@"model": @"社区", @"type": _TYPE, @"name": _NAME, @"param1": _PARAM1, @"param2": _PARAM2} extraMessage:nil]

#define TB_SA_TRACK_APP_BEHAVIOR_DISCOVERY(_TYPE, _NAME)  TB_SA_TRACK_APP_BEHAVIOR_DISCOVERY_PARAM(_TYPE, _NAME, @"", @"")
#define TB_SA_TRACK_APP_BEHAVIOR_DISCOVERY_PARAM(_TYPE, _NAME, _PARAM1, _PARAM2)  [TBUserBehaviorManager track:@"appBehavior" withProperties:@{@"model": @"发现", @"type": _TYPE, @"name": _NAME, @"param1": _PARAM1, @"param2": _PARAM2} extraMessage:nil]

#define TB_SA_TRACK_APP_BEHAVIOR_TRADE(_TYPE, _NAME)  TB_SA_TRACK_APP_BEHAVIOR_TRADE_PARAM(_TYPE, _NAME, @"", @"")
#define TB_SA_TRACK_APP_BEHAVIOR_TRADE_PARAM(_TYPE, _NAME, _PARAM1, _PARAM2)  [TBUserBehaviorManager track:@"appBehavior" withProperties:@{@"model": @"交易", @"type": _TYPE, @"name": _NAME, @"param1": _PARAM1, @"param2": _PARAM2} extraMessage:nil]

#define TB_SA_TRACK_APP_BEHAVIOR_ME(_TYPE, _NAME)  TB_SA_TRACK_APP_BEHAVIOR_ME_PARAM(_TYPE, _NAME, @"", @"")
#define TB_SA_TRACK_APP_BEHAVIOR_ME_PARAM(_TYPE, _NAME, _PARAM1, _PARAM2)  [TBUserBehaviorManager track:@"appBehavior" withProperties:@{@"model": @"我的", @"type": _TYPE, @"name": _NAME, @"param1": _PARAM1, @"param2": _PARAM2} extraMessage:nil]

#define TB_SA_TRACK_COMMUNITY_ACTION_DIC(_DIC) [TBUserBehaviorManager track:@"communityAction" withProperties:_DIC extraMessage:nil]
#define TB_SA_TRACK_COMMUNITY_ACTION_PARAM(_TYPE, _OBJECTTYPE, _OBJECTID, _CURRENTPAGE, _CURRENTPAGEID, AUTHOR, SYMBOL, _OBJECTFEATURES)  [TBUserBehaviorManager track:@"communityAction" withProperties:@{@"type": _TYPE, @"objectType": _OBJECTTYPE, @"objectId": _OBJECTID, @"currentPage": _CURRENTPAGE, @"currentPageId": _CURRENTPAGEID, @"author": AUTHOR, @"symbols": SYMBOL, @"objectFeatures": _OBJECTFEATURES ?: @[]} extraMessage:nil]

#define TB_SA_TRACK_APP_SHARE_WITH_ID(_UUID, _TYPE, _CHANNEL, _SHAREID)   [TBUserBehaviorManager track:@"appShare" withProperties:@{@"uuid": _UUID, @"type": _TYPE, @"shareTo": _CHANNEL, @"shareID": _SHAREID} extraMessage:nil]

//TODO: 添加 shareID 之后，不使用这个宏
#define TB_SA_TRACK_APP_SHARE(_UUID, _TYPE, _CHANNEL)   [TBUserBehaviorManager track:@"appShare" withProperties:@{@"uuid": _UUID, @"type": _TYPE, @"shareTo": _CHANNEL} extraMessage:nil]

#define TB_SA_TRACK(_EVENT, _PROPERTIES)                [TBUserBehaviorManager track:_EVENT withProperties:_PROPERTIES extraMessage:nil]

#define TB_SA_TRACK_APP_QUOTE_IMPRESSION(_MODEL, _TYPE, _SECTOR)  [TBUserBehaviorManager track:@"quoteImpression" withProperties:@{@"model": _MODEL, @"type": _TYPE, @"sector": _SECTOR} extraMessage:nil]

#define TB_SA_TRACK_APPLE_PAY(_PROPERTIES) [TBUserBehaviorManager track:@"ApplePay" withProperties:_PROPERTIES extraMessage:nil]

#define TB_TRACK_APP_BEHAVIOR_IPO(_model, _TYPE, _NAME)  TB_TRACK_APP_BEHAVIOR_IPO_PARAM(_model, _TYPE, _NAME, @"", @"")

#define TB_TRACK_APP_BEHAVIOR_IPO_PARAM(_model, _TYPE, _NAME, _PARAM1, _PARAM2)  [TBUserBehaviorManager track:@"appBehavior" withProperties:@{@"model":_model, @"type": _TYPE, @"name": _NAME, @"param1": _PARAM1, @"param2": _PARAM2} extraMessage:nil]

#define TB_SA_TRACK_APP_BEHAVIOR_STOCK_DETAIL(_NAME)  TB_SA_TRACK_APP_BEHAVIOR_STOCK_DETAIL_PARAM(_NAME, @"", @"")
#define TB_SA_TRACK_APP_BEHAVIOR_STOCK_DETAIL_PARAM(_NAME, _PARAM1, _PARAM2) TB_SA_TRACK_APP_BEHAVIOR_QUOTE_PARAM(@"标的详情页", _NAME, _PARAM1, _PARAM2)

#define TB_SA_PEOPLE_SET(_PROFILE, _CONTENT)            [TBUserBehaviorManager setPeopleProfile:_PROFILE content:_CONTENT]

#define TB_SA_TRACK_TIMER_START(_EVENT)                 [TBUserBehaviorManager trackTimerStart:_EVENT]
#define TB_SA_TRACK_TIMER_END(_EVENT, _PROPERTIES)      [TBUserBehaviorManager trackTimerEnd:_EVENT withProperties:_PROPERTIES]

#define TB_SA_TRACK_APP_BEHAVIOR_ACCOUNT(_TYPE, _NAME)  TB_SA_TRACK_APP_BEHAVIOR_ACCOUNT_PARAM(_TYPE, _NAME, nil)
#define TB_SA_TRACK_APP_BEHAVIOR_ACCOUNT_PARAM(_TYPE, _NAME, _PRIVATEPARAMS)  [TBUserBehaviorManager track:@"appBehavior" withProperties:@{@"model": @"账户", @"type": _TYPE, @"name": _NAME} privateParameters:_PRIVATEPARAMS extraMessage:nil]

#pragma mark - 这两个宏暂保留，新增埋点不再使用
/// 事件：page_view
/// 输入属性参数：component、actionType、page、自定义属性（_COMPONENT）
#define TB_SA_TRACK_APP_PAGE_VIEW(_COMPONENT, _ACTIONTYPE, _PAGE, _CUSTOMIZEPATAMS)  [TBUserBehaviorManager track:@"page_view" withProperties:@{@"component": _COMPONENT, @"actionType": _ACTIONTYPE, @"page": _PAGE} privateParameters:_CUSTOMIZEPATAMS extraMessage:nil]
/// 事件：action
/// 输入属性参数：component、actionType、自定义属性（_COMPONENT）
#define TB_SA_TRACK_APP_ACTION(_COMPONENT, _ACTIONTYPE, _PAGE, _CUSTOMIZEPATAMS)  [TBUserBehaviorManager track:@"action" withProperties:@{@"component": _COMPONENT, @"actionType": _ACTIONTYPE, @"page": _PAGE} privateParameters:_CUSTOMIZEPATAMS extraMessage:nil]

#pragma mark - 包含基本属性：event、component、actionType、page、arriveFrom

/*
 通常使用前三个宏即可满足需求：参数传递VC对象，内部自动处理page、arriveFrom数据；
 特殊情况下，各参数值想要自行传递，可用后边几个。
 具体使用指引可查看文档：https://tigertech.feishu.cn/docs/doccnfXWnj6xIgVMKE0lv2sKAGb
 */

/// 展示事件：page_view （方法内部会自动处理arriveFrom）
/// 输入属性参数：ViewController对象、自定义属性（可选）
#define TB_SA_TRACK_PAGE_VIEW_VIEWCONTROLLER(_VIEWCONTROLLER, _CUSTOMIZEPATAMS)                         [TBUserBehaviorManager trackPageViewWithViewController:_VIEWCONTROLLER extraMessage:_CUSTOMIZEPATAMS]

/// 点击事件：click action（方法内部会处理page）
/// 输入属性参数：component、ViewController对象、自定义属性（可选）
#define TB_SA_TRACK_ACTION_CLICK_VIEWCONTROLLER(_COMPONENT, _VIEWCONTROLLER, _CUSTOMIZEPATAMS)   [TBUserBehaviorManager trackActionWithComponent:_COMPONENT actionType:@"click" ViewController:_VIEWCONTROLLER extraMessage:_CUSTOMIZEPATAMS]

/// 输入事件：input action（方法内部会处理page）
/// 输入属性参数：component、ViewController对象、自定义属性（可选）
#define TB_SA_TRACK_ACTION_INPUT_VIEWCONTROLLER(_COMPONENT, _VIEWCONTROLLER, _CUSTOMIZEPATAMS)   [TBUserBehaviorManager trackActionWithComponent:_COMPONENT actionType:@"input" ViewController:_VIEWCONTROLLER extraMessage:_CUSTOMIZEPATAMS]

/// 事件：action（方法内部会处理page）
/// 输入属性参数：component、actionType、ViewController对象、自定义属性（可选）
#define TB_SA_TRACK_ACTION_VIEWCONTROLLER(_COMPONENT, _ACTIONTYPE, _VIEWCONTROLLER, _CUSTOMIZEPATAMS)   [TBUserBehaviorManager trackActionWithComponent:_COMPONENT actionType:_ACTIONTYPE ViewController:_VIEWCONTROLLER extraMessage:_CUSTOMIZEPATAMS]

/// 展示事件：page_view （所有参数都自己传递）
/// 输入属性参数：component、actionType、page、arriveFrom、自定义属性（可选）
#define TB_SA_TRACK_PAGE_VIEW(_COMPONENT, _ACTIONTYPE, _PAGE, _ARRIVEFROM, _CUSTOMIZEPATAMS)                [TBUserBehaviorManager trackWithEvent:@"page_view" component:_COMPONENT actionType:_ACTIONTYPE page:_PAGE arriveFrom:_ARRIVEFROM extraMessage:_CUSTOMIZEPATAMS]
/// 点击、输入等事件：action（所有参数自己传递）
/// 输入属性参数：component、actionType、page、arriveFrom、自定义属性（可选）
#define TB_SA_TRACK_ACTION(_COMPONENT, _ACTIONTYPE, _PAGE, _ARRIVEFROM, _CUSTOMIZEPATAMS)                   [TBUserBehaviorManager trackWithEvent:@"action" component:_COMPONENT actionType:_ACTIONTYPE page:_PAGE arriveFrom:_ARRIVEFROM extraMessage:_CUSTOMIZEPATAMS]
/// 模块曝光事件：impression（所有参数自己传递）
/// 输入属性参数：component、actionType、page、arriveFrom、自定义属性（可选）
#define TB_SA_TRACK_IMPRESSION(_COMPONENT, _ACTIONTYPE, _PAGE, _ARRIVEFROM, _CUSTOMIZEPATAMS)                   [TBUserBehaviorManager trackWithEvent:@"impression" component:_COMPONENT actionType:_ACTIONTYPE page:_PAGE arriveFrom:_ARRIVEFROM extraMessage:_CUSTOMIZEPATAMS]


#pragma mark --- 8.0首页埋点
/// 首页action事件
#define TB_SA_TRACK_HOMEPAGE_ACTION(_COMPONENT, _ACTIONTYPE, _CUSTOMIZEPATAMS) TB_SA_TRACK_ACTION(_COMPONENT, _ACTIONTYPE, @"首页", nil, _CUSTOMIZEPATAMS)

#define TB_SA_TRACK_APP_ACTION_CLICK(_COMPONENT, _PAGE, _CUSTOMIZEPATAMS) TB_SA_TRACK_ACTION(_COMPONENT, @"click", _PAGE, nil, _CUSTOMIZEPATAMS)

/// 首页action事件-click事件
#define TB_SA_TRACK_HOMEPAGE_ACTION_CLICK(_COMPONENT, _CUSTOMIZEPATAMS) TB_SA_TRACK_HOMEPAGE_ACTION(_COMPONENT, @"click", _CUSTOMIZEPATAMS)

/// 首页page_view事件
#define TB_SA_TRACK_HOMEPAGE_PAGE_VIEW(_COMPONENT, _CUSTOMIZEPATAMS) TB_SA_TRACK_PAGE_VIEW(_COMPONENT, @"page_view", @"首页", nil, _CUSTOMIZEPATAMS)


#endif /* TBUserBehaviorMarcro_h */
