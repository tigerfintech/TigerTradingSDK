//
//  TBDemoCustomHomeModule.h
//  TigerQuoteSDK
//
//  Demo:首页自定义模块的完整封装。
//  内部持有 customView / 状态 / item 引用,对外提供一个 -currentItem 方法给
//  TigerTradingQuoteDelegate.customHomePageModules 使用。
//
//  演示要点:
//    - customView 跨 pull 稳定(单次构造后复用),让"切换高度"按钮的状态能保持
//    - 按钮 target-action 走 self,与 host VC 解耦
//    - -reload 通过 [item reload] 触发,验证 SDK → tbhomepage 反向调用链路
//

#import <UIKit/UIKit.h>

@class TigerTradingSDKHomeModuleItem;

NS_ASSUME_NONNULL_BEGIN

@interface TBDemoCustomHomeModule : NSObject

/// 生成当前 item(内部按需构造 customView,跨 pull 复用)。
/// 每次调用都返回一个新的 model 实例(SDK 侧过滤 / 顺序等由 SDK 处理),
/// 但内部持有的 customView / 状态保持不变。
- (TigerTradingSDKHomeModuleItem *)currentItem;

@end

NS_ASSUME_NONNULL_END
