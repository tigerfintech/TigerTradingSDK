//
//  TBFloatingPanelListViewController.h
//  TBUIKit
//
//  Created by linbingjie on 2023/7/28.
//

#import <TBUIKit/TBUIKit.h>
#import <TBUIKit/TBListTableViewController.h>
#import <TBUIKit/TBFloatingPanelTopTitleView.h>
#import <TBUIKit/TBFloatingPanelBtoomDetailView.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBFloatingPanelListViewController : TBListTableViewController

@property (nonatomic, copy) CheckboxButtonBlock checkboxButtonBlock; // checkbox的勾选按钮点击事件
@property (nonatomic, copy) CheckboxMessageBlock checkboxMessageBlock; // checkbox 文案点击事件
@property (nonatomic, copy) ComfirmClickActionBlock comfirmClickActionBlock; // 确认按钮block
@property (nonatomic, copy) CancelClickActionBlock cancelClickActionBlock;  // 取消按钮block

@property (nonatomic, assign) BOOL dismissWhenDidSelected;              // 选中某个item页面是否消失，默认:NO

/// 配置标题文案和detail文案
/// - Parameters:
///   - strTitle: 标题文案
///   - strDetail: detail 文案
- (void)configTitleString:(NSString *)strTitle subTitleString:(NSString *)strDetail;

/// 配置确认按钮文案
/// - Parameters:
///   - title: 文案
///   - isComfirmHidden: 是否隐藏
- (void)configBtnComfirmTitle:(NSString *)title comfirmHidden:(BOOL)isComfirmHidden;

/// 配置取消按钮文案
/// - Parameters:
///   - title: 文案
///   - isComfirmHidden: 是否隐藏
- (void)configBtnCancelTitle:(NSString *)title cancelHidden:(BOOL)isCancelHidden;
- (void)configBtnCancelTitle:(NSString *)title cancelHidden:(BOOL)isCancelHidden borderHidden:(BOOL)isBorderHidden; // 边是否隐藏

/// check按钮相关配置 （默认未选中）
/// - Parameters:
///   - title: 显示文案  最多3行
///   - isCheckHidden: 是否隐藏
- (void)configLblCheckTitle:(NSString *)title
                checkHidden:(BOOL)isCheckHidden;

/// check按钮相关配置 （默认未选中）
/// - Parameters:
///   - title: 显示文案  最多3行
///   - isCheckSeledted: 设置check选中状态
///   - isCheckHidden: 是否隐藏
- (void)configLblCheckTitle:(NSString *)title
              checkSeledted:(BOOL)isCheckSeledted
                checkHidden:(BOOL)isCheckHidden;

- (void)configCancelButtonBorderHidden:(BOOL)isBorderHidden;


- (NSInteger)fetchTopViewHeight;    // 获取顶部页面高度
- (NSInteger)fetchBottomViewHeight; // 获取底部页面高度

// 更新内部UI约束
- (void)updateViewUI;

@end

NS_ASSUME_NONNULL_END
