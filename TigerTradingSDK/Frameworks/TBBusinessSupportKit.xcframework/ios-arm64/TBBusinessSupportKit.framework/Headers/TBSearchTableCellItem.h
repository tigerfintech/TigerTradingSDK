//
//  TBSearchTableCellItem.h
//  Stock
//
//  Created by liwt on 15/1/9.
//  Copyright (c) 2015年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
#import <TBUIKit/TBTableViewCellItem.h>
//#import "TBWatchListTableCellItem.h"
//#import "TBMarketConditionsUntils.h"


@interface TBSearchTableCellItem : TBTableViewCellItem

// 显示的symbol，和symbol不一样，比如组合期权
@property (nonatomic, copy) NSString *displaySymbol;

@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *nameCN;
@property (nonatomic, copy) NSString *fullName; // 多腿期权专用
@property (nonatomic, copy) NSString *market;
@property (nonatomic, strong) NSNumber *type;   //type: 数据类型 0代表股票，1代表板块，2代表窝轮牛熊证链表，3代表窝轮，4代表牛熊证，5代表期货，6代表OTC， 8代表基金
@property (nonatomic, assign) NSInteger halted;
@property (nonatomic, assign) BOOL isWatched;
@property (nonatomic, assign) BOOL withoutAccessory;//YES:取消自选操作longaddin9/12/2015
@property (nonatomic, assign) BOOL hideBottomLine;  ///Default:YES

@property (nonatomic, copy) NSArray *labels;
@property (nonatomic, copy) NSString *secType;

- (TBSearchTableCellItem *) applySymbol:(NSString *)symbol nameCN:(NSString *)nameCN marketType:(NSString *)marketType isWatched:(BOOL) isWatched;

- (CGFloat)cellHeight;

/// 早晚报相关属性
@property (nonatomic, strong) NSNumber *gmtCreate; ///< 用于早晚报搜索界面
@property (nonatomic, assign) BOOL isNewspaperSearch; ///< 是否用于早晚报搜索结果
@property (nonatomic, assign) BOOL isNewspaperList; ///< 是否用于早晚报偏好管理列表
@property (nonatomic, assign) BOOL isNewerThemeUI; // 是否是8.0的UI

/// 为行情添加埋点，用于优化股票搜索
@property (nonatomic, copy) NSString *sid;
@property (nonatomic, assign) NSInteger offset;
@property (nonatomic, assign) NSInteger leadingOffset; ///Default:0
@property (nonatomic, assign) BOOL enableLogo;
@property (nonatomic, strong) UIImage *logoImage;

@end

@interface TBSearchTableCell : TBTableViewCell



@end
