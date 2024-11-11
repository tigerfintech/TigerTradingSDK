//
//  TBOptionEmptyView.h
//  TBStockBusiness
//
//  Created by 王灵博 on 2021/9/16.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionEmptyView : UIView

@property(nonatomic, strong)UILabel *emptyLabel;
@property (nonatomic, assign) BOOL isOptionScreener; // 是否是期权筛选器（UI不同）

// 图片顶部边距，默认为80
@property (nonatomic, assign) CGFloat imageTopOffset;
@property(nonatomic, assign)BOOL havePermission;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *trackPage; // 埋点page参数

- (void)changeAppColorStyle;

@end

NS_ASSUME_NONNULL_END
