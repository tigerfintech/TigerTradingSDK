//
//  TBStockFundamentalCell.h
//  Stock
//
//  Created by Pengfei_Luo on 16/9/2.
//  Copyright © 2016年 com.tigerbrokers. All rights reserved.
//

#import <TBUIKit/TBTableViewCell.h>
//#import "TBStockDetailCombineModel.h"

#define FUNDAMENTAL_SINGLE_LINE_HEIGHT_LITE (56)
#define FUNDAMENTAL_SINGLE_LINE_HEIGHT_PRO (21)

UIKIT_EXTERN NSString *const TBSTOCK_DETAIL_TURNOVERRATE; // 换手率
UIKIT_EXTERN NSString *const TBSTOCK_DETAIL_MARKETVALUE; // 市值


@class TBOptionFundamentalModel;
@class TBOptionInfoDetailItem;
@class TBStockDetailCombineModel;

@protocol TBStockFundamentalCellDelegate <NSObject>

@optional
- (NSString *)secTypeString;
- (TBOptionFundamentalModel *)fundamentalModel;
- (TBOptionInfoDetailItem *)optionInfoItem;

@end

typedef NS_ENUM(NSInteger, TBStockFundamentalContentAlignmentType) {
    TBStockFundamentalContentAlignmentTypeDefault,
    TBStockFundamentalContentAlignmentTypeLeft,
    TBStockFundamentalContentAlignmentTypeLeading,
    TBStockFundamentalContentAlignmentTypeTrailing,
};

@interface TBStockFundamentalDetailEmptyCell : UICollectionViewCell
@end

@interface TBStockFundamentalDetailCell : UICollectionViewCell

@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UILabel *valueLabel;
@property (nonatomic, strong) UIImageView *ttmImageView;

@property (nonatomic, assign) TBStockFundamentalContentAlignmentType contentAlignment;///< 内容对齐


@property (nonatomic, strong) UITapGestureRecognizer *tapGesture;

@property (nonatomic, copy) void(^tapAction)(void);

@end

/**
 *  7种类型：A股、A股基金、A股指数、美股、美股指数、港股、港股指数
 */
@interface TBStockFundamentalCell : TBTableViewCell



@end

@interface TBStockFundamentalCellItem : TBTableViewCellItem

/// 是否折叠，默认折叠
@property (nonatomic, assign, getter=isFold) BOOL fold;

@property (nonatomic, copy) NSString *secType;

@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, assign) BOOL isIndex;
@property (nonatomic, assign, readonly) BOOL isHiddenIndicator;

@property (nonatomic, strong) id<TBStockFundamentalCellDelegate> dataSouce;
/// 个股基本面信息合并model
@property (nonatomic, strong) TBStockDetailCombineModel *combineModel;

+ (CGFloat)numberOfLines;

@end
