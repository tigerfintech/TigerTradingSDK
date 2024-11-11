//
//  TBStockNoticeGroupTableCell.h
//  StockBusiness
//
//  Created by liuhuan on 2024/4/1.
//  Copyright © 2024 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

typedef NS_ENUM(NSUInteger, TBStockNoticeGroupTableStyle) {
    TBStockNoticeGroupTableStyleList,
    TBStockNoticeGroupTableStyleFold,
};

NS_ASSUME_NONNULL_BEGIN

@protocol TBStockNoticeGroupTableCellProtocol <NSObject>

/// 设置是否显示折叠按钮，折叠样式并首行显示
- (void)setFoldButtonShow:(BOOL)show;
/// 设置是否显示关闭按钮，折叠按钮强制不显示
- (void)setCloseButtonShow:(BOOL)show;
/// 折叠状态改变时触发设置文案和状态
- (void)foldChangeWithText:(NSString *)text fold:(BOOL)fold;
/// 配置折叠操作方法，要求实现类保留该Block并在折叠操作时调用
- (void)configFoldAction:(void(^)(void))foldBlock;
/// 配置关闭操作方法，要求实现类保留该Block并在关闭操作时调用
- (void)configCloseAction:(void(^)(TBTableViewCellItem *))closeBlock;

@end

@interface TBStockNoticeGroupTableCell : TBTableViewCell

@end

/// 可折叠列表组控件，可以将多个Cell放到一组中折叠展开操作
/// 添加到组的Cell需实现子Cell协议，实现界面更新、折叠和关闭等操作
@interface TBStockNoticeGroupTableCellItem : TBTableViewCellItem

@property (nonatomic, assign) TBStockNoticeGroupTableStyle style;
@property (nonatomic, assign) BOOL fold;
@property (nonatomic, copy) NSArray<TBTableViewCellItem *> *items;
@property (nonatomic, copy) void(^foldBlock)(BOOL fold);
@property (nonatomic, copy) void(^closeBlock)(TBTableViewCellItem *item);

@end

NS_ASSUME_NONNULL_END
