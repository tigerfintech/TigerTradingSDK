//
//  TBTradeTitleView.h
//  Stock
//
//  Created by 马超 on 2017/10/27.
//  Copyright © 2017年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TBUIKit/TBTableView.h>

@protocol TBTradeTitleViewDelegate;

@interface TBTradeTitleView : UIView

@property (nonatomic, strong) UILabel *titleLabel;

@property (nonatomic, strong) UILabel *subTitleLabel;

@property (nonatomic, strong) UIButton *riskWarningBtn;///< 风控状态

@property (nonatomic, strong, readonly) UIImageView *virtualAccountImageView;///< 模拟盘图标

@property (nonatomic, weak) id<TBTradeTitleViewDelegate> delegate;

@property (nonatomic, assign) BOOL showRiskWarning;  // Default:NO

@property (nonatomic, assign) BOOL showOnkeyWindow;  //!< 交易tab展示在KeyWindow，下单展示在当前view

/**
 * UI样式设置：只支持titleLabel 不支持subTitleLabel
 */
@property (nonatomic, assign) BOOL showOneLineTitle;

//ui
@property (nonatomic, strong) UIView *backView;
@property (nonatomic, strong) UITableView *tableView;

@property (nonatomic, copy) void (^warningActionBlock)(void);
@property (nonatomic, assign) BOOL hideMoreSelect;///< 隐藏箭头，只有在下单页的模拟账户时才会隐藏

@property (nonatomic, weak) UIViewController *targetVC;

@property (nonatomic, assign) BOOL filterContraAccountEnable; ///< 是否过滤contra账户
@property (nonatomic, assign) BOOL contractSupportContraTradeable; ///< 合约是否支持contra账户交易

@property (nonatomic, assign) BOOL isIBAccountDisplayDisable; ///< 是否隐藏IB账户（lite下单页时使用）

@property (nonatomic, copy, nullable) NSString *saPage;
@property (nonatomic, copy, nullable) NSString *saComponent;

- (void)reloadData;

- (void)reloadDataWithFetchAvailableVirtualAccount:(BOOL)fetchAvailableVirtualAccount;

- (void)showTradeTitleView;

- (void)reloadTitle;

/// 内部调用reloadTableView
- (void)reloadLayout;

@end

@protocol TBTradeTitleViewDelegate <NSObject>

- (void)handleTradeView:(UIView *)switchView titleView:(TBTradeTitleView *)titleView tableView:(UITableView *)tableView hidden:(BOOL)hidden onKeyWindow:(BOOL)onKeyWindow compelete:(void (^)(void))compelete;

/**
 切换交易账户

 @param switchView backgroundView
 @param tableView 切换视图
 @param tradeAccount 切换的账户
 */
- (void)netSwitchTradeWithTableView:(UIView *)switchView tableView:(UITableView *)tableView tradeAccount:(NSString *)tradeAccount withId:(NSString *)accountOrCustomerId compelete:(void (^)(void))compelete;

@end
