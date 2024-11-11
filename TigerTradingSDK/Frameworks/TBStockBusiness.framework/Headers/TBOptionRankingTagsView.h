//
//  TBOptionRankingTagsView.h
//  TBStockBusiness
//
//  Created by 王昌阳 on 2023/8/3.
//

#import <TBUIKit/TBUIKit.h>
#import <TBUIKit/TBView.h>
#import <TBUIKit/TBTableViewCell.h>
#import "TBOptionTabModel.h"

NS_ASSUME_NONNULL_BEGIN

#define kTBOptionRankingTags2LinesViewHeight (82)
#define kTBOptionRankingTags1LineViewHeight (46)

@interface TBOptionRankingTagsView : TBView

@property (nonatomic, copy) void(^selectRankTypeBlock)(TBOptionRankTypeModel *selectedRankType);

@property (nonatomic, assign) NSInteger numberOfLines;

- (void)reloadDisplayTags:(NSArray<TBOptionRankTypeModel *> *)rankTypes
         selectedRankType:(TBOptionRankTypeModel *)selectedRankType;

- (void)reloadTagsView;

- (void)scrollToSelectedIndex;

@end

NS_ASSUME_NONNULL_END
