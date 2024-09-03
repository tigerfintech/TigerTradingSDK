//
//  TBSelectCellProtocol.h
//  TBUIKit
//
//  Created by linbingjie on 2023/8/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    TBSelectCellUIType_None = 0, // 基础只有一个边框
    TBSelectCellUIType_SingleChoice = 1, // 单选样式 (最前面一个选中的点)
    TBSelectCellUIType_MutChoice_MandatoryChoice = 2, // 多选_必选样式 (无对钩)
    TBSelectCellUIType_MutChoice_MenuOption = 3, // 多选_菜单可选样式 （圆圈+勾）
    TBSelectCellUIType_MutChoice_Option = 4, // 多选_不含菜单的可选项样式 （内嵌对钩）
} TBSelectCellUIType;

@protocol TBSelectCellProtocol <NSObject>

/// 更新选中状态 会变更相关的文字边框的样式
/// - Parameter isSelected: 是否选中
- (void)setSelectionCellSelected:(BOOL)isSelected;

/// 获取当前cell是否选中
- (BOOL)fetchSelectedStauts;

/// 获取当前collection的UI样式类型
- (TBSelectCellUIType)fetchCurrentSelectCellType;

@end

NS_ASSUME_NONNULL_END
