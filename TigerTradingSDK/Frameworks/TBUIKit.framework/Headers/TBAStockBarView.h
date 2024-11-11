//
//  TBAStockBarView.h
//  Stock
//
//  Created by Pengfei_Luo on 15/12/4.
//  Copyright © 2015年 com.tigerbrokers. All rights reserved.
//

#import <UIKit/UIKit.h>

static int const titleLimitLength = 8;

typedef NS_ENUM(NSInteger, kStockPriceChangeStyle) {
    kStockPriceChangeStyleZero = 0,
    kStockPriceChangeStyleIncrease,
    kStockPriceChangeStyleDecrease
};


/**
 *  股票详情页上下滑动方向
 */
typedef NS_ENUM(NSInteger, kStockDetailScrollDirection){
    kStockDetailScrollDirectionNone = 0,
    kStockDetailScrollDirectionUp,     // 向上
    kStockDetailScrollDirectionDown    // 向下
};

/**
 *  subTitle显示的样式：top、bottom
 */
typedef NS_ENUM(NSInteger, kStockDetailSubtitleShowType){
    kStockDetailSubtitleShowTypeTop,     // 显示头
    kStockDetailSubtitleShowTypeBottom    // 显示尾
};

typedef NS_ENUM(NSInteger, kStockNoticeType) {
    kStockNoticeTypeNone = -1,       // 没有公告
    kStockNoticeTypeNormal = 0, // 普通公告
    kStockNoticeTypeSerious = 1,// 紧急公告
    kStockNoticeTypeETF,        // EFT公告
    kStockNoticeTypeSIDLCs,        // EFT公告
    kStockNoticeTypeToday,       //A股今日股市的诸多公告
    kStockNoticeTypeNameCN,       // nameCN
    kStockNoticeTypeAStockAction //A股前缀文案解释 XD XR DR N
};

@protocol TBAStockBarViewDelegate;
@interface TBAStockBarView : UIView
-(void)updateBarNameCN:(NSString*)nameCN symbol:(NSString *)symbol subTitle:(NSString*)subTitle market:(NSString*)market secType:(NSString *)secType;

@property (nonatomic, copy) void(^tapTitleShowInfo)(kStockNoticeType type);
@property (nonatomic, copy) void(^tapNameSymbolInfo)(kStockNoticeType type);

@property (nonatomic, weak) id<TBAStockBarViewDelegate> delegate;

@property (nonatomic, assign) BOOL showLeftRightIcon;
@property (nonatomic, assign) BOOL showNamePrompt;

/**
 *  展示公告标示
 *
 *  @param noticeType 公告标示类型
 */
-(void)showNoticeType:(kStockNoticeType)noticeType;
/**
 *  标题内容
 *
 *  @param title 标题
 */
- (void)updateBarTitle:(NSString *)title;
/**
 *  更新副标题内容
 *
 *  @param subTitle    副标题时间更新
 *  @param priceTitle  副标题价格更新
 *  @param changeStyle 价格变动：增，减，zero
 */
-(void)updateBarSubTitle:(NSString *)subTitle priceTitle:(NSString*)priceTitle pricChangeColor:(UIColor *)changeColor;

-(void)updateBarTitle:(NSString*)title subTitle:(NSString*)subTitle market:(NSString*)market secType:(NSString *)secType;

///**
// *  更新副标题展示类型
// *
// *  @param scrollDirection 滚动方向
// */
//-(void)updateBarShowSubtitleTyle:(kStockDetailScrollDirection)scrollDirection;
//
//-(void)updateBarShowSubtitleTyle:(kStockDetailScrollDirection)scrollDirection withAnimation:(BOOL)animated;

/**
 *  更新副标题展示类型
 *
 *  @param type 显示类型
 */
- (void)updateBarSubtitleType:(kStockDetailSubtitleShowType)type;

- (void)updateBarSubtitleType:(kStockDetailSubtitleShowType)type withAnimation:(BOOL)animated;

/// 标的名称居中展示，隐藏时间、价格
/// @param hiddenMarket 是否隐藏市场
- (void)updateTitleLabelCeterY:(BOOL)hiddenMarket;

@property (nonatomic, readonly) UIScrollView *subtitleScrollView;
-(BOOL)hasShowedAnimation;
@end

@protocol TBAStockBarViewDelegate <NSObject>
@optional
-(void)stockTitleBarClicked;
@end
