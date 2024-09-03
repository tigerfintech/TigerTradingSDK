//
//  TBOptionStrategyBuilderCombinedInfoCell.h
//  TBStockBusiness
//
//  Created by zlc on 2023/6/20.
//

#import <TBUIKit/TBUIKit.h>
#import <TBUIKit/TBTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionStrategyBuilderCombinedInfoCellItem : TBTableViewCellItem

@property (nonatomic, assign) BOOL isThreeLinesInfoTheme; // 是否是3列信息样式，默认2列

@property (nonatomic, assign) BOOL isSegHidden; // seg 区域是否隐藏

@property (nonatomic, assign) NSInteger segIndex;
@property (nonatomic, copy) NSArray <NSDictionary *> *detailDatas;

@end


@interface TBOptionStrategyBuilderCombinedInfoCell : TBTableViewCell

- (UICollectionViewFlowLayout *)getLayout;

@end

/// 3列info数据，子类配置
@interface TBOptionStrategyBuilderCombinedInfoThreeLinesCell : TBOptionStrategyBuilderCombinedInfoCell

@end

NS_ASSUME_NONNULL_END
