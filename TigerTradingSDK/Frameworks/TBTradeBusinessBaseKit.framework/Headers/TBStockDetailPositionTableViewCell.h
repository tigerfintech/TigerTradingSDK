//
//  TBStockDetailPositionTableViewCell.h
//  Stock
//
//  Created by 骆鹏飞 on 2021/3/8.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBBusinessSupportKit/TBStockDetailBaseTradeTableViewCell.h>
#import <TBTradeBusinessBaseKit/TBTradeAPIPositionModel.h>

@class TBStockDetailActiveOrderLegsInfoView;

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN NSString *const kStockDetailPositionFoldKey;

/*
 
 个股持仓：
 文档：https://wiki.tigerbrokers.net/pages/viewpage.action?pageId=77663550
 设计稿：https://app.mockplus.cn/app/NCghar47Li/specs/design/LbRm3AV98Q
 上线版本：V700
 产品：@chenfu
 
 update: v9.12
 文档：https://tigertech.feishu.cn/docx/JI7edM51Ioe8oYxkffucsCiIn3d
 设计稿：https://www.figma.com/file/9hy0ZePGTtSzpx6rhVEaTw/912-%E3%80%90Option-Rollover%E4%B8%80%E6%9C%9F%E3%80%91%E6%94%AF%E6%8C%81%E5%8D%95%E8%85%BF%E6%9C%9F%E6%9D%83%E5%B1%95%E6%9C%9F?node-id=128%3A2344&mode=dev
 个股详情，持仓模块不再使用pro样式，统一使用lite样式，即TBStockDetailPositionLiteTableViewCell
 */
@protocol TBStockDetailInfoDataSource;

@protocol TBStockDetailPositionTableViewCellDataSource <NSObject>

- (NSString *)positionInStockDetailTableCellPosition;
- (NSString *)positionInStockDetailTableCellAverageCost;
- (NSString *)positionInStockDetailTableCellUnrealPnl;
- (NSString *)positionInStockDetailTableCellUnrealPnlRatio;
- (NSString *)positionInStockDetailTableCellMarketValue;
- (NSString *)positionInStockDetailTableCellPositionPnl;

- (UIColor *)positionInStockDetailTableCellUnrealizedPnlColor;

- (UIColor *)positionInStockDetailTableCellPnlColor;

@end

@interface TBStockDetailPositionTableViewCell : TBStockDetailBaseTradeTableViewCell

/// 持仓标志
@property (nonatomic, strong) UILabel *tagLabel;

@property (nonatomic, strong) UILabel *positionAndPriceLabel;

@property (nonatomic, strong) TBStockDetailActiveOrderLegsInfoView *legsInfoView;

@property (nonatomic, strong) UILabel *pnlLabel;
@property (nonatomic, strong) UILabel *pnlRatioLabel;

/// 市值标题
@property (nonatomic, strong) UILabel *mtkTitleLabel;


@property (nonatomic, strong) UIStackView *operateVStackView; // 纵向布局，margin left/right
@property (nonatomic, strong) UIStackView *operateHStackView; // 横向布局，控制spacing
@property (nonatomic, strong) UIButton *closeBtn;
@property (nonatomic, strong) UIButton *shareBtn;
@property (nonatomic, strong) UIButton *pnlBtn;
@property (nonatomic, strong) UIButton *rollBtn;
@property (nonatomic, strong) UIButton *optionExerciseBtn; // 提前行权/放弃行权按钮

@property (nonatomic, strong) UILabel *mtkValueLabel;

@end

@interface TBStockDetailPositionTableViewCellItem : TBStockDetailBaseTradeTableViewCellItem
{
    BOOL _opened;
}

@property (nonatomic, strong) TBTradeAPIPositionItemModel *positionModelItem;

/// 数据源
@property (nonatomic, weak) id<TBStockDetailPositionTableViewCellDataSource> dataSource;


@property (nonatomic, strong) id/*<TBStockDetailInfoDataSource>*/ secInfo;

@property (nonatomic, assign) BOOL usePositionPnl;

/** 907 是否需要修正组合持仓-数量（组合期权详情页）
 *  https://tigertech.feishu.cn/docx/PX1wd1M3doeihrx8IVEcU9d4nHb#part-GyWZdZjHXooKW1xiwoIcpdLNnNf
 *
 *  quoteLegs 行情页的腿的信息
 */
@property (nonatomic, copy, nullable) NSArray <NSDictionary *> *quoteLegs;

@end

NS_ASSUME_NONNULL_END
