//
//  TBMultipleChoiceSelectCollectionViewCell.h
//  TBUIKit
//
//  Created by linbingjie on 2023/8/17.
//

#import <TBUIKit/TBUIKit.h>
#import <TBUIKit/TBSelectBaseBorderCollectionViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBMultipleChoiceSelectCollectionViewCell : TBSelectBaseBorderCollectionViewCell


/// 配置选项cell的UI样式 默认为 TBSelectCellUIType_MutChoice_MandatoryChoice 样式
/// - Parameter selectUIType: selectUIType
- (void)configSelectUIStyle:(TBSelectCellUIType)selectUIType;

@property (nonatomic, copy) void(^menuOption_removeBlock)(TBSelectCellUIType selectUIType, TBMultipleChoiceSelectCollectionViewCell *cell);  // TBSelectCellUIType_MutChoice_MenuOption 点击右上角取消按钮会响应block


- (void)updateTitle:(nullable NSString *)strTitle
        detailTitle:(nullable NSString *)strSubTtitle
     selectedStatus:(BOOL)isSelected;
@end

NS_ASSUME_NONNULL_END
