//
//  TBWealthCheckManager.h
//  AFNetworking
//
//  Created by wind on 2023/11/1.
//

// 注意事项：使用这边检查项，如果有使用 [TBSupportUtility getTopVC] 展示隐藏 loading 类的操作，建议持有 showLoading 时候的 VC，因为有些检查项有一些默认操作，会跳转到其他 VC ，最后回调的时候 [TBSupportUtility getTopVC] 拿到的已经不是之前的 VC，导致无法正确隐藏 loading

#import <Foundation/Foundation.h>
#import "TBWealthCheckDataSource.h"

@class TBWealthCheckBaseItem;

NS_ASSUME_NONNULL_BEGIN

@interface TBWealthCheckManager : NSObject

/// 检查财富业务各类基础权限
/// - Parameters:
///   - checkItems: 各检查项，根据检查类型 TBWealthCehckType 生成
///   - completion: 检查结果回调
///     - succeed：是否通过
///     - stoppedCheckItem: 停止的检查项，全部通过的话，对应最后一个检查项
///     - resultInfo: 检查结果需要回传的额外信息，用于检查不通过，回传给外部的具体原因
- (void)checkItems:(NSArray<TBWealthCheckBaseItem *> *)checkItems
        completion:(void(^)(BOOL succeed, TBWealthCheckType stoppedCheckItem,  NSDictionary * _Nullable resultInfo))completion;

@end

NS_ASSUME_NONNULL_END
