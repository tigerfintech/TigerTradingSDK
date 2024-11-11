//
//  TBStockDetailPositionOrderSectionHeaderView.h
//  Stock
//
//  Created by 骆鹏飞 on 2021/3/8.
//  Copyright © 2021 com.tigerbrokers. All rights reserved.
//

#import <TBStockBusinessBaseKit/TBStockDetailBaseTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN NSString * const STOCKDETAILPOSITIONORDERFOLDKEY;

@interface TBStockDetailPositionOrderSectionHeaderView : TBStockDetailBaseTableViewCell

@end

@interface TBStockDetailPositionOrderSectionHeaderViewItem : TBStockDetailBaseTableViewCellItem

@property (nonatomic, assign) BOOL isIntroBtnEnable;
@property (nonatomic, assign, getter=isOpened) BOOL opened;
@property (nonatomic, copy) NSString *market;
@property (nonatomic, copy) NSString *symbol;
@property (nonatomic, copy) NSString *secType;

@end

NS_ASSUME_NONNULL_END
