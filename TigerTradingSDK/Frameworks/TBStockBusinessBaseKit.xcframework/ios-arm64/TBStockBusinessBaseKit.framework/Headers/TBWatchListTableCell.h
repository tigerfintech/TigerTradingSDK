//
//  TBWatchListTableCell.h
//  Stock
//
//  Created by yangfan on 2018/9/3.
//  Copyright © 2018年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>

typedef void(^WatchlistEditBlock)(NSDictionary *obj);

@interface TBWatchListTableCell : TBTableViewCell
//暗盘相关
@property (nonatomic, copy) NSString *greyMarketTag;

@property (nonatomic, strong) UIImageView *marketType;
@property (nonatomic, copy) NSString *hourTradingTag;
@property (nonatomic, strong) UILabel *hourTradingTagLabel;
@property (nonatomic, strong) UILabel *hourTradingPrice;
@property (nonatomic, strong) UILabel *hourTradingChangeRate;

@property (nonatomic, strong) UILabel *des;
@property (nonatomic, strong) UILabel *code;
@property (nonatomic, strong) UILabel *price;
@property (nonatomic, strong) UILabel *changeRate;
@property (nonatomic, assign) BOOL directionUp;
@property (nonatomic, assign) BOOL priceZero;
@property (nonatomic, strong) UIImageView *backColorView;

@property (nonatomic, strong) UILabel * delayLabel;

@property (nonatomic, assign) BOOL flowWarning;//决定是否使用股价变化动效。设置为YES则支持有动效，

//下边两个主连相关，都是用于是否显示“主”图标，由item中的isContractMain决定
@property (nonatomic, strong) UIImageView *mainTypeIcon;//是否是主连合约（目前期货用到）
@property (nonatomic, assign) BOOL isMainContract;//是否是主连合约

- (void)watchlistEdit:(WatchlistEditBlock)thisBlock;

@end
