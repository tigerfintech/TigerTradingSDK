//
//  TBUtils+TBWatchList.h
//  TBStockBusiness
//
//  Created by zhengzhiwen on 2021/6/23.
//

#import <TBBaseKit/TBBaseKit.h>
#import <TBStockKit/TBStock.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBUtils (TBWatchList)

//自选是否智能排序
+ (BOOL)isAllowHangqingSmartSorting;
//自选是否开启点击最后一列
+ (BOOL)isAllowClickLastColumnSwitchDisplayItem;
+ (void)setAllowClickLastColumnSwitchDisplayItem:(BOOL)allow;

//自选长按是否出现数据项菜单
+ (BOOL)isAllowItemListMenu;
+ (void)setAllowItemListMenu:(BOOL)allow;
+ (void)setPortraitLastRow:(int)lastRow;
+ (int)portraitLastRow;

//是否展示色块
+ (BOOL)isAllowItemBGView;
+ (void)setAllowItemBGView:(BOOL)allow;

//自选列表显示持仓标识
+ (BOOL)isDisplayOptionPosition;
+ (BOOL)isItemsDefault;
+ (void)setItemsDefault:(BOOL)defa;
+ (BOOL)isAllowHangqingAnimationLayer;

/// 是否显示 *个股详情页* 底部大盘指数
+ (BOOL)isAllowDetailBottomShowIndexNotification;
+ (void)setIsAllowDetailBottomShowIndexNotification:(NSNumber *)value;

// 是否展示自选页面未开户新人福利浮层图片
+ (BOOL)showWatchlistNewerGiftFloatingView;

// 处理开户页面为新人福利页面的标记位问题
+ (void)handleNewerWelfareStorage;

+ (void)addStockToWatchListWithSymbol:(NSString *)symbol nameCN:(NSString *)nameCN market:(NSString *)market successed:(void(^)(TBDealWatchListItemType type))successed;

/**
此方法添加标的到自选列表没有相应的hud文字提示， 供新手引导使用
 */

+ (void)addStockToWatchListNoAlertForNewGuideWithSymbol:(NSString *)symbol nameCN:(NSString *)nameCN market:(NSString *)market successed:(void (^)(TBDealWatchListItemType type))successed;

@end

NS_ASSUME_NONNULL_END
