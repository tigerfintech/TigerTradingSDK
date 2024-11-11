//
//  TBOptionScreenerRecommendFilterView.h
//  Pods
//
//  Created by zlc on 2022/5/18.
//  
//

#import <TBUIKit/TBTableViewCell.h>

@class TBOptionScreenerConfigurationStrategy;

NS_ASSUME_NONNULL_BEGIN

@interface TBOptionScreenerRecommendFilterViewItem : TBTableViewCellItem

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *subTitle;
@property (nonatomic, copy) NSString *filterTips;
@property (nonatomic, assign) BOOL isAscending; // 是否是升序；默认降序

@property (nonatomic, strong) TBOptionScreenerConfigurationStrategy *strategyModel;

@end

@interface TBOptionScreenerRecommendFilterView : TBTableViewCell

@end

NS_ASSUME_NONNULL_END
