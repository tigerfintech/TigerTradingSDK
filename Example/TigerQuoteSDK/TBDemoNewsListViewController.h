//
//  TBDemoNewsListViewController.h
//  TigerQuoteSDK
//
//  Demo:内嵌 UITableView + MJRefresh 上拉加载的资讯列表。
//  用于演示 TigerTradingSDKStockDetailTabItem 的 listScrollViewProvider /
//  contentHeightProvider 兼容路径 —— host newsVC 内部是 tableView 且有分页加载时,
//  SDK 侧 wrapper 能拿到实时 contentSize 完成嵌套滚动联动。
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBDemoNewsListViewController : UIViewController

/// 内嵌 tableView,暴露给 delegate 层用来喂 provider block。
@property (nonatomic, strong, readonly) UITableView *newsTable;

@end

NS_ASSUME_NONNULL_END
