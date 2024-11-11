//
//  TBFloatPanelSelectViewController.h
//  TBUIKit
//
//  Created by zlc on 2024/1/9.
//

#import <TBUIKit/TBFloatingPanelListViewController.h>
#import <TBUIKit/TBStockSettingChoiceCellItem.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^SelectedComfirmClickActionBlock)(TBStockSettingChoiceCellItem *selectedItem);

@interface TBFloatPanelSelectViewController : TBFloatingPanelListViewController

@property (nonatomic, strong, nullable) SelectedComfirmClickActionBlock selectedItemDidChangedBlock;

/**
 * 生成默认样式的listItems
 * eg: 仅支持综合账户进行交易（默认无选中状态）
 * UI: https://www.figma.com/file/YnWpqhLngtJ7pHaLshXZk8/913%5C914-Contra?node-id=1128%3A13145&mode=dev
 */
+ (NSArray <TBStockSettingChoiceCellItem *> *)generateDefaultListItemsWithTitles:(NSArray <NSString *> *)titles;

/// alert （string）
/// ⭐️如果传入的按钮文案为nil，就隐藏该按钮⭐️
/// - Parameters:
///   - title: 标题
///   - secTitle: 副标题
///   - listItems: 详情可选项配置
///   - comfirmBtnTitle: 确认按钮
///   - cancelBtnTitle: 取消按钮
///   - comfirmClickActionBlock: 确认按钮点击事件
///   - cancelClickActionBlock: 取消按钮点击事件
+ (TBFloatPanelSelectViewController *)showWithTitle:(nullable NSString *)title
                                           subtitle:(nullable NSString *)secTitle
                                          listItems:(nullable NSArray <TBStockSettingChoiceCellItem *> *)listItems
                                    comfirmBtnTitle:(nullable NSString *)comfirmBtnTitle
                                     cancelBtnTitle:(nullable NSString *)cancelBtnTitle
                            comfirmClickActionBlock:(nullable SelectedComfirmClickActionBlock)comfirmClickActionBlock
                             cancelClickActionBlock:(nullable CancelClickActionBlock)cancelClickActionBlock;


+ (TBFloatPanelSelectViewController *)showWithTitle:(nullable NSString *)title
                                           subtitle:(nullable NSString *)secTitle
                                           parentVC:(nullable UIViewController *)parentVC
                                          listItems:(nullable NSArray <TBStockSettingChoiceCellItem *> *)listItems
                                    comfirmBtnTitle:(nullable NSString *)comfirmBtnTitle
                                     cancelBtnTitle:(nullable NSString *)cancelBtnTitle
                            comfirmClickActionBlock:(nullable SelectedComfirmClickActionBlock)comfirmClickActionBlock
                             cancelClickActionBlock:(nullable CancelClickActionBlock)cancelClickActionBlock;
@end

NS_ASSUME_NONNULL_END
