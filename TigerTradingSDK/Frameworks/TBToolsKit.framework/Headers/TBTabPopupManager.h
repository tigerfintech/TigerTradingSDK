//
//  TBTabPopupManager.h
//  TBToolsKit
//
//  Created by dulijun on 2023/6/1.
//

#import <Foundation/Foundation.h>
#import <TBBaseKit/TBBaseUtility.h>


@interface TBTabPopupManager : NSObject

DECLARE_SHARED_INSTANCE(TBTabPopupManager)

/// tabBar 二级tab物料弹框请求、展示
/// - Parameters:
///   - tabKey:各tab key，用于请求物料
///   homePage   首页
///   discoveryTab  发现
///   watchList 自选
///   stocks 股票
///   futures 期货
///   funds 基金
///   global全球
///   comunityTab 社区
///   news 资讯
///   college 学堂
///   communityLive 直播
///   tradeTab 交易
///   mineTab  我的）
///   - tabIndex: 该弹框所在一级tab index
///   - subTabIndex: 该弹框所在二级tab index
///   - isRealTime: 是否是实时物料
+ (void)showTabPopupIfNeedWithTabKey:(NSString *)tabKey
                            tabIndex:(NSInteger)tabIndex
                         subTabIndex:(NSInteger)subTabIndex
                          isRealTime:(BOOL)isRealTime;

@end

