//
//  TBSegmentControlView.h
//  AFNetworking
//
//  Created by linbingjie on 2023/9/25.
//

#import <TBUIKit/JXCategoryTitleView.h>

#define kTBSegmentHeight 32

NS_ASSUME_NONNULL_BEGIN

@interface TBSegmentControlView : JXCategoryTitleView

+ (UIFont *)textFont;

/// 设置title标题，必须设置准确地view宽度，因为内部需要根据view width/ titles.count进行页面布局
/// - Parameters:
///   - titles: 标题
///   - viewWidth: contentview的总宽度
- (void)configTitle:(NSArray<NSString *>*)titles viewWidth:(NSInteger)viewWidth;

@end

NS_ASSUME_NONNULL_END
